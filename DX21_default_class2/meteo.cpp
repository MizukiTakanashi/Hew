#include "meteo.h"

//==========================
// �萔�̏�����
//==========================
//public
const float Meteo::SIZE_X = 200.0f;
const float Meteo::SIZE_Y = 240.0f;

//private
const float Meteo::SPEED_X = 1.5f;
const float Meteo::SPEED_Y = 2.5f;

//==========================
// �X�V����
//==========================
void Meteo::Update(void)
{
	m_invincible_flame--;
	GameObject::MovePos(D3DXVECTOR2(0.0f, SPEED_Y));
}
