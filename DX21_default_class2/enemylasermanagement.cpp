//=======================================
// レーザーの敵の管理関係(cppファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#include "enemylasermanagement.h"
#define _USE_MATH_DEFINES
#include <math.h>

//==========================
// 定数の初期化
//==========================
const float EnemyLaserManagement::BULLET_SIZE_X = 30.0f;
const float EnemyLaserManagement::BULLET_SIZE_Y = 0.0f;


//=========================
// 引数付きコンストラクタ
//=========================
EnemyLaserManagement::EnemyLaserManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, EnemySetPos& pEnemySetPos)
	:EnemyManagement(MAX_NUM, MAX_NUM, ATTACK, LASER_ATTACK), m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectLaser(pDrawObject2), m_pEnemySetPos(pEnemySetPos)
{
	m_pEnemyLaser = new EnemyLaser[MAX_NUM];
	m_pLaser = new Laser[MAX_NUM];
}

//======================
// 更新処理
//======================
void EnemyLaserManagement::Update()
{
	//時間が来たら敵を配置
	if (m_count++ > APPEARANCE_TIME && GetObjNum() != MAX_NUM) {
		//ランダムで出現位置を決める
		float x = rand() % (SCREEN_WIDTH - (int)EnemyLaser::SIZE_X / 2) + EnemyLaser::SIZE_X / 2;

		//フラグに応じて敵を作る
		if (m_pEnemySetPos.SetEnemy(D3DXVECTOR2(x, EnemyLaser::STOP_POS_Y), D3DXVECTOR2(EnemyLaser::SIZE_X + EnemyLaser::RANGE * 2, EnemyLaser::SIZE_Y))) {
			EnemyLaser temp(m_pDrawObjectEnemy, D3DXVECTOR2(x, -EnemyLaser::SIZE_Y / 2));
			m_pEnemyLaser[GetObjNum()] = temp;
			EnemyManagement::IncreaseObjNum(1);
		}

		m_count = 0;
	}

	//今いる敵の処理
	for (int i = 0; i < GetObjNum(); i++)
	{
		m_pEnemyLaser[i].Update();

		//弾を作る
		if (m_pEnemyLaser[i].GetFlagBulletMake() && EnemyManagement::GetBulletNum() != MAX_NUM)
		{
			//レーザー番号をセット
			m_pEnemyLaser[i].SetLaserIndex(EnemyManagement::GetBulletNum());
			Laser temp(m_pDrawObjectLaser, m_pEnemyLaser[i].GetPos() + D3DXVECTOR2(0.0f, 10.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y));
			m_pLaser[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyLaser[i].BulletMake();
		}
	}

	//今いる弾の処理
	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++)
	{
		//レーザーの発射場所と敵の位置と合わせる
		for (int j = 0; j < GetObjNum(); j++) {
			if (m_pEnemyLaser[j].GetLaserIndex() == i) {
				//更新
				m_pLaser[i].Update(m_pEnemyLaser[j].GetPos());
			}
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
	EnemyManagement::IncreaseBulletNum(-1);
}