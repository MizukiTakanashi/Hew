//=======================================
// �������~�߂�G�֌W(cpp�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#include "enemy_stop.h"

//==========================
// �萔������
//==========================
//public
const float EnemyStop::SIZE_X = 60.0f;
const float EnemyStop::SIZE_Y = 60.0f;
const float EnemyStop::STOP_POS_Y = 100.0f;
const float EnemyStop::RANGE = 20.0f;
//private
const float EnemyStop::SPEED_X = 1.5f;
const float EnemyStop::SPEED_Y = 2.5f;

//======================
// �X�V����
//======================
void EnemyStop::Update(void)
{
	m_invincible_flame--;
	//�~�܂�ꏊ�܂ňړ�����
	if (GameObject::GetPos().y < STOP_POS_Y) {
		GameObject::MovePos(D3DXVECTOR2(0.0f, SPEED_Y));
	}

	//���E�ɓ���
	float rad = D3DXToRadian(m_move_width);
	SetPos(D3DXVECTOR2(m_init_posx + cosf(rad) * RANGE, GetPos().y));
	m_move_width += SPEED_X;

	//���Ԃ�������e�����
	if (m_bullet_count++ > BULLET_TIME) {
		m_bullet_make = true;
		m_bullet_count = 0;
	}
}
