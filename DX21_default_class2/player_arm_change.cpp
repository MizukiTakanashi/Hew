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
		temp = m_PlayerRight->GetArmPointer();
		m_PlayerRight->SetArmPointer(m_PlayerLeft->GetArmPointer());
		m_PlayerLeft->SetArmPointer(m_PlayerCenter->GetArmPointer());
		m_PlayerCenter->SetArmPointer(temp);

		//腕の中のタイプを変更
		inhPlayerArmBoth::TYPE temp1;
		temp1 = m_PlayerRight->GetType();
		m_PlayerRight->SetType(m_PlayerLeft->GetType(), false);
		m_PlayerLeft->SetType(m_PlayerCenter->GetType(), false);
		m_PlayerCenter->SetType(temp1, false);
	}
}
