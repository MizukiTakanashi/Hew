//=======================================
// プレイヤーの腕1関係(cppファイル)
// 作成日：2022/10/30
// 作成者：高梨水希
//=======================================
#include "PlayerArm3.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "input.h"

//==========================
// 定数の初期化
//==========================
const float PlayerArm3::BULLET_SIZE_X = 40.0f;
const float PlayerArm3::BULLET_SIZE_Y = 40.0f;
const float PlayerArm3::BULLET_SPEED = 2.5f;

//==========================
// 更新処理
//==========================
void PlayerArm3::Update(const D3DXVECTOR2& arm_pos)
{
	//ボタンが押されたら
	if ((inhPlayerArm::GetRightLeft() && GetKeyboardPress(DIK_RIGHT)) || 
		(!inhPlayerArm::GetRightLeft() && GetKeyboardPress(DIK_LEFT))) {
		//発射できる時間になったら...
		if (++m_bullet_interval_count > BULLET_INTERVAL) {
			m_bullet_interval_count = 0;

			//弾を作る
			Bullet temp(m_bulletdraw, GetPos(),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0.0f, -BULLET_SPEED), 0.0f);

			m_pBullet[inhPlayerArm::GetBulletNum()] = temp;

			//現在の弾の数を増やす
			inhPlayerArm::IncreaseBulletNum();

			//作った弾の数を増やす
			inhPlayerArm::IncreaseBulletMaked();
		}
	}

	//今いる弾の処理
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		//弾の更新処理
		m_pBullet[i].Update();

		//画面外から出たら...
		if (m_pBullet[i].GetScreenOut()){
			DeleteBullet(i);
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