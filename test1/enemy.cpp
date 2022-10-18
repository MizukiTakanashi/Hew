//==========================================================
//
//   �G�l�~�[�Ǘ� [enemy.cpp]
//									 Author :
//									 Date   :
//==========================================================
#pragma once

#include "main.h"
#include "enemy.h"
#include "player.h"

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
static	char	*g_TextureName = (char*)"data\\texture\\yuurei.png";//�e�N�X�`���t�@�C���p�X JPG BMP PNG


int interval;

ENEMY Enemy[ENEMY_MAX];

//�e�N�X�`���̃C���f�b�N�X
static int g_TextureNo = 0;


int GetRandom(int min, int max);
//==========================================================
// ����������
//==========================================================
HRESULT InitEnemy(void)
{
	//�e�N�X�`���̃��[�h
	g_TextureNo = LoadTexture(g_TextureName);
	if (g_TextureNo == -1)
	{	//���[�h�G���[
		exit(999);
	}

	for (int i = 0; i < ENEMY_MAX; i++)
	{


		//�v���C���[�̏�����
		for (int i = 0; i < ENEMY_MAX; i++)
		{
			Enemy[i].Position.x = SCREEN_WIDTH / 2;
			Enemy[i].Position.y = SCREEN_HEIGHT / 2;

			Enemy[i].Size.x = ENEMY_W;
			Enemy[i].Size.y = ENEMY_H;

			Enemy[i].Color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

			Enemy[i].Rotation = 0.0f;

			Enemy[i].PaternNo = 0.0f;
			Enemy[i].FrameWait = 0;

			Enemy[i].isUse = false;

		}
	}

	//SetEnemy(D3DXVECTOR2(100, -100), D3DXVECTOR2(0, 2), 60 * 0);
	//SetEnemy(D3DXVECTOR2(200, -100), D3DXVECTOR2(0, 2), 60 * 0);
	//SetEnemy(D3DXVECTOR2(400, -100), D3DXVECTOR2(0, 2), 60 * 2);
	//SetEnemy(D3DXVECTOR2(600, -100), D3DXVECTOR2(0, 2), 60 * 4);
	//SetEnemy(D3DXVECTOR2(800, -100), D3DXVECTOR2(0, 2), 60 * 6);
	
	interval = 60;
	return S_OK;
}

//==========================================================
// �I������
//==========================================================
void UninitEnemy(void)
{

	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (Enemy[i].isUse)
		{



		}
	}
}


//==========================================================
// �X�V����
//==========================================================
void UpdateEnemy(void)
{
	interval--;
	if (interval < 0)
	{
		//�G�l�~�[�̔���
		interval = 30;
		SetEnemy(D3DXVECTOR2(GetRandom(100, 900) , -100), D3DXVECTOR2(0, GetRandom(1, 5)), 60 * 0);
	}

	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (Enemy[i].isUse)
		{

			if (Enemy[i].FrameWait == 0)
			{
				//�G�̃A�b�v�f�[�g����

				D3DXVECTOR2 temp;
				PLAYER *player = GetPlayer();
				temp = player->Position - Enemy[i].Position;
				D3DXVec2Normalize(&temp, &temp);
				temp *= 1.5f;
				Enemy[i].Speed = temp;

				Enemy[i].Position += Enemy[i].Speed;


				if (Enemy[i].Position.y > SCREEN_HEIGHT + 100)
				{
					Enemy[i].isUse = FALSE;
				}
			}
			else
			{
				Enemy[i].FrameWait--;
			}

		}
	}
}


//==========================================================
// �`�揈��
//==========================================================
void DrawEnemy(void)
{
	// �Q�c�\�������邽�߂̃}�g���N�X��ݒ�
	SetWorldViewProjection2D();

	//�e�N�X�`���̐ݒ�
	GetDeviceContext()->PSSetShaderResources(
		0, 1, GetTexture(g_TextureNo));


	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (Enemy[i].isUse && Enemy[i].FrameWait ==0)
		{
			//SetBlendState(BLEND_MODE_ADD);		//BlendMode�؂�ւ�
			//�X�v���C�g�\��
			DrawSpriteColorRotation(
				Enemy[i].Position.x,
				Enemy[i].Position.y,
				Enemy[i].Size.x,
				Enemy[i].Size.y,
				Enemy[i].Rotation,
				Enemy[i].Color,
				Enemy[i].PaternNo,		//�p�^�[���ԍ�
				1.0f / ENEMY_U,			//���T�C�Y
				1.0f / ENEMY_V,			//�c�T�C�Y
				ENEMY_U		//������
			);
			//SetBlendState(BLEND_MODE_ALPHABLEND);	//BlendMode�؂�ւ�
		}
	}

}

//==========================================================
// �Z�b�^�[
//in ���W
//out
//==========================================================
void SetEnemy(D3DXVECTOR2 pos,D3DXVECTOR2 sp, float wait)
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (!Enemy[i].isUse)
		{
			Enemy[i].Position = pos;
			Enemy[i].Speed = sp;

			Enemy[i].isUse = true;
			Enemy[i].FrameWait = wait;
			break;
		}
	}

}

//==========================================================
// �Q�b�^�[
//in
//out ENEMY�\���̂̐擪�|�C���^
//==========================================================
ENEMY * GetEnemy(void)
{
	return Enemy;
}


int GetRandom(int min, int max)
{
	return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}