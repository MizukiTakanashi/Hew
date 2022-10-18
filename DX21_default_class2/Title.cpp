//=======================================
// �^�C�g����ʊ֌W(cpp�t�@�C��)
// �쐬���F2022/07/14
// �쐬�ҁF��������
//=======================================
#include	"main.h"
#include	"renderer.h"
#include	"texture.h"
#include	"sprite.h"
#include	"input.h"
#include	"scene.h"
#include	"sound.h"
#include	"BG.h"

//======================
// �O���[�o���ϐ�
//======================
static	ID3D11ShaderResourceView	*g_TitleTexture = NULL;//�e�N�X�`�����
static	char	*g_TitleTextureName = (char*)"data\\texture\\Title.png";
int		g_TitleSoundNo;
BG* p_title_bg;
Sprite* g_p1Sprite;

//�^�C�g���\����
typedef	struct
{
	D3DXVECTOR3		Position;	//�\�����W
	D3DXVECTOR2		Size;		//�T�C�Y
	D3DXCOLOR		Color;		//�F
	float			Rotate;		//�p�x
}TITLE;

TITLE	TitleObject;	//�^�C�g����ʃI�u�W�F�N�g

int		TitleTextureNo;	//�e�N�X�`���ԍ�

//==========================
// ����������
//==========================
void	InitTitle()
{
	TitleTextureNo = LoadTexture(g_TitleTextureName);				//�e�N�X�`���̃��[�h
	g_TitleSoundNo = LoadSound((char*)"data\\BGM\\sample000.wav");	//�T�E���h�̃��[�h

	if (TitleTextureNo == -1)
	{//�ǂݍ��݃G���[
		exit(999);	//�����I��
	}

	TitleObject.Position = D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);
	TitleObject.Size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	TitleObject.Color = D3DXCOLOR(1.0, 1.0, 1.0, 1.0);
	TitleObject.Rotate = 0.0;

	PlaySound(g_TitleSoundNo, -1);	//BGM�Đ�

	g_p1Sprite = new Sprite;
}

//==========================
// �I������
//==========================
void	UninitTitle()
{
	StopSound(g_TitleSoundNo);

	delete p_title_bg;
}

//======================
// �X�V����
//======================
void	UpdateTitle()
{
	//�L�[���͂̃`�F�b�N
	if (GetKeyboardTrigger(DIK_SPACE))
	{
		SetScene(SCENE::SCENE_GAME);
	}
}

//==========================
// �`�揈��
//==========================
void	DrawTitle()
{
	//�e�N�X�`���̃Z�b�g
	GetDeviceContext()->PSSetShaderResources(0, 1,
		GetTexture(TitleTextureNo));

	//�X�v���C�g�̕`��
	g_p1Sprite->DrawSpriteAnimationRotation
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



