//=======================================
// 普通の敵関係(cppファイル)
// 作成日：2022/09/13
// 作成者：高梨水希
//=======================================
#include "enemy_gatoring.h"

//==========================
// 定数初期化
//==========================
//public
const float EnemyGatoring::SIZE_X = 60.0f;
const float EnemyGatoring::SIZE_Y = 60.0f;
const float EnemyGatoring::STOP_POS_Y = 100.0f;
const float EnemyGatoring::RANGE = 20.0f;
//private
const float EnemyGatoring::SPEED_X = 1.5f;
const float EnemyGatoring::SPEED_Y = 2.5f;
const int EnemyGatoring::HP_MAX = 1;

//======================
// 更新処理
//======================
void EnemyGatoring::Update(void)
{
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
}
