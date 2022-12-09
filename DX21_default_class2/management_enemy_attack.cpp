#include "management_enemy_attack.h"
#define _USE_MATH_DEFINES
#include <math.h>


const float EnemyAttackManagement::ATTACK_SPEED = 5.0f;
//=========================
// 引数付きコンストラクタ
//=========================
EnemyAttackManagement::EnemyAttackManagement(DrawObject& pDrawObject1)
	:EnemyManagement(ENEMY_NUM, ATTACK, 0), m_pDrawObjectEnemy(pDrawObject1)
{
	m_pEnemyAttack = new EnemyAttack[ENEMY_NUM];
}

//======================
// 更新処理
//======================
void EnemyAttackManagement::Update(const D3DXVECTOR2& PlayerPos)
{
	m_FlameNum++; //フレーム数を増加

	if (m_FlameNum == m_SetEnemyTime[m_EnemyNum])
	{
		EnemyAttack temp(m_pDrawObjectEnemy, m_SetEnemy[m_EnemyNum]);
		m_pEnemyAttack[GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		m_EnemyNum++;
	}

	//今いる敵の処理
	for (int i = 0; i < GetObjNum(); i++) {
		m_pEnemyAttack[i].Update();

		//時間になったら突っ込む
		if (m_pEnemyAttack[i].GetFlagAttack()) {
			//プレイヤーの後を追う(ホーミング弾)
			D3DXVECTOR2 movTemp = PlayerPos - m_pEnemyAttack[i].GetPos();
			D3DXVECTOR2 rotposTemp = m_pEnemyAttack[i].GetPos() - PlayerPos;
			D3DXVec2Normalize(&movTemp, &movTemp);
			movTemp *= ATTACK_SPEED;
			m_pEnemyAttack[i].MovePos(movTemp);
		
			if (m_pEnemyAttack[i].GetFlagExplosion())
			{
				
				m_pEnemyAttack[i].MovePos(D3DXVECTOR2(0.0f, 0.0f));
				//DeleteObj(i);
			}
		}
	}
}

//==========================
// 描画処理
//==========================
void EnemyAttackManagement::Draw(void)const
{
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemyAttack[i].Draw();
	}


}

//======================
// 敵のHPを減らす
//======================
bool EnemyAttackManagement::ReduceHP(int index_num, int reduceHP)
{
	m_pEnemyAttack[index_num].ReduceHP(reduceHP);
	if (m_pEnemyAttack[index_num].GetHP() <= 0)
	{//HPが０以下なら敵を消す

		return true;
	}
	return false;
}
//==========================
// 敵を消す
//==========================
void EnemyAttackManagement::DeleteObj(int index_num)
{
	//敵を消す
	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemyAttack[i] = m_pEnemyAttack[i + 1];
	}

	//継承元の敵を消すを呼ぶ
	EnemyManagement::DeleteObj(index_num);
}
