#pragma once
//=============================================
// ステージ選択画面の火星関係(ヘッダファイル)
// 作成日：2022/11/29
// 作成者：高梨水希
//=============================================

#ifndef _STAGE_SELECT_MARS_H_
#define _STAGE_SELECT_MARS_H_

#include "game_object.h"
#include "draw_object.h"

class StageSelectMars:public GameObject
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
	StageSelectMars(){}

	//引数付きコンストラクタ
	StageSelectMars(DrawObject& pDrawObj):GameObject(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y), D3DXVECTOR2(BOX_W, BOX_H)) {}

	//デストラクタ
	~StageSelectMars() {}
};

#endif // !_STAGE_SELECT_MARS_H_