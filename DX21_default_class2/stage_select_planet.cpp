//=============================================
// �X�e�[�W�I����ʂ̘f���֌W(cpp�t�@�C��)
// �쐬���F2022/11/30
// �쐬�ҁF��������
//=============================================

#include "stage_select_planet.h"
#include "inputx.h"
#include "keyboard.h"

//==========================
// �����t���R���X�g���N�^
//==========================
StageSelectPlanet::StageSelectPlanet(DrawObject& mars, DrawObject& mercury, DrawObject& jupiter, 
	DrawObject& venus, DrawObject& saturn, DrawObject& sun, bool sun_appearance) :m_sun_appearance(sun_appearance)
{
	//�f���̃Z�b�g
	m_planets[(int)PLANET::MARS] = new StageSelectMars(mars);
	m_planets[(int)PLANET::MERCURY] = new StageSelectMercury(mercury);
	m_planets[(int)PLANET::JUPITER] = new StageSelectJupiter(jupiter);
	m_planets[(int)PLANET::VENUS] = new StageSelectVenus(venus);
	m_planets[(int)PLANET::SATURN] = new StageSelectSaturn(saturn);
	m_planets[(int)PLANET::SUN] = new StageSelectSun(sun);

	//���z������̂ł����...
	if (sun_appearance) {
		//���z�ȊO�̘f��������������
		for (int i = 0; i < (int)PLANET::SUN; i++) {
			m_planets[i]->SetSunSizeSmaller();
		}
		//���z��傫������(�I��)
		m_planets[(int)PLANET::SUN]->SetSizeBigger();

		//�C���f�b�N�X�ԍ��𑾗z�ɃZ�b�g
		m_planet_index = (int)PLANET::SUN;
		m_planet_index_before = (int)PLANET::SUN;

		//�������ԃJ�E���g���Z�b�g
		m_move_time = 0;
	}
	else {
		//�ŏ��̘f����傫������(�I��)
		m_planets[0]->SetSizeBigger();
	}
}

//==========================
// �X�V����
//==========================
void StageSelectPlanet::Update()
{
	//�f���������Ă����...
	if (m_move_time++ >= 0) {
		for (int i = 0; i < (int)PLANET::NUM; i++) {
			m_planets[i]->MovePos(D3DXVECTOR2(m_move_speed, 0.0f));
		}
	}

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
		//�O�t���[���̃X�e�B�b�N���E�ɓ|����Ă���...(�A������������)
		if (m_thumb_before >= 0) {
			//���ɂ��炷
			m_planet_index--;
		}
	}
	//���X�e�B�b�N�ŉE�ɓ|���ꂽ��...
	if (GetThumbLeftX(0) > 0) {
		//�O�t���[���̃X�e�B�b�N�����ɓ|����Ă���...(�A������������)
		if (m_thumb_before <= 0) {
			//�E�ɂ��炷
			m_planet_index++;
		}
	}
	//�X�e�B�b�N�̒l��ۑ�
	m_thumb_before = GetThumbLeftX(0);

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

	//�T�C�Y���X�V����
	//�O�̃C���f�b�N�X�ԍ�����ύX�������...
	if (m_planet_index != m_planet_index_before) {

		//���z�������...
		if (m_sun_appearance) {
			//���z�����̃C���f�b�N�X�ԍ��ł����...
			if (m_planet_index == (int)PLANET::SUN) {
				//���݂̃C���f�b�N�X�ԍ��̘f����傫������
				m_planets[m_planet_index]->SetSizeBigger();
			}
			else {
				//���݂̃C���f�b�N�X�ԍ��̘f����傫������
				m_planets[m_planet_index]->SetSunSizeBigger();
			}

			//���z���O�̃C���f�b�N�X�ԍ��ł����...
			if (m_planet_index_before == (int)PLANET::SUN) {
				//�O�̃C���f�b�N�X�ԍ��̘f��������������
				m_planets[m_planet_index_before]->SetSizeSmaller();
			}
			else {
				//�O�̃C���f�b�N�X�ԍ��̘f��������������
				m_planets[m_planet_index_before]->SetSunSizeSmaller();
			}
		}
		else {
			//���݂̃C���f�b�N�X�ԍ��̘f����傫������
			m_planets[m_planet_index]->SetSizeBigger();

			//�O�̃C���f�b�N�X�ԍ��̘f��������������
			m_planets[m_planet_index_before]->SetSizeSmaller();
		}
	}

	//���݂̘f���C���f�b�N�X�ԍ���ۑ�
	m_planet_index_before = m_planet_index;
}

//==========================
// �`�揈��
//==========================
void StageSelectPlanet::Draw() const
{
	//���z�ȊO�̕`��
	for (int i = 0; i < (int)PLANET::SUN; i++) {
		m_planets[i]->Draw();
	}

	//���z�������o�Ă��Ȃ�...
	if (m_sun_appearance) {
		//���z��`��
		m_planets[(int)PLANET::SUN]->Draw();
	}
}