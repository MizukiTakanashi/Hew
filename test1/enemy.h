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
#define ENEMY_MAX 20
#define	ENEMY_W	(50)	//四角形の横のサイズ
#define	ENEMY_H	(50)	//四角形の縦のサイズ

#define ENEMY_ANIME_MAX (1)
#define ENEMY_U 1
#define ENEMY_V 1

//==============================================
// 構造体定義
//==============================================
typedef struct
{
	D3DXVECTOR2 Position;	//表示座標
	D3DXCOLOR Color;		//表示色
	float Rotation;			//角度
	D3DXVECTOR2 Size;		//ポリゴンのサイズ
	D3DXVECTOR2 Speed;

	float PaternNo;			//パターン番号

	float FrameWait;

	bool isUse;

}ENEMY;

//==============================================
// プロトタイプ宣言
//==============================================
HRESULT InitEnemy(void);
void UninitEnemy(void);
void UpdateEnemy(void);
void DrawEnemy(void);

ENEMY* GetEnemy(void);	//ENEMY構造体の先頭ポインタを取得
void SetEnemy(D3DXVECTOR2, D3DXVECTOR2, float);
