#pragma once
//=======================================
// 自機の左(ヘッダ)
// 作成日：2022/10/25
// 作成者：小西 蓮
//=======================================
#ifndef PLAYER_LEFT_H_
#define PLAYER_LEFT_H_

#include "GameObject.h"
#include "DrawObject.h"
#include "inhPlayerArm.h"
#include "PlayerArm1.h"

class PlayerLeft :public GameObject
{
//定数
public:
	// 腕に着く敵の種類
	enum class TYPE :int
	{
		TYPE_NONE,	// 何も付いていない
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
	static const D3DXVECTOR2 SIZE;				//サイズ
	static const float SHOT_SPEED;				// 切り離し発射スピード
	static const D3DXVECTOR2 FROM_PLAYER_POS;	//プレイヤーからどれくらい離れているか

// メンバ変数
private:
	bool m_shot = false;					// 発射したかどうか
	TYPE m_type = TYPE::TYPE_NONE;			// 付いた敵のタイプ
	
	inhPlayerArm* m_pEnemyItem = nullptr;	//腕についている敵のクラス
	DrawObject m_bullet_draw;				//弾の描画オブジェクト
	DrawObject m_laser_draw;				//レーザーの描画オブジェクト

//メンバ関数
public:
	PlayerLeft() {}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	PlayerLeft(DrawObject& pDrawObject, DrawObject& pBullet, DrawObject& pLaser, const D3DXVECTOR2& pos)
		:GameObject(pDrawObject, pos, SIZE),
		m_bullet_draw(pBullet), m_laser_draw(pLaser) {}

	~PlayerLeft()override { delete m_pEnemyItem; }	//デストラクタ

	//更新処理
	// player_pos：プレイヤーの座標　enemy_pos：一番近い敵の座標
	void Update(const D3DXVECTOR2& player_pos, const D3DXVECTOR2& enemy_pos);

	// 描画処理
	void LeftDraw(void)const;

	// 腕のタイプを設定
	void SetType(int type);

	// 腕のクラスのポインタを返す
	inhPlayerArm* GetArmPointer(void)const { return m_pEnemyItem; }
};

#endif // !PLAYER_LEFT_H_