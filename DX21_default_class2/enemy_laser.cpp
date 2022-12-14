//=======================================
// レーザーの敵関係(cppファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#include "enemy_laser.h"

//==========================
// 定数初期化
//==========================
//public
const float EnemyLaser::SIZE_X = 50.0f;
const float EnemyLaser::SIZE_Y = 60.0f;
const float EnemyLaser::STOP_POS_Y = 100.0f;
const float EnemyLaser::RANGE = 240.0f;
//private
const float EnemyLaser::SPEED_X = 0.5f;
const float EnemyLaser::SPEED_Y = 2.5f;

//======================
// 更新処理
//======================
void EnemyLaser::Update(void)
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

	//時間が来たらレーザーを作る
	if (m_bullet_count++ > LASER_BETWEEN) {
		m_bullet_make = true;
		m_bullet_count = 0;
	}

	//画面外に出ないようにする
	GameObject::SetPos(ScreenOut::GetScreenIn(GameObject::GetPos(), GameObject::GetSize()));
}