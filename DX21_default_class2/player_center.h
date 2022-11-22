//=======================================
// 自機の真ん中(ヘッダ)
// 作成日：
// 作成者：恩田洋行
//=======================================
#pragma once
#ifndef PLAYER_CEENTER_H_
#define PLAYER_CEENTER_H_

#include "inh_player_arm_both.h"
#include "draw_object.h"

class PlayerCenter :public inhPlayerArmBoth
{
	//定数
private:
	//ここで初期化
	static const int TRIGGER = 100;				//トリガーの重さ(0～255)

	//cppで初期化
	static const D3DXVECTOR2 FROM_PLAYER_POS;	//プレイヤーからどれくらい離れているか

	//メンバ関数
public:
	PlayerCenter() {}			//デフォルトコンストラクタ

	//引数付きコンストラクタ
	PlayerCenter(DrawObject& pDrawObject, DrawObject& pBullet, DrawObject& pLaser, const D3DXVECTOR2& pos, Number* pNum, D3DXVECTOR2 icon_pos)
		:inhPlayerArmBoth(pDrawObject, pBullet, pLaser, pos, FROM_PLAYER_POS, pNum, icon_pos) {}

	~PlayerCenter()override {}	//デストラクタ

	//ボタン判定
	void ButtonPress(void);
};

#endif // !PLAYER_CEENTER_H_