#pragma once
//=======================================
// 自機の左(ヘッダ)
// 作成日：2022/10/25
// 作成者：小西 蓮
//=======================================
#ifndef PLAYER_LEFT
#define PLAYER_LEFT



#include "GameObject.h"
#include "DrawObject.h"

class PlayerLeft :public GameObject
{
private:

	// 定数
	static const float SHOT_SPEED;	// 弾の発射速度

	// メンバ変数
	bool m_shot = false; // 発射したかどうか

public:
	PlayerLeft() {}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	PlayerLeft(DrawObject& pDrawObject, const D3DXVECTOR2& pos, float rot)
		:GameObject(pDrawObject, pos, D3DXVECTOR2(30.0f, 50.0f), rot) {}

	virtual ~PlayerLeft() {}	//デストラクタ


	//更新処理
	void Update(D3DXVECTOR2 pos);

};

#endif // !PLAYER_LEFT