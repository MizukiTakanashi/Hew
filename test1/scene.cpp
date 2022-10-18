
#include	"scene.h"
#include	"main.h"
#include	"renderer.h"

#include	"Game.h"
#include	"Title.h"
#include	"result.h"


//===========================
//�}�N����`
//===========================
//===========================
//�O���[�o���ϐ�
//===========================
static	SCENE	g_SceneIndex = SCENE::SCENE_NONE;//���ݎ��s���̃V�[���ԍ�

static	SCENE	g_SceneNextIndex = g_SceneIndex;

int score;

//==================
//������
//
//in  ����������V�[���ԍ�
//==================
void	InitScene(SCENE no)
{
	g_SceneIndex = g_SceneNextIndex = no;//���e�����킹��

	switch (g_SceneIndex)
	{
		case	SCENE::SCENE_NONE:	//�������Ȃ�
			break;
		case	SCENE::SCENE_TITLE:	//�^�C�g�����
			InitTitle();
			break;
		case	SCENE::SCENE_GAME:	//�Q�[��
			InitGame();
			break;
		case	SCENE::SCENE_RESULT://���U���g���
			InitResult();
			break;
	}

}
//==================
//�I������
//==================
void	UninitScene()
{
	switch (g_SceneIndex)
	{
		case	SCENE::SCENE_NONE:	//�������Ȃ�
			break;
		case	SCENE::SCENE_TITLE:	//�^�C�g�����
			UninitTitle();
			break;
		case	SCENE::SCENE_GAME:	//�Q�[��
			UninitGame();
			break;
		case	SCENE::SCENE_RESULT://���U���g���
			UninitResult();
			break;
	}


}
//==================
//�X�V����
//==================
void	UpdateScene()
{
	switch (g_SceneIndex)
	{
		case	SCENE::SCENE_NONE:	//�������Ȃ�
			break;
		case	SCENE::SCENE_TITLE:	//�^�C�g�����
			UpdateTitle();
			break;
		case	SCENE::SCENE_GAME:	//�Q�[��
			UpdateGame();
			break;
		case	SCENE::SCENE_RESULT://���U���g���
			UpdateResult();
			break;
	}

}
//==================
//�`�揈��
//==================
void	DrawScene()
{
	switch (g_SceneIndex)
	{
		case	SCENE::SCENE_NONE:	//�������Ȃ�
			break;
		case	SCENE::SCENE_TITLE:	//�^�C�g�����
			DrawTitle();
			break;
		case	SCENE::SCENE_GAME:	//�Q�[��
			DrawGame();
			break;
		case	SCENE::SCENE_RESULT://���U���g���
			DrawResult();
			break;
	}
}

//�V�����V�[�����Z�b�g���ă��N�G�X�g����
void	SetScene(SCENE no)
{
	g_SceneNextIndex = no;	//���̃V�[���ԍ�
}

//�V�[���؂�ւ��̃��N�G�X�g���`�F�b�N����
void	CheckScene()
{
	if (g_SceneIndex != g_SceneNextIndex)//���̃V�[�������݂̃V�[���ƈႤ
	{
		UninitScene();	//���݂̃V�[�����I��������

		InitScene(g_SceneNextIndex);//���̃V�[��������������
	}


}
