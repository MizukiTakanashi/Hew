#pragma once

//=======================================
// �{���֌W(�w�b�_�t�@�C��)
// �쐬���F2022/12/07
// �쐬�ҁF��������
//=======================================

#ifndef _BOM_H_
#define _BOM_H_


#include "game_object.h"
#include "draw_object.h"

class Bom :public GameObject
{
//�萔
private:
	//�����ŏ�����
	static const int TIME_LIMIT = 60;	//�{�����o���Ă鎞��
	static const int ATTACK = 10;		//�{���̍U����


//�����o�ϐ�
private:
	int m_time = -1;					//�{�����o���Ă���̌o�ߎ���
	int m_num = 0;						//�{���̌��݂̐�
	int m_num_max = 0;					//�{���̍ő吔


//�����o�֐�
public:
	Bom() {}	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	Bom(DrawObject& pDrawObject, int num_max)
		:GameObject(pDrawObject, D3DXVECTOR2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), 
			D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT), 0.0f), m_num_max(num_max) {}

	~Bom()override {}	//�f�X�g���N�^

	//�X�V����
	void Update(void);

	//�`�揈��
	void BomDraw(void);

	//�{�����I����Ă��邩�ǂ����̃t���O��Ԃ�
	bool IsBomb(void)const { 
		if (m_time == -1) {
			return false;
		}
		return true;
	}

	//�{���̍U���͂�Ԃ�
	int GetBombAttack(void)const { return ATTACK; }
};

#endif // !_BOM_H_