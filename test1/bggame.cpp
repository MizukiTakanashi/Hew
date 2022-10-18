//==============================================
//
//	[.cpp]
//	Author	:
//	Date	:
//==============================================
#pragma once

//==============================================
//インクルード
//==============================================
#include "bggame.h"

//==============================================
// マクロ定義
//==============================================


//==============================================
// グローバル変数
//==============================================
//テクスチャ情報の保存変数
static	ID3D11ShaderResourceView	*g_TextureBG;//画像1枚で1つの変数が必要
static	char	*g_TextureNameBG = (char*)"data\\texture\\bggame.png";//テクスチャファイルパス JPG BMP PNG

//テクスチャのインデックス
static int g_TextureNoBG = 0;

BG* Sample;	//背景構造体

//==============================================
// 初期化処理
//==============================================
HRESULT InitBgGame(void)
{

	//テクスチャのロード
	g_TextureNoBG = LoadTexture(g_TextureNameBG);
	if (g_TextureNoBG == -1)
	{	//ロードエラー
		exit(999);
	}

	//背景の初期化
	{
		Sample = new BG;	//背景のインスタンス作成
		Sample->Position.x = SCREEN_WIDTH / 2;
		Sample->Position.y = SCREEN_HEIGHT / 2;
		Sample->Position.z = 0.0f;

		Sample->Size.x = SCREEN_WIDTH;
		Sample->Size.y = SCREEN_HEIGHT;

		Sample->Color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		Sample->Rotation = 0.0f;

		Sample->PaternNo = 0.0f;
		Sample->u = 1.0f;
		Sample->v = 1.0f;
		Sample->NumPatern = 1;
	}



	return S_OK;

}

//==============================================
// 終了処理
//==============================================
void UninitBgGame(void)
{

	if (Sample)
	{
		delete Sample;
	}

}


//==============================================
// 更新処理
//==============================================
void UpdateBgGame(void)
{


}


//==============================================
// 描画処理
//==============================================
void DrawBgGame(void)
{

	// ２Ｄ表示をするためのマトリクスを設定
	SetWorldViewProjection2D();

	//背景の表示
	{
		//テクスチャの設定
		GetDeviceContext()->PSSetShaderResources(
			0, 1, GetTexture(g_TextureNoBG));

		DrawSpriteColorRotation(
			Sample->Position.x,
			Sample->Position.y,
			Sample->Size.x,
			Sample->Size.y,
			Sample->Rotation,
			Sample->Color,
			Sample->PaternNo,		//パターン番号
			Sample->u,				//横サイズf
			Sample->v,				//縦サイズf
			Sample->NumPatern		//横枚数
		);

	}


}
