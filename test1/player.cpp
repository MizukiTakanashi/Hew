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
#include "player.h"
#include "bullet.h"
#include "explosion.h"
#include "enemy.h"
#include "main.h"

//==============================================
// �}�N����`
//==============================================


//==============================================
// �v���g�^�C�v�錾
//==============================================



//==============================================
// �O���[�o���ϐ�
//==============================================

//�e�N�X�`�����̕ۑ��ϐ�
static	ID3D11ShaderResourceView	*g_Texture;//�摜1����1�̕ϐ����K�v
static	char	*g_TextureName = (char*)"data\\texture\\ghost.png";//�e�N�X�`���t�@�C���p�X JPG BMP PNG

PLAYER Player[PLAYER_MAX];	//�v���C���[�L�����N�^�[�\����

//�e�N�X�`���̃C���f�b�N�X
static int g_TextureNo = 0;


//==============================================
// ����������
//==============================================
HRESULT InitPlayer(void)
{
	//�e�N�X�`���̃��[�h
	g_TextureNo = LoadTexture(g_TextureName);
	if (g_TextureNo == -1)
	{	//���[�h�G���[
		exit(999);
	}


	//�v���C���[�̏�����
	for(int i = 0; i < PLAYER_MAX; i++)
	{
		Player[i].Position.x = SCREEN_WIDTH / 2;
		Player[i].Position.y = SCREEN_HEIGHT / 2;
		Player[i].Speed = D3DXVECTOR2(0, 0);
		Player[i].Size.x = PLAYER_W;
		Player[i].Size.y = PLAYER_H;

		Player[i].HP = 120;
		Player[i].DamageWait = 0;

		Player[i].Color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		Player[i].Rotation = 0.0f;

		Player[i].PaternNo = 0.0f;
		Player[i].direction = D_DOWN;

		Player[i].isUse = false;
	}
	
	
	Player[0].isUse = true;
	
	return S_OK;

}

//==============================================
// �I������
//==============================================
void UninitPlayer(void)
{
	for (int i = 0; i < PLAYER_MAX; i++)
	{
		if (Player[i].isUse)
		{

		}
	}


}


//==============================================
// �X�V����
//==============================================
void UpdatePlayer(void)
{

	for (int i = 0; i < PLAYER_MAX; i++)
	{
		if (Player[i].isUse)
		{
			//�X�s�[�h������
			Player[i].Speed = D3DXVECTOR2(0, 0);

			//�A�j���[�V����
			Player[i].PaternNo += 0.03f;
			if (Player[i].PaternNo >= 3.0f) { Player[i].PaternNo -= 3.0f; }

			
			//�L�[�{�[�h����
			//�L�[�{�[�hPress�̓���
			if (GetKeyboardPress(DIK_UP))	//��L�[
			{
				//������Ă���Ƃ��̏���
				Player[i].Speed.y = -MARIO_SPEED;
				Player[i].direction = D_UP;
			}
			if (GetKeyboardPress(DIK_DOWN))	//���L�[
			{
				//������Ă���Ƃ��̏���
				Player[i].Speed.y = +MARIO_SPEED;
				Player[i].direction = D_DOWN;
			}
			if (GetKeyboardPress(DIK_LEFT))	//���L�[
			{
				//������Ă���Ƃ��̏���
				Player[i].Speed.x = -MARIO_SPEED;
				Player[i].direction = D_LEFT;
			}
			if (GetKeyboardPress(DIK_RIGHT))	//�E�L�[
			{
				//������Ă���Ƃ��̏���
				Player[i].Speed.x = +MARIO_SPEED;
				Player[i].direction = D_RIGHT;
			}
			//if (GetKeyboardPress(DIK_Z))	//Z�L�[
			//{
			//	//������Ă���Ƃ��̏���
			//	Mario[i].Rotation += -MARIO_ROTATION_SPEED;
			//}
			//if (GetKeyboardPress(DIK_X))	//X�L�[
			//{
			//	//������Ă���Ƃ��̏���
			//	Mario[i].Rotation += +MARIO_ROTATION_SPEED;
			//}
			//�L�[�{�[�h��Trigger����
			if (GetKeyboardTrigger(DIK_UP))	//��L�[
			{
				//�������Ƃ��̏���

			}
			//�L�[�{�[�h�̃����[�X����
			if (GetKeyboardRelease(DIK_UP))	//��L�[
			{
				//�������Ƃ��̏���

			}

			//�e����
			if (GetKeyboardTrigger(DIK_Z))
			{
				SetBullet(Player[i].Position);
			}

			//�_���[�W����
			if (Player[i].DamageWait > 0)
			{
				Player[i].DamageWait--;
				//�\���F�̕ύX
				if (Player[i].DamageWait % 5 > 2)
				{
					Player[i].Color = D3DXCOLOR(1.0f, 0.4f, 0.4f, 1.0f);
				}
				else
				{
					Player[i].Color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				}
			}
			else
			{

			}

			//�v���C���[�s�k����
			if (Player[i].HP < 0)
			{
				SetScene(SCENE::SCENE_RESULT);
			}

			//���K��
			D3DXVec2Normalize(&Player[i].Speed, &Player[i].Speed);
			Player[i].Speed *= 3.0f;
			//�v���C���[�ړ�
			Player[i].Position += Player[i].Speed;
		}
	}
}



//==============================================
// �`�揈��
//==============================================
void DrawPlayer(void)
{

	// �Q�c�\�������邽�߂̃}�g���N�X��ݒ�
	SetWorldViewProjection2D();

	//�e�N�X�`���̐ݒ�
	GetDeviceContext()->PSSetShaderResources(
		0, 1, GetTexture(g_TextureNo));

	//�v���C���[�\��
	for (int i = 0; i < PLAYER_MAX; i++)
	{
		if (Player[i].isUse)
		{
			//�X�v���C�g�\��
			DrawSpriteColorRotation(
				Player[i].Position.x,
				Player[i].Position.y,
				Player[i].Size.x,
				Player[i].Size.y,
				Player[i].Rotation,
				Player[i].Color,
				Player[i].PaternNo + Player[i].direction,		//�p�^�[���ԍ�
				1.0f / PLAYER_U,			//���T�C�Y
				1.0f / PLAYER_V,			//�c�T�C�Y
				PLAYER_U		//������
			);
		}
	}

}

//==============================================
// �Q�b�^�[
//in
//out PLAYER�\���̂̐擪�|�C���^
//==============================================
PLAYER * GetPlayer(void)
{
	return Player;
}