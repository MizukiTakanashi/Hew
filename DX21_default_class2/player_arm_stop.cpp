//=======================================
// プレイヤーの腕(STOP)関係(cppファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#include "player_arm_stop.h"

//==========================
// 定数の初期化
//==========================
const float PlayerArmStop::BULLET_SIZE_X = 100.0f;
const float PlayerArmStop::BULLET_SIZE_Y = 300.0f;

//==========================
// 更新処理
//==========================
void PlayerArmStop::Update(const D3DXVECTOR2& arm_pos)
{

	//今いる弾の処理
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		//弾の更新処理
		m_pBullet[i].Update();

		//画面外から出たら...
		if (m_pBullet[i].GetScreenOut() || m_pBullet[i].GetTime() > BULLET_TIME) {
			DeleteBullet(i);
		}
	}

	//もしも弾の制限が超えてたら弾を作らない
	if (inhPlayerArm::IsBulletUsed()) {
		return;
	}

	//発射間隔カウント
	m_bullet_interval_count++;

	//ボタンが押されたら
	if ((inhPlayerArm::GetRightLeft() && inhPlayerArm::IsButtonPush()) ||
		(!inhPlayerArm::GetRightLeft() && inhPlayerArm::IsButtonPush())) 
	{
		//発射できる時間になったら...
		if (m_bullet_interval_count > BULLET_INTERVAL)
		{
			m_bullet_interval_count = 0;

			//腕の切り離しと同時に弾を作らないための処理
			if (inhPlayerArm::GetBulletMaked() == BULLET_NUM_MAX - 1)
			{
				//作った弾の数を増やす
				inhPlayerArm::IncreaseBulletMaked();

				return;
			}

			//弾を作る
			BulletStop temp(m_bulletdraw, arm_pos - D3DXVECTOR2(0, 300), D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y));

			m_pBullet[inhPlayerArm::GetBulletNum()] = temp;

			//現在の弾の数を増やす
			inhPlayerArm::IncreaseBulletNum();

			//作った弾の数を増やす
			inhPlayerArm::IncreaseBulletMaked();
		}
	}
}

//==========================
// 描画処理
//==========================
void PlayerArmStop::PlayerArmDraw()const
{
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		m_pBullet[i].Draw();
	}
}

//==========================
// 指定した番号の弾を消す
//==========================
void PlayerArmStop::DeleteBullet(int index_num)
{
	//弾を消す
	for (int i = index_num; i < inhPlayerArm::GetBulletNum(); i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	inhPlayerArm::IncreaseBulletNum(-1);
}
