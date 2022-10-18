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
#define PLAYER_MAX 5
#define	PLAYER_W	(50)	//�l�p�`�̉��̃T�C�Y
#define	PLAYER_H	(50)	//�l�p�`�̏c�̃T�C�Y

#define MARIO_SPEED 5
#define MARIO_ROTATION_SPEED 2

#define PLAYER_ANIME_MAX 1
#define PLAYER_U 3
#define PLAYER_V 4

//==============================================
// �\���̒�`
//==============================================
typedef enum {
	D_UP = 9,
	D_DOWN = 0,
	D_LEFT = 3,
	D_RIGHT = 6
}DIRECTION;

//�L�����N�^�[�\����
typedef struct
{
	D3DXVECTOR2 Position;	//�\�����W
	D3DXVECTOR2 Speed;	//�\�����W
	D3DXCOLOR Color;		//�\���F
	float Rotation;			//�p�x
	D3DXVECTOR2 Size;		//�|���S���̃T�C�Y

	int HP;
	int DamageWait;

	float PaternNo;			//�p�^�[���ԍ�
	DIRECTION direction;	//�ړ�����

	bool isUse;
}PLAYER;

//==============================================
// �v���g�^�C�v�錾
//==============================================
HRESULT InitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);

PLAYER* GetPlayer(void);	//PLAYER�\���̂̐擪�|�C���^���擾
