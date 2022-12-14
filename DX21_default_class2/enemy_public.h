//==============================
//何もしない敵
//11/22
//矢野翔大
//=============================
#pragma once
#include "inh_enemy.h"

class EnemyPublic :public Inh_Enemy
{
	//定数
public:
	//cppで初期化
	static const float SIZE_X;			//サイズX
	static const float SIZE_Y;			//サイズY

private:
	static const float SPEED_X;			//敵のスピードY
	static const float SPEED_Y;			//敵のスピードY
	static const int HP_MAX = 1;		//敵のHP最大値

//メンバ変数
private:


//メンバ関数
public:
	//デフォルトコンストラクタ
	EnemyPublic() {}	
	//引数付きコンストラクタ
	EnemyPublic(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:Inh_Enemy(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y), HP_MAX) {}
	//デストラクタ
	~EnemyPublic() {}

	//更新処理
	void Update(void);	

};

