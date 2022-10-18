//=======================================
// ��ʊO�ɏo�����֌W(cpp�t�@�C��)
// �쐬���F2022/09/15
// �쐬�ҁF��������
//=======================================
#include "ScreenOut.h"

//==========================
// ��ʊO�ɏo�����ۂ�
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
// ��ʊO�ɏo����߂�
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
