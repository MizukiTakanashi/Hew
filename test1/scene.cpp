
#include	"scene.h"
#include	"main.h"
#include	"renderer.h"

#include	"Game.h"
#include	"Title.h"
#include	"result.h"


//===========================
//マクロ定義
//===========================
//===========================
//グローバル変数
//===========================
static	SCENE	g_SceneIndex = SCENE::SCENE_NONE;//現在実行中のシーン番号

static	SCENE	g_SceneNextIndex = g_SceneIndex;

int score;

//==================
//初期化
//
//in  初期化するシーン番号
//==================
void	InitScene(SCENE no)
{
	g_SceneIndex = g_SceneNextIndex = no;//内容を合わせる

	switch (g_SceneIndex)
	{
		case	SCENE::SCENE_NONE:	//何もしない
			break;
		case	SCENE::SCENE_TITLE:	//タイトル画面
			InitTitle();
			break;
		case	SCENE::SCENE_GAME:	//ゲーム
			InitGame();
			break;
		case	SCENE::SCENE_RESULT://リザルト画面
			InitResult();
			break;
	}

}
//==================
//終了処理
//==================
void	UninitScene()
{
	switch (g_SceneIndex)
	{
		case	SCENE::SCENE_NONE:	//何もしない
			break;
		case	SCENE::SCENE_TITLE:	//タイトル画面
			UninitTitle();
			break;
		case	SCENE::SCENE_GAME:	//ゲーム
			UninitGame();
			break;
		case	SCENE::SCENE_RESULT://リザルト画面
			UninitResult();
			break;
	}


}
//==================
//更新処理
//==================
void	UpdateScene()
{
	switch (g_SceneIndex)
	{
		case	SCENE::SCENE_NONE:	//何もしない
			break;
		case	SCENE::SCENE_TITLE:	//タイトル画面
			UpdateTitle();
			break;
		case	SCENE::SCENE_GAME:	//ゲーム
			UpdateGame();
			break;
		case	SCENE::SCENE_RESULT://リザルト画面
			UpdateResult();
			break;
	}

}
//==================
//描画処理
//==================
void	DrawScene()
{
	switch (g_SceneIndex)
	{
		case	SCENE::SCENE_NONE:	//何もしない
			break;
		case	SCENE::SCENE_TITLE:	//タイトル画面
			DrawTitle();
			break;
		case	SCENE::SCENE_GAME:	//ゲーム
			DrawGame();
			break;
		case	SCENE::SCENE_RESULT://リザルト画面
			DrawResult();
			break;
	}
}

//新しいシーンをセットしてリクエストする
void	SetScene(SCENE no)
{
	g_SceneNextIndex = no;	//次のシーン番号
}

//シーン切り替えのリクエストをチェックする
void	CheckScene()
{
	if (g_SceneIndex != g_SceneNextIndex)//次のシーンが現在のシーンと違う
	{
		UninitScene();	//現在のシーンを終了させる

		InitScene(g_SceneNextIndex);//次のシーンを初期化する
	}


}
