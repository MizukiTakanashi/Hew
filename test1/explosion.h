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
#define EXPLOSION_MAX 20
#define	EXPLOSION_W	(50)	//�l�p�`�̉��̃T�C�Y
#define	EXPLOSION_H	(50)	//�l�p�`�̏c�̃T�C�Y

#define EXPLOSION_ANIME_MAX (8)
#define EXPLOSION_U 8
#define EXPLOSION_V 1

//==============================================
// �\���̒�`
//==============================================
typedef struct
{
	D3DXVECTOR2 Position;	//�\�����W
	D3DXCOLOR Color;		//�\���F
	float Rotation;			//�p�x
	D3DXVECTOR2 Size;		//�|���S���̃T�C�Y

	float PaternNo;			//�p�^�[���ԍ�
	float AnimeSpeed;		//�A�j���[�V�����X�s�[�h

	bool isUse;

}EXPLOSION;

//==============================================
// �v���g�^�C�v�錾
//==============================================
HRESULT InitExplosion(void);
void UninitExplosion(void);
void UpdateExplosion(void);
void DrawExplosion(void);

EXPLOSION* GetExplosion(void);	//EXPLOSION�\���̂̐擪�|�C���^���擾
void SetExplosion(D3DXVECTOR2, float);
