//==============================================
//
//	[.h]
//	Author	:	恩田洋行
//	Date	:
//==============================================
#pragma once

//==============================================
//インクルード
//==============================================
#include "main.h"

//==============================================
//マクロ定義
//==============================================
#define EXPLOSION_MAX 20
#define	EXPLOSION_W	(50)	//四角形の横のサイズ
#define	EXPLOSION_H	(50)	//四角形の縦のサイズ

#define EXPLOSION_ANIME_MAX (8)
#define EXPLOSION_U 8
#define EXPLOSION_V 1

//==============================================
// 構造体定義
//==============================================
typedef struct
{
	D3DXVECTOR2 Position;	//表示座標
	D3DXCOLOR Color;		//表示色
	float Rotation;			//角度
	D3DXVECTOR2 Size;		//ポリゴンのサイズ

	float PaternNo;			//パターン番号
	float AnimeSpeed;		//アニメーションスピード

	bool isUse;

}EXPLOSION;

//==============================================
// プロトタイプ宣言
//==============================================
HRESULT InitExplosion(void);
void UninitExplosion(void);
void UpdateExplosion(void);
void DrawExplosion(void);

EXPLOSION* GetExplosion(void);	//EXPLOSION構造体の先頭ポインタを取得
void SetExplosion(D3DXVECTOR2, float);
