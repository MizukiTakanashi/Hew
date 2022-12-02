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
// 惑星(ポリモーフィズム用)
//==========================
class inhStageSelectPlanetMake :public GameObject
{
//メンバ変数
private:
	D3DXVECTOR2 m_small_size = D3DXVECTOR2(0.0f, 0.0f);
	D3DXVECTOR2 m_big_size = D3DXVECTOR2(0.0f, 0.0f);


//メンバ関数
public:
	//デフォルトコンストラクタ
	inhStageSelectPlanetMake(){}

	//引数付きコンストラクタ
	inhStageSelectPlanetMake(DrawObject& pDrawObj, D3DXVECTOR2 pos, D3DXVECTOR2 small_size, D3DXVECTOR2 big_size)
		:GameObject(pDrawObj, pos, small_size), m_small_size(small_size), m_big_size(big_size) {}

	//デストラクタ
	virtual ~inhStageSelectPlanetMake()override{}

	//小さくする
	void SetSizeSmaller(void) { GameObject::SetSize(m_small_size); }

	//大きくする
	void SetSizeBigger(void) { GameObject::SetSize(m_big_size); }
};

//==========================
// 火星
//==========================
class StageSelectMars :public inhStageSelectPlanetMake
{
//定数
private:
	//cppで初期化
	static const float BOX_W;		//四角形の横のサイズ
	static const float BOX_H;		//四角形の縦のサイズ
	static const float BIG_BOX_W;	//大きくなる時の四角形の横のサイズ
	static const float BIG_BOX_H;	//大きくなる時の四角形の縦のサイズ
	static const float START_POS_X;	//初期位置X
	static const float START_POS_Y;	//初期位置Y


//メンバ関数
public:
	//デフォルトコンストラクタ
	StageSelectMars() {}

	//引数付きコンストラクタ
	StageSelectMars(DrawObject& pDrawObj) 
		:inhStageSelectPlanetMake(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y),
			D3DXVECTOR2(BOX_W, BOX_H), D3DXVECTOR2(BIG_BOX_W, BIG_BOX_H)) {}

	//デストラクタ
	~StageSelectMars()override {}
};

//==========================
// 水星
//==========================
class StageSelectMercury :public inhStageSelectPlanetMake
{
//定数
private:
	//cppで初期化
	static const float BOX_W;		//四角形の横のサイズ
	static const float BOX_H;		//四角形の縦のサイズ
	static const float BIG_BOX_W;	//大きくなる時の四角形の横のサイズ
	static const float BIG_BOX_H;	//大きくなる時の四角形の縦のサイズ
	static const float START_POS_X;	//初期位置X
	static const float START_POS_Y;	//初期位置Y


//メンバ関数
public:
	//デフォルトコンストラクタ
	StageSelectMercury() {}

	//引数付きコンストラクタ
	StageSelectMercury(DrawObject& pDrawObj) 
		:inhStageSelectPlanetMake(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y), 
			D3DXVECTOR2(BOX_W, BOX_H), D3DXVECTOR2(BIG_BOX_W, BIG_BOX_H)) {}

	//デストラクタ
	~StageSelectMercury()override {}
};

//==========================
// 木星
//==========================
class StageSelectJupiter :public inhStageSelectPlanetMake
{
//定数
private:
	//cppで初期化
	static const float BOX_W;		//四角形の横のサイズ
	static const float BOX_H;		//四角形の縦のサイズ
	static const float BIG_BOX_W;	//大きくなる時の四角形の横のサイズ
	static const float BIG_BOX_H;	//大きくなる時の四角形の縦のサイズ
	static const float START_POS_X;	//初期位置X
	static const float START_POS_Y;	//初期位置Y


//メンバ関数
public:
	//デフォルトコンストラクタ
	StageSelectJupiter() {}

	//引数付きコンストラクタ
	StageSelectJupiter(DrawObject& pDrawObj) 
		:inhStageSelectPlanetMake(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y), 
			D3DXVECTOR2(BOX_W, BOX_H), D3DXVECTOR2(BIG_BOX_W, BIG_BOX_H)) {}

	//デストラクタ
	~StageSelectJupiter()override {}
};

//==========================
// 金星
//==========================
class StageSelectVenus :public inhStageSelectPlanetMake
{
//定数
private:
	//cppで初期化
	static const float BOX_W;		//四角形の横のサイズ
	static const float BOX_H;		//四角形の縦のサイズ
	static const float BIG_BOX_W;	//大きくなる時の四角形の横のサイズ
	static const float BIG_BOX_H;	//大きくなる時の四角形の縦のサイズ
	static const float START_POS_X;	//初期位置X
	static const float START_POS_Y;	//初期位置Y


//メンバ関数
public:
	//デフォルトコンストラクタ
	StageSelectVenus() {}

	//引数付きコンストラクタ
	StageSelectVenus(DrawObject& pDrawObj)
		:inhStageSelectPlanetMake(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y), 
			D3DXVECTOR2(BOX_W, BOX_H), D3DXVECTOR2(BIG_BOX_W, BIG_BOX_H)) {}

	//デストラクタ
	~StageSelectVenus()override {}
};

//==========================
// 土星
//==========================
class StageSelectSaturn :public inhStageSelectPlanetMake
{
//定数
private:
	//cppで初期化
	static const float BOX_W;		//四角形の横のサイズ
	static const float BOX_H;		//四角形の縦のサイズ
	static const float BIG_BOX_W;	//大きくなる時の四角形の横のサイズ
	static const float BIG_BOX_H;	//大きくなる時の四角形の縦のサイズ
	static const float START_POS_X;	//初期位置X
	static const float START_POS_Y;	//初期位置Y


//メンバ関数
public:
	//デフォルトコンストラクタ
	StageSelectSaturn() {}

	//引数付きコンストラクタ
	StageSelectSaturn(DrawObject& pDrawObj)
		:inhStageSelectPlanetMake(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y), 
			D3DXVECTOR2(BOX_W, BOX_H), D3DXVECTOR2(BIG_BOX_W, BIG_BOX_H)) {}

	//デストラクタ
	~StageSelectSaturn()override {}
};

//==========================
// 太陽
//==========================
class StageSelectSun :public inhStageSelectPlanetMake
{
//定数
private:
	//cppで初期化
	static const float BOX_W;		//四角形の横のサイズ
	static const float BOX_H;		//四角形の縦のサイズ
	static const float BIG_BOX_W;	//大きくなる時の四角形の横のサイズ
	static const float BIG_BOX_H;	//大きくなる時の四角形の縦のサイズ
	static const float START_POS_X;	//初期位置X
	static const float START_POS_Y;	//初期位置Y


//メンバ関数
public:
	//デフォルトコンストラクタ
	StageSelectSun() {}

	//引数付きコンストラクタ
	StageSelectSun(DrawObject& pDrawObj)
		:inhStageSelectPlanetMake(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y), 
			D3DXVECTOR2(BOX_W, BOX_H), D3DXVECTOR2(BIG_BOX_W, BIG_BOX_H)) {}

	//デストラクタ
	~StageSelectSun()override {}
};

#endif // !_STAGE_SELECT_PLANET_MAKE_H_