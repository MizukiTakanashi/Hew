//=======================================
// �~�T�C���̓G�֌W(cpp�t�@�C��)
// 
// �쐬�ҁF���c�m�s
//=======================================
#include "enemy_missile.h"

//==========================
// �萔������
//==========================
//public
const float EnemyMissile::SIZE_X = 50.0f;
const float EnemyMissile::SIZE_Y = 60.0f;
const float EnemyMissile::STOP_POS_Y = 100.0f;
const float EnemyMissile::RANGE = 20.0f;
//private
const float EnemyMissile::SPEED_X = 1.5f;
const float EnemyMissile::SPEED_Y = 2.5f;
const int EnemyMissile::HP_MAX = 2;

//======================
// �X�V����
//======================
void EnemyMissile::Update(void)
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
