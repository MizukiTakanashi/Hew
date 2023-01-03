//=======================================
// ボスクラス(cppファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#include "boss.h"
//==========================
// 定数初期化
//==========================
//public
const float Boss::SIZE_X = 50.0f;
const float Boss::SIZE_Y = 60.0f;
const float Boss::STOP_POS_Y = 100.0f;
const float Boss::RANGE = 20.0f;
//private
const float Boss::SPEED_X = 1.5f;
const float Boss::SPEED_Y = 2.5f;
const float Boss::ALPHA_SPEED = 0.01f;
const float Boss::POS_X = SCREEN_WIDTH / 2;
const float Boss::POS_Y = -100;



//======================
// 更新処理
//======================
void Boss::Update(void)
{
	//無敵時間減少
	m_invincible_flame--;

	if (m_stop_time > 0)
	{
		m_stop_time--;
		return;
	}


	//止まる場所まで移動する
	if (GameObject::GetPos().y < STOP_POS_Y) {
		GameObject::MovePos(D3DXVECTOR2(0.0f, SPEED_Y));
	}

	//左右に動く
	float rad = D3DXToRadian(m_move_width);
	SetPos(D3DXVECTOR2(m_init_posx + cosf(rad) * RANGE, GetPos().y));
	m_move_width += SPEED_X;

	//時間が来たら弾を作る
	if (m_bullet_count++ > BULLET_TIME) {
		m_bullet_make = true;
		m_bullet_count = 0;
	}

	//出現してからのカウントを数える
	m_appearance_time++;

	//退出のフラグが立ったら
	if (m_alpha_flag) {
		//どんどんアルファ値を低くしていく
		m_alpha -= ALPHA_SPEED;
		if (m_alpha < 0.0f) {
			m_alpha = 0.0f;
		}
		GameObject::SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, m_alpha));
	}
