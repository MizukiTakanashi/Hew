//=======================================
// 画面外に出たか関係(cppファイル)
// 作成日：2022/09/15
// 作成者：高梨水希
//=======================================
#include "screen_out.h"

//==========================
// 画面外に出たか否か
//==========================
bool ScreenOut::GetScreenOut(const D3DXVECTOR2& pos, const D3DXVECTOR2& size)
{
	if (pos.x - size.x / 2 > SCREEN_WIDTH ||
		pos.x + size.x / 2 < 0 ||
		pos.y - size.y / 2 > SCREEN_HEIGHT ||
		pos.y + size.y / 2 < 0) {
		return true;
	}

	return false;
}

//==========================
// 画面外に出たら戻す
//==========================
const D3DXVECTOR2& ScreenOut::GetScreenIn(const D3DXVECTOR2& pos, const D3DXVECTOR2& size)
{
	D3DXVECTOR2 result_pos = pos;

	if (pos.x + size.x / 2 > SCREEN_WIDTH) {
		result_pos.x = SCREEN_WIDTH - size.x / 2;
	}
	else if (pos.x - size.x / 2 < 0) {
		result_pos.x = size.x / 2;
	}

	if (pos.y + size.y / 2 > SCREEN_HEIGHT) {
		result_pos.y = SCREEN_HEIGHT - size.y / 2;
	}
	else if (pos.y - size.y / 2 < 0) {
		result_pos.y = size.y / 2;
	}

	//最終的に出た座標を返す
	return result_pos;
}
