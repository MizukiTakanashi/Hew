//==============================================
//
//	[.h]
//	Author	:	���c�m�s
//	Date	:
//==============================================
#pragma once

//==============================================
//	�C���N���[�h
//==============================================
#include "main.h"

//==============================================
//	�}�N����`
//==============================================
#define BULLET_MAX (20)
#define	BOX_SIZE_W	(30)	//�l�p�`�̉��̃T�C�Y
#define	BOX_SIZE_H	(30)	//�l�p�`�̏c�̃T�C�Y
#define BULLET_SPEED_X (-10)

#define BULLET_ANIME_MAX 1
#define BULLET_U 1
#define BULLET_V 1

//==============================================
//	�\���̒�`
//==============================================
typedef struct
{
	D3DXVECTOR2 Position;	//�\�����W
	D3DXCOLOR Color;		//�\���F
	float Rotation;			//�p�x
	D3DXVECTOR2 Size;		//�|���S���̃T�C�Y
	D3DXVECTOR2 Move;

	float PaternNo;			//�p�^�[���ԍ�

	bool isUse;

}BULLET;

//==============================================
//	�v���g�^�C�v�錾
//==============================================
HRESULT InitBullet(void);
void UninitBullet(void);
void UpdateBullet(void);
void DrawBullet(void);

BULLET* GetBullet(void);	//BULLET�\���̂̐擪�|�C���^���擾
void SetBullet(D3DXVECTOR2 pos);	//�e����
