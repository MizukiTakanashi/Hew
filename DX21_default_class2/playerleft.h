#pragma once
//=======================================
// 自機の左(ヘッダ)
// 作成日：2022/10/23
// 作成者：恩田洋行
//=======================================
#ifndef PLAYER_LEFT
#define PLAYER_LEFT



#include "GameObject.h"
#include "DrawObject.h"

class PlayerLeft :public GameObject
{
private:

public:
	PlayerLeft() {}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	PlayerLeft(DrawObject& pDrawObject, const D3DXVECTOR2& pos, float rot)
		:GameObject(pDrawObject, pos, D3DXVECTOR2(30.0f, 50.0f), rot) {}

	virtual ~PlayerLeft() {}	//デストラクタ


	//更新処理
	void Update(D3DXVECTOR2 pos) { SetPos(pos - D3DXVECTOR2(30.0f, 0.0f)); }

};

#endif // !PLAYER_LEFT