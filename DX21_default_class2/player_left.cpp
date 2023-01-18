//=======================================
// ���@�̍�(�w�b�_)
// �쐬���F2022/10/25
// �쐬�ҁF���� �@
//=======================================
#include "player_left.h"

//#include "input.h"
#include "inputx.h"
#include "keyboard.h"

//==========================
// �萔�̏�����
//==========================
const D3DXVECTOR2 PlayerLeft::FROM_PLAYER_POS = D3DXVECTOR2(-30.0f, 0.0f);

void PlayerLeft::ArmDraw(void) const
{
	//�r�ɂȂɂ����Ă���Ε`��
	if (m_type != TYPE::TYPE_NONE)
	{
		if (m_type != TYPE::TYPE_OLD) {
			//�r�ɂ��Ă���A�C�e�����g�̕`��
			DrawReverse();
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
void PlayerLeft::ButtonPress(void)
{
	//�؂藣���{�^��
	inhPlayerArmBoth::SetSeparationButton(InputGetKeyDown(KK_E) || IsButtonTriggered(0, XINPUT_GAMEPAD_LEFT_SHOULDER));

	//�e���˃{�^��(�����Ă����)
	inhPlayerArmBoth::SetBulletShotButton((InputGetKey(KK_SPACE) || IsButtonPressed(0, XINPUT_GAMEPAD_A)) ||
		GetRightTrigger(0) > TRIGGER);

	//�e���˃{�^��(��������)
	inhPlayerArmBoth::SetBulletShotButtonTrigger((InputGetKeyDown(KK_SPACE) || IsButtonTriggered(0, XINPUT_GAMEPAD_A)) ||
		GetRightTriggerTriggered(0, TRIGGER));
}
