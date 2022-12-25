//=======================================
// �������~�߂�e�֌W(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#pragma once
#ifndef _BULLET_STOP_H_
#define _BULLET_STOP_H_

#include <time.h>
#include "game_object.h"
#include "draw_object.h"

class BulletStop:public GameObject
{
private:
	int m_time = 0;									//�e���o���Ă���̌o�ߎ���

public:
	BulletStop(){}	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	BulletStop(DrawObject& pDrawObject, const D3DXVECTOR2& pos, const D3DXVECTOR2& size, float rot = 0.0f)
		:GameObject(pDrawObject, pos, size, rot){}

	~BulletStop()override {}	//�f�X�g���N�^

	//�X�V����(�e���ړ�)(�o�ߎ��Ԃ��v��)
	void Update(void) {m_time++; }

	//�e���o���Ă���̌o�ߎ��Ԃ�Ԃ�
	int GetTime(void)const { return m_time; }
};

#endif // !_BULLET_STOP_H_