//==========================================================
//
//   エクスプロージョン管理 [explosion.cpp]
//									 Author :
//									 Date   :
//==========================================================
#pragma once

#include "explosion.h"

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
static	char	*g_TextureName = (char*)"data\\texture\\explosion000.png";//テクスチャファイルパス JPG BMP PNG

EXPLOSION Explosion[EXPLOSION_MAX];

//テクスチャのインデックス
static int g_TextureNo = 0;


//==========================================================
// 初期化処理
//==========================================================
HRESULT InitExplosion(void)
{
	//テクスチャのロード
	g_TextureNo = LoadTexture(g_TextureName);
	if (g_TextureNo == -1)
	{	//ロードエラー
		exit(999);
	}

	for (int i = 0; i < EXPLOSION_MAX; i++)
	{


		//プレイヤーの初期化
		for (int i = 0; i < EXPLOSION_MAX; i++)
		{
			Explosion[i].Position.x = SCREEN_WIDTH / 2;
			Explosion[i].Position.y = SCREEN_HEIGHT / 2;

			Explosion[i].Size.x = EXPLOSION_W;
			Explosion[i].Size.y = EXPLOSION_H;

			Explosion[i].Color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

			Explosion[i].Rotation = 0.0f;

			Explosion[i].PaternNo = 0.0f;
			Explosion[i].AnimeSpeed = 0.1f;

			Explosion[i].isUse = false;

		}
	}


	return S_OK;
}

//==========================================================
// 終了処理
//==========================================================
void UninitExplosion(void)
{
	for (int i = 0; i < EXPLOSION_MAX; i++)
	{
		if (Explosion[i].isUse)
		{



		}
	}
}


//==========================================================
// 更新処理
//==========================================================
void UpdateExplosion(void)
{
	for (int i = 0; i < EXPLOSION_MAX; i++)
	{
		if (Explosion[i].isUse)
		{
			if (Explosion[i].PaternNo >= EXPLOSION_ANIME_MAX)
			{
				Explosion[i].isUse = false;
			}
			Explosion[i].PaternNo += Explosion[i].AnimeSpeed;


		}
	}
}


//==========================================================
// 描画処理
//==========================================================
void DrawExplosion(void)
{
	// ２Ｄ表示をするためのマトリクスを設定
	SetWorldViewProjection2D();

	//テクスチャの設定
	GetDeviceContext()->PSSetShaderResources(
		0, 1, GetTexture(g_TextureNo));


	for (int i = 0; i < EXPLOSION_MAX; i++)
	{
		if (Explosion[i].isUse)
		{
			//スプライト表示
			DrawSpriteColorRotation(
				Explosion[i].Position.x,
				Explosion[i].Position.y,
				Explosion[i].Size.x,
				Explosion[i].Size.y,
				Explosion[i].Rotation,
				Explosion[i].Color,
				Explosion[i].PaternNo,		//パターン番号
				1.0f / EXPLOSION_U,			//横サイズ
				1.0f / EXPLOSION_V,			//縦サイズ
				EXPLOSION_U		//横枚数
			);

		}
	}

}

//==========================================================
// セッター
//in 座標
//out
//==========================================================
void SetExplosion(D3DXVECTOR2 pos, float animespeed)
{
	for (int i = 0; i < EXPLOSION_MAX; i++)
	{
		if (!Explosion[i].isUse)
		{
			Explosion[i].Position = pos;
			Explosion[i].AnimeSpeed = animespeed;

			Explosion[i].PaternNo = 0;
			Explosion[i].isUse = true;
			break;
		}
	}

}

//==========================================================
// ゲッター
//in
//out EXPLOSION構造体の先頭ポインタ
//==========================================================
EXPLOSION * GetExplosion(void)
{
	return Explosion;
}
