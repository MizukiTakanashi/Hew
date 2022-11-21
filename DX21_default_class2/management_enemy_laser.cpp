//=======================================
// レーザーの敵の管理関係(cppファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#include "management_enemy_laser.h"
#define _USE_MATH_DEFINES
#include <math.h>

//==========================
// 定数の初期化
//==========================
const float EnemyLaserManagement::BULLET_SIZE_X = 20.0f;
const float EnemyLaserManagement::BULLET_SIZE_Y = 0.0f;


//=========================
// 引数付きコンストラクタ
//=========================
EnemyLaserManagement::EnemyLaserManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, EnemySetPos& pEnemySetPos)
	:EnemyManagement(ENEMY_NUM, ATTACK, LASER_ATTACK), m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectLaser(pDrawObject2), m_pEnemySetPos(pEnemySetPos)
{
	m_pEnemyLaser = new EnemyLaser[ENEMY_NUM];
	m_pLaser = new Laser[ENEMY_NUM];
}

//======================
// 更新処理
//======================
void EnemyLaserManagement::Update()
{
	AddFlame(); //フレーム数を増加

	int i = GetFlameNum();
	if (GetFlameNum() == m_SetEnemyTime[m_EnemyNum] && GetObjNum() != ENEMY_NUM)
	{
		EnemyLaser temp(m_pDrawObjectEnemy, m_SetEnemy[m_EnemyNum]);
		m_pEnemyLaser[GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		m_EnemyNum++;
	}

	//今いる敵の処理
	for (int i = 0; i < GetObjNum(); i++)
	{
		m_pEnemyLaser[i].Update();
		//レーザーのアップデート
		if (m_pEnemyLaser[i].GetLaserIndex() >= 0)
		{
			m_pLaser[m_pEnemyLaser[i].GetLaserIndex()].Update(m_pEnemyLaser[i].GetPos());
		}

		//弾を作る
		if (m_pEnemyLaser[i].GetFlagBulletMake() && EnemyManagement::GetBulletNum() != ENEMY_NUM)
		{
			//レーザー番号をセット
			m_pEnemyLaser[i].SetLaserIndex(EnemyManagement::GetBulletNum());
			Laser temp(m_pDrawObjectLaser, m_pEnemyLaser[i].GetPos() + D3DXVECTOR2(0.0f, 10.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y));
			m_pLaser[EnemyManagement::GetBulletNum()] = temp;
			m_pEnemyLaser[i].SetLaserIndex(EnemyManagement::GetBulletNum());
			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyLaser[i].BulletMake();
		}
	}

	//死んだ敵のレーザーのアップデート
	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++)
	{
		if (m_pLaser[i].GetLaserTime() < 0)
		{
			m_pLaser[i].Update(m_pLaser->GetPos());
		}
		
		//画面外から出たら...
		if (m_pLaser[i].GetScreenOut())
		{
			//弾を消す
			DeleteBullet(i);
		}
	}
}

//==========================
// 描画処理
//==========================
void EnemyLaserManagement::Draw(void)const
{
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemyLaser[i].Draw();
	}

	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++)
	{
		m_pLaser[i].Draw();
	}
}

//======================
// 敵を消す
//======================
void EnemyLaserManagement::DeleteObj(int index_num)
{
	EnemyManagement::DeleteObj(index_num);

	if (m_pEnemyLaser[index_num].GetLaserIndex() >= 0)
	{
		m_pLaser[m_pEnemyLaser[index_num].GetLaserIndex()].DeleteLaser();
	}

	m_pEnemySetPos.DeleteEnemy(m_pEnemyLaser[index_num].GetPos());

	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemyLaser[i] = m_pEnemyLaser[i + 1];

	}
	EnemyManagement::IncreaseObjNum(-1);
}

//======================
// 弾を消す
//======================
void EnemyLaserManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < EnemyManagement::GetBulletNum() - 1; i++)
	{
		m_pLaser[i] = m_pLaser[i + 1];
	}
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++)
	{
		if (m_pEnemyLaser[i].GetLaserIndex() == index_num)
		{
			m_pEnemyLaser[i].SetLaserIndex(-1);
		}
		else if (m_pEnemyLaser[i].GetLaserIndex() > index_num)
		{
			m_pEnemyLaser[i].SetLaserIndex(m_pEnemyLaser[i].GetLaserIndex() - 1);
		}
	}
	EnemyManagement::IncreaseBulletNum(-1);
}