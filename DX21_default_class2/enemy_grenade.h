//=======================================
// �O���|���̓G�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/12/27
// �쐬�ҁF��������
//=======================================
#pragma once

#ifndef _ENEMY_GRENADE_H_
#define _ENEMY_GRENADE_H_

#include "main.h"
#include "inh_enemy.h"

class EnemyGrenade :public Inh_Enemy
{
	//�萔
public:
	//cpp�ŏ�����
	static const float SIZE_X;			//�T�C�YX
	static const float SIZE_Y;			//�T�C�YY
	static const float STOP_POS_Y;		//�G���~�܂�ꏊ
	static const float RANGE;			//�G�������͈�

private:
	//�����ŏ�����
	static const int BULLET_TIME = 300;	//�e�̔��ˊԊu
	static const int HP_MAX = 2;		//�G��HP�ő�l

	//cpp�ŏ�����
	static const float SPEED_X;			//�G�̃X�s�[�hY
	static const float SPEED_Y;			//�G�̃X�s�[�hY
	static const float ALPHA_SPEED;		//�A���t�@�l�ύX�X�s�[�h

	//�����o�ϐ�
private:
	int m_appearance_time = 0;			//�o�����Ă���̃J�E���g
	float m_alpha = 1.0f;				//�A���t�@�l
	bool m_alpha_flag = false;			//�A���t�@�l��ς��Ă�����

	//�����o�֐�
public:
	EnemyGrenade() {}		//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	EnemyGrenade(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:Inh_Enemy(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y), HP_MAX) {}

	~EnemyGrenade()override {}	//�f�X�g���N�^

	void Update(void);	//�X�V����

	//�o�����Ă���̃J�E���g�𐔂���
	int GetAppearanceTime(void)const { return m_appearance_time; }

	//�A���t�@�l���A��t���O���I��
	void OnAlphaFlag(void) { m_alpha_flag = true; }

	//���݂̃A���t�@�l��Ԃ�
	float GetAlpha(void)const { return m_alpha; }
};

#endif // !_ENEMY_GRENADE_H_