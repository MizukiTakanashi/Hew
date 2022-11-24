#pragma once
#include <time.h>
#include "game_object.h"
#include "draw_object.h"
class Bom :public GameObject
{
private:
	D3DXVECTOR2 m_mov = D3DXVECTOR2(0.0f, 0.0f);	//移動量
	int m_time = 0;									//弾が出来てからの経過時間

public:
	Bom() {}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	Bom(DrawObject& pDrawObject, const D3DXVECTOR2& pos, const D3DXVECTOR2& size, float rot)
		:GameObject(pDrawObject, pos, size, rot) {}

	~Bom()override {}	//デストラクタ

	//更新処理(弾を移動)(経過時間を計測)
	void Update(void) { GameObject::MovePos(m_mov); m_time++; }

	//弾の移動を再セット(ホーミング弾用かな？)
	void SetMove(const D3DXVECTOR2& mov) { m_mov = mov; }

	//弾が出来てからの経過時間を返す
	int GetTime(void)const { return m_time; }
};

