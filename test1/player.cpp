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
#include "player.h"
#include "bullet.h"
#include "explosion.h"
#include "enemy.h"
#include "main.h"

//==============================================
// マクロ定義
//==============================================


//==============================================
// プロトタイプ宣言
//==============================================



//==============================================
// グローバル変数
//==============================================

//テクスチャ情報の保存変数
static	ID3D11ShaderResourceView	*g_Texture;//画像1枚で1つの変数が必要
static	char	*g_TextureName = (char*)"data\\texture\\ghost.png";//テクスチャファイルパス JPG BMP PNG

PLAYER Player[PLAYER_MAX];	//プレイヤーキャラクター構造体

//テクスチャのインデックス
static int g_TextureNo = 0;


//==============================================
// 初期化処理
//==============================================
HRESULT InitPlayer(void)
{
	//テクスチャのロード
	g_TextureNo = LoadTexture(g_TextureName);
	if (g_TextureNo == -1)
	{	//ロードエラー
		exit(999);
	}


	//プレイヤーの初期化
	for(int i = 0; i < PLAYER_MAX; i++)
	{
		Player[i].Position.x = SCREEN_WIDTH / 2;
		Player[i].Position.y = SCREEN_HEIGHT / 2;
		Player[i].Speed = D3DXVECTOR2(0, 0);
		Player[i].Size.x = PLAYER_W;
		Player[i].Size.y = PLAYER_H;

		Player[i].HP = 120;
		Player[i].DamageWait = 0;

		Player[i].Color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		Player[i].Rotation = 0.0f;

		Player[i].PaternNo = 0.0f;
		Player[i].direction = D_DOWN;

		Player[i].isUse = false;
	}
	
	
	Player[0].isUse = true;
	
	return S_OK;

}

//==============================================
// 終了処理
//==============================================
void UninitPlayer(void)
{
	for (int i = 0; i < PLAYER_MAX; i++)
	{
		if (Player[i].isUse)
		{

		}
	}


}


//==============================================
// 更新処理
//==============================================
void UpdatePlayer(void)
{

	for (int i = 0; i < PLAYER_MAX; i++)
	{
		if (Player[i].isUse)
		{
			//スピード初期化
			Player[i].Speed = D3DXVECTOR2(0, 0);

			//アニメーション
			Player[i].PaternNo += 0.03f;
			if (Player[i].PaternNo >= 3.0f) { Player[i].PaternNo -= 3.0f; }

			
			//キーボード入力
			//キーボードPressの入力
			if (GetKeyboardPress(DIK_UP))	//上キー
			{
				//押されているときの処理
				Player[i].Speed.y = -MARIO_SPEED;
				Player[i].direction = D_UP;
			}
			if (GetKeyboardPress(DIK_DOWN))	//下キー
			{
				//押されているときの処理
				Player[i].Speed.y = +MARIO_SPEED;
				Player[i].direction = D_DOWN;
			}
			if (GetKeyboardPress(DIK_LEFT))	//左キー
			{
				//押されているときの処理
				Player[i].Speed.x = -MARIO_SPEED;
				Player[i].direction = D_LEFT;
			}
			if (GetKeyboardPress(DIK_RIGHT))	//右キー
			{
				//押されているときの処理
				Player[i].Speed.x = +MARIO_SPEED;
				Player[i].direction = D_RIGHT;
			}
			//if (GetKeyboardPress(DIK_Z))	//Zキー
			//{
			//	//押されているときの処理
			//	Mario[i].Rotation += -MARIO_ROTATION_SPEED;
			//}
			//if (GetKeyboardPress(DIK_X))	//Xキー
			//{
			//	//押されているときの処理
			//	Mario[i].Rotation += +MARIO_ROTATION_SPEED;
			//}
			//キーボードのTrigger入力
			if (GetKeyboardTrigger(DIK_UP))	//上キー
			{
				//押したときの処理

			}
			//キーボードのリリース入力
			if (GetKeyboardRelease(DIK_UP))	//上キー
			{
				//離したときの処理

			}

			//弾発射
			if (GetKeyboardTrigger(DIK_Z))
			{
				SetBullet(Player[i].Position);
			}

			//ダメージ処理
			if (Player[i].DamageWait > 0)
			{
				Player[i].DamageWait--;
				//表示色の変更
				if (Player[i].DamageWait % 5 > 2)
				{
					Player[i].Color = D3DXCOLOR(1.0f, 0.4f, 0.4f, 1.0f);
				}
				else
				{
					Player[i].Color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				}
			}
			else
			{

			}

			//プレイヤー敗北処理
			if (Player[i].HP < 0)
			{
				SetScene(SCENE::SCENE_RESULT);
			}

			//正規化
			D3DXVec2Normalize(&Player[i].Speed, &Player[i].Speed);
			Player[i].Speed *= 3.0f;
			//プレイヤー移動
			Player[i].Position += Player[i].Speed;
		}
	}
}



//==============================================
// 描画処理
//==============================================
void DrawPlayer(void)
{

	// ２Ｄ表示をするためのマトリクスを設定
	SetWorldViewProjection2D();

	//テクスチャの設定
	GetDeviceContext()->PSSetShaderResources(
		0, 1, GetTexture(g_TextureNo));

	//プレイヤー表示
	for (int i = 0; i < PLAYER_MAX; i++)
	{
		if (Player[i].isUse)
		{
			//スプライト表示
			DrawSpriteColorRotation(
				Player[i].Position.x,
				Player[i].Position.y,
				Player[i].Size.x,
				Player[i].Size.y,
				Player[i].Rotation,
				Player[i].Color,
				Player[i].PaternNo + Player[i].direction,		//パターン番号
				1.0f / PLAYER_U,			//横サイズ
				1.0f / PLAYER_V,			//縦サイズ
				PLAYER_U		//横枚数
			);
		}
	}

}

//==============================================
// ゲッター
//in
//out PLAYER構造体の先頭ポインタ
//==============================================
PLAYER * GetPlayer(void)
{
	return Player;
}