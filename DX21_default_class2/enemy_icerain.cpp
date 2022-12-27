//=======================================
// �X�̓G�֌W(cpp�t�@�C��)
// �쐬���F2022/12/19
// �쐬�ҁF����đ�
//=======================================
#include "enemy_icerain.h"

//==========================
// �萔������
//==========================
//public
const float EnemyIceRain::SIZE_X = 60.0f;
const float EnemyIceRain::SIZE_Y = 60.0f;
const float EnemyIceRain::STOP_POS_Y = 100.0f;
const float EnemyIceRain::RANGE = 20.0f;
//private
const float EnemyIceRain::SPEED_X = 1.5f;
const float EnemyIceRain::SPEED_Y = 2.5f;

int m_count = 0;
int m_count1 = 0;
int m_count2 = 0;
int m_count3 = 0;
int m_count4 = 0;
//======================
// �X�V����
//======================
void EnemyIceRain::Update(void)
{
	m_invincible_flame--;

	if (m_stop_time > 0)
	{
		m_stop_time--;
		return;
	}

	//�~�܂�ꏊ�܂ňړ�����
	if (GameObject::GetPos().y < STOP_POS_Y) {
		GameObject::MovePos(D3DXVECTOR2(0.0f, SPEED_Y));
	}

	//���E�ɓ���
	float rad = D3DXToRadian(m_move_width);
	SetPos(D3DXVECTOR2(m_init_posx + cosf(rad) * RANGE, GetPos().y));
	m_move_width += SPEED_X;

	m_count++;
	m_count1++;
	m_count2++;
	m_count3++;
	m_count4++;

	//���Ԃ�������e�����
	if (m_count > BULLET_TIME) {
		m_bullet_make = true;
		m_count = 0;
	}
	if (m_count1 > BULLET_TIME+1) {
		m_bullet_make1 = true;
		m_count1 = 0;
	}
	if (m_count2 > BULLET_TIME+2) {
		m_bullet_make2 = true;
		m_count2 = 0;
	}
	if (m_count3 > BULLET_TIME+3) {
		m_bullet_make3 = true;
		m_count3 = 0;
	}
	if (m_count4 > BULLET_TIME+4) {
		m_bullet_make4 = true;
		m_count4 = 0;
	}
}
