//=======================================
// ���@�̍�(�w�b�_)
// �쐬���F2022/10/25
// �쐬�ҁF���� �@
//=======================================
#include "playerleft.h"
#include "input.h"

const float PlayerLeft::SHOT_SPEED = 0.1f;

void PlayerLeft::Update(D3DXVECTOR2 pos) 
{
	//  R�L�[�������Ƙr�ɑ������Ă���G�𔭎˂���
	if (GetKeyboardTrigger(DIK_E))	
	{
		m_shot = true;	// ���˂���
	}

	// ���˂���
	if (m_shot)
	{
		MovePos(D3DXVECTOR2(0.0f, -SHOT_SPEED));	// �����ۂɕK�v
		
		// ��ʊO�ɏo����TYPE�����ɖ߂�
		if (GetScreenOut())
		{
			m_type = TYPE::TYPE_NONE;
		}
	}
	else
	{
		// �ړ�
		SetPos(pos - D3DXVECTOR2(30.0f, 0.0f));
	}
}

void PlayerLeft::LeftDraw(void)
{
	if (m_type != TYPE::TYPE_NONE)
	{
		Draw();
	}
}
