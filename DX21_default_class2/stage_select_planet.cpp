//=============================================
// ステージ選択画面の惑星関係(cppファイル)
// 作成日：2022/11/30
// 作成者：高梨水希
//=============================================

#include "stage_select_planet.h"

//==========================
// 定数の初期化
//==========================
const float StageSelectMercury::BOX_W = 50.0f;
const float StageSelectMercury::BOX_H = 50.0f;
const float StageSelectMercury::START_POS_X = 400.0f;
const float StageSelectMercury::START_POS_Y = SCREEN_HEIGHT / 2;

//==========================
// 更新処理
//==========================
void StageSelectPlanet::Update()
{
}

//==========================
// 描画処理
//==========================
void StageSelectPlanet::Draw() const
{
	//火星
	m_mars->Draw();

	//水星
	m_mercury->Draw();
}