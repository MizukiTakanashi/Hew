//=======================================
// ���@�̉E(�w�b�_)
// �쐬���F2022/10/25
// �쐬�ҁF�R�{����
//=======================================
#include "player_right.h"

//#include "input.h"
#include "inputx.h"
#include "keyboard.h"

//==========================
// �萔�̏�����
//==========================
const D3DXVECTOR2 PlayerRight::FROM_PLAYER_POS = D3DXVECTOR2(30.0f, 0.0f);

//==========================
// �{�^������
//==========================
void PlayerRight::ButtonPress(void)
{
	//�؂藣���{�^��
	inhPlayerArmBoth::SetSeparationButton(InputGetKeyDown(KK_R) || IsButtonTriggered(0, XINPUT_GAMEPAD_RIGHT_SHOULDER));

	//�e���˃{�^��(�����Ă����)
	inhPlayerArmBoth::SetBulletShotButton((InputGetKey(KK_SPACE) || IsButtonPressed(0, XINPUT_GAMEPAD_A)) ||
		GetRightTrigger(0) > TRIGGER);

	//�e���˃{�^��(��������)
	inhPlayerArmBoth::SetBulletShotButtonTrigger((InputGetKey(KK_SPACE) || IsButtonPressed(0, XINPUT_GAMEPAD_A)) ||
		GetRightTriggerTriggered(0, TRIGGER));
}
