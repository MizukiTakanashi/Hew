#include "main.h"
#include "title.h"

#include "bgtitle.h"
#include "titletext.h"

//==============================================
//マクロ定義
//=======================
//======================
//グローバル変数
//======================
int TitleSoundNo;	//ゲームサウンドインデックス


//======================
//初期化
//======================
void	InitTitle()
{
	//BGMのロード
	char filename[] = "data\\BGM\\ゆっくり急げ！.wav";
	TitleSoundNo = LoadSound(filename);

	InitBGTitle();
	InitTitletext();

	PlaySound(TitleSoundNo, -1);
	SetVolume(TitleSoundNo, 0.1);

}
//======================
//終了処理
//======================
void	UninitTitle()
{
	UninitBGTitle();
	UninitTitletext();

	StopSoundAll();
}

//======================
//更新処理
//======================
void	UpdateTitle()
{
	UpdateBGTitle();
	UpdateTitletext();




	//キー入力のチェック
	if (GetKeyboardTrigger(DIK_X))
	{
		SetScene(SCENE::SCENE_GAME);
	}

}
//======================
//描画処理
//======================
void	DrawTitle()
{
	DrawBGTitle();
	DrawTitletext();

}
