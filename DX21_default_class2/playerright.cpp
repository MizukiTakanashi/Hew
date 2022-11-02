//=======================================
// ���@�̉E(�w�b�_)
// �쐬���F2022/10/25
// �쐬�ҁF�R�{����
//=======================================
#include "playerright.h"
#include "input.h"

//==========================
// �萔�̏�����
//==========================
const float PlayerRight::SHOT_SPEED = 0.1f;

void PlayerRight::Update(const D3DXVECTOR2& player_pos, const D3DXVECTOR2& enemy_pos)
{
	//R���������玩�����g�𔭎�
	if (GetKeyboardTrigger(DIK_R))
	{
		m_shot = true;
	}

	//�������g�𔭎�
	if (m_shot)
	{
		MovePos(D3DXVECTOR2(0.0f, -SHOT_SPEED));

		//��ʊO�ɏo����TYPE�����ɖ߂�
		if (GetScreenOut())
		{
			m_type = TYPE::TYPE_NONE;
		}
	}
	//���ˈȊO�̎��̓v���C���[�̉��ɂ��Ēe�𔭎˂���
	else
	{
		//�ړ�
		SetPos(player_pos + D3DXVECTOR2(30.0f, 0.0f));

		if (m_pEnemyItem != nullptr) {
			//�r�ɂ��Ă�A�C�e���̏���
			m_pEnemyItem->Update();
		}
	}

}

void PlayerRight::RightDraw(void)const
{
	//�r�ɂȂɂ����Ă���Ε`��
	if (m_type != TYPE::TYPE_NONE)
	{
		Draw();

		if (m_pEnemyItem != nullptr) {
			//�r�ɂ��Ă���A�C�e���̕`��
			m_pEnemyItem->PlayerArmDraw();
		}
	}
}

void PlayerRight::SetType(int type)
{
	//�^�C�v���Z�b�g
	 m_type = (TYPE)type; 

	 //�e�N�X�`�����^�C�v�ɍ��킹�ăZ�b�g
	 GameObject::SetAnimationNum((float)m_type - 1.0f);
}