#include "poisonfield.h"

//==========================
// �萔�̏�����
//==========================
//public
const float PoisonField::SIZE_X = 20.0f;
const float PoisonField::SIZE_Y = 240.0f;

//private
const float PoisonField::SPEED_X = 1.5f;
const float PoisonField::SPEED_Y = 2.5f;

//�X�V����
void PoisonField::Update(void)
{
	m_invincible_flame--;
	GameObject::MovePos(D3DXVECTOR2(0.0f, SPEED_Y));
}
