//=======================================
// シーン関係(cppファイル)
// 作成日：2022/07/14
// 作成者：高梨水希
//=======================================
#include "scene.h"
#include "game.h"
#include "Title.h"
#include "texture_useful.h"
#include "sprite.h"
#include "game.h"
#include "result.h"
#include "score.h"
#include "draw_object.h"
#include "stage_select.h"
#include "stage_mercury.h"
#include "stage_mars.h"
#include "stage_saturn.h"
#include "title_score.h"

//======================
// グローバル変数
//======================
SCENE g_scene;			//現在のシーン
SCENE g_scene_next;		//次のシーン

StageSelect* pStageSelect = nullptr;	//ステージ選択画面
TitleScore* pTitleScore = nullptr;		//最高スコア表示画面
Game* pGame = nullptr;					//ゲーム画面
Result* pResult = nullptr;				//リザルト画面

StageMercury* pMercury = nullptr;		//水星ステージ
StageMars* pMars = nullptr;				//火星ステージ
StageSaturn* pSaturn = nullptr;

TextureUseful* g_pTexUseful;
DrawObject* g_pDrawObject;
Score* g_pNumber;

int g_Score[STAGE_NUM];		//スコア保持用

//==========================
// 初期化処理
//==========================
void InitScene(SCENE s)
{
	g_scene = s;
	g_scene_next = s;

	switch (g_scene){

	case SCENE::SCENE_NONE:
		break;

	case SCENE::SCENE_TITLE:
		InitTitle();
		break;

	case SCENE::SCENE_TITLE_SCORE:
		pTitleScore = new TitleScore(g_Score);
		break;

	case SCENE::SCENE_STAGE_SELECT:
		pStageSelect = new StageSelect(g_Score);
		break;

	case SCENE::SCENE_GAME:
		pGame = new Game(g_pNumber = new Score(g_pDrawObject[0]));
		break;

	case SCENE::SCENE_MERCURY:
		pMercury = new StageMercury(new Score(g_pDrawObject[0]));
		break;

	case SCENE::SCENE_VENUS:
		break;

	case SCENE::SCENE_MARS:
		pMars = new StageMars(new Score(g_pDrawObject[0]));
		break;

	case SCENE::SCENE_JUPITER:
		break;

	case SCENE::SCENE_SATURN:
		pSaturn = new StageSaturn(new Score(g_pDrawObject[0]));
		break;

	case SCENE::SCENE_SUN:
		break;

	case SCENE::SCENE_RESULT:
		pResult = new Result(true, g_pNumber, STAGE::STAGE_MOON);
		break;

	default:
		break;
	}
}

//==========================
// 初期化処理
//==========================
void InitScene2(SCENE s)
{
	//テクスチャ
	g_pTexUseful = new TextureUseful[10];
	g_pDrawObject = new DrawObject[10];

	//数字
	g_pTexUseful[0].SetTextureName((char*)"data\\texture\\number.png");
	g_pDrawObject[0].SetDrawObject(g_pTexUseful[0], 0.0f, 0.0909f, 1.0f, 11);
	g_pNumber = new Score(g_pDrawObject[0]);

	//スコアを初期化
	for (int i = 0; i < STAGE_NUM; i++) {
		g_Score[i] = 0;
	}

	InitScene(s);
}

//==========================
// 終了処理
//==========================
void UninitScene(void)
{
	switch (g_scene) {

	case SCENE::SCENE_NONE:
		break;

	case SCENE::SCENE_TITLE:
		UninitTitle();
		break;

	case SCENE::SCENE_TITLE_SCORE:
		delete pTitleScore;
		break;

	case SCENE::SCENE_STAGE_SELECT:
		delete pStageSelect;
		break;

	case SCENE::SCENE_GAME:
		//前のスコアよりも超えそうであれば...
		if (pGame->GetScore() > g_Score[STAGE_MOON]) {
			//スコアを更新
			g_Score[STAGE_MOON] = pGame->GetScore();
		}
		delete pGame;
		break;

	case SCENE::SCENE_MERCURY:
		//前のスコアよりも超えそうであれば...
		if (pMercury->GetScore() > g_Score[STAGE_MERCURY]) {
			//スコアを更新
			g_Score[STAGE_MERCURY] = pMercury->GetScore();
		}
		delete pMercury;
		break;

	case SCENE::SCENE_VENUS:
		break;

	case SCENE::SCENE_MARS:
		//前のスコアよりも超えそうであれば...
		if (pMars->GetScore() > g_Score[STAGE_MARS]) {
			//スコアを更新
			g_Score[STAGE_MARS] = pMars->GetScore();
		}
		delete pMars;
		break;

	case SCENE::SCENE_JUPITER:
		break;

	case SCENE::SCENE_SATURN:
		//前のスコアよりも超えそうであれば...
		if (pSaturn->GetScore() > g_Score[STAGE_SATURN]) {
			//スコアを更新
			g_Score[STAGE_SATURN] = pSaturn->GetScore();
		}
		delete pSaturn;
		break;

	case SCENE::SCENE_SUN:
		break;

	case SCENE::SCENE_RESULT:
		delete pResult;
		break;

	default:
		break;
	}
}

//==========================
// 終了処理
//==========================
void UninitScene2(void)
{
	delete[] g_pTexUseful;
	delete[] g_pDrawObject;
	delete g_pNumber;
}

//======================
// 更新処理
//======================
void UpdateScene(void)
{
	switch (g_scene) {

	case SCENE::SCENE_NONE:
		break;

	case SCENE::SCENE_TITLE:
		UpdateTitle();
		break;

	case SCENE::SCENE_TITLE_SCORE:
		pTitleScore->Update();
		break;

	case SCENE::SCENE_STAGE_SELECT:
		pStageSelect->Update();
		break;

	case SCENE::SCENE_GAME:
		pGame->Update();
		break;

	case SCENE::SCENE_MERCURY:
		pMercury->Update();
		break;

	case SCENE::SCENE_VENUS:
		break;

	case SCENE::SCENE_MARS:
		pMars->Update();
		break;

	case SCENE::SCENE_JUPITER:
		break;

	case SCENE::SCENE_SATURN:
		pSaturn->Update();
		break;

	case SCENE::SCENE_SUN:
		break;

	case SCENE::SCENE_RESULT:
		pResult->Update();
		break;

	default:
		break;
	}
}

//==========================
// 描画処理
//==========================
void DrawScene(void)
{
	switch (g_scene) {

	case SCENE::SCENE_NONE:
		break;

	case SCENE::SCENE_TITLE:
		DrawTitle();
		break;

	case SCENE::SCENE_TITLE_SCORE:
		pTitleScore->Draw();
		break;

	case SCENE::SCENE_STAGE_SELECT:
		pStageSelect->Draw();
		break;

	case SCENE::SCENE_GAME:
		pGame->Draw();
		break;

	case SCENE::SCENE_MERCURY:
		pMercury->Draw();
		break;

	case SCENE::SCENE_VENUS:
		break;

	case SCENE::SCENE_MARS:
		pMars->Draw();
		break;

	case SCENE::SCENE_JUPITER:
		break;

	case SCENE::SCENE_SATURN:
		pSaturn->Draw();
		break;

	case SCENE::SCENE_SUN:
		break;

	case SCENE::SCENE_RESULT:
		pResult->Draw();
		break;

	default:
		break;
	}
}

//==========================
// シーンをセット
//==========================
void SetScene(SCENE s)
{
	g_scene_next = s;
}

//==========================
// シーンをチェック
//==========================
void CheckScene(void)
{
	if (g_scene != g_scene_next) {
		UninitScene();				//現在のシーンの終了処理

		InitScene(g_scene_next);	//次のシーンの初期化処理
	}
}
