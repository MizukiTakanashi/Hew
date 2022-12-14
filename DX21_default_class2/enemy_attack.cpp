//=======================================
// �����̓G�֌W(cpp�t�@�C��)
// �쐬���F2022/12/02
// �쐬�ҁF����đ�
//=======================================
#include "enemy_attack.h"

//==========================
// �萔������
//==========================
//public
const float EnemyAttack::SIZE_X = 50.0f;
const float EnemyAttack::SIZE_Y = 60.0f;
const float EnemyAttack::STOP_POS_Y = 100.0f;
const float EnemyAttack::RANGE = 20.0f;
//private
const float EnemyAttack::SPEED_X = 1.5f;
const float EnemyAttack::SPEED_Y = 2.5f;

//======================
// �X�V����
//======================
void EnemyAttack::Update(void)
{
	GameObject::MovePos(m_mov); m_time++;
	//�~�܂�ꏊ�܂ňړ�����
	
	//���˂���ĂȂ��Ƃ�
	if (m_shot == false) {
		if (GameObject::GetPos().y < STOP_POS_Y) {
			GameObject::MovePos(D3DXVECTOR2(0.0f, SPEED_Y));
		}
		//���E�ɓ���
		float rad = D3DXToRadian(m_move_width);
		SetPos(D3DXVECTOR2(m_init_posx + cosf(rad) * RANGE, GetPos().y));
		m_move_width += SPEED_X;
		//���Ԃ�������ˌ�����
		if (m_attack_count++ == ATTACK_TIME) {
			m_shot = true;
		}
	}

	//�ˌ����n�߂���
	if (m_shot == true)
	{
		explosion_time++;
		if (explosion_time >= 300)
		{
			//�����t���O��true�ɂ���
			m_explosion = true;
			m_shot = false;
			m_bullet_make = true;
		}
	}
}