//=======================================
// ���@�̍�(�w�b�_)
// �쐬���F2022/10/25
// �쐬�ҁF���� �@
//=======================================
#include "playerleft.h"
#include "input.h"

//==========================
// �萔�̏�����
//==========================
const float PlayerLeft::SHOT_SPEED = 5.0f;
const D3DXVECTOR2 PlayerLeft::FROM_PLAYER_POS = D3DXVECTOR2(-30.0f, 0.0f);

//==========================
// �X�V����
//==========================
void PlayerLeft::Update(const D3DXVECTOR2& player_pos, const D3DXVECTOR2& enemy_pos)
{
	//  R�L�[�������Ƙr�ɑ������Ă���G�𔭎˂���
	if (GetKeyboardTrigger(DIK_E))	
	{
		m_shot = true;	// ���˂���
	}

	// �������g�𔭎˂���
	if (m_shot)
	{
		MovePos(D3DXVECTOR2(0.0f, -SHOT_SPEED));	// �����ۂɕK�v
		
		// ��ʊO�ɏo����...
		if (GetScreenOut())
		{
			//TYPE�����ɖ߂�
			m_type = TYPE::TYPE_NONE;
			
			//�ʒu�����ɖ߂�
			SetPos(player_pos);
			
			//���˂̃t���O���I�t
			m_shot = false;
		}
	}
	//���ˈȊO�̎��̓v���C���[�̉��ɂ��Ēe�𔭎˂���
	else
	{
		// �ړ�
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
void PlayerLeft::LeftDraw(void)const
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

void PlayerLeft::SetType(int type)
{
	//�^�C�v���Z�b�g
	m_type = (TYPE)type;

	//�e�N�X�`�����^�C�v�ɍ��킹�ăZ�b�g
	GameObject::SetAnimationNum((float)m_type - 1.0f);
}