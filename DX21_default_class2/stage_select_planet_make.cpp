//=======================================
// �f������֌W(�w�b�_�t�@�C��)
// �쐬���F2022/11/30
// �쐬�ҁF��������
//=======================================

#include "stage_select_planet_make.h"

//==========================
// �萔�̏�����
//==========================
//�ΐ�
const float StageSelectMars::BOX_W = 50.0f;
const float StageSelectMars::BOX_H = 50.0f;
const float StageSelectMars::BIG_BOX_W = 100.0f;
const float StageSelectMars::BIG_BOX_H = 100.0f;
const float StageSelectMars::SUN_BOX_W = 25.0f;
const float StageSelectMars::SUN_BOX_H = 25.0f;
const float StageSelectMars::SUN_BIG_BOX_W = 50.0f;
const float StageSelectMars::SUN_BIG_BOX_H = 50.0f;
const float StageSelectMars::START_POS_X = 200.0f;
const float StageSelectMars::START_POS_Y = SCREEN_HEIGHT / 2;

//����
const float StageSelectMercury::BOX_W = 50.0f;
const float StageSelectMercury::BOX_H = 50.0f;
const float StageSelectMercury::BIG_BOX_W = 100.0f;
const float StageSelectMercury::BIG_BOX_H = 100.0f;
const float StageSelectMercury::SUN_BOX_W = 25.0f;
const float StageSelectMercury::SUN_BOX_H = 25.0f;
const float StageSelectMercury::SUN_BIG_BOX_W = 50.0f;
const float StageSelectMercury::SUN_BIG_BOX_H = 50.0f;
const float StageSelectMercury::START_POS_X = 400.0f;
const float StageSelectMercury::START_POS_Y = SCREEN_HEIGHT / 2;

//�ؐ�
const float StageSelectJupiter::BOX_W = 50.0f;
const float StageSelectJupiter::BOX_H = 50.0f;
const float StageSelectJupiter::BIG_BOX_W = 100.0f;
const float StageSelectJupiter::BIG_BOX_H = 100.0f;
const float StageSelectJupiter::SUN_BOX_W = 25.0f;
const float StageSelectJupiter::SUN_BOX_H = 25.0f;
const float StageSelectJupiter::SUN_BIG_BOX_W = 50.0f;
const float StageSelectJupiter::SUN_BIG_BOX_H = 50.0f;
const float StageSelectJupiter::START_POS_X = 600.0f;
const float StageSelectJupiter::START_POS_Y = SCREEN_HEIGHT / 2;

//����
const float StageSelectVenus::BOX_W = 50.0f;
const float StageSelectVenus::BOX_H = 50.0f;
const float StageSelectVenus::BIG_BOX_W = 100.0f;
const float StageSelectVenus::BIG_BOX_H = 100.0f;
const float StageSelectVenus::SUN_BOX_W = 25.0f;
const float StageSelectVenus::SUN_BOX_H = 25.0f;
const float StageSelectVenus::SUN_BIG_BOX_W = 50.0f;
const float StageSelectVenus::SUN_BIG_BOX_H = 50.0f;
const float StageSelectVenus::START_POS_X = 800.0f;
const float StageSelectVenus::START_POS_Y = SCREEN_HEIGHT / 2;

//�y��
const float StageSelectSaturn::BOX_W = 50.0f;
const float StageSelectSaturn::BOX_H = 50.0f;
const float StageSelectSaturn::BIG_BOX_W = 100.0f;
const float StageSelectSaturn::BIG_BOX_H = 100.0f;
const float StageSelectSaturn::SUN_BOX_W = 25.0f;
const float StageSelectSaturn::SUN_BOX_H = 25.0f;
const float StageSelectSaturn::SUN_BIG_BOX_W = 50.0f;
const float StageSelectSaturn::SUN_BIG_BOX_H = 50.0f;
const float StageSelectSaturn::START_POS_X = 1000.0f;
const float StageSelectSaturn::START_POS_Y = SCREEN_HEIGHT / 2;

//���z
const float StageSelectSun::BOX_W = 100.0f;
const float StageSelectSun::BOX_H = 100.0f;
const float StageSelectSun::BIG_BOX_W = 200.0f;
const float StageSelectSun::BIG_BOX_H = 200.0f;
const float StageSelectSun::START_POS_X = 50.0f;
const float StageSelectSun::START_POS_Y = SCREEN_HEIGHT / 2;