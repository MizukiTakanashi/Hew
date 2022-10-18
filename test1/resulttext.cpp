
#include "main.h"
#include "resulttext.h"

static	ID3D11ShaderResourceView	*g_ResultTextTexture = NULL;//�e�N�X�`�����
static	char	*g_ResultTextureName = (char*)"data\\texture\\resulttext.png";
int		ResultTextTextureNo;//�e�N�X�`���ԍ�


void InitResulttext()
{
	//	�e�N�X�`���̃��[�h
	ResultTextTextureNo = LoadTexture(g_ResultTextureName);
	if (ResultTextTextureNo == -1)
	{//�ǂݍ��݃G���[
		exit(999);	//�����I��
	}
}


void UninitResulttext()
{

}


void UpdateResulttext()
{

}


void DrawResulttext()
{
	////�Q�c�\�������邽�߂̃}�g���N�X��ݒ�
	SetWorldViewProjection2D();
	//�e�N�X�`���̃Z�b�g
	GetDeviceContext()->PSSetShaderResources(0, 1,
		GetTexture(ResultTextTextureNo));
	//�X�v���C�g�̕`��
	DrawSpriteColorRotation
	(
		SCREEN_WIDTH / 2,
		SCREEN_HEIGHT / 2 - 100,
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
