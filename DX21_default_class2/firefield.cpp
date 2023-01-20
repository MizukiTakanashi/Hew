#include "firefield.h"
//==========================
// 定数の初期化
//==========================
//public
const float FireField::SIZE_X = 100.0f;
const float FireField::SIZE_Y = 100.0f;

//private
const float FireField::SPEED_X = 1.5f;
const float FireField::SPEED_Y = 2.5f;

//更新処理
void FireField::Update(void)
{
	m_invincible_flame--;
	GameObject::MovePos(D3DXVECTOR2(0.0f, SPEED_Y));
}
