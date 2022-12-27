//=======================================
// ���ʂ̓G�֌W(cpp�t�@�C��)
// �쐬���F2022/09/13
// �쐬�ҁF��������
//=======================================
#include "enemy_grenade.h"

//==========================
// �萔������
//==========================
//public
const float EnemyGrenade::SIZE_X = 50.0f;
const float EnemyGrenade::SIZE_Y = 60.0f;
const float EnemyGrenade::STOP_POS_Y = 100.0f;
const float EnemyGrenade::RANGE = 20.0f;
//private
const float EnemyGrenade::SPEED_X = 1.5f;
const float EnemyGrenade::SPEED_Y = 2.5f;
const float EnemyGrenade::ALPHA_SPEED = 0.01f;

//======================
// �X�V����
//======================
void EnemyGrenade::Update(void)
{
	//���G���Ԍ���
	m_invincible_flame--;

	//�~�܂�ꏊ�܂ňړ�����
	if (GameObject::GetPos().y < STOP_POS_Y) {
		GameObject::MovePos(D3DXVECTOR2(0.0f, SPEED_Y));
	}

	//���E�ɓ���
	/*float rad = D3DXToRadian(m_move_width);
	SetPos(D3DXVECTOR2(m_init_posx + cosf(rad) * RANGE, GetPos().y));
	m_move_width += SPEED_X;*/

	//���Ԃ�������e�����
	if (m_bullet_count++ > BULLET_TIME) {
		m_bullet_make = true;
		m_bullet_count = 0;
	}

	//�o�����Ă���̃J�E���g�𐔂���
	m_appearance_time++;

	//�ޏo�̃t���O����������
	if (m_alpha_flag) {
		//�ǂ�ǂ�A���t�@�l��Ⴍ���Ă���
		m_alpha -= ALPHA_SPEED;
		if (m_alpha < 0.0f) {
			m_alpha = 0.0f;
		}
		GameObject::SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, m_alpha));
	}
}
