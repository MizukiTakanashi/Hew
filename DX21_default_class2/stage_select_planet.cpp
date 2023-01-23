//=============================================
// �X�e�[�W�I����ʂ̘f���֌W(cpp�t�@�C��)
// �쐬���F2022/11/30
// �쐬�ҁF��������
//=============================================

#include "stage_select_planet.h"
#include "inputx.h"
#include "keyboard.h"
#include "sound.h"

//==========================
// �萔�̏�����
//==========================
const float StageSelectPlanet::MOVE_SPEED = -1.0f;
const float StageSelectPlanet::SUN_MOVE_SPEED_Y = 0.6f;

//==========================
// �f�t�H���g�R���X�g���N�^
//==========================
StageSelectPlanet::StageSelectPlanet()
{
	for (int i = 0; i < (int)PLANET::NUM; i++) {
		m_planets[i] = nullptr;
	}

	for (int i = 0; i < (int)PLANET::NUM - 1; i++) {
		m_pWhiteLine[i] = nullptr;
	}
}

//==========================
// �����t���R���X�g���N�^
//==========================
StageSelectPlanet::StageSelectPlanet(DrawObject& mars, DrawObject& mercury, DrawObject& jupiter, 
	DrawObject& venus, DrawObject& saturn, DrawObject& sun, DrawObject& white_line, 
	bool stage_clear[], bool sun_appearance) :m_sun_appearance(sun_appearance)
{
	//�f���̃Z�b�g
	m_planets[(int)PLANET::MARS] = new StageSelectMars(mars);
	m_planets[(int)PLANET::MERCURY] = new StageSelectMercury(mercury);
	m_planets[(int)PLANET::JUPITER] = new StageSelectJupiter(jupiter);
	m_planets[(int)PLANET::VENUS] = new StageSelectVenus(venus);
	m_planets[(int)PLANET::SATURN] = new StageSelectSaturn(saturn);
	m_planets[(int)PLANET::SUN] = new StageSelectSun(sun);

	//�f���̐F�̃Z�b�g(�N���A���ĂȂ������獕�ڂɂ���)
	for(int i = 0; i < STAGE_MOON; i++) {
		if (!stage_clear[i]) {
			//�Â��F�ɂ���
			m_planets[i]->SetDarker();
		}
	}

	//�������̏�����
	for (int i = 0; i < (int)PLANET::NUM - 1; i++) {
		m_pWhiteLine[i] = new GameObject(white_line, D3DXVECTOR2(SCREEN_WIDTH, 0.0f), D3DXVECTOR2(0.0f, 0.0f));
	}

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

	//���������Z�b�g
	for (int i = 0; i < (int)PLANET::NUM - 1; i++) {
		WhiteLineSet(m_planets[i]->GetPos(), i);
	}

	//=====================
	// ��

	//���艹
	m_SE_01 = LoadSound((char*)"data\\SE\\2_01.wav");
	//SetVolume(g_SE, 0.1f);

	//�J�[�\���ړ���
	m_SE_03 = LoadSound((char*)"data\\SE\\2_03.wav");
}

//==========================
// �f�X�g���N�^
//==========================
StageSelectPlanet::~StageSelectPlanet()
{
	for (int i = 0; i < (int)PLANET::NUM; i++) {
		delete m_planets[i];
	}

	for (int i = 0; i < (int)PLANET::NUM - 1; i++) {
		if (m_pWhiteLine[i] != nullptr) {
			delete m_pWhiteLine[i];
		}
	}
}

//==========================
// �X�V����
//==========================
void StageSelectPlanet::Update()
{
	//�f�����������Ԃł����...
	if (m_move_time >= 0) {
		//�f���𓮂���
		for (int i = 0; i < (int)PLANET::NUM; i++) {
			if (i == (int)PLANET::SUN) {
				m_planets[i]->MovePos(D3DXVECTOR2(0.0f, StageSelectPlanet::SUN_MOVE_SPEED_Y));
			}
			m_planets[i]->MovePos(D3DXVECTOR2(StageSelectPlanet::MOVE_SPEED, 0.0f));
		}

		//���������Z�b�g
		for (int i = 0; i < (int)PLANET::NUM - 1; i++) {
			WhiteLineSet(m_planets[i]->GetPos(), i);
		}

		//�f�����~�܂鎞�Ԃ�������...
		if (m_move_time++ >= StageSelectPlanet::MOVE_TIME_LIMIT) {
			//�J�E���g���X�g�b�v
			m_move_time = -1;
		}

		return;
	}

	//=======================
	// �L�[�{�[�h

	//A�L�[����������...
	if (InputGetKeyDown(KK_A)) {
		//���ɂ��炷
		m_planet_index++;
		PlaySound(m_SE_03, 0);
	}
	//D�L�[����������...
	if (InputGetKeyDown(KK_D)) {
		//�E�ɂ��炷
		m_planet_index--;
		PlaySound(m_SE_03, 0);
	}


	//=======================
	// �p�b�h

	//�\���L�[������������...
	if (IsButtonTriggered(0, XINPUT_GAMEPAD_DPAD_LEFT)) {
		//���ɂ��炷
		m_planet_index++;
		PlaySound(m_SE_03, 0);
	}
	//�\���L�[�E����������...
	if (IsButtonTriggered(0, XINPUT_GAMEPAD_DPAD_RIGHT)) {
		//�E�ɂ��炷
		m_planet_index--;
		PlaySound(m_SE_03, 0);
	}

	//���X�e�B�b�N�ō��ɓ|���ꂽ��...
	if (GetThumbLeftX(0) < 0) {
		//�O�t���[���̃X�e�B�b�N���E�ɓ|����Ă���...(�A������������)
		if (m_thumb_before >= 0) {
			//���ɂ��炷
			m_planet_index++;
			PlaySound(m_SE_03, 0);
		}
	}
	//���X�e�B�b�N�ŉE�ɓ|���ꂽ��...
	if (GetThumbLeftX(0) > 0) {
		//�O�t���[���̃X�e�B�b�N�����ɓ|����Ă���...(�A������������)
		if (m_thumb_before <= 0) {
			//�E�ɂ��炷
			m_planet_index--;
			PlaySound(m_SE_03, 0);
		}
	}
	//�X�e�B�b�N�̒l��ۑ�
	m_thumb_before = (int)GetThumbLeftX(0);

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

	//�p�b�h��B�{�^������������...
	if (IsButtonTriggered(0, XINPUT_GAMEPAD_B)) {
		PlaySound(m_SE_01, 0);
		Fade((SCENE)(SCENE::SCENE_MERCURY + m_planet_index), STAGE::STAGE_MERCURY);
	}
	//�L�[�{�[�h��Enter����������...
	else if (InputGetKeyDown(KK_ENTER)) {
		PlaySound(m_SE_01, 0);
		Fade((SCENE)(SCENE::SCENE_MERCURY + m_planet_index), STAGE::STAGE_MERCURY);
	}
}

//==========================
// �`�揈��
//==========================
void StageSelectPlanet::Draw() const
{
	//�������̕`��
	for (int i = 0; i < (int)PLANET::SUN; i++) {
		m_pWhiteLine[i]->Draw();
	}

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

//==========================
// ���������Z�b�g����
//==========================
void StageSelectPlanet::WhiteLineSet(const D3DXVECTOR2& planet_pos, int type)
{
	//�x�N�g���m��
	D3DXVECTOR2 vec = m_pWhiteLine[type]->GetPos() - planet_pos;

	if (vec.x < 0) {
		vec.x *= -1;
	}
	if (vec.y < 0) {
		vec.y *= -1;
	}

	float length = D3DXVec2Length(&vec);

	m_pWhiteLine[type]->SetSize(D3DXVECTOR2(length * 2, length * 2));
}
