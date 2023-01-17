#pragma once
//=======================================
// 自機の右(ヘッダ)
// 作成日：2022/10/23
// 作成者：恩田洋行
//=======================================
#ifndef PLAYER_RIGHT_H_
#define PLAYER_RIGHT_H_

#include "inh_player_arm_both.h"
#include "draw_object.h"

class PlayerRight :public inhPlayerArmBoth
{
	//定数
private:
	//ここで初期化
	static const int TRIGGER = 100;				//トリガーの重さ(0～255)
	
	//cppで初期化
	static const D3DXVECTOR2 FROM_PLAYER_POS;	//プレイヤーからどれくらい離れているか

	//メンバ関数
public:
	PlayerRight() {}			//デフォルトコンストラクタ

	//引数付きコンストラクタ
	PlayerRight(const D3DXVECTOR2& pos, DrawObject& pDrawobNumber, D3DXVECTOR2 num_pos, D3DXVECTOR2 icon_pos)
		:inhPlayerArmBoth(pos, FROM_PLAYER_POS, pDrawobNumber, num_pos, icon_pos) {}

	~PlayerRight()override {}	//デストラクタ

	//ボタン判定
	void ButtonPress(void);
};

#endif // !PLAYER_RIGHT_H_