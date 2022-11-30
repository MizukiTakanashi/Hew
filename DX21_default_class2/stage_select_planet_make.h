#pragma once
//=======================================
// 惑星制作関係(ヘッダファイル)
// 作成日：2022/11/30
// 作成者：高梨水希
//=======================================

#ifndef _STAGE_SELECT_PLANET_MAKE_H_
#define _STAGE_SELECT_PLANET_MAKE_H_

#include "game_object.h"

//==========================
// 火星
//==========================
class StageSelectMars :public GameObject
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
	StageSelectMars() {}

	//引数付きコンストラクタ
	StageSelectMars(DrawObject& pDrawObj) 
		:GameObject(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y), D3DXVECTOR2(BOX_W, BOX_H)) {}

	//デストラクタ
	~StageSelectMars() {}
};

//==========================
// 水星
//==========================
class StageSelectMercury :public GameObject
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
	StageSelectMercury(DrawObject& pDrawObj) 
		:GameObject(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y), D3DXVECTOR2(BOX_W, BOX_H)) {}

	//デストラクタ
	~StageSelectMercury() {}
};

//==========================
// 木星
//==========================
class StageSelectJupiter :public GameObject
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
	StageSelectJupiter() {}

	//引数付きコンストラクタ
	StageSelectJupiter(DrawObject& pDrawObj) 
		:GameObject(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y), D3DXVECTOR2(BOX_W, BOX_H)) {}

	//デストラクタ
	~StageSelectJupiter() {}
};

//==========================
// 金星
//==========================
class StageSelectVenus :public GameObject
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
	StageSelectVenus() {}

	//引数付きコンストラクタ
	StageSelectVenus(DrawObject& pDrawObj)
		:GameObject(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y), D3DXVECTOR2(BOX_W, BOX_H)) {}

	//デストラクタ
	~StageSelectVenus() {}
};

//==========================
// 土星
//==========================
class StageSelectSaturn :public GameObject
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
	StageSelectSaturn() {}

	//引数付きコンストラクタ
	StageSelectSaturn(DrawObject& pDrawObj)
		:GameObject(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y), D3DXVECTOR2(BOX_W, BOX_H)) {}

	//デストラクタ
	~StageSelectSaturn() {}
};

//==========================
// 太陽
//==========================
class StageSelectSun :public GameObject
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
	StageSelectSun() {}

	//引数付きコンストラクタ
	StageSelectSun(DrawObject& pDrawObj)
		:GameObject(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y), D3DXVECTOR2(BOX_W, BOX_H)) {}

	//デストラクタ
	~StageSelectSun() {}
};

#endif // !_STAGE_SELECT_PLANET_MAKE_H_