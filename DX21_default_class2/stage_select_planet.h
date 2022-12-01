#pragma once
//=============================================
// ステージ選択画面の惑星関係(ヘッダファイル)
// 作成日：2022/11/29
// 作成者：高梨水希
//=============================================

#ifndef _STAGE_SELECT_PLANET_H_
#define _STAGE_SELECT_PLANET_H_

#include "game_object.h"
#include "draw_object.h"
#include "stage_select_planet_make.h"

//==========================
// 惑星全体
//==========================
class StageSelectPlanet
{
//定数
private:
	//腕につく敵のタイプ
	enum class PLANET :int
	{
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
	StageSelectMars* m_mars = nullptr;			//火星
	StageSelectMercury* m_mercury = nullptr;	//水星
	StageSelectJupiter* m_jupiter = nullptr;	//木星
	StageSelectVenus* m_venus = nullptr;		//金星
	StageSelectSaturn* m_saturn = nullptr;		//土星
	StageSelectSun* m_sun = nullptr;			//太陽

	bool m_sun_appearance = false;				//太陽が出てるかどうか

	int m_planet_index = 0;						//惑星のインデックス番号

public:
	//デフォルトコンストラクタ
	StageSelectPlanet(){}

	//引数付きコンストラクタ
	StageSelectPlanet(DrawObject& mars, DrawObject& mercury, DrawObject& jupiter, 
		DrawObject& venus, DrawObject& saturn, DrawObject& sun, bool sun_appearance = false)
		:m_mars(new StageSelectMars(mars)), m_mercury(new StageSelectMercury(mercury)),
		m_jupiter(new StageSelectJupiter(jupiter)), m_venus(new StageSelectVenus(venus)),
		m_saturn(new StageSelectSaturn(saturn)), m_sun(new StageSelectSun(sun)) {}

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