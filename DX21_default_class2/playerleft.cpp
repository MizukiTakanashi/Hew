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
	//  R�L�[�������Ƙr�ɑ������Ă���G�̒e�𔭎˂���
	if (GetKeyboardTrigger(DIK_E))	// �e�𔭎˂�����
	{
		m_shot = true;	// �e�����˂���
	}
	// ���˂���
	if (m_shot)
	{
		MovePos(D3DXVECTOR2(0.0f, -SHOT_SPEED));	// �����ۂɕK�v

		if (GetScreenOut());
	}
	else
	{
		// �ړ�
		SetPos(pos - D3DXVECTOR2(30.0f, 0.0f));
	}
}
