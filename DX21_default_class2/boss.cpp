//=======================================
// �{�X�N���X(cpp�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#include "boss.h"
//==========================
// �萔������
//==========================
//public
const float Boss::SIZE_X = 50.0f;
const float Boss::SIZE_Y = 60.0f;
const float Boss::STOP_POS_Y = 100.0f;
const float Boss::RANGE = 20.0f;
//private
const float Boss::SPEED_X = 1.5f;
const float Boss::SPEED_Y = 2.5f;
const float Boss::ALPHA_SPEED = 0.01f;
const float Boss::POS_X = SCREEN_WIDTH / 2;
const float Boss::POS_Y = -100;



//======================
// �X�V����
//======================
void Boss::Update(void)
{
	//���G���Ԍ���
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
