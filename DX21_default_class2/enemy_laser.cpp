//=======================================
// ���[�U�[�̓G�֌W(cpp�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#include "enemy_laser.h"

//==========================
// �萔������
//==========================
//public
const float EnemyLaser::SIZE_X = 50.0f;
const float EnemyLaser::SIZE_Y = 60.0f;
const float EnemyLaser::STOP_POS_Y = 100.0f;
const float EnemyLaser::RANGE = 240.0f;
//private
const float EnemyLaser::SPEED_X = 0.5f;
const float EnemyLaser::SPEED_Y = 2.5f;
const int EnemyLaser::HP_MAX = 3;

//======================
// �X�V����
//======================
void EnemyLaser::Update(void)
{
	//�~�܂�ꏊ�܂ňړ�����
	if (GameObject::GetPos().y < STOP_POS_Y) {
		GameObject::MovePos(D3DXVECTOR2(0.0f, SPEED_Y));
	}

	//���E�ɓ���
	float rad = D3DXToRadian(m_move_width);
	SetPos(D3DXVECTOR2(m_init_posx + cosf(rad) * RANGE, GetPos().y));
	m_move_width += SPEED_X;

	//���Ԃ������烌�[�U�[�����
	if (m_laser_count++ > LASER_BETWEEN) {
		m_laser_make = true;
		m_laser_count = 0;
	}

	//��ʊO�ɏo�Ȃ��悤�ɂ���
	GameObject::SetPos(ScreenOut::GetScreenIn(GameObject::GetPos(), GameObject::GetSize()));
}