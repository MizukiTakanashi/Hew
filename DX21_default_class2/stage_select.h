#pragma once
//=======================================
// ステージ選択画面関係(ヘッダファイル)
// 作成日：2022/11/29
// 作成者：高梨水希
//=======================================

#ifndef _STAGE_SELECT_H_
#define _STAGE_SELECT_H_

#include "main.h"
#include "sprite.h"
#include "BG.h"
#include "draw_object.h"
#include "number.h"
#include "scene.h"
#include "stage_select_planet.h"

class StageSelect
{
//定数
private:
	//ここで初期化
	static const int NUMBER_DIGIT = 10;		//数字の桁

	//cppで初期化
	static const D3DXVECTOR2 NUMBER_SIZE;	//数字のサイズ
	static const D3DXVECTOR2 NUMBER_POS;	//数字の位置

	enum class TEXTURE_TYPE :int
	{
		MOON,
		MARS,
		MERCURY,
		JUPITER,
		VENUS,
		SATURN,
		SUN,
		NUM
	};

	enum class DRAW_TYPE :int
	{
		MOON,
		MARS,
		MERCURY,
		JUPITER,
		VENUS,
		SATURN,
		SUN,
		NUM
	};


//メンバ変数
private:
	int m_stage_score[STAGE_NUM];

	int m_BGM = 0;

	TextureUseful* m_pTexUseful = nullptr;
	DrawObject* m_pDrawObject = nullptr;

	BG* m_pBG = nullptr;

	UI* m_pMultiply = nullptr;
	Number* m_pComboNum = nullptr;
	
	StageSelectPlanet* m_pPlanet = nullptr;

//メンバ関数
public:
	StageSelect();	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	StageSelect(int stage_score[]);

	~StageSelect() {}	//デストラクタ

	//更新
	void Update(void);

	//描画
	void Draw(void)const;
};
#endif // !_STAGE_SELECT_H_