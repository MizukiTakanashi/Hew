//=======================================
// レーザー関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================

#ifndef _LASER_H_
#define _LASER_H_

#include "game_object.h"
#include "draw_object.h"

class Laser:public GameObject
{
//定数
public:
	//方向(上下は初期化で行うため除く)
	enum class DIRECTION :int {
		NONE,
		RIGHT,
		LEFT,
		NUM
	};

	//cppで初期化
	static const float SPEED_X;			//レーザーのスピードX
	static const float SPEED_Y;			//レーザーのスピードY

	//ここで初期化
	static const int LASER_TIME = 180;	//レーザーの最大射出時間

//メンバ変数
private:
	int m_lasertime = LASER_TIME;				//レーザーの現在の射出時間
	DIRECTION m_direction = DIRECTION::NONE;	//レーザーの向き

//メンバ関数
public:
	Laser(){}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	Laser(DrawObject& pDrawObject, const D3DXVECTOR2& pos, const D3DXVECTOR2& size)
		:GameObject(pDrawObject, pos, size, 0.0f) {}

	~Laser()override {}	//デストラクタ

	//レーザーの向き変更
	void SetLaserDirectioon(DIRECTION direction) { m_direction = direction; }

	//レーザーの削除
	void DeleteLaser() { m_lasertime = -1; }

	//レーザーの残り時間を返す
	int GetLaserTime() { return m_lasertime; }

	//更新処理(弾を移動)
	void Update(const D3DXVECTOR2& pos, bool down = true); 
};

#endif // !_LASER_H_