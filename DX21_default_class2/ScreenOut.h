//=======================================
// 画面外に出たか関係(cppファイル)
// 作成日：2022/09/15
// 作成者：高梨水希
//=======================================
#pragma once

#ifndef _SCREEN_OUT_H_
#define _SCREEN_OUT_H_

#include "main.h"

class ScreenOut
{
public:
	ScreenOut(){}	//デフォルトコンストラクタ

	~ScreenOut(){}	//デストラクタ

	static bool GetScreenOut(D3DXVECTOR2 pos, D3DXVECTOR2 size);

	static void GetScreenIn(D3DXVECTOR2 pos, D3DXVECTOR2 size);
};

#endif // !_SCREEN_OUT_H_