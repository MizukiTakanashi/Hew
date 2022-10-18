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
#include "bgresult.h"

//==============================================
//�}�N����`
//==============================================

//==============================================
//�O���[�o���ϐ�
//==============================================
static	ID3D11ShaderResourceView	*g_ResultTexture = NULL;//�e�N�X�`�����
static	char	*g_ResultTextureName = (char*)"data\\texture\\bg.png";

typedef	struct
{
	D3DXVECTOR3		Position;	//�\�����W
	D3DXVECTOR2		Size;		//�T�C�Y
	D3DXCOLOR		Color;		//�F
	float			Rotate;		//�p�x
}RESULT;

RESULT	ResultObject;//�^�C�g����ʃI�u�W�F�N�g

int		ResultTextureNo;//�e�N�X�`���ԍ�

//==============================================
//������
//==============================================
void	InitBGResult()
{
	//	�e�N�X�`���̃��[�h
	ResultTextureNo = LoadTexture(g_ResultTextureName);
	if (ResultTextureNo == -1)
	{//�ǂݍ��݃G���[
		exit(999);	//�����I��
	}

	ResultObject.Position = D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);
	ResultObject.Size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	ResultObject.Color = D3DXCOLOR(1.0, 1.0, 1.0, 1.0);
	ResultObject.Rotate = 0.0;


}
//==============================================
//�I������
//==============================================
void	UninitBGResult()
{
}

//==============================================
//�X�V����
//==============================================
void	UpdateBGResult()
{
	//�L�[���͂̃`�F�b�N
	if (GetKeyboardTrigger(DIK_SPACE))
	{
		SetScene(SCENE::SCENE_GAME);
	}


}
//==============================================
//�`�揈��
//==============================================
void	DrawBGResult()
{
	//�Q�c�\�������邽�߂̃}�g���N�X��ݒ�
	SetWorldViewProjection2D();
	//�e�N�X�`���̃Z�b�g
	GetDeviceContext()->PSSetShaderResources(0, 1,
		GetTexture(ResultTextureNo));
	//�X�v���C�g�̕`��
	DrawSpriteColorRotation
	(
		ResultObject.Position.x,
		ResultObject.Position.y,
		ResultObject.Size.x,
		ResultObject.Size.y,
		ResultObject.Rotate,
		ResultObject.Color,
		0,
		1.0f,
		1.0f,
		1
	);


}



