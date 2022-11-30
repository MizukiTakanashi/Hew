#pragma once
//=============================================
// ステージ選択画面の惑星関係(ヘッダファイル)
// 作成日：2022/11/29
// 作成者：高梨水希
//=============================================

#ifndef _STAGE_SELECT_PLANET_H_
#define _STAGE_SELECT_PLANET_H_

#include "game_object.h"
#include "stage_select_mars.h"
#include "draw_object.h"

//==========================
// 水星
//==========================
class StageSelectMercury:public GameObject
{
//定数
private:
	//cppで初期化
	static const float BOX_W;		//四角形の横のサイズ
	static const float BOX_H;		//四角形の縦のサイズ
	static const float START_POS_X;	//初期位置X
	static const float START_POS_Y;	//初期位置Y


//メンバ関数
public:
	//デフォルトコンストラクタ
	StageSelectMercury() {}

	//引数付きコンストラクタ
	StageSelectMercury(DrawObject& pDrawObj) :GameObject(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y), D3DXVECTOR2(BOX_W, BOX_H)) {}

	//デストラクタ
	~StageSelectMercury() {}
};

//==========================
// 惑星全体
//==========================
class StageSelectPlanet
{
//メンバ変数
private:
	StageSelectMars* m_mars = nullptr;			//火星
	StageSelectMercury* m_mercury = nullptr;	//水星

public:
	//デフォルトコンストラクタ
	StageSelectPlanet(){}

	//引数付きコンストラクタ
	StageSelectPlanet(DrawObject& mars, DrawObject& mercury)
		:m_mars(new StageSelectMars(mars)), m_mercury(new StageSelectMercury(mercury)) {}

	//デストラクタ
	~StageSelectPlanet() {
		delete m_mars;
	}

	//更新処理
	void Update();

	//描画処理
	void Draw()const;
};

#endif // !_STAGE_SELECT_PLANET_H_