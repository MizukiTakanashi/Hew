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
#include "title_score.h"

//======================
// �O���[�o���ϐ�
//======================
SCENE g_scene;			//���݂̃V�[��
SCENE g_scene_next;		//���̃V�[��

StageSelect* pStageSelect = nullptr;	//�X�e�[�W�I�����
TitleScore* pTitleScore = nullptr;		//�ō��X�R�A�\�����
Game* pGame = nullptr;					//�Q�[�����
Result* pResult = nullptr;				//���U���g���

StageMercury* pMercury = nullptr;		//�����X�e�[�W
StageMars* pMars = nullptr;				//�ΐ��X�e�[�W
StageSaturn* pSaturn = nullptr;

TextureUseful* g_pTexUseful;
DrawObject* g_pDrawObject;
Score* g_pNumber;

int g_Score[STAGE_NUM];		//�X�R�A�ێ��p

//==========================
// ����������
//==========================
void InitScene(SCENE s)
{
	g_scene = s;
	g_scene_next = s;

	switch (g_scene){

	case SCENE::SCENE_NONE:
		break;

	case SCENE::SCENE_TITLE:
		InitTitle();
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
		pResult = new Result(true, g_pNumber, STAGE::STAGE_MOON);
		break;

	default:
		break;
	}
}

//==========================
// ����������
//==========================
void InitScene2(SCENE s)
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

	InitScene(s);
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
void SetScene(SCENE s)
{
	g_scene_next = s;
}

//==========================
// �V�[�����`�F�b�N
//==========================
void CheckScene(void)
{
	if (g_scene != g_scene_next) {
		UninitScene();				//���݂̃V�[���̏I������

		InitScene(g_scene_next);	//���̃V�[���̏���������
	}
}
