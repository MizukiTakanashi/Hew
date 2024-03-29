#include "icefield.h"

//==========================
// 定数の初期化
//==========================
//public
const float IceField::SIZE_X = 100.0f;
const float IceField::SIZE_Y = 100.0f;

//private
const float IceField::SPEED_X = 1.5f;
const float IceField::SPEED_Y = 2.5f;

//更新処理
void IceField::Update(void)
{
	m_invincible_flame--;
	GameObject::MovePos(D3DXVECTOR2(0.0f, SPEED_Y));
}