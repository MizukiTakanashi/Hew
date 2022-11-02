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
const float PlayerRight::SHOT_SPEED = 5.0f;
const D3DXVECTOR2 PlayerRight::FROM_PLAYER_POS = D3DXVECTOR2(30.0f, 0.0f);

//==========================
// �X�V����
//==========================
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

		//��ʊO�ɏo����...
		if (GetScreenOut())
		{
			//TYPE�����ɖ߂�
			m_type = TYPE::TYPE_NONE;
			
			//�ʒu�����ɖ߂�
			SetPos(player_pos + FROM_PLAYER_POS);

			//���˂̃t���O���I�t
			m_shot = false;
		}
	}
	//���ˈȊO�̎��̓v���C���[�̉��ɂ��Ēe�𔭎˂���
	else
	{
		//�ړ�
		SetPos(player_pos + FROM_PLAYER_POS);

		if (m_pEnemyItem != nullptr) {
			//�r�ɂ��Ă�A�C�e���̏���
			m_pEnemyItem->Update(GameObject::GetPos());
		}
	}
}

//==========================
// �`�揈��
//==========================
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
	//���˒��ł���΃Z�b�g���Ȃ�
	if (m_shot) {
		return;
	}

	//�^�C�v���Z�b�g
	 m_type = (TYPE)type; 

	 //�e�N�X�`�����^�C�v�ɍ��킹�ăZ�b�g
	 GameObject::SetAnimationNum((float)m_type - 1.0f);
}