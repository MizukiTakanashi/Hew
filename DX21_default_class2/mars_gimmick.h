#pragma once
//=======================================
// �ΐ��M�~�b�N�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/01/13
// �쐬�ҁF��������
//=======================================

#ifndef _MARS_GIMMICK_H_
#define _MARS_GIMMICK_H_

#include "draw_object.h"
#include "UI.h"

class MarsGimmick:public UI
{
//�萔
public:
	//cpp�ŏ�����
	static const int TIME[6];

//�����o�ϐ�
private:
	bool m_move_down = false;	//�ړ����x�ቺ�t���O
	int m_frame_count = 0;		//�t���[���J�E���g

//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	MarsGimmick(){}

	//�����t���R���X�g���N�^
	MarsGimmick(DrawObject& pDrawObj)
		:UI(pDrawObj, D3DXVECTOR2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), 
			D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT)) {}

	//�f�X�g���N�^
	~MarsGimmick(){}

	//�X�V����
	void Update() { m_frame_count++; }

	//�ړ����x�ቺ�t���O��Ԃ�
	bool GetMoveDown() { return m_move_down; }
};

#endif // !_MARS_GIMMICK_H_