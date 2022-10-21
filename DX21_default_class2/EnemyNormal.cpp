//=======================================
// •’Ê‚Ì“GŠÖŒW(cppƒtƒ@ƒCƒ‹)
// ì¬“úF2022/09/13
// ì¬ŽÒF‚—œ…Šó
//=======================================
#include "EnemyNormal.h"

//==========================
// ’è”‰Šú‰»
//==========================
const float EnemyNormal::SIZE_X = 50.0f;
const float EnemyNormal::SIZE_Y = 50.0f;
const float EnemyNormal::STOP_POS_Y = 100.0f;

const float EnemyNormal::SPEED = 1.5f;

//======================
// XVˆ—
//======================
void EnemyNormal::Update(void)
{
	//Ž~‚Ü‚éêŠ‚Ü‚ÅˆÚ“®‚·‚é
	if (GameObject::GetPos().y > STOP_POS_Y) {
		GameObject::MovePos(D3DXVECTOR2(0.0f, SPEED));
	}

	//ŽžŠÔ‚ª—ˆ‚½‚ç’e‚ðì‚é
	if (m_bullet_count++ > BULLET_TIME) {
		m_bullet_make = true;
		m_bullet_count = 0;
	}
}
