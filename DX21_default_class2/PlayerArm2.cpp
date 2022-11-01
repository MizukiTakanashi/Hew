#include "PlayerArm2.h"

#include <math.h>

//==========================
// 定数の初期化
//==========================
const float PlayerArm2::BULLET_SIZE_X = 40.0f;
const float PlayerArm2::BULLET_SIZE_Y = 40.0f;
const float PlayerArm2::BULLET_SPEED = 2.5f;

void PlayerArm2::Update()
{
	//発射できる時間になったら...
	if (++m_bullet_interval_count > BULLET_INTERVAL) {
		for (int i = 0; i < m_bullet_num; i++) {
			//レーザーの残り時間減少
			m_lasertime--;

			if (m_pBullet[i].GetSize().y > SCREEN_HEIGHT) //レーザーが十分な長さになったか
			{
				if (m_lasertime < 0) //レーザーの射出時間が終わったか
				{
					//レーザーを短くする
					m_pBullet[i].SetSize(D3DXVECTOR2(m_pBullet[i].GetSize().x, m_pBullet[i].GetSize().y - BULLET_SPEED * 2));
				}
				//レーザーのX座標をプレイヤーに合わせる
				m_pBullet[i].SetPos(D3DXVECTOR2(m_pPlayer->GetPos().x, m_pBullet[i].GetPos().y));
			}
			else
			{
				//レーザーを長くする
				m_pBullet[i].SetSize(D3DXVECTOR2(m_pBullet[i].GetSize().x, m_pBullet[i].GetSize().y - BULLET_SPEED * 2));
				//レーザーのX座標をエネミーに合わせる
				m_pBullet[i].SetPos(D3DXVECTOR2(m_pPlayer->GetPos().x, m_pBullet[i].GetPos().y - BULLET_SPEED));
			}

			//現在の弾の数を増やす
			m_bullet_num++;
		}
	}
}

void PlayerArm2::PlayerArmDraw()const
{
	for (int i = 0; i < m_bullet_num; i++) {
		m_pBullet[i].Draw();
	}
}