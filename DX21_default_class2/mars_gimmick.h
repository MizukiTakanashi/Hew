#pragma once
//=======================================
// 火星ギミック関係(ヘッダファイル)
// 作成日：2022/01/13
// 作成者：高梨水希
//=======================================

#ifndef _MARS_GIMMICK_H_
#define _MARS_GIMMICK_H_

#include "draw_object.h"
#include "UI.h"

class MarsGimmick:public UI
{
//定数
public:
	//cppで初期化
	static const int TIME[6];

//メンバ変数
private:
	bool m_move_down = false;	//移動速度低下フラグ
	int m_frame_count = 0;		//フレームカウント

//メンバ関数
public:
	//デフォルトコンストラクタ
	MarsGimmick(){}

	//引数付きコンストラクタ
	MarsGimmick(DrawObject& pDrawObj)
		:UI(pDrawObj, D3DXVECTOR2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), 
			D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT)) {}

	//デストラクタ
	~MarsGimmick(){}

	//更新処理
	void Update() { m_frame_count++; }

	//移動速度低下フラグを返す
	bool GetMoveDown() { return m_move_down; }
};

#endif // !_MARS_GIMMICK_H_