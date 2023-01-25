#pragma once
// 水星の氷ギミックのステージギミック
//製作者：矢野翔大

#include "inh_enemy.h"
#include "main.h"

class IceField :public Inh_Enemy
{
	//定数
public:
	//cppで初期化
	static const float SIZE_X;			//サイズX
	static const float SIZE_Y;			//サイズY

private:
	static const int INVINCIBLE_FLAME = 30;	//敵の無敵時間

	//cppで初期化
	static const float SPEED_X;			//敵のスピードY
	static const float SPEED_Y;			//敵のスピードY
	static const int HP_MAX = 1000;		//敵のHP最大値


	//メンバ変数
private:
	float m_move_width = 0.0f;			//敵が動く時のcosカーブ
	float m_init_posx = 0.0f;			//敵の初期位置X

	int m_hp = HP_MAX;					//敵の現在のHP
	int m_invincible_flame = 0;			//無敵時間の残り


	//メンバ関数
public:
	IceField() {}	//デフォルトコンストラクタ

	IceField(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:Inh_Enemy(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y), HP_MAX) {}

	~IceField()override {}

	void Update(void);	//更新処理

	//HPを減らす
	void ReduceHP(int amount)
	{
		if (m_invincible_flame <= 0)
		{
			m_hp -= amount;
			m_invincible_flame = INVINCIBLE_FLAME;
		}
	}

	//HPを返す
	int GetHP(void) { return m_hp; }
};