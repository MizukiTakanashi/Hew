//=======================================
// �{�X�N���X(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#pragma once

#ifndef _BOSS_H_
#define _BOSS_H_

#include "main.h"
#include "inh_enemy.h"

class Boss :public Inh_Enemy
{
	//�萔
public:
	//cpp�ŏ�����
	static const float SIZE_X;			//�T�C�YX
	static const float SIZE_Y;			//�T�C�YY
	static const float STOP_POS_Y;		//�G���~�܂�ꏊ
	static const float RANGE;			//�G�������͈�
	static const int HP_MAX = 40;		//�G��HP�ő�l
private:
	//�����ŏ�����
	static const int BULLET_TIME = 120;	//�e�̔��ˊԊu
	static const int INVINCIBLE_FLAME = 30;	//�G�̖��G����

	//cpp�ŏ�����
	static const float SPEED_X;			//�G�̃X�s�[�hY
	static const float SPEED_Y;			//�G�̃X�s�[�hY
	

	//�����o�ϐ�
private:
	int m_appearance_time = 0;			//�o�����Ă���̃J�E���g

	//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	Boss() {}

	//�����t���R���X�g���N�^
	Boss(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:Inh_Enemy(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y), HP_MAX) {}

	//�f�X�g���N�^
	~Boss()override;

	//�X�V����
	void Update(void);

	//�e����邩�ۂ��̃t���O��Ԃ�
	bool GetFlagBulletMake()const { return m_bullet_make; }

	//�e�������
	void BulletMake() { m_bullet_make = false; }

};

#endif // !_BOSS_H_