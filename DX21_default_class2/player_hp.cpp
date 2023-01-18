//=======================================
// �v���C���[HP�֌W(cpp�t�@�C��)
// �쐬���F2022/09/17
// �쐬�ҁF��������
//=======================================
#include "player_hp.h"
#include "game.h"
#include "sound.h"
#include "inh_stage.h"


//==========================
// �萔������
//==========================
const float PlayerHP::HP_MAX = 3.0f;
const D3DXVECTOR2 PlayerHP::SIZE = D3DXVECTOR2(60.0f, 60.0f);
const float PlayerHP::POS_X = 1040.0f;
const float PlayerHP::POS_Y = 625.0f;
const float PlayerHP::BET_X = 80.0f;

//==========================
// �����t���R���X�g���N�^
//==========================
PlayerHP::PlayerHP(DrawObject& DrawObject1, ExplosionManagement* pEM, Player* pPlayer, InhStage* pStage)
	:UI(DrawObject1, D3DXVECTOR2(POS_X, POS_Y), SIZE), 
	m_pExplosionManagement(pEM), m_pPlayer(pPlayer), m_pStage(pStage)
{
	//�v���C���[�_���[�W��
	m_SE_04 = LoadSound((char*)"data\\SE\\1_04_2.wav");
	//SetVolume(g_SE, 0.1f);
}

//==========================
// HP�����炷
//==========================
void PlayerHP::ReduceHP(float reduce_num)
{
	//���G���ǂ���
	if (m_invincible > 0)
	{//���G
		return;
	}
	else
	{//���G����Ȃ�
		m_hp -= reduce_num;

		//�q�b�g�X�g�b�v
		m_pStage->HitStop(30);
		SetInvincibleFrame();

		PlaySound(m_SE_04, 0);
	}

	//������HP��0�ł����
	if (m_hp <= 0) {
		m_hp = 0;
		m_HP0 = true;
		return;
	}
}
//=====================================
// �񕜏���
//=====================================
void PlayerHP::HeelHP(float heel_num)
{
	//�񕜏���
	m_hp += heel_num;
}

//==========================
// �X�V����
//==========================
void PlayerHP::Update(void)
{
	if (m_hp < HP_MAX)
	{//HP�����Ȃ��Ȃ�����
		//�v���C���[�̌����ڕύX
		m_pPlayer->SetAnimationNum(2);
	}

	//���G���Ԍ���
	if (m_invincible > 0)
	{
		m_invincible--;
	}

}

//==========================
// �`�揈��
//==========================
void PlayerHP::DrawHP(void)
{
	//���g����
	for (int i = 0; i < (int)m_hp; i++)
	{
		UI::SetAnimationNum(0.0f);
		UI::Draw(D3DXVECTOR2(POS_X  + i * BET_X, POS_Y), SIZE);
	}

	//���g�Ȃ�
	for (int i = (int)m_hp; i < (int)HP_MAX; i++) {
		UI::SetAnimationNum(1.0f);
		UI::Draw(D3DXVECTOR2(POS_X + i * BET_X, POS_Y), SIZE);
	}
}