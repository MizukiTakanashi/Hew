#include "player_arm_change.h"
#include "inh_player_arm.h"
#include "inputx.h"
#include "keyboard.h"

void PlayerArmChange::Change()
{
	//キーボードのPボタンまたはパッドのBボタンをおす
	if (InputGetKeyDown(KK_P)|| IsButtonTriggered(0, XINPUT_GAMEPAD_B)) {
		PlayerLeft::TYPE temp1;
		temp1 = m_PlayerLeft->GetType();
		m_PlayerLeft->SetType((int)m_PlayerRight->GetType(),true);
		m_PlayerRight->SetType((int)temp1,true);
		inhPlayerArm* temp;

		temp = m_PlayerLeft->GetArmPointer();
		m_PlayerLeft->SetArmPointer(m_PlayerRight->GetArmPointer());
		m_PlayerRight->SetArmPointer(temp);
	}
}
