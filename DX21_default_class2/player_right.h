#pragma once
//=======================================
// ���@�̉E(�w�b�_)
// �쐬���F2022/10/23
// �쐬�ҁF���c�m�s
//=======================================
#ifndef PLAYER_RIGHT_H_
#define PLAYER_RIGHT_H_

#include "inh_player_arm_both.h"
#include "draw_object.h"

class PlayerRight :public inhPlayerArmBoth
{
	//�萔
private:
	//�����ŏ�����
	static const int TRIGGER = 100;				//�g���K�[�̏d��(0�`255)
	
	//cpp�ŏ�����
	static const D3DXVECTOR2 FROM_PLAYER_POS;	//�v���C���[����ǂꂭ�炢����Ă��邩

	//�����o�֐�
public:
	PlayerRight() {}			//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	PlayerRight(const D3DXVECTOR2& pos, DrawObject& pDrawobNumber, D3DXVECTOR2 num_pos, D3DXVECTOR2 icon_pos)
		:inhPlayerArmBoth(pos, FROM_PLAYER_POS, pDrawobNumber, num_pos, icon_pos) {}

	~PlayerRight()override {}	//�f�X�g���N�^

	//�{�^������
	void ButtonPress(void);
};

#endif // !PLAYER_RIGHT_H_