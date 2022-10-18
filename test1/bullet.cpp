//==============================================
//
//	[.cpp]
//	Author	:
//	Date	:
//==============================================

//==============================================
//�C���N���[�h
//==============================================
#include "bullet.h"

//==========================================================
// �}�N����`
//==========================================================


//==========================================================
// �v���g�^�C�v�錾
//==========================================================



//==========================================================
// �O���[�o���ϐ�
//==========================================================
BULLET Bullet[BULLET_MAX];

//�e�N�X�`�����̕ۑ��ϐ�
static	ID3D11ShaderResourceView	*g_Texture;//�摜1����1�̕ϐ����K�v
static	char	*g_TextureName = (char*)"data\\texture\\tama.png";//�e�N�X�`���t�@�C���p�X JPG BMP PNG

//�e�N�X�`���̃C���f�b�N�X
static int g_TextureNo = 0;

//�T�E���h�̃C���f�b�N�X
int BulletSoundNo;		//�e�̔��ˉ��̃C���f�b�N�X


//==========================================================
// ����������
//==========================================================
HRESULT InitBullet(void)
{
	//�e�N�X�`���̃��[�h
	g_TextureNo = LoadTexture(g_TextureName);
	if (g_TextureNo == -1)
	{	//���[�h�G���[
		exit(999);
	}

	//�e�̔��ˉ��̃��[�h
	char filename[] = "data\\SE\\�V���b�g.wav";
	BulletSoundNo = LoadSound(filename);

	//�o���b�g������
	for (int i = 0; i < BULLET_MAX; i++)
	{
		Bullet[i].Position.x = SCREEN_WIDTH / 2;
		Bullet[i].Position.y = SCREEN_HEIGHT / 2;

		Bullet[i].Size.x = BOX_SIZE_W;
		Bullet[i].Size.y = BOX_SIZE_H;

		Bullet[i].Color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		Bullet[i].Move = D3DXVECTOR2(0.0f, BULLET_SPEED_X);

		Bullet[i].Rotation = 0.0f;
		Bullet[i].PaternNo = 0.0f;

		Bullet[i].isUse = false;

	}

	return S_OK;

}

//==========================================================
// �I������
//==========================================================
void UninitBullet(void)
{
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (Bullet[i].isUse)
		{



		}
	}
}


//==========================================================
// �X�V����
//==========================================================
void UpdateBullet(void)
{
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (Bullet[i].isUse)
		{
			//���W�̍X�V
			Bullet[i].Position += Bullet[i].Move;

			//��ʊO�`�F�b�N
			if (Bullet[i].Position.y < SCREEN_LIMIT_UP)
			{
				//�e�̏���
				Bullet[i].isUse = false;
			}
		}
	}
}


//==========================================================
// �`�揈��
//==========================================================
void DrawBullet(void)
{
	// �Q�c�\�������邽�߂̃}�g���N�X��ݒ�
	SetWorldViewProjection2D();



	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (Bullet[i].isUse)
		{
			//�e�N�X�`���̐ݒ�
			GetDeviceContext()->PSSetShaderResources(
				0, 1, GetTexture(g_TextureNo));

			//�X�v���C�g�\��
			DrawSpriteColorRotation(
				Bullet[i].Position.x,
				Bullet[i].Position.y,
				Bullet[i].Size.x,
				Bullet[i].Size.y,
				Bullet[i].Rotation,
				Bullet[i].Color,
				Bullet[i].PaternNo,		//�p�^�[���ԍ�
				1.0f / BULLET_U,			//���T�C�Y
				1.0f / BULLET_V,			//�c�T�C�Y
				BULLET_U		//������
			);
		}
	}
}

//==========================================================
// �Z�b�^�[
//in ���W
//out
//==========================================================
void SetBullet(D3DXVECTOR2 pos)
{
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (!Bullet[i].isUse)
		{
			Bullet[i].Position = pos;

			Bullet[i].isUse = true;

			PlaySound(BulletSoundNo, 0);
			SetVolume(BulletSoundNo, 0.1);

			break;
		}
	}
}

//==========================================================
// �Q�b�^�[
//in
//out BULLET�\���̂̐擪�|�C���^
//==========================================================
BULLET * GetBullet(void)
{
	return Bullet;
}
