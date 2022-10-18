//==============================================
//
//	[.cpp]
//	Author	:
//	Date	:
//==============================================

//==============================================
//インクルード
//==============================================
#include "main.h"
#include "game.h"

#include "player.h"
#include "explosion.h"
#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "bggame.h"

//==============================================
//マクロ定義
//==============================================

//==============================================
//グローバル変数
//==============================================
int GameSoundNo;	//ゲームサウンドインデックス

//==============================================
//初期化
//==============================================
void InitGame()
{
	//BGMのロード
	char filename[] = "data\\BGM\\Do you have any evidence.wav";
	GameSoundNo = LoadSound(filename);

	InitBgGame();

	InitPlayer();
	InitEnemy();
	InitBullet();
	InitExplosion();


	PlaySound(GameSoundNo, -1);
	SetVolume(GameSoundNo, 0.1);

}

//==============================================
//終了処理
//==============================================
void UninitGame()
{
	UninitBgGame();

	UninitPlayer();
	UninitEnemy();
	UninitBullet();
	UninitExplosion();

	StopSoundAll();
}

//==============================================
//更新処理
//==============================================
void UpdateGame()
{
	UpdateBgGame();

	UpdatePlayer();
	UpdateEnemy();
	UpdateBullet();
	UpdateCollision();
	UpdateExplosion();

}

//==============================================
//描画処理
//==============================================
void DrawGame()
{
	DrawBgGame();

	DrawExplosion();
	DrawPlayer();
	DrawEnemy();
	DrawBullet();
}
