#pragma once
//=======================================
// 自機の右(ヘッダ)
// 作成日：2022/10/23
// 作成者：恩田洋行
//=======================================
#ifndef PLAYER_RIGHT_H_
#define PLAYER_RIGHT_H_

#include "GameObject.h"
#include "DrawObject.h"
#include "inhPlayerArm.h"
#include "PlayerArm1.h"

class PlayerRight :public GameObject
{
//定数
public:
	//腕につく敵のタイプ
	enum class TYPE :int
	{
		TYPE_NONE,	//	何もついていない
		TYPE1,
		TYPE2,
		TYPE3,
		TYPE4,
		TYPE5,
		TYPE6,
		TYPE7,
		TYPE8,
		TYPE_NUM,
	};

private:
	//cppで初期化
	static const float SHOT_SPEED;		//切り離し発射スピード
	static const D3DXVECTOR2 FROM_PLAYER_POS;	//プレイヤーからどれくらい離れているか

//メンバ変数
private:
	bool m_shot = false;					//発射したか否か
	TYPE m_type = TYPE::TYPE_NONE;			//ついた敵のタイプ
	inhPlayerArm* m_pEnemyItem = nullptr;	//腕についている敵のクラス

//メンバ関数
public:
	PlayerRight() {}			//デフォルトコンストラクタ

	//引数付きコンストラクタ
	PlayerRight(DrawObject& pDrawObject, const D3DXVECTOR2& pos, float rot)
		:GameObject(pDrawObject, pos, D3DXVECTOR2(30.0f, 50.0f), rot) {}

	virtual ~PlayerRight() {}	//デストラクタ

	//更新処理
	void Update(const D3DXVECTOR2& player_pos, const D3DXVECTOR2& enemy_pos);

	//描画処理
	void RightDraw(void)const;

	//腕のタイプを設定
	void SetType(int type);
};

#endif // !PLAYER_RIGHT_H_