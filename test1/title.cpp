#include "main.h"
#include "title.h"

#include "bgtitle.h"
#include "titletext.h"

//==============================================
//�}�N����`
//=======================
//======================
//�O���[�o���ϐ�
//======================
int TitleSoundNo;	//�Q�[���T�E���h�C���f�b�N�X


//======================
//������
//======================
void	InitTitle()
{
	//BGM�̃��[�h
	char filename[] = "data\\BGM\\�������}���I.wav";
	TitleSoundNo = LoadSound(filename);

	InitBGTitle();
	InitTitletext();

	PlaySound(TitleSoundNo, -1);
	SetVolume(TitleSoundNo, 0.1);

}
//======================
//�I������
//======================
void	UninitTitle()
{
	UninitBGTitle();
	UninitTitletext();

	StopSoundAll();
}

//======================
//�X�V����
//======================
void	UpdateTitle()
{
	UpdateBGTitle();
	UpdateTitletext();




	//�L�[���͂̃`�F�b�N
	if (GetKeyboardTrigger(DIK_X))
	{
		SetScene(SCENE::SCENE_GAME);
	}

}
//======================
//�`�揈��
//======================
void	DrawTitle()
{
	DrawBGTitle();
	DrawTitletext();

}
