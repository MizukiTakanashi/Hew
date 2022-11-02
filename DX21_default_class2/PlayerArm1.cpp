//=======================================
// プレイヤーの腕1関係(cppファイル)
// 作成日：2022/10/30
// 作成者：高梨水希
//=======================================
#include "PlayerArm1.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "input.h"

//==========================
// 定数の初期化
//==========================
const float PlayerArm1::BULLET_SIZE_X = 40.0f;
const float PlayerArm1::BULLET_SIZE_Y = 40.0f;
const float PlayerArm1::BULLET_SPEED = 2.5f;

//==========================
// 更新処理
//==========================
void PlayerArm1::Update(const D3DXVECTOR2& arm_pos)
{
	//発射間隔カウント
	m_interval_count++;

	//ボタンが押されたら
	if ((inhPlayerArm::GetRightLeft() && GetKeyboardPress(DIK_RIGHT)) || 
		(!inhPlayerArm::GetRightLeft() && GetKeyboardPress(DIK_LEFT))) {
		//発射間隔が一定以上になったら
		if (m_interval_count > BULLET_INTERVAL) {
			//カウントをリセット
			m_interval_count = 0;

			//プレイヤーの後を追うようにして、弾を生成
			D3DXVECTOR2 movTemp = m_enemy_pos - arm_pos;
			D3DXVECTOR2 rotposTemp = arm_pos - m_enemy_pos;
			D3DXVec2Normalize(&movTemp, &movTemp);
			movTemp *= BULLET_SPEED;

			float rotTemp = atan2(rotposTemp.y, rotposTemp.x) * (180 / M_PI) + 180.0f;

			//弾を作る
			Bullet temp(m_bulletdraw, arm_pos,
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), movTemp, rotTemp);

			m_pBullet[inhPlayerArm::GetBulletNum()] = temp;

			//現在の弾の数を増やす
			inhPlayerArm::IncreaseBulletNum();

			//作った弾の数を増やす
			inhPlayerArm::IncreaseBulletMaked();
		}
	}

	//今いる弾の処理
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		//プレイヤーの後を追う(ホーミング弾)
		D3DXVECTOR2 movTemp = m_enemy_pos - m_pBullet[i].GetPos();
		D3DXVECTOR2 rotposTemp = m_pBullet[i].GetPos() - m_enemy_pos;
		D3DXVec2Normalize(&movTemp, &movTemp);
		movTemp *= BULLET_SPEED;

		float rotTemp = atan2(rotposTemp.y, rotposTemp.x) * (180 / M_PI) + 180.0f;

		m_pBullet[i].SetRot(rotTemp);
		m_pBullet[i].SetMove(movTemp);

		//弾の更新処理
		m_pBullet[i].Update();

		//画面外から出たら、時間経過したら...
		if (m_pBullet[i].GetScreenOut() || m_pBullet[i].GetTime() > BULLET_BREAK_TIME) {
			DeleteBullet(i);
		}
	}
}

//==========================
// 描画処理
//==========================
void PlayerArm1::PlayerArmDraw()const
{
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		m_pBullet[i].Draw();
	}
}

//==========================
// 指定した番号の弾を消す
//==========================
void PlayerArm1::DeleteBullet(int index_num)
{
	//弾を消す
	for (int i = index_num; i < inhPlayerArm::GetBulletNum() - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	inhPlayerArm::IncreaseBulletNum(-1);
 }