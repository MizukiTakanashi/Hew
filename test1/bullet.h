//==============================================
//
//	[.h]
//	Author	:	恩田洋行
//	Date	:
//==============================================
#pragma once

//==============================================
//	インクルード
//==============================================
#include "main.h"

//==============================================
//	マクロ定義
//==============================================
#define BULLET_MAX (20)
#define	BOX_SIZE_W	(30)	//四角形の横のサイズ
#define	BOX_SIZE_H	(30)	//四角形の縦のサイズ
#define BULLET_SPEED_X (-10)

#define BULLET_ANIME_MAX 1
#define BULLET_U 1
#define BULLET_V 1

//==============================================
//	構造体定義
//==============================================
typedef struct
{
	D3DXVECTOR2 Position;	//表示座標
	D3DXCOLOR Color;		//表示色
	float Rotation;			//角度
	D3DXVECTOR2 Size;		//ポリゴンのサイズ
	D3DXVECTOR2 Move;

	float PaternNo;			//パターン番号

	bool isUse;

}BULLET;

//==============================================
//	プロトタイプ宣言
//==============================================
HRESULT InitBullet(void);
void UninitBullet(void);
void UpdateBullet(void);
void DrawBullet(void);

BULLET* GetBullet(void);	//BULLET構造体の先頭ポインタを取得
void SetBullet(D3DXVECTOR2 pos);	//弾発生
