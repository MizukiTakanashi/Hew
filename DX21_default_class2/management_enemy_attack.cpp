//=======================================
// 普通の敵の管理関係(cppファイル)
// 作成日：2022/09/13
// 作成者：高梨水希
//=======================================
#include "management_enemy_attack.h"
#define _USE_MATH_DEFINES
#include <math.h>


const float EnemyAttackManagement::ATTACK_SPEED = 5.0f;
//=========================
// 引数付きコンストラクタ
//=========================
EnemyAttackManagement::EnemyAttackManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, EnemySetPos& pEnemySetPos)
	:EnemyManagement(ENEMY_NUM, ATTACK, BULLET_ATTACK), m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBullet(pDrawObject2), m_pEnemySetPos(pEnemySetPos)
{
	m_pEnemyAttack = new EnemyAttack[ENEMY_NUM];
	m_pBullet = new Bullet[ENEMY_NUM];
}

//======================
// 更新処理
//======================
void EnemyAttackManagement::Update(const D3DXVECTOR2& PlayerPos)
{
	m_FlameNum++; //フレーム数を増加

	int i = m_FlameNum;
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

	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		m_pBullet[i].Draw();
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
		EnemyManagement::DeleteObj(index_num, reduceHP);

		m_pEnemySetPos.DeleteEnemy(m_pEnemyAttack[index_num].GetPos());

		for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
			m_pEnemyAttack[i] = m_pEnemyAttack[i + 1];
		}
		EnemyManagement::IncreaseObjNum(-1);

		return true;
	}
	return false;
}

void EnemyAttackManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < EnemyManagement::GetBulletNum() - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	EnemyManagement::IncreaseBulletNum(-1);
}


