//=======================================
// スコア関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#pragma once
#ifndef _SCORE_H_
#define _SCORE_H_

#include "main.h"
#include "UI.h"
#include "draw_object.h"

class Score :public UI
{
	//定数
private:
	//cppで初期化
	static const float SPACE_RATIO;	//数字と数字の間の比率
	static const float COMBO_MAGNIFICATION; //コンボ継続時の倍率

private:
	int m_num = 0;					//数字			
	int m_digit = 0;				//桁数
	float m_space = 0.0f;			//数字と数字の間
	D3DXVECTOR2 m_init_pos = D3DXVECTOR2(0.0f, 0.0f);	//数字の最初の位置
	float m_ComboMagnification = 1.0f; //コンボ倍率
	int m_ComboNum = 0; //コンボ継続数

public:
	Score() {}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	Score(DrawObject& pDrawObject, const D3DXVECTOR2& pos = D3DXVECTOR2(0.0f, 0.0f),
		const D3DXVECTOR2& size = D3DXVECTOR2(0.0f, 0.0f), int digit = 0);

	~Score()override {}	//デストラクタ

	//数字を追加
	void AddScore(int num);

	//数字をセット
	void SetNumber(int num) { m_num = 0; }

	//桁数をセット
	void SetDigit(int digit) { m_digit = digit; }

	//初期座標をセット
	void SetInitPos(const D3DXVECTOR2& pos) { m_init_pos = pos; }

	//描画処理
	void DrawNumber(void);

	//コンボが途切れた時の処理
	void InitCombo(void) { m_ComboMagnification = 1.0f; m_ComboNum = 0; }

};

#endif // !_SCORE_H_