//=======================================
// ���@�̉E(�w�b�_)
// �쐬���F2022/10/25
// �쐬�ҁF�R�{����
//=======================================
#include "playerright.h"
#include "input.h"

const float PlayerRight::SHOT_SPEED = 0.1f;

void PlayerRight::Update(D3DXVECTOR2 pos)
{ 
	 

	//R���������甭��
	if (GetKeyboardTrigger(DIK_R)) 
	{
		m_shot = true;
	}

	//����
	if (m_shot)
	{
		MovePos(D3DXVECTOR2(0.0f, -SHOT_SPEED));

		if (GetScreenOut());
	}
	else
	{
		//�ړ�
		SetPos(pos + D3DXVECTOR2(30.0f, 0.0f));
	}

}