#pragma once
#include "game_object.h"
class Meteo :public GameObject
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

public:
	Meteo(){}	//デフォルトコンストラクタ
	Meteo(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:GameObject(pDrawObject,pos,D3DXVECTOR2(SIZE_X, SIZE_Y)){}
	~Meteo(){}
	void Update(void);	//更新処理
};