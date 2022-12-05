//=======================================
// 普通の敵の管理関係(cppファイル)
// 作成日：2022/09/13
// 作成者：高梨水希
//=======================================
#include "management_enemy_gatoring.h"
#define _USE_MATH_DEFINES
#include <math.h>

//==========================
// 定数の初期化
//==========================
const float EnemyGatoringManagement::BULLET_SIZE_X = 20.0f;
const float EnemyGatoringManagement::BULLET_SIZE_Y = 20.0f;
const float EnemyGatoringManagement::BULLET_SPEED = 2.5f;

//=========================
// 引数付きコンストラクタ
//=========================
EnemyGatoringManagement::EnemyGatoringManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, EnemySetPos& pEnemySetPos)
	:EnemyManagement(ENEMY_NUM, ATTACK, BULLET_ATTACK),m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBullet(pDrawObject2), m_pEnemySetPos(pEnemySetPos)
{
	m_pEnemyGatoring = new EnemyGatoring[ENEMY_NUM];
	m_pBullet = new Bullet[ENEMY_NUM];
}

//======================
// 更新処理
//======================
void EnemyGatoringManagement::Update(const D3DXVECTOR2& PlayerPos)
{
	m_FlameNum++; //フレーム数を増加

	if (m_FlameNum == m_SetEnemyTime[m_EnemyNum])
	{
		EnemyGatoring temp(m_pDrawObjectEnemy, m_SetEnemy[m_EnemyNum]);
		m_pEnemyGatoring[GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		m_EnemyNum++;
	}

	//今いる敵の処理
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemyGatoring[i].Update();

		//弾を作る
		if (m_pEnemyGatoring[i].GetFlagBulletMake())
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyGatoring[i].GetPos(),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y),D3DXVECTOR2(0, 10.0f), 0.0f);
						   // 弾の大きさ								弾を撃つ方向		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyGatoring[i].BulletMake();
		}
	}

	//今いる弾の処理
	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		m_pBullet[i].Update();
		//画面外から出たら...
		if (m_pBullet[i].GetScreenOut()) {
			//弾を消す
			DeleteBullet(i);
		}
	}
}

//==========================
// 描画処理
//==========================
void EnemyGatoringManagement::Draw(void)const
{
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemyGatoring[i].Draw();
	}

	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		m_pBullet[i].Draw();
	}
}

//======================
// 敵のHPを減らす
//======================
bool EnemyGatoringManagement::ReduceHP(int index_num, int reduceHP)
{
	m_pEnemyGatoring[index_num].ReduceHP(reduceHP);

	if (m_pEnemyGatoring[index_num].GetHP() <= 0)
	{//HPが０以下なら敵を消す

		EnemyManagement::DeleteObj(index_num);

		m_pEnemySetPos.DeleteEnemy(m_pEnemyGatoring[index_num].GetPos());

		for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
			m_pEnemyGatoring[i] = m_pEnemyGatoring[i + 1];
		}

		return true;
	}
	return false;
}

//======================
// 弾を消す
//======================
void EnemyGatoringManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < EnemyManagement::GetBulletNum() - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	EnemyManagement::IncreaseBulletNum(-1);
}