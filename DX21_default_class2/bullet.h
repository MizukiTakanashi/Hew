//=======================================
// 弾関係(ヘッダファイル)
// 作成日：2022/07/07
// 作成者：高梨水希
//=======================================

#ifndef _BULLET_H_
#define _BULLET_H_

#include "GameObject.h"
#include "DrawObject.h"

class Bullet:public GameObject
{
private:
	D3DXVECTOR2 m_mov = D3DXVECTOR2(0.0f, 0.0f);

public:
	Bullet(){}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	Bullet(DrawObject& pDrawObject, const D3DXVECTOR2& pos, const D3DXVECTOR2& size, const D3DXVECTOR2& mov, float rot)
		:GameObject(pDrawObject, pos, size, rot), m_mov(mov){}

	virtual ~Bullet() {}	//デストラクタ

	//更新処理(弾を移動)
	void Update(void){ GameObject::MovePos(m_mov); }
};

#endif // !_BULLET_H_