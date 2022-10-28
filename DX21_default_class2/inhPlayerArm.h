#pragma once
//==============================================
// (継承用)プレイヤーの腕関係(ヘッダファイル)
// 作成日：2022/10/28
// 作成者：高梨水希
//==============================================

#ifndef _INH_PLAYER_ARM_H_
#define _INH_PLAYER_ARM_H_

#include "GameObject.h"

class inhPlayerArm:public GameObject
{
public:
	//デフォルトコンストラクタ
	inhPlayerArm(){}

	//デストラクタ
	~inhPlayerArm(){}

	//更新処理(オーバーライド)
	virtual void Update() = 0;

	//描画処理(オーバーライド)
	virtual void Draw() = 0;
};

#endif // !_INH_PLAYER_ARM_H_