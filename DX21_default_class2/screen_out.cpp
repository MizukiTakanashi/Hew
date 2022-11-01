//=======================================
// ��ʊO�ɏo�����֌W(cpp�t�@�C��)
// �쐬���F2022/09/15
// �쐬�ҁF��������
//=======================================
#include "screen_out.h"

//==========================
// ��ʊO�ɏo�����ۂ�
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
// ��ʊO�ɏo����߂�
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

	//�ŏI�I�ɏo�����W��Ԃ�
	return result_pos;
}
