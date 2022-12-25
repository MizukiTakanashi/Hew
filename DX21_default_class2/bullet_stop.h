//=======================================
// 動きを止める弾関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#pragma once
#ifndef _BULLET_STOP_H_
#define _BULLET_STOP_H_

#include <time.h>
#include "game_object.h"
#include "draw_object.h"

class BulletStop:public GameObject
{
private:
	int m_time = 0;									//弾が出来てからの経過時間

public:
	BulletStop(){}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	BulletStop(DrawObject& pDrawObject, const D3DXVECTOR2& pos, const D3DXVECTOR2& size, float rot = 0.0f)
		:GameObject(pDrawObject, pos, size, rot){}

	~BulletStop()override {}	//デストラクタ

	//更新処理(弾を移動)(経過時間を計測)
	void Update(void) {m_time++; }

	//弾が出来てからの経過時間を返す
	int GetTime(void)const { return m_time; }
};

#endif // !_BULLET_STOP_H_