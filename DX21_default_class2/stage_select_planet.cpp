//=============================================
// �X�e�[�W�I����ʂ̘f���֌W(cpp�t�@�C��)
// �쐬���F2022/11/30
// �쐬�ҁF��������
//=============================================

#include "stage_select_planet.h"
#include "inputx.h"
#include "keyboard.h"

//==========================
// �X�V����
//==========================
void StageSelectPlanet::Update()
{
	//=======================
	// �L�[�{�[�h

	//A�L�[����������...
	if (InputGetKeyDown(KK_A)) {
		//���ɂ��炷
		m_planet_index--;
	}
	//D�L�[����������...
	if (InputGetKeyDown(KK_D)) {
		//�E�ɂ��炷
		m_planet_index++;
	}


	//=======================
	// �p�b�h

	//�\���L�[������������...
	if (IsButtonTriggered(0, XINPUT_GAMEPAD_DPAD_LEFT)) {
		//���ɂ��炷
		m_planet_index--;
	}
	//�\���L�[�E����������...
	if (IsButtonTriggered(0, XINPUT_GAMEPAD_DPAD_RIGHT)) {
		//�E�ɂ��炷
		m_planet_index++;
	}

	//���X�e�B�b�N�ō��ɓ|���ꂽ��...
	if (GetThumbLeftX(0) < 0) {
		//���ɂ��炷
		m_planet_index--;
	}
	//���X�e�B�b�N�ŉE�ɓ|���ꂽ��...
	if (GetThumbLeftX(0) > 0) {
		//�E�ɂ��炷
		m_planet_index++;
	}

	//���z���Ȃ�������...
	if (!m_sun_appearance) {
		//�E�[�ɍs������...
		if (m_planet_index == (int)PLANET::SUN) {
			//���[�ɖ߂�
			m_planet_index = 0;
		}
		//���[�ɍs������...
		if (m_planet_index == -1) {
			//�E�[�ɖ߂�
			m_planet_index = (int)PLANET::SUN - 1;
		}
	}
	//���z����������...
	else {
		//�E�[�ɍs������...
		if (m_planet_index == (int)PLANET::NUM) {
			//���[�ɖ߂�
			m_planet_index = 0;
		}
		//���[�ɍs������...
		if (m_planet_index == -1) {
			//�E�[�ɖ߂�
			m_planet_index = (int)PLANET::NUM - 1;
		}
	}

	//
}

//==========================
// �`�揈��
//==========================
void StageSelectPlanet::Draw() const
{
	//�ΐ�
	m_mars->Draw();

	//����
	m_mercury->Draw();

	//�ؐ�
	m_jupiter->Draw();

	//����
	m_venus->Draw();

	//�y��
	m_saturn->Draw();

	if (m_sun_appearance) {
		//���z
		m_sun->Draw();
	}
}