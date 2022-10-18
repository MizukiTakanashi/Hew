//==========================================================
//
//   �G�N�X�v���[�W�����Ǘ� [explosion.cpp]
//									 Author :
//									 Date   :
//==========================================================
#pragma once

#include "explosion.h"

//==========================================================
// �}�N����`
//==========================================================


//==========================================================
// �v���g�^�C�v�錾
//==========================================================



//==========================================================
// �O���[�o���ϐ�
//==========================================================
//�e�N�X�`�����̕ۑ��ϐ�
static	ID3D11ShaderResourceView	*g_Texture;//�摜1����1�̕ϐ����K�v
static	char	*g_TextureName = (char*)"data\\texture\\explosion000.png";//�e�N�X�`���t�@�C���p�X JPG BMP PNG

EXPLOSION Explosion[EXPLOSION_MAX];

//�e�N�X�`���̃C���f�b�N�X
static int g_TextureNo = 0;


//==========================================================
// ����������
//==========================================================
HRESULT InitExplosion(void)
{
	//�e�N�X�`���̃��[�h
	g_TextureNo = LoadTexture(g_TextureName);
	if (g_TextureNo == -1)
	{	//���[�h�G���[
		exit(999);
	}

	for (int i = 0; i < EXPLOSION_MAX; i++)
	{


		//�v���C���[�̏�����
		for (int i = 0; i < EXPLOSION_MAX; i++)
		{
			Explosion[i].Position.x = SCREEN_WIDTH / 2;
			Explosion[i].Position.y = SCREEN_HEIGHT / 2;

			Explosion[i].Size.x = EXPLOSION_W;
			Explosion[i].Size.y = EXPLOSION_H;

			Explosion[i].Color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

			Explosion[i].Rotation = 0.0f;

			Explosion[i].PaternNo = 0.0f;
			Explosion[i].AnimeSpeed = 0.1f;

			Explosion[i].isUse = false;

		}
	}


	return S_OK;
}

//==========================================================
// �I������
//==========================================================
void UninitExplosion(void)
{
	for (int i = 0; i < EXPLOSION_MAX; i++)
	{
		if (Explosion[i].isUse)
		{



		}
	}
}


//==========================================================
// �X�V����
//==========================================================
void UpdateExplosion(void)
{
	for (int i = 0; i < EXPLOSION_MAX; i++)
	{
		if (Explosion[i].isUse)
		{
			if (Explosion[i].PaternNo >= EXPLOSION_ANIME_MAX)
			{
				Explosion[i].isUse = false;
			}
			Explosion[i].PaternNo += Explosion[i].AnimeSpeed;


		}
	}
}


//==========================================================
// �`�揈��
//==========================================================
void DrawExplosion(void)
{
	// �Q�c�\�������邽�߂̃}�g���N�X��ݒ�
	SetWorldViewProjection2D();

	//�e�N�X�`���̐ݒ�
	GetDeviceContext()->PSSetShaderResources(
		0, 1, GetTexture(g_TextureNo));


	for (int i = 0; i < EXPLOSION_MAX; i++)
	{
		if (Explosion[i].isUse)
		{
			//�X�v���C�g�\��
			DrawSpriteColorRotation(
				Explosion[i].Position.x,
				Explosion[i].Position.y,
				Explosion[i].Size.x,
				Explosion[i].Size.y,
				Explosion[i].Rotation,
				Explosion[i].Color,
				Explosion[i].PaternNo,		//�p�^�[���ԍ�
				1.0f / EXPLOSION_U,			//���T�C�Y
				1.0f / EXPLOSION_V,			//�c�T�C�Y
				EXPLOSION_U		//������
			);

		}
	}

}

//==========================================================
// �Z�b�^�[
//in ���W
//out
//==========================================================
void SetExplosion(D3DXVECTOR2 pos, float animespeed)
{
	for (int i = 0; i < EXPLOSION_MAX; i++)
	{
		if (!Explosion[i].isUse)
		{
			Explosion[i].Position = pos;
			Explosion[i].AnimeSpeed = animespeed;

			Explosion[i].PaternNo = 0;
			Explosion[i].isUse = true;
			break;
		}
	}

}

//==========================================================
// �Q�b�^�[
//in
//out EXPLOSION�\���̂̐擪�|�C���^
//==========================================================
EXPLOSION * GetExplosion(void)
{
	return Explosion;
}
