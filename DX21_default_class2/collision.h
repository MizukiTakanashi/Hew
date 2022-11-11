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
//メンバ関数
public:
	Collision(){}	//デフォルトコンストラクタ

	~Collision(){}	//デストラクタ

	//四角形同士の当たり判定 true:当たった false:当たってない
	//pos1：オブジェクト1の座標　pos2：オブジェクト2の座標　
	//size1：オブジェクト1のサイズ　size2：オブジェクト2のサイズ
	static bool ColBox(const D3DXVECTOR2& pos1, const D3DXVECTOR2& pos2, 
		const D3DXVECTOR2& size1, const D3DXVECTOR2& size2);

	//丸同士の当たり判定 true:当たった false:当たってない
	//pos1：オブジェクト1の座標　pos2：オブジェクト2の座標
	//rot1：オブジェクト1の半径　rot2：オブジェクト2の半径
	static bool ColCircle(const D3DXVECTOR2& pos1, const D3DXVECTOR2& pos2, float rot1, float rot2);
};

#endif // !_COLLISION_H_
