//=======================================
// 当たり判定関係(ヘッダファイル)
// 作成日：2022/06/27
// 作成者：高梨水希
//=======================================

#ifndef _COLLISION_H_
#define _COLLISION_H_

#include "main.h"

class Collision
{
private:						//半径2(丸)

public:
	Collision(){}	//デフォルトコンストラクタ

	~Collision(){}	//デストラクタ

	//四角形同士の当たり判定 true:当たった false:当たってない
	static bool ColBox(const D3DXVECTOR2& pos1, const D3DXVECTOR2& pos2, 
		const D3DXVECTOR2& size1, const D3DXVECTOR2& size2);

	//丸同士の当たり判定 true:当たった false:当たってない
	static bool ColCircle(const D3DXVECTOR2& pos1, const D3DXVECTOR2& pos2, float rot1, float rot2);
};

#endif // !_COLLISION_H_
