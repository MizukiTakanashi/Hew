//==============================
//何もしない敵
//11/22
//矢野翔大
//=============================
#pragma once
#include "game_object.h"
class EnemyPublic :public GameObject
{
	//定数
public:
	//cppで初期化
	static const float SIZE_X;			//サイズX
	static const float SIZE_Y;			//サイズY

	//メンバ変数
private:
	float m_move_width = 0.0f;			//敵が動く時のcosカーブ
	float m_init_posx = 0.0f;			//敵の初期位置X
	//cppで初期化
	static const float SPEED_X;			//敵のスピードY
	static const float SPEED_Y;			//敵のスピードY
	static const int HP_MAX;			//敵のHP最大値

	int m_hp = HP_MAX;					//敵の現在のHP

public:
	EnemyPublic() {}	//デフォルトコンストラクタ
	EnemyPublic(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:GameObject(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y)) {}
	~EnemyPublic() {}
	void Update(void);	//更新処理

	//HPを減らす
	void ReduceHP(int amount) { m_hp -= amount; }

	//HPを返す
	int GetHP(void) { return m_hp; }

};

