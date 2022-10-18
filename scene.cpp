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
#include "number.h"
#include "DrawObject.h"

//======================
// �O���[�o���ϐ�
//======================
SCENE g_scene;	//���݂̃V�[��
SCENE g_scene_next;		//���̃V�[��
Game* pGame;
Result* pResult;

TextureUseful* g_pTexUseful;
DrawObject* g_pDrawObject;
Number* g_pNumber;

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

	case SCENE::SCENE_GAME:
		pGame = new Game(g_pNumber);
		break;

	case SCENE::SCENE_RESULT:
		pResult = new Result(g_pNumber);
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
	g_pNumber = new Number(g_pDrawObject[0]);

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

	case SCENE::SCENE_GAME:
		delete pGame;
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

	case SCENE::SCENE_GAME:
		pGame->Update();
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

	case SCENE::SCENE_GAME:
		pGame->Draw();
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
