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

void PlayerArm2::Update(const D3DXVECTOR2& arm_pos)
{
	//ボタンが押されたら
	if ((inhPlayerArm::GetRightLeft() && GetKeyboardPress(DIK_RIGHT)) || (!inhPlayerArm::GetRightLeft() && GetKeyboardPress(DIK_LEFT))) {
		//発射できる時間になったら...
		if (++m_bullet_interval_count > BULLET_INTERVAL) {
			Laser temp(m_laser_draw, arm_pos,
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), &m_pEnemyLaser[i]);
			m_pLaser[inhPlayerArm::GetBulletNum()] = temp;
			
			//現在の弾の数を増やす
			inhPlayerArm::IncreaseBulletNum();

			//作った弾のあk図を増やす
			inhPlayerArm::IncreaseBulletMaked();
		}
	}

	//現在の弾の処理
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		//レーザーの残り時間減少
		m_lasertime--;

		if (m_pLaser[i].GetSize().y > SCREEN_HEIGHT) //レーザーが十分な長さになったか
		{
			if (m_lasertime < 0) //レーザーの射出時間が終わったか
			{
				//レーザーを短くする
				m_pLaser[i].SetSize(D3DXVECTOR2(m_pLaser[i].GetSize().x, m_pLaser[i].GetSize().y - BULLET_SPEED * 2));
			}
			//レーザーのX座標をプレイヤーに合わせる
			m_pLaser[i].SetPos(D3DXVECTOR2(m_pPlayer->GetPos().x, m_pLaser[i].GetPos().y));
		}
		else
		{
			//レーザーを長くする
			m_pLaser[i].SetSize(D3DXVECTOR2(m_pLaser[i].GetSize().x, m_pLaser[i].GetSize().y - BULLET_SPEED * 2));
			//レーザーのX座標をエネミーに合わせる
			m_pLaser[i].SetPos(D3DXVECTOR2(m_pPlayer->GetPos().x, m_pLaser[i].GetPos().y - BULLET_SPEED));
		}
	}
}

void PlayerArm2::PlayerArmDraw()const
{
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		m_pLaser[i].Draw();
	}
}