//==============================================
//
//	[.cpp]
//	Author	:
//	Date	:
//==============================================

//==============================================
//�C���N���[�h
//==============================================
#include "main.h"
#include "result.h"

#include "bgresult.h"
#include "resulttext.h"


//==============================================
//�}�N����`
//==============================================
//==============================================
//�O���[�o���ϐ�
//==============================================
int ResultSoundNo;	//�Q�[���T�E���h�C���f�b�N�X


//==============================================
//������
//==============================================
void	InitResult()
{
	//BGM�̃��[�h
	char filename[] = "data\\BGM\\�ǐՎ�.wav";
	ResultSoundNo = LoadSound(filename);

	InitBGResult();
	InitResulttext();


	PlaySound(ResultSoundNo, -1);
	SetVolume(ResultSoundNo, 0.1);

}

//==============================================
//�I������
//==============================================
void	UninitResult()
{
	UninitBGResult();
	UninitResulttext();


	StopSoundAll();
}

//==============================================
//�X�V����
//==============================================
void	UpdateResult()
{
	UpdateBGResult();
	UpdateResulttext();

	//�L�[���͂̃`�F�b�N
	if (GetKeyboardTrigger(DIK_X))
	{
		SetScene(SCENE::SCENE_TITLE);
	}


}
//==============================================
//�`�揈��
//==============================================
void	DrawResult()
{
	DrawBGResult();
	DrawResulttext();

}
