#pragma once
//=======================================
// 自機の右(ヘッダ)
// 作成日：2022/10/23
// 作成者：恩田洋行
//=======================================
#ifndef PLAYER_RIGHT
#define PLAYER_RIGHT



#include "GameObject.h"
#include "DrawObject.h"

class PlayerRight :public GameObject
{
private:
	//定数
	static const float SHOT_SPEED;	//発射スピード

	//メンバー変数
	bool m_shot = false;	//発射したか否か

public:
	PlayerRight() {}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	PlayerRight(DrawObject& pDrawObject, const D3DXVECTOR2& pos, float rot)
		:GameObject(pDrawObject, pos, D3DXVECTOR2(30.0f, 50.0f), rot) {}
	 
	virtual ~PlayerRight() {}	//デストラクタ


	//更新処理
	void Update(D3DXVECTOR2 pos);


};

#endif // !PLAYER_RIGHT
