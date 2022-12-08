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
}
