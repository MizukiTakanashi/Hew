//==========================================================
//
//   エネミー管理 [enemy.cpp]
//									 Author :
//									 Date   :
//==========================================================
#pragma once

#include "main.h"
#include "enemy.h"
#include "player.h"

//==========================================================
// マクロ定義
//==========================================================


//==========================================================
// プロトタイプ宣言
//==========================================================



//==========================================================
// グローバル変数
//==========================================================
//テクスチャ情報の保存変数
static	ID3D11ShaderResourceView	*g_Texture;//画像1枚で1つの変数が必要
static	char	*g_TextureName = (char*)"data\\texture\\yuurei.png";//テクスチャファイルパス JPG BMP PNG


int interval;

ENEMY Enemy[ENEMY_MAX];

//テクスチャのインデックス
static int g_TextureNo = 0;


int GetRandom(int min, int max);
//==========================================================
// 初期化処理
//==========================================================
HRESULT InitEnemy(void)
{
	//テクスチャのロード
	g_TextureNo = LoadTexture(g_TextureName);
	if (g_TextureNo == -1)
	{	//ロードエラー
		exit(999);
	}

	for (int i = 0; i < ENEMY_MAX; i++)
	{


		//プレイヤーの初期化
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
// 終了処理
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
// 更新処理
//==========================================================
void UpdateEnemy(void)
{
	interval--;
	if (interval < 0)
	{
		//エネミーの発生
		interval = 30;
		SetEnemy(D3DXVECTOR2(GetRandom(100, 900) , -100), D3DXVECTOR2(0, GetRandom(1, 5)), 60 * 0);
	}

	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (Enemy[i].isUse)
		{

			if (Enemy[i].FrameWait == 0)
			{
				//敵のアップデート処理

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
// 描画処理
//==========================================================
void DrawEnemy(void)
{
	// ２Ｄ表示をするためのマトリクスを設定
	SetWorldViewProjection2D();

	//テクスチャの設定
	GetDeviceContext()->PSSetShaderResources(
		0, 1, GetTexture(g_TextureNo));


	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (Enemy[i].isUse && Enemy[i].FrameWait ==0)
		{
			//SetBlendState(BLEND_MODE_ADD);		//BlendMode切り替え
			//スプライト表示
			DrawSpriteColorRotation(
				Enemy[i].Position.x,
				Enemy[i].Position.y,
				Enemy[i].Size.x,
				Enemy[i].Size.y,
				Enemy[i].Rotation,
				Enemy[i].Color,
				Enemy[i].PaternNo,		//パターン番号
				1.0f / ENEMY_U,			//横サイズ
				1.0f / ENEMY_V,			//縦サイズ
				ENEMY_U		//横枚数
			);
			//SetBlendState(BLEND_MODE_ALPHABLEND);	//BlendMode切り替え
		}
	}

}

//==========================================================
// セッター
//in 座標
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
// ゲッター
//in
//out ENEMY構造体の先頭ポインタ
//==========================================================
ENEMY * GetEnemy(void)
{
	return Enemy;
}


int GetRandom(int min, int max)
{
	return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}