//=======================================
// レーザー関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================

#ifndef _LASER_H_
#define _LASER_H_

#include "GameObject.h"
#include "DrawObject.h"
#include "enemylaser.h"

class Laser:public GameObject
{
private:
	int m_lasertime = LASER_TIME;

public:
	static const float SPEED_Y;			//レーザーのスピードY
	static const int LASER_TIME;			//レーザーの射出時間


	Laser(){}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	Laser(DrawObject& pDrawObject, const D3DXVECTOR2& pos, const D3DXVECTOR2& size)
		:GameObject(pDrawObject, pos, size, 0.0f) {}

	virtual ~Laser() {}	//デストラクタ

	//レーザーの削除
	void DeleteLaser() { m_lasertime = -1; }

	//更新処理(弾を移動)
	void Update(const D3DXVECTOR2& pos); 
};

#endif // !_LASER_H_