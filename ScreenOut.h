//=======================================
// ��ʊO�ɏo�����֌W(cpp�t�@�C��)
// �쐬���F2022/09/15
// �쐬�ҁF��������
//=======================================
#pragma once

#ifndef _SCREEN_OUT_H_
#define _SCREEN_OUT_H_

#include "main.h"

class ScreenOut
{
public:
	ScreenOut(){}	//�f�t�H���g�R���X�g���N�^

	~ScreenOut(){}	//�f�X�g���N�^

	static bool GetScreenOut(D3DXVECTOR2 pos, D3DXVECTOR2 size);

	static void GetScreenIn(D3DXVECTOR2 pos, D3DXVECTOR2 size);
};

#endif // !_SCREEN_OUT_H_