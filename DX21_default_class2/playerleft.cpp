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
const float PlayerLeft::SHOT_SPEED = 0.1f;

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
		
		// ��ʊO�ɏo����TYPE�����ɖ߂�
		if (GetScreenOut())
		{
			m_type = TYPE::TYPE_NONE;
		}
	}
	//���ˈȊO�̎��̓v���C���[�̉��ɂ��Ēe�𔭎˂���
	else
	{
		// �ړ�
		SetPos(player_pos - D3DXVECTOR2(30.0f, 0.0f));

		if (m_pEnemyItem != nullptr) {
			//�r�ɂ��Ă�A�C�e���̏���
			m_pEnemyItem->Update();
		}
	}
}

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
