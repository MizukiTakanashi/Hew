//=======================================
// プレイヤーの腕1関係(cppファイル)
// 作成日：2022/10/30
// 作成者：高梨水希
//=======================================
#include "player_arm3.h"
#define _USE_MATH_DEFINES
#include <math.h>

//==========================
// 定数の初期化
//==========================
const float PlayerArm3::BULLET_SIZE_X = 40.0f;
const float PlayerArm3::BULLET_SIZE_Y = 40.0f;
const float PlayerArm3::BULLET_SPEED = 2.5f;

//==========================
// 更新処理
//==========================
void PlayerArm3::Update()
{
	//発射できる時間になったら...
	if (++m_bullet_interval_count > BULLET_INTERVAL) {
		
		//弾を作る
		Bullet temp(m_bulletdraw, GetPos(),
			D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0.0f,-BULLET_SPEED),0.0f );

		m_pBullet[m_bullet_num] = temp;

		//現在の弾の数を増やす
		m_bullet_num++;
	}

	//今いる弾の処理
	for (int i = 0; i < m_bullet_num; i++) {
		

		//弾の更新処理
		m_pBullet[i].Update();

		//画面外から出たら、時間経過したら...
		if (m_pBullet[i].GetScreenOut()){
			//弾を消す
			for (int j = i; j < m_bullet_num; j++) {
				m_pBullet[j] = m_pBullet[j + 1];
			}
			m_bullet_num--;
		}
	}
}

//==========================
// 描画処理
//==========================
void PlayerArm3::PlayerArmDraw()
{
	for (int i = 0; i < m_bullet_num; i++) {
		m_pBullet[i].Draw();
	}
}
