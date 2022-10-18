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
#define PLAYER_MAX 5
#define	PLAYER_W	(50)	//四角形の横のサイズ
#define	PLAYER_H	(50)	//四角形の縦のサイズ

#define MARIO_SPEED 5
#define MARIO_ROTATION_SPEED 2

#define PLAYER_ANIME_MAX 1
#define PLAYER_U 3
#define PLAYER_V 4

//==============================================
// 構造体定義
//==============================================
typedef enum {
	D_UP = 9,
	D_DOWN = 0,
	D_LEFT = 3,
	D_RIGHT = 6
}DIRECTION;

//キャラクター構造体
typedef struct
{
	D3DXVECTOR2 Position;	//表示座標
	D3DXVECTOR2 Speed;	//表示座標
	D3DXCOLOR Color;		//表示色
	float Rotation;			//角度
	D3DXVECTOR2 Size;		//ポリゴンのサイズ

	int HP;
	int DamageWait;

	float PaternNo;			//パターン番号
	DIRECTION direction;	//移動方向

	bool isUse;
}PLAYER;

//==============================================
// プロトタイプ宣言
//==============================================
HRESULT InitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);

PLAYER* GetPlayer(void);	//PLAYER構造体の先頭ポインタを取得
