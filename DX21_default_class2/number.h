//=======================================
// 数字関係(ヘッダファイル)
// 作成日：2022/09/29
// 作成者：高梨水希
//=======================================
#pragma once

#ifndef _NUMBER_H_
#define _NUMBER_H_

#include "main.h"
#include "UI.h"
#include "draw_object.h"

class Number :public UI
{
	//定数
private:
	//cppで初期化
	static const float SPACE_RATIO;	//数字と数字の間の比率

private:
	int m_num = 0;					//数字			
	int m_digit = 0;				//桁数
	float m_space = 0.0f;			//数字と数字の間
	D3DXVECTOR2 m_init_pos = D3DXVECTOR2(0.0f, 0.0f);	//数字の最初の位置

public:
	Number() {}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	Number(DrawObject& pDrawObject, const D3DXVECTOR2& pos = D3DXVECTOR2(0.0f, 0.0f),
		const D3DXVECTOR2& size = D3DXVECTOR2(0.0f, 0.0f), int digit = 0);

	~Number()override {}	//デストラクタ

 
	//数字をセット
	void SetNumber(int num) { m_num = num; }

	//数字を返す
	int GetNumber(void) { return m_num; }

	//数字を加算
	void AddNumber(int num) { m_num += num; }

	//桁数をセット
	void SetDigit(int digit) { m_digit = digit; }

	//初期座標をセット
	void SetInitPos(const D3DXVECTOR2& pos) { m_init_pos = pos; }

	//描画処理
	void DrawNumber(void);

};


#endif // !_NUMBER_H_

