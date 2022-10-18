//==============================================
//
//	[.cpp]
//	Author	:
//	Date	:
//==============================================
#pragma once

//==============================================
//�C���N���[�h
//==============================================
#include "bggame.h"

//==============================================
// �}�N����`
//==============================================


//==============================================
// �O���[�o���ϐ�
//==============================================
//�e�N�X�`�����̕ۑ��ϐ�
static	ID3D11ShaderResourceView	*g_TextureBG;//�摜1����1�̕ϐ����K�v
static	char	*g_TextureNameBG = (char*)"data\\texture\\bggame.png";//�e�N�X�`���t�@�C���p�X JPG BMP PNG

//�e�N�X�`���̃C���f�b�N�X
static int g_TextureNoBG = 0;

BG* Sample;	//�w�i�\����

//==============================================
// ����������
//==============================================
HRESULT InitBgGame(void)
{

	//�e�N�X�`���̃��[�h
	g_TextureNoBG = LoadTexture(g_TextureNameBG);
	if (g_TextureNoBG == -1)
	{	//���[�h�G���[
		exit(999);
	}

	//�w�i�̏�����
	{
		Sample = new BG;	//�w�i�̃C���X�^���X�쐬
		Sample->Position.x = SCREEN_WIDTH / 2;
		Sample->Position.y = SCREEN_HEIGHT / 2;
		Sample->Position.z = 0.0f;

		Sample->Size.x = SCREEN_WIDTH;
		Sample->Size.y = SCREEN_HEIGHT;

		Sample->Color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		Sample->Rotation = 0.0f;

		Sample->PaternNo = 0.0f;
		Sample->u = 1.0f;
		Sample->v = 1.0f;
		Sample->NumPatern = 1;
	}



	return S_OK;

}

//==============================================
// �I������
//==============================================
void UninitBgGame(void)
{

	if (Sample)
	{
		delete Sample;
	}

}


//==============================================
// �X�V����
//==============================================
void UpdateBgGame(void)
{


}


//==============================================
// �`�揈��
//==============================================
void DrawBgGame(void)
{

	// �Q�c�\�������邽�߂̃}�g���N�X��ݒ�
	SetWorldViewProjection2D();

	//�w�i�̕\��
	{
		//�e�N�X�`���̐ݒ�
		GetDeviceContext()->PSSetShaderResources(
			0, 1, GetTexture(g_TextureNoBG));

		DrawSpriteColorRotation(
			Sample->Position.x,
			Sample->Position.y,
			Sample->Size.x,
			Sample->Size.y,
			Sample->Rotation,
			Sample->Color,
			Sample->PaternNo,		//�p�^�[���ԍ�
			Sample->u,				//���T�C�Yf
			Sample->v,				//�c�T�C�Yf
			Sample->NumPatern		//������
		);

	}


}
