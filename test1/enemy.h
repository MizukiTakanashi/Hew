//==============================================
//
//	[.h]
//	Author	:	���c�m�s
//	Date	:
//==============================================
#pragma once

//==============================================
//�C���N���[�h
//==============================================
#include "main.h"

//==============================================
//�}�N����`
//==============================================
#define ENEMY_MAX 20
#define	ENEMY_W	(50)	//�l�p�`�̉��̃T�C�Y
#define	ENEMY_H	(50)	//�l�p�`�̏c�̃T�C�Y

#define ENEMY_ANIME_MAX (1)
#define ENEMY_U 1
#define ENEMY_V 1

//==============================================
// �\���̒�`
//==============================================
typedef struct
{
	D3DXVECTOR2 Position;	//�\�����W
	D3DXCOLOR Color;		//�\���F
	float Rotation;			//�p�x
	D3DXVECTOR2 Size;		//�|���S���̃T�C�Y
	D3DXVECTOR2 Speed;

	float PaternNo;			//�p�^�[���ԍ�

	float FrameWait;

	bool isUse;

}ENEMY;

//==============================================
// �v���g�^�C�v�錾
//==============================================
HRESULT InitEnemy(void);
void UninitEnemy(void);
void UpdateEnemy(void);
void DrawEnemy(void);

ENEMY* GetEnemy(void);	//ENEMY�\���̂̐擪�|�C���^���擾
void SetEnemy(D3DXVECTOR2, D3DXVECTOR2, float);
