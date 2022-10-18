//==============================================
//
//	[.cpp]
//	Author	:
//	Date	:
//==============================================

//==============================================
//インクルード
//==============================================
#include "bullet.h"

//==========================================================
// マクロ定義
//==========================================================


//==========================================================
// プロトタイプ宣言
//==========================================================



//==========================================================
// グローバル変数
//==========================================================
BULLET Bullet[BULLET_MAX];

//テクスチャ情報の保存変数
static	ID3D11ShaderResourceView	*g_Texture;//画像1枚で1つの変数が必要
static	char	*g_TextureName = (char*)"data\\texture\\tama.png";//テクスチャファイルパス JPG BMP PNG

//テクスチャのインデックス
static int g_TextureNo = 0;

//サウンドのインデックス
int BulletSoundNo;		//弾の発射音のインデックス


//==========================================================
// 初期化処理
//==========================================================
HRESULT InitBullet(void)
{
	//テクスチャのロード
	g_TextureNo = LoadTexture(g_TextureName);
	if (g_TextureNo == -1)
	{	//ロードエラー
		exit(999);
	}

	//弾の発射音のロード
	char filename[] = "data\\SE\\ショット.wav";
	BulletSoundNo = LoadSound(filename);

	//バレット初期化
	for (int i = 0; i < BULLET_MAX; i++)
	{
		Bullet[i].Position.x = SCREEN_WIDTH / 2;
		Bullet[i].Position.y = SCREEN_HEIGHT / 2;

		Bullet[i].Size.x = BOX_SIZE_W;
		Bullet[i].Size.y = BOX_SIZE_H;

		Bullet[i].Color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		Bullet[i].Move = D3DXVECTOR2(0.0f, BULLET_SPEED_X);

		Bullet[i].Rotation = 0.0f;
		Bullet[i].PaternNo = 0.0f;

		Bullet[i].isUse = false;

	}

	return S_OK;

}

//==========================================================
// 終了処理
//==========================================================
void UninitBullet(void)
{
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (Bullet[i].isUse)
		{



		}
	}
}


//==========================================================
// 更新処理
//==========================================================
void UpdateBullet(void)
{
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (Bullet[i].isUse)
		{
			//座標の更新
			Bullet[i].Position += Bullet[i].Move;

			//画面外チェック
			if (Bullet[i].Position.y < SCREEN_LIMIT_UP)
			{
				//弾の消滅
				Bullet[i].isUse = false;
			}
		}
	}
}


//==========================================================
// 描画処理
//==========================================================
void DrawBullet(void)
{
	// ２Ｄ表示をするためのマトリクスを設定
	SetWorldViewProjection2D();



	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (Bullet[i].isUse)
		{
			//テクスチャの設定
			GetDeviceContext()->PSSetShaderResources(
				0, 1, GetTexture(g_TextureNo));

			//スプライト表示
			DrawSpriteColorRotation(
				Bullet[i].Position.x,
				Bullet[i].Position.y,
				Bullet[i].Size.x,
				Bullet[i].Size.y,
				Bullet[i].Rotation,
				Bullet[i].Color,
				Bullet[i].PaternNo,		//パターン番号
				1.0f / BULLET_U,			//横サイズ
				1.0f / BULLET_V,			//縦サイズ
				BULLET_U		//横枚数
			);
		}
	}
}

//==========================================================
// セッター
//in 座標
//out
//==========================================================
void SetBullet(D3DXVECTOR2 pos)
{
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (!Bullet[i].isUse)
		{
			Bullet[i].Position = pos;

			Bullet[i].isUse = true;

			PlaySound(BulletSoundNo, 0);
			SetVolume(BulletSoundNo, 0.1);

			break;
		}
	}
}

//==========================================================
// ゲッター
//in
//out BULLET構造体の先頭ポインタ
//==========================================================
BULLET * GetBullet(void)
{
	return Bullet;
}
