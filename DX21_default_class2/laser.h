//=======================================
// レーザー関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================

#ifndef _LASER_H_
#define _LASER_H_

#include "game_object.h"
#include "draw_object.h"
#include "enemy_laser.h"

class Laser:public GameObject
{
private:
	//D3DXVECTOR2 m_mov = D3DXVECTOR2(0.0f, 0.0f);
	EnemyLaser* m_pEnemynum = nullptr; //レーザーを射出しているエネミーのポインタ
	int m_lasertime = LASER_TIME;

public:
	static const float SPEED_Y;			//レーザーのスピードY
	static const int LASER_TIME;			//レーザーの射出時間


	Laser(){}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	Laser(DrawObject& pDrawObject, const D3DXVECTOR2& pos, const D3DXVECTOR2& size, EnemyLaser* pEnemyLaser)
		:GameObject(pDrawObject, pos, size, 0.0f), m_pEnemynum(pEnemyLaser) {}

	virtual ~Laser() {}	//デストラクタ

	bool IsLaserUse() { if (m_lasertime < 0) { return false; } return true; }

	//更新処理(弾を移動)
	void Update(void); 
};

#endif // !_LASER_H_