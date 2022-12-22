//=======================================
// �v���C���[�̘r�ύX�֌W(cpp�t�@�C��)
// �쐬���F2022/?/?
// �쐬�ҁF?
//=======================================
#include "player_arm_change.h"
#include "inh_player_arm.h"
#include "inputx.h"
#include "keyboard.h"

void PlayerArmChange::Change()
{
	//�L�[�{�[�h��P�{�^���܂��̓p�b�h��B�{�^��������
	if (InputGetKeyDown(KK_P)|| IsButtonTriggered(0, XINPUT_GAMEPAD_B)) {
		//�r�̒��̈ʒu��ύX
		if (m_PlayerRight->GetArmPointer() != nullptr) {
			m_PlayerRight->GetArmPointer()->SetCenter(true);
		}
		if (m_PlayerLeft->GetArmPointer() != nullptr) {
			m_PlayerLeft->GetArmPointer()->SetRightLeft(true);
		}
		if (m_PlayerCenter->GetArmPointer() != nullptr) {
			m_PlayerCenter->GetArmPointer()->SetCenter(false);
			m_PlayerCenter->GetArmPointer()->SetRightLeft(false);
		}

		//�r�̒��̃|�C���^��ύX
		inhPlayerArm* temp;
		temp = m_PlayerRight->GetArmPointer();
		m_PlayerRight->SetArmPointer(m_PlayerLeft->GetArmPointer());
		m_PlayerLeft->SetArmPointer(m_PlayerCenter->GetArmPointer());
		m_PlayerCenter->SetArmPointer(temp);

		//�r�̒��̃^�C�v��ύX
		inhPlayerArmBoth::TYPE temp1;
		temp1 = m_PlayerRight->GetType();
		m_PlayerRight->SetType(m_PlayerLeft->GetType(), false);
		m_PlayerLeft->SetType(m_PlayerCenter->GetType(), false);
		m_PlayerCenter->SetType(temp1, false);
	}
}
