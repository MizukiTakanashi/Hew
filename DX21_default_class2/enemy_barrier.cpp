//=======================================
// �o���A�̓G�֌W(cpp�t�@�C��)
// �쐬���F2022/12/08
// �쐬�ҁF��������
//=======================================
#include "enemy_barrier.h"

//==========================
// �萔������
//==========================
//public
const float EnemyBarrier::SIZE_X = 50.0f;
const float EnemyBarrier::SIZE_Y = 60.0f;
const float EnemyBarrier::STOP_POS_Y = 100.0f;
const float EnemyBarrier::RANGE = 20.0f;
//private
const float EnemyBarrier::SPEED_X = 1.5f;
const float EnemyBarrier::SPEED_Y = 2.5f;
const D3DXVECTOR2 EnemyBarrier::BARRIER_SIZE = D3DXVECTOR2(50.0f, 50.0f);
const D3DXVECTOR2 EnemyBarrier::INTERVAL_POS = D3DXVECTOR2(0.0f, 10.0f);

//======================
// �X�V����
//======================
void EnemyBarrier::Update(void)
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

	//============================
	// �o���A

	//�o���A���o�����Ă�����...
	if (m_barrier_time >= 0) {
		//�o���A�̍��W��G�ׂ̗ɃZ�b�g
		m_pBarrier->SetPos(GameObject::GetPos() + INTERVAL_POS);

		//�o���A�̎��Ԃ��������Ԃ��߂��Ă�����...
		if (m_barrier_time++ > BARRIER_TIME_LIMIT) {
			//�o���A������
			m_barrier_time = -1;
			m_barrier_interval_time = 0;
		}
	}
	//�o���A���o�����Ă��Ȃ�������...
	else {
		//���̃o���A�̏o�����Ԃ��������Ԃ��߂��Ă�����...
		if (m_barrier_interval_time++ > BARRIER_INTERVAL) {
			//�o���A���o��
			m_barrier_interval_time = -1;
			m_barrier_time = 0;
		}
	}
}
