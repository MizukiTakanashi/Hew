//=======================================
// �V�[���֌W(cpp�t�@�C��)
// �쐬���F2022/07/14
// �쐬�ҁF��������
//=======================================
#include "scene.h"
#include "game.h"
#include "Title.h"
#include "texture_useful.h"
#include "sprite.h"
#include "game.h"
#include "result.h"
#include "score.h"
#include "draw_object.h"
#include "stage_select.h"
#include "stage_mercury.h"
#include "stage_mars.h"
#include "stage_saturn.h"
#include "stage_venus.h"
#include "title_score.h"

//======================
// �O���[�o���ϐ�
//======================
SCENE g_scene;			//���݂̃V�[��
SCENE g_scene_next;		//���̃V�[��
STAGE g_stage = STAGE::STAGE_MOON; //���̃X�e�[�W

StageSelect* pStageSelect = nullptr;	//�X�e�[�W�I�����
TitleScore* pTitleScore = nullptr;		//�ō��X�R�A�\�����
Game* pGame = nullptr;					//�Q�[�����
Result* pResult = nullptr;				//���U���g���

StageMercury* pMercury = nullptr;		//�����X�e�[�W
StageMars* pMars = nullptr;				//�ΐ��X�e�[�W
StageSaturn* pSaturn = nullptr;
StageVenus* pVenus = nullptr;

TextureUseful* g_pTexUseful;
DrawObject* g_pDrawObject;
Score* g_pNumber;

int g_Score[STAGE_NUM];		//�X�R�A�ێ��p
bool g_isclear = false;

//==========================
// ����������
//==========================
void InitScene(SCENE s, STAGE stage)
{
	g_stage = stage;
	g_scene = s;
	g_scene_next = s;

	bool tutorial = false;
	if (g_Score[STAGE_MOON] > 0) {
		tutorial = true;
	}

	switch (g_scene){

	case SCENE::SCENE_NONE:
		break;

	case SCENE::SCENE_TITLE:
		InitTitle(tutorial);
		break;

	case SCENE::SCENE_TITLE_SCORE:
		pTitleScore = new TitleScore(g_Score);
		break;

	case SCENE::SCENE_STAGE_SELECT:
		pStageSelect = new StageSelect(g_Score);
		break;

	case SCENE::SCENE_GAME:
		pGame = new Game(g_pNumber = new Score(g_pDrawObject[0]));
		break;

	case SCENE::SCENE_MERCURY:
		pMercury = new StageMercury(new Score(g_pDrawObject[0]));
		break;

	case SCENE::SCENE_VENUS:
		pVenus = new StageVenus(new Score(g_pDrawObject[0]));
		break;

	case SCENE::SCENE_MARS:
		pMars = new StageMars(new Score(g_pDrawObject[0]));
		break;

	case SCENE::SCENE_JUPITER:
		break;

	case SCENE::SCENE_SATURN:
		pSaturn = new StageSaturn(new Score(g_pDrawObject[0]));
		break;

	case SCENE::SCENE_SUN:
		break;

	case SCENE::SCENE_RESULT:
		switch (g_stage)
		{
		case STAGE::STAGE_MOON:
			pResult = new Result(g_isclear, g_pNumber, STAGE::STAGE_MOON);
			break;
		case STAGE::STAGE_MARS:
			pResult = new Result(g_isclear, g_pNumber, STAGE::STAGE_MARS);
			break;
		case STAGE::STAGE_MERCURY:
			pResult = new Result(g_isclear, g_pNumber, STAGE::STAGE_MERCURY);
			break;
		case STAGE::STAGE_JUPITER:
			pResult = new Result(g_isclear, g_pNumber, STAGE::STAGE_JUPITER);
			break;
		case STAGE::STAGE_VENUS:
			pResult = new Result(g_isclear, g_pNumber, STAGE::STAGE_VENUS);
			break;
		case STAGE::STAGE_SATURN:
			pResult = new Result(g_isclear, g_pNumber, STAGE::STAGE_SATURN);
			break;
		case STAGE::STAGE_SUN:
			pResult = new Result(g_isclear, g_pNumber, STAGE::STAGE_SUN);
			break;
		case STAGE::STAGE_NUM:
			pResult = new Result(g_isclear, g_pNumber, STAGE::STAGE_MOON);
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}
}

//==========================
// ����������
//==========================
void InitScene2(SCENE s, STAGE stage)
{
	//�e�N�X�`��
	g_pTexUseful = new TextureUseful[10];
	g_pDrawObject = new DrawObject[10];

	//����
	g_pTexUseful[0].SetTextureName((char*)"data\\texture\\number.png");
	g_pDrawObject[0].SetDrawObject(g_pTexUseful[0], 0.0f, 0.0909f, 1.0f, 11);
	g_pNumber = new Score(g_pDrawObject[0]);

	//�X�R�A��������
	for (int i = 0; i < STAGE_NUM; i++) {
		g_Score[i] = 0;
	}

	InitScene(s, stage);
}

//==========================
// �I������
//==========================
void UninitScene(void)
{
	switch (g_scene) {

	case SCENE::SCENE_NONE:
		break;

	case SCENE::SCENE_TITLE:
		UninitTitle();
		break;

	case SCENE::SCENE_TITLE_SCORE:
		delete pTitleScore;
		break;

	case SCENE::SCENE_STAGE_SELECT:
		delete pStageSelect;
		break;

	case SCENE::SCENE_GAME:
		//�O�̃X�R�A�������������ł����...
		if (pGame->GetScore() > g_Score[STAGE_MOON]) {
			//�X�R�A���X�V
			g_Score[STAGE_MOON] = pGame->GetScore();
		}
		delete pGame;
		break;

	case SCENE::SCENE_MERCURY:
		//�O�̃X�R�A�������������ł����...
		if (pMercury->GetScore() > g_Score[STAGE_MERCURY]) {
			//�X�R�A���X�V
			g_Score[STAGE_MERCURY] = pMercury->GetScore();
		}
		delete pMercury;
		break;

	case SCENE::SCENE_VENUS:
		//�O�̃X�R�A�������������ł����...
		if (pVenus->GetScore() > g_Score[STAGE_VENUS]) {
			//�X�R�A���X�V
			g_Score[STAGE_VENUS] = pVenus->GetScore();
		}
		delete pVenus;

		break;

	case SCENE::SCENE_MARS:
		//�O�̃X�R�A�������������ł����...
		if (pMars->GetScore() > g_Score[STAGE_MARS]) {
			//�X�R�A���X�V
			g_Score[STAGE_MARS] = pMars->GetScore();
		}
		delete pMars;
		break;

	case SCENE::SCENE_JUPITER:
		break;

	case SCENE::SCENE_SATURN:
		//�O�̃X�R�A�������������ł����...
		if (pSaturn->GetScore() > g_Score[STAGE_SATURN]) {
			//�X�R�A���X�V
			g_Score[STAGE_SATURN] = pSaturn->GetScore();
		}
		delete pSaturn;
		break;

	case SCENE::SCENE_SUN:
		break;

	case SCENE::SCENE_RESULT:
		delete pResult;
		break;

	default:
		break;
	}
}

//==========================
// �I������
//==========================
void UninitScene2(void)
{
	delete[] g_pTexUseful;
	delete[] g_pDrawObject;
	delete g_pNumber;
}

//======================
// �X�V����
//======================
void UpdateScene(void)
{
	switch (g_scene) {

	case SCENE::SCENE_NONE:
		break;

	case SCENE::SCENE_TITLE:
		UpdateTitle();
		break;

	case SCENE::SCENE_TITLE_SCORE:
		pTitleScore->Update();
		break;

	case SCENE::SCENE_STAGE_SELECT:
		pStageSelect->Update();
		break;

	case SCENE::SCENE_GAME:
		pGame->Update();
		break;

	case SCENE::SCENE_MERCURY:
		pMercury->Update();
		break;

	case SCENE::SCENE_VENUS:
		pVenus->Update();
		break;

	case SCENE::SCENE_MARS:
		pMars->Update();
		break;

	case SCENE::SCENE_JUPITER:
		break;

	case SCENE::SCENE_SATURN:
		pSaturn->Update();
		break;

	case SCENE::SCENE_SUN:
		break;

	case SCENE::SCENE_RESULT:
		pResult->Update();
		break;

	default:
		break;
	}
}

//==========================
// �`�揈��
//==========================
void DrawScene(void)
{
	switch (g_scene) {

	case SCENE::SCENE_NONE:
		break;

	case SCENE::SCENE_TITLE:
		DrawTitle();
		break;

	case SCENE::SCENE_TITLE_SCORE:
		pTitleScore->Draw();
		break;

	case SCENE::SCENE_STAGE_SELECT:
		pStageSelect->Draw();
		break;

	case SCENE::SCENE_GAME:
		pGame->Draw();
		break;

	case SCENE::SCENE_MERCURY:
		pMercury->Draw();
		break;

	case SCENE::SCENE_VENUS:
		pVenus->Draw();
		break;

	case SCENE::SCENE_MARS:
		pMars->Draw();
		break;

	case SCENE::SCENE_JUPITER:
		break;

	case SCENE::SCENE_SATURN:
		pSaturn->Draw();
		break;

	case SCENE::SCENE_SUN:
		break;

	case SCENE::SCENE_RESULT:
		pResult->Draw();
		break;

	default:
		break;
	}
}

//==========================
// �V�[�����Z�b�g
//==========================
void SetScene(SCENE s, STAGE stage)
{
	g_scene_next = s;
	g_stage = stage;
}

//==========================
// �V�[�����`�F�b�N
//==========================
void CheckScene(void)
{
	if (g_scene != g_scene_next) {
		UninitScene();				//���݂̃V�[���̏I������

		InitScene(g_scene_next, g_stage);	//���̃V�[���̏���������
	}
}

void SetStageClear(bool is)
{
	g_isclear = is;
}