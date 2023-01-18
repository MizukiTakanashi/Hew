#pragma once
//=======================================
// ���@�̍�(�w�b�_)
// �쐬���F2022/10/25
// �쐬�ҁF���� �@
//=======================================
#ifndef PLAYER_LEFT_H_
#define PLAYER_LEFT_H_

#include "inh_player_arm_both.h"
#include "draw_object.h"

class PlayerLeft :public inhPlayerArmBoth
{
	//�萔
private:
	//�����ŏ�����
	static const int TRIGGER = 100;				//�g���K�[�̏d��(0�`255)

	//cpp�ŏ�����
	static const D3DXVECTOR2 FROM_PLAYER_POS;	//�v���C���[����ǂꂭ�炢����Ă��邩

	//�����o�֐�
public:
	PlayerLeft() {}			//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	PlayerLeft(const D3DXVECTOR2& pos, DrawObject& pDrawobNumber, D3DXVECTOR2 num_pos, D3DXVECTOR2 icon_pos)
		:inhPlayerArmBoth(pos, FROM_PLAYER_POS, pDrawobNumber, num_pos, icon_pos) {}

	~PlayerLeft()override {}	//�f�X�g���N�^

	//�{�^������
	void ButtonPress(void);
};

#endif // !PLAYER_LEFT_H_