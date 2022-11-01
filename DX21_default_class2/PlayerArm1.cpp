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
void PlayerArm1::Update()
{
	//ボタンが押されたら
	if ((m_right && GetKeyboardPress(DIK_RIGHT)) || (!m_right && GetKeyboardPress(DIK_LEFT))) {
		//プレイヤーの後を追うようにして、弾を生成
		D3DXVECTOR2 movTemp = m_enemy_pos - GetPos();
		D3DXVECTOR2 rotposTemp = GetPos() - m_enemy_pos;
		D3DXVec2Normalize(&movTemp, &movTemp);
		movTemp *= BULLET_SPEED;

		float rotTemp = atan2(rotposTemp.y, rotposTemp.x) * (180 / M_PI) + 180.0f;

		//弾を作る
		Bullet temp(m_bulletdraw, GetPos(),
			D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), movTemp, rotTemp);

		m_pBullet[m_bullet_num] = temp;

		//現在の弾の数を増やす
		m_bullet_num++;
	}

	//今いる弾の処理
	for (int i = 0; i < m_bullet_num; i++) {
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
void PlayerArm1::PlayerArmDraw()
{
	for (int i = 0; i < m_bullet_num; i++) {
		m_pBullet[i].Draw();
	}
}
