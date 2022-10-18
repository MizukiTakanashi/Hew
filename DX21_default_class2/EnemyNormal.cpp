//=======================================
// ���ʂ̓G�֌W(cpp�t�@�C��)
// �쐬���F2022/09/13
// �쐬�ҁF��������
//=======================================
#include "EnemyNormal.h"

//==========================
// �萔������
//==========================
const float EnemyNormal::SIZE_X = 50.0f;
const float EnemyNormal::SIZE_Y = 50.0f;
const float EnemyNormal::STOP_POS_X = 800.0f;

const float EnemyNormal::SPEED = 1.5f;

//======================
// �X�V����
//======================
void EnemyNormal::Update(void)
{
	//�~�܂�ꏊ�܂ňړ�����
	if (GameObject::GetPos().x > STOP_POS_X) {
		GameObject::MovePos(D3DXVECTOR2(-SPEED, 0.0f));
	}

	//���Ԃ�������e�����
	if (m_bullet_count++ > BULLET_TIME) {
		m_bullet_make = true;
		m_bullet_count = 0;
	}
}
