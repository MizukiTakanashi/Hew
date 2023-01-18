#pragma once
//=======================================
// 自機の左(ヘッダ)
// 作成日：2022/10/25
// 作成者：小西 蓮
//=======================================
#ifndef PLAYER_LEFT_H_
#define PLAYER_LEFT_H_

#include "inh_player_arm_both.h"
#include "draw_object.h"

class PlayerLeft :public inhPlayerArmBoth
{
	//定数
private:
	//ここで初期化
	static const int TRIGGER = 100;				//トリガーの重さ(0～255)

	//cppで初期化
	static const D3DXVECTOR2 FROM_PLAYER_POS;	//プレイヤーからどれくらい離れているか

	//メンバ関数
public:
	PlayerLeft() {}			//デフォルトコンストラクタ

	//引数付きコンストラクタ
	PlayerLeft(const D3DXVECTOR2& pos, DrawObject& pDrawobNumber, D3DXVECTOR2 num_pos, D3DXVECTOR2 icon_pos)
		:inhPlayerArmBoth(pos, FROM_PLAYER_POS, pDrawobNumber, num_pos, icon_pos) {}

	~PlayerLeft()override {}	//デストラクタ

	//ボタン判定
	void ButtonPress(void);
};

#endif // !PLAYER_LEFT_H_