//=======================================
// ���@�̐^��(�w�b�_)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#pragma once
#ifndef PLAYER_CEENTER_H_
#define PLAYER_CEENTER_H_

#include "inh_player_arm_both.h"
#include "draw_object.h"

class PlayerCenter :public inhPlayerArmBoth
{
	//�萔
private:
	//�����ŏ�����
	static const int TRIGGER = 100;				//�g���K�[�̏d��(0�`255)

	//cpp�ŏ�����
	static const D3DXVECTOR2 FROM_PLAYER_POS;	//�v���C���[����ǂꂭ�炢����Ă��邩

	//�����o�֐�
public:
	PlayerCenter() {}			//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	PlayerCenter(DrawObject& pDrawObject, DrawObject& pBullet, DrawObject& pLaser, const D3DXVECTOR2& pos, Number* pNum, D3DXVECTOR2 icon_pos)
		:inhPlayerArmBoth(pDrawObject, pBullet, pLaser, pos, FROM_PLAYER_POS, pNum, icon_pos) {}

	~PlayerCenter()override {}	//�f�X�g���N�^

	//�{�^������
	void ButtonPress(void);
};

#endif // !PLAYER_CEENTER_H_