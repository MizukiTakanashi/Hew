//=============================================
// �X�e�[�W�I����ʂ̘f���֌W(cpp�t�@�C��)
// �쐬���F2022/11/30
// �쐬�ҁF��������
//=============================================

#include "stage_select_planet.h"

//==========================
// �萔�̏�����
//==========================
const float StageSelectMercury::BOX_W = 50.0f;
const float StageSelectMercury::BOX_H = 50.0f;
const float StageSelectMercury::START_POS_X = 400.0f;
const float StageSelectMercury::START_POS_Y = SCREEN_HEIGHT / 2;

//==========================
// �X�V����
//==========================
void StageSelectPlanet::Update()
{
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
}