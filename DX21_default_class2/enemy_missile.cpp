//=======================================
// ミサイルの敵関係(cppファイル)
// 
// 作成者：恩田洋行
//=======================================
#include "enemy_missile.h"

//==========================
// 定数初期化
//==========================
//public
const float EnemyMissile::SIZE_X = 50.0f;
const float EnemyMissile::SIZE_Y = 60.0f;
const float EnemyMissile::STOP_POS_Y = 100.0f;
const float EnemyMissile::RANGE = 20.0f;
//private
const float EnemyMissile::SPEED_X = 1.5f;
const float EnemyMissile::SPEED_Y = 2.5f;
const int EnemyMissile::HP_MAX = 2;

//======================
// 更新処理
//======================
void EnemyMissile::Update(void)
{
	m_invincible_flame--;
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
