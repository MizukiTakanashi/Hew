//=======================================
// ���@�̐^��(�w�b�_)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#include "player_center.h"
#include "inputx.h"
#include "keyboard.h"

//==========================
// �萔�̏�����
//==========================
const D3DXVECTOR2 PlayerCenter::FROM_PLAYER_POS = D3DXVECTOR2(0.0f, 30.0f);

void PlayerCenter::ArmDraw(void) const
{
	//�r�ɂȂɂ����Ă���Ε`��
	if (m_type != TYPE::TYPE_NONE)
	{
		if (m_type != TYPE::TYPE_OLD) {
			//�r�ɂ��Ă���A�C�e�����g�̕`��
			//DrawReverse();
			//�c�e�����̓G�A�C�R���\��
			Draw(m_Remaining_Icon_Pos, ICON_SIZE);
		}

		if (m_pEnemyItem != nullptr) {
			//�r�ɂ��Ă���A�C�e���̒e���`��
			m_pEnemyItem->PlayerArmDraw();
			if (m_type != TYPE::TYPE_OLD)
			{
				m_pRemaining_Num->DrawNumber();
			}
		}

	}
}

//==========================
// �{�^������
//==========================
void PlayerCenter::ButtonPress(void)
{

}
