//==============================================
//
//	[.cpp]
//	Author	:
//	Date	:
//==============================================

//==============================================
//�C���N���[�h
//==============================================
#include	"main.h"
#include	"renderer.h"
#include	"texture.h"
#include	"sprite.h"

//==============================================
//�}�N����`
//==============================================

//==============================================
//�O���[�o���ϐ�
//==============================================
static	ID3D11ShaderResourceView	*g_TitleTexture = NULL;//�e�N�X�`�����
static	char	*g_TitleTextureName = (char*)"data\\texture\\bg.png";

typedef	struct
{
	D3DXVECTOR3		Position;	//�\�����W
	D3DXVECTOR2		Size;		//�T�C�Y
	D3DXCOLOR		Color;		//�F
	float			Rotate;		//�p�x
}TITLE;

TITLE	TitleObject;//�^�C�g����ʃI�u�W�F�N�g

int		TitleTextureNo;//�e�N�X�`���ԍ�

//==============================================
//������
//==============================================
void	InitBGTitle()
{
	//	�e�N�X�`���̃��[�h
	TitleTextureNo = LoadTexture(g_TitleTextureName);
	if (TitleTextureNo == -1)
	{//�ǂݍ��݃G���[
		exit(999);	//�����I��
	}

	TitleObject.Position = D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);
	TitleObject.Size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	TitleObject.Color = D3DXCOLOR(1.0, 1.0, 1.0, 1.0);
	TitleObject.Rotate = 0.0;


}
//==============================================
//�I������
//==============================================
void	UninitBGTitle()
{
}

//==============================================
//�X�V����
//==============================================
void	UpdateBGTitle()
{



}
//==============================================
//�`�揈��
//==============================================
void	DrawBGTitle()
{
	//�Q�c�\�������邽�߂̃}�g���N�X��ݒ�
	SetWorldViewProjection2D();
	//�e�N�X�`���̃Z�b�g
	GetDeviceContext()->PSSetShaderResources(0, 1,
		GetTexture(TitleTextureNo));
	//�X�v���C�g�̕`��
	DrawSpriteColorRotation
	(
		TitleObject.Position.x,
		TitleObject.Position.y,
		TitleObject.Size.x,
		TitleObject.Size.y,
		TitleObject.Rotate,
		TitleObject.Color,
		0,
		1.0f,
		1.0f,
		1
	);


}



