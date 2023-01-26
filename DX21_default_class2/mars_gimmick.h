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
#include "sound.h"

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
	int m_frame_index = 0;
	int m_SE_26 = 0;			//スピード低下音

//メンバ関数
public:
	//デフォルトコンストラクタ
	MarsGimmick(){}

	//引数付きコンストラクタ
	MarsGimmick(DrawObject& pDrawObj)
		:UI(pDrawObj, D3DXVECTOR2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), 
			D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT)) {
		m_SE_26 = LoadSound((char*)"data\\SE\\2_10.wav");
	}

	//デストラクタ
	~MarsGimmick(){}

	//更新処理
	void Update() { 
		m_frame_count++; 
		if (m_frame_count > TIME[m_frame_index]) {
			m_move_down = !m_move_down;
			if (m_move_down) {
				PlaySound(m_SE_26, 0);
			}
 			m_frame_index++;
		}
	}

	//描画処理
	void Draw() { 
		if (m_move_down) {
			UI::Draw();
		}
	}

	//移動速度低下フラグを返す
	bool GetMoveDown()const { return m_move_down; }
};

#endif // !_MARS_GIMMICK_H_