#include "player_arm_change.h"
#include "inh_player_arm.h"
#include "inputx.h"
#include "keyboard.h"

void PlayerArmChange::Change()
{
	//キーボードのPボタンまたはパッドのBボタンをおす
	if (InputGetKeyDown(KK_P)|| IsButtonTriggered(0, XINPUT_GAMEPAD_B)) {
		//腕の中のポインタを変更
		inhPlayerArm* temp;
		temp = m_PlayerLeft->GetArmPointer();
		m_PlayerLeft->SetArmPointer(m_PlayerRight->GetArmPointer());
		m_PlayerRight->SetArmPointer(temp);

		//腕の中のタイプを変更
		inhPlayerArmBoth::TYPE temp1;
		temp1 = m_PlayerLeft->GetType();
		m_PlayerLeft->SetType(m_PlayerRight->GetType(), false);
		m_PlayerRight->SetType(temp1, false);
	}
}
