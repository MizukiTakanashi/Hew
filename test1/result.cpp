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
#include "result.h"

#include "bgresult.h"
#include "resulttext.h"


//==============================================
//マクロ定義
//==============================================
//==============================================
//グローバル変数
//==============================================
int ResultSoundNo;	//ゲームサウンドインデックス


//==============================================
//初期化
//==============================================
void	InitResult()
{
	//BGMのロード
	char filename[] = "data\\BGM\\追跡者.wav";
	ResultSoundNo = LoadSound(filename);

	InitBGResult();
	InitResulttext();


	PlaySound(ResultSoundNo, -1);
	SetVolume(ResultSoundNo, 0.1);

}

//==============================================
//終了処理
//==============================================
void	UninitResult()
{
	UninitBGResult();
	UninitResulttext();


	StopSoundAll();
}

//==============================================
//更新処理
//==============================================
void	UpdateResult()
{
	UpdateBGResult();
	UpdateResulttext();

	//キー入力のチェック
	if (GetKeyboardTrigger(DIK_X))
	{
		SetScene(SCENE::SCENE_TITLE);
	}


}
//==============================================
//描画処理
//==============================================
void	DrawResult()
{
	DrawBGResult();
	DrawResulttext();

}
