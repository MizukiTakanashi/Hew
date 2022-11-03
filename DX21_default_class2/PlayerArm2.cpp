//=======================================
// プレイヤーの腕2関係(cppファイル)
// 作成日：2022/00/00
// 作成者：高梨水希
//=======================================
#include "PlayerArm2.h"

#include <math.h>
#include "input.h"

//==========================
// 定数の初期化
//==========================
const float PlayerArm2::BULLET_SIZE_X = 40.0f;
const float PlayerArm2::BULLET_SIZE_Y = 40.0f;
const float PlayerArm2::BULLET_SPEED = 2.5f;
const float PlayerArm2::SPEED_Y = 15.0f;

//==========================
// 更新処理
//==========================
void PlayerArm2::Update(const D3DXVECTOR2& arm_pos)
{
	m_bullet_interval_count++;

	//ボタンが押されたら
	if ((inhPlayerArm::GetRightLeft() && GetKeyboardTrigger(DIK_RIGHT)) || 
		(!inhPlayerArm::GetRightLeft() && GetKeyboardTrigger(DIK_LEFT))) {
		//発射できる時間になったら...
		if (m_bullet_interval_count > BULLET_INTERVAL) {
			m_bullet_interval_count = 0;
			
			Laser temp(m_laser_draw, arm_pos, D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y));
			m_pLaser[inhPlayerArm::GetBulletNum()] = temp;
			
			//現在の弾の数を増やす
			inhPlayerArm::IncreaseBulletNum();

			//作った弾の数を増やす
			inhPlayerArm::IncreaseBulletMaked();
		}
	}

	//現在の弾の処理
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		m_pLaser[i].Update(arm_pos, false);

		//画面から出たら消す
		if (m_pLaser[i].GetScreenOut()) {
			DeleteBullet(i);
		}
	}
}

//==========================
// 描画処理
//==========================
void PlayerArm2::PlayerArmDraw()const
{
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		m_pLaser[i].Draw();
	}
}

//==========================
// 指定した番号の弾を消す
//==========================
void PlayerArm2::DeleteBullet(int index_num)
{
	//レーザーを縮める
	m_pLaser[index_num].DeleteLaser();

	//レーザーを消す
	for (int i = index_num; i < inhPlayerArm::GetBulletNum() - 1; i++) {
		m_pLaser[i] = m_pLaser[i + 1];
	}

	inhPlayerArm::IncreaseBulletNum(-1);
}