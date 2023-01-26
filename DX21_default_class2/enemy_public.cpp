#include "enemy_public.h"
//public
const float EnemyPublic::SIZE_X = 50.0f;
const float EnemyPublic::SIZE_Y = 60.0f;

//private
const float EnemyPublic::SPEED_X = 1.5f;
const float EnemyPublic::SPEED_Y = 2.5f;

void EnemyPublic::Update(void)
{
	m_invincible_flame--;

	if (m_stop_time > 0)
	{
		m_stop_time--;
		return;
	}

	GameObject::MovePos(D3DXVECTOR2(0.0f, SPEED_Y));

	//出現してからのカウントを数える
	m_appearance_time++;
}