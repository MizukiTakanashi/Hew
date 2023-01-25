//===================================================
// プレイヤーの腕、ガトリング・炎関係(cppファイル)
// 作成日：2022/10/30
// 作成者：高梨水希
//===================================================
#include "player_arm_3.h"

//==========================
// 定数の初期化
//==========================
const float PlayerArm3::BULLET_SIZE_X = 20.0f;
const float PlayerArm3::BULLET_SIZE_Y = 20.0f;
const float PlayerArm3::BULLET_SPEED = 20.0f;
const float PlayerArm3::FIRE_SPEED = 10.0f;
const float PlayerArm3::ACID_SPEED = 5.0f;
const float PlayerArm3::FIREBALL_SPEED = 5.0f;

//==========================
// 更新処理
//==========================
void PlayerArm3::Update(const D3DXVECTOR2& arm_pos)
{
	//今いる弾の処理
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		//弾の更新処理
		m_pBullet[i].Update();

		//画面外から出たら...
		if (m_pBullet[i].GetScreenOut()){
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
		(!inhPlayerArm::GetRightLeft() && inhPlayerArm::IsButtonPush())) {
		//発射できる時間になったら...
		if (m_bullet_interval_count > m_interval) {
			m_bullet_interval_count = 0;

			//腕の切り離しと同時に弾を作らないための処理
			if (inhPlayerArm::GetBulletMaked() == BULLET_NUM_MAX - 1)
			{
				//作った弾の数を増やす
				inhPlayerArm::IncreaseBulletMaked();

				return;
			}

			float temp_speed = 0.0f;
			if (m_type == TYPE::GATORING) {
				temp_speed = BULLET_SPEED;
			}
			else if (m_type == TYPE::FIRE) {
				temp_speed = FIRE_SPEED;
			}
			else if (m_type == TYPE::ACID)
			{
				temp_speed = ACID_SPEED;
			}
			else if (m_type == TYPE::FIREBALL)
			{
				temp_speed = FIREBALL_SPEED;
			}

			//弾を作る
			Bullet temp;
			if (m_type == TYPE::ACID)
			{
				temp = Bullet(m_bulletdraw, arm_pos,
					D3DXVECTOR2(100.0f, 200.0f), D3DXVECTOR2(0.0f, -temp_speed), 0.0f);

			}
			else if (m_type == TYPE::FIREBALL)
			{
				temp = Bullet(m_bulletdraw, arm_pos,
					D3DXVECTOR2(200.0f, 200.0f), D3DXVECTOR2(0.0f, -temp_speed), 0.0f);
			}
			else
			{
				temp = Bullet(m_bulletdraw, arm_pos,
					D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0.0f, -temp_speed), 0.0f);

			}

			m_pBullet[inhPlayerArm::GetBulletNum()] = temp;

			//現在の弾の数を増やす
			inhPlayerArm::IncreaseBulletNum();

			//作った弾の数を増やす
			inhPlayerArm::IncreaseBulletMaked();

			//音を鳴らす
			if (m_type == TYPE::GATORING) {
				PlaySound(m_SE_21, 0);
			}
			else if (m_type == TYPE::FIRE) {
				PlaySound(m_SE_15_1, 0);
			}
		}
	}
}

//==========================
// 描画処理
//==========================
void PlayerArm3::PlayerArmDraw()const
{
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		m_pBullet[i].Draw();
	}
}

//==========================
// 指定した番号の弾を消す
//==========================
void PlayerArm3::DeleteBullet(int index_num)
{
	//弾を消す
	for (int i = index_num; i < inhPlayerArm::GetBulletNum(); i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	inhPlayerArm::IncreaseBulletNum(-1);
}