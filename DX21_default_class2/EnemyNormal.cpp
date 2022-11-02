//=======================================
// ���ʂ̓G�֌W(cpp�t�@�C��)
// �쐬���F2022/09/13
// �쐬�ҁF��������
//=======================================
#include "EnemyNormal.h"

//==========================
// �萔������
//==========================
//public
const float EnemyNormal::SIZE_X = 50.0f;
const float EnemyNormal::SIZE_Y = 60.0f;
const float EnemyNormal::STOP_POS_Y = 100.0f;
const float EnemyNormal::RANGE = 20.0f;
//private
const float EnemyNormal::SPEED_X = 1.5f;
const float EnemyNormal::SPEED_Y = 2.5f;

//======================
// �X�V����
//======================
void EnemyNormal::Update(void)
{
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
