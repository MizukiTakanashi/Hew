#pragma once
//=======================================
// プレイヤーの腕1関係(ヘッダファイル)
// 作成日：2022/10/28
// 作成者：高梨水希
//=======================================

#ifndef _PLAYER_ARM_1_H_
#define _PLAYER_ARM_1_H_

#include "inhPlayerArm.h"

class PlayerArm1:public inhPlayerArm
{
public:
	//デフォルトコンストラクタ
	PlayerArm1(){}

	//デストラクタ
	~PlayerArm1(){}

	void Update()override;

	void PlayerArmDraw()override;
};

#endif // !_PLAYER_ARM_1_H_