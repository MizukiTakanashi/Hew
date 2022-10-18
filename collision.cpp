//=======================================
// 当たり判定関係(cppファイル)
// 作成日：2022/06/27
// 作成者：高梨水希
//=======================================
#include "collision.h"

//=========================
// 四角形同士の当たり判定
//=========================
bool Collision::ColBox(const D3DXVECTOR2& pos1, const D3DXVECTOR2& pos2, 
	const D3DXVECTOR2& size1, const D3DXVECTOR2& size2)
{
	D3DXVECTOR2 min1, min2;	//四角形最小座標
	D3DXVECTOR2 max1, max2;	//四角形最大座標

	//四角形1、左上の座標
	min1 = pos1 - size1 / 2;
	//四角形1、右下の座標
	max1 = pos1 + size1 / 2;

	//四角形2、左上の座標
	min2 = pos2 - size2 / 2;
	//四角形2、右下の座標
	max2 = pos2 + size2 / 2;

	//四角形1を基準にして判定を取る
	if (max1.x < min2.x) return false;
	if (max1.y < min2.y) return false;
	if (min1.x > max2.x) return false;
	if (min1.y > max2.y) return false;

	return true;
}

//=========================
// 丸同士の当たり判定
//=========================
bool Collision::ColCircle(const D3DXVECTOR2& pos1, const D3DXVECTOR2& pos2, float rot1, float rot2)
{
	//中心同士のベクトル
	D3DXVECTOR2 distance = pos1 - pos2;

	//ベクトルの長さを作る
	float length;
	length = D3DXVec2LengthSq(&distance);	//ルートを使わないver
	//length = D3DXVec2Length(&distance);	//ルートを使うver(正確な長さ)

	//lengthが二乗のままの値のため、こちらも二乗する
	float size = (rot1 + rot2) * (rot1 + rot2);

	//もしも円と円の中心座標の長さが
	//二つの円の半径の長さよりも短ければ当たっている
	if (length < size) return true;

	return false;
}
