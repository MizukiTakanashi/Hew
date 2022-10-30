#pragma once

#include <time.h>
#include "GameObject.h"
#include "DrawObject.h"

class Bullet02 :public GameObject
{
private:
	D3DXVECTOR2 m_mov = D3DXVECTOR2(0.0f, 0.0f);	//移動量
	int m_time = 0;									//弾が出来てからの経過時間

public:
	Bullet02() {}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	Bullet02(DrawObject& pDrawObject, const D3DXVECTOR2& pos, const D3DXVECTOR2& size, const D3DXVECTOR2& mov, float rot)
		:GameObject(pDrawObject, pos, size, rot), m_mov(mov) {}

	virtual ~Bullet02() {}	//デストラクタ

	//更新処理(弾を移動)(経過時間を計測)
	void Update(void) { GameObject::MovePos(m_mov); m_time++; }

	//弾の移動を再セット(ホーミング弾用かな？)
	void SetMove(const D3DXVECTOR2& mov) { m_mov = mov; }

	//弾が出来てからの経過時間を返す
	int GetTime(void)const { return m_time; }
};
