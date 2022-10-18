
#include "main.h"
#include "titletext.h"

static	ID3D11ShaderResourceView	*g_TitleTextTexture = NULL;//�e�N�X�`�����
static	char	*g_ResultTextureName = (char*)"data\\texture\\titletext.png";
int		TitleTextTextureNo;//�e�N�X�`���ԍ�


void InitTitletext()
{
	//	�e�N�X�`���̃��[�h
	TitleTextTextureNo = LoadTexture(g_ResultTextureName);
	if (TitleTextTextureNo == -1)
	{//�ǂݍ��݃G���[
		exit(999);	//�����I��
	}
}


void UninitTitletext()
{

}


void UpdateTitletext()
{

}


void DrawTitletext()
{
	////�Q�c�\�������邽�߂̃}�g���N�X��ݒ�
	SetWorldViewProjection2D();
	//�e�N�X�`���̃Z�b�g
	GetDeviceContext()->PSSetShaderResources(0, 1,
		GetTexture(TitleTextTextureNo));
	//�X�v���C�g�̕`��
	DrawSpriteColorRotation
	(
		SCREEN_WIDTH / 2,
		SCREEN_HEIGHT / 2,
		400,
		100,
		0,
		D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f),
		0,
		1.0f,
		1.0f,
		1
	);


}
