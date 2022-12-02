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
	//惑星(左から並ぶ)(SUNは最後)
	enum class PLANET :int
	{
		MARS,		//火星
		MERCURY,	//水星
		JUPITER,	//木星
		VENUS,		//金星
		SATURN,		//土星
		SUN,		//太陽
		NUM			//惑星の数
	};

	static const float MOVE_LIMIT;


//メンバ変数
private:	
	inhStageSelectPlanetMake* m_planets[(int)PLANET::NUM];	//惑星達

	bool m_sun_appearance = false;							//太陽が出てるかどうか

	int m_planet_index = 0;									//惑星の現在のインデックス番号
	int m_planet_index_before = 0;							//惑星の前のインデックス番号

	int m_thumb_before = 0;									//前フレームのスティックの値

	int m_move_time = -1;									//動く時間カウント
	float m_move_speed = 0.1f;								//スピード


//メンバ関数
public:
	//デフォルトコンストラクタ
	StageSelectPlanet(){
		for (int i = 0; i < (int)PLANET::NUM; i++) {
			m_planets[i] = nullptr;
		}
	}

	//引数付きコンストラクタ
	StageSelectPlanet(DrawObject& mars, DrawObject& mercury, DrawObject& jupiter,
		DrawObject& venus, DrawObject& saturn, DrawObject& sun, bool sun_appearance = false);

	//デストラクタ
	~StageSelectPlanet() {
		for (int i = 0; i < (int)PLANET::NUM; i++) {
			delete m_planets[i];
		}
	}

	//更新処理
	void Update();

	//描画処理
	void Draw()const;
};

#endif // !_STAGE_SELECT_PLANET_H_