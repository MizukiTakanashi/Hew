//=======================================
// スコア関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#pragma once
#ifndef _SCORE_H_
#define _SCORE_H_

#include "main.h"
#include "number.h"
#include "draw_object.h"

class Score :public Number
{
	//定数
private:
	//cppで初期化
	static const float COMBO_MAGNIFICATION; //コンボ継続時の倍率

private:
	float m_ComboMagnification = 1.0f; //コンボ倍率
	int m_ComboNum = 0; //コンボ継続数

public:
	Score() {}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	Score(DrawObject& pDrawObject, const D3DXVECTOR2& pos = D3DXVECTOR2(0.0f, 0.0f),
		const D3DXVECTOR2& size = D3DXVECTOR2(0.0f, 0.0f), int digit = 0);

	~Score()override {}	//デストラクタ

	//スコアを追加
	void AddScore(int num);


	//コンボが途切れた時の処理
	void InitCombo(void) { m_ComboMagnification = 1.0f; m_ComboNum = 0; }

};

#endif // !_SCORE_H_