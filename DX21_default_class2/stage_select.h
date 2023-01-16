#pragma once
//=======================================
// ステージ選択画面関係(ヘッダファイル)
// 作成日：2022/11/29
// 作成者：高梨水希
//=======================================

#ifndef _STAGE_SELECT_H_
#define _STAGE_SELECT_H_

#include "main.h"
#include "BG.h"
#include "draw_object.h"
#include "stage_select_planet.h"

class StageSelect
{
//定数
private:
	enum class TEXTURE_TYPE :int
	{
		BG,
		MOON,
		MARS,
		MERCURY,
		JUPITER,
		VENUS,
		SATURN,
		SUN,
		WHITE_CIRCLE,
		NUM
	};

	enum class DRAW_TYPE :int
	{
		BG,
		MOON,
		MARS,
		MERCURY,
		JUPITER,
		VENUS,
		SATURN,
		SUN,
		WHITE_CIRCLE,
		NUM
	};


//メンバ変数
private:
	int m_BGM = 0;	//BGM

	TextureUseful* m_pTexUseful = nullptr;
	DrawObject* m_pDrawObject = nullptr;

	BG* m_pBG = nullptr;
	
	StageSelectPlanet* m_pPlanet = nullptr;	//惑星

//メンバ関数
public:
	//デフォルトコンストラクタ
	StageSelect(){}

	//引数付きコンストラクタ
	StageSelect(int stage_score[]);

	//デストラクタ
	~StageSelect() {}

	//更新(惑星の更新)
	void Update(void){ m_pPlanet->Update(); }

	//描画
	void Draw(void)const;
};
#endif // !_STAGE_SELECT_H_