//=======================================
// 画面外に出たか関係(cppファイル)
// 作成日：2022/09/15
// 作成者：高梨水希
//=======================================
#include "ScreenOut.h"

//==========================
// 画面外に出たか否か
//==========================
bool ScreenOut::GetScreenOut(D3DXVECTOR2 pos, D3DXVECTOR2 size)
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
void ScreenOut::GetScreenIn(D3DXVECTOR2 pos, D3DXVECTOR2 size)
{
	if (pos.x + size.x / 2 > SCREEN_WIDTH) {
		pos.x = SCREEN_WIDTH - size.x / 2;
	}
	else if (pos.x - size.x / 2 < 0) {
		pos.x = size.x / 2;
	}

	if (pos.y + size.y / 2 > SCREEN_HEIGHT) {
		pos.y = SCREEN_HEIGHT - size.y / 2;
	}
	else if (pos.y - size.y / 2 < 0) {
		pos.y = size.y / 2;
	}
}
