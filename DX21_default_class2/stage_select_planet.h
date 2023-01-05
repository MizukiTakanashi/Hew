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
		MERCURY,	//水星
		VENUS,		//金星
		MARS,		//火星
		JUPITER,	//木星
		SATURN,		//土星
		SUN,		//太陽
		NUM			//惑星の数
	};

	//ここで初期化
	static const int MOVE_TIME_LIMIT = 100;	//惑星が動く時間

	//cppで初期化
	static const float MOVE_SPEED;			//動くスピード
	static const float SUN_MOVE_SPEED_Y;	//太陽が動くスピードY


//メンバ変数
private:	
	inhStageSelectPlanetMake* m_planets[(int)PLANET::NUM];	//惑星達
	GameObject* m_pWhiteLine[(int)PLANET::NUM - 1];			//白い線

	bool m_sun_appearance = false;							//太陽が出てるかどうか

	int m_planet_index = 0;									//惑星の現在のインデックス番号
	int m_planet_index_before = 0;							//惑星の前のインデックス番号

	int m_thumb_before = 0;									//前フレームのスティックの値

	int m_move_time = -1;									//動く時間カウント

	int m_SE_01 = 0;										//決定音
	int m_SE_03 = 0;										//カーソル移動音

//メンバ関数
public:
	//デフォルトコンストラクタ
	StageSelectPlanet(){
		for (int i = 0; i < (int)PLANET::NUM; i++) {
			m_planets[i] = nullptr;
		}

		for (int i = 0; i < (int)PLANET::NUM - 1; i++) {
			m_pWhiteLine[i] = nullptr;
		}
	}

	//引数付きコンストラクタ
	StageSelectPlanet(DrawObject& mars, DrawObject& mercury, DrawObject& jupiter,
		DrawObject& venus, DrawObject& saturn, DrawObject& sun, DrawObject& white_line, 
		bool stage_clear[], bool sun_appearance = false);

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

private:
	//白い線をセットする
	void WhiteLineSet(const D3DXVECTOR2& planet_pos, int type);
};

#endif // !_STAGE_SELECT_PLANET_H_