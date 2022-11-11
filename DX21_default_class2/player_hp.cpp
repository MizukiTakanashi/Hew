//=======================================
// �v���C���[HP�֌W(cpp�t�@�C��)
// �쐬���F2022/09/17
// �쐬�ҁF��������
//=======================================
#include "player_hp.h"

//==========================
// �萔������
//==========================
const float PlayerHP::HP_MAX = 1.0f;
const float PlayerHP::SIZE_X = 200.0f;
const float PlayerHP::SIZE_Y = 25.0f;
const float PlayerHP::FLAME_SIZE_X = 205.0f;
const float PlayerHP::FLAME_SIZE_Y = 30.0f;
const float PlayerHP::POS_SPACE_X = 20.0f;
const float PlayerHP::POS_SPACE_Y = 20.0f;
const float PlayerHP::POS_X = (PlayerHP::SIZE_X / 2 + PlayerHP::POS_SPACE_X);
const float PlayerHP::POS_Y = (PlayerHP::SIZE_Y / 2 + PlayerHP::POS_SPACE_Y);
const int PlayerHP::INVINCIBLE__FRAME = 30;	//���G����


//==========================
// HP�����炷
//==========================
void PlayerHP::ReduceHP(float reduce_num, D3DXVECTOR2 ppos)
{
	//���G���ǂ���
	if (m_invincible > 0)
	{//���G
		return;
	}
	else
	{//���G����Ȃ�
		m_hp -= reduce_num;
		//�������Z�b�g
		m_pExplosionManagement->SetExplosion(ppos);
		//�R���{��r�؂ꂳ����
		m_pNumber->InitCombo();
		SetInvincibleFrame();
	}

	//������HP��0�ł����
	if (m_hp <= 0) {
		m_hp = 0;
		m_HP0 = true;
		return;
	}

	//HP�o�[�̃T�C�Y�A�ʒu�̕ύX
	float tempXsize = SIZE_X * (m_hp / HP_MAX);
	UI::SetSize(D3DXVECTOR2(tempXsize, SIZE_Y));
	UI::SetPos(D3DXVECTOR2(tempXsize / 2 + POS_SPACE_X, POS_Y));
}
//=====================================
//�񕜏���
//=====================================
void PlayerHP::HeelHP(float heel_num, D3DXVECTOR2 ppos)
{
	//�񕜏���
	m_hp += heel_num;
	//HP�o�[�̃T�C�Y�A�ʒu�̕ύX
	float tempXsize = SIZE_X * (m_hp / HP_MAX);
	UI::SetSize(D3DXVECTOR2(tempXsize, SIZE_Y));
	UI::SetPos(D3DXVECTOR2(tempXsize / 2 + POS_SPACE_X, POS_Y));
}

//==========================
// �X�V����
//==========================
void PlayerHP::Update(void)
{
	//���G���Ԍ���
	if (m_invincible > 0)
	{
		m_invincible--;
	}

}
//==========================
// �`�揈��
//==========================
void PlayerHP::DrawHP(void)const
{
	if (!m_HP0) {
		//HP�o�[��`��
		UI::Draw();
	}

	//�t���[����`��
	m_frame_DrawObject.Draw(D3DXVECTOR2(POS_X, POS_Y), D3DXVECTOR2(FLAME_SIZE_X, FLAME_SIZE_Y));
}