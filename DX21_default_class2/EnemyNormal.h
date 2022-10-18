//=======================================
// ���ʂ̓G�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/09/13
// �쐬�ҁF��������
//=======================================
#pragma once

#ifndef _ENEMY_NORMAL_H_
#define _ENEMY_NORMAL_H_

#include "main.h"
#include "bullet.h"
#include "DrawObject.h"
#include "GameObject.h"

class EnemyNormal:public GameObject
{
//�萔
public:
	//cpp�ŏ�����
	static const float SIZE_X;			//�T�C�YX
	static const float SIZE_Y;			//�T�C�YY
	static const float STOP_POS_X;		//�G���~�܂�ꏊ

private:
	//�����ŏ�����
	static const int BULLET_TIME = 200;	//�e�̔��ˊԊu

	//cpp�ŏ�����
	static const float SPEED;			//�G�̃X�s�[�h


private:
	//�����o�ϐ�
	int m_bullet_count = 0;		//�e�𔭎˂���܂ł̃J�E���g
	bool m_bullet_make = false;	//�e����邩�ۂ�

public:
	EnemyNormal(){}		//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	EnemyNormal(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:GameObject(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y)){}

	~EnemyNormal(){}	//�f�X�g���N�^

	void Update(void);	//�X�V����

	//�e����邩�ۂ��̃t���O��Ԃ�
	bool GetFlagBulletMake()const { return m_bullet_make; }

	//�e�������
	void BulletMake() { m_bullet_make = false; }
};

#endif // !_ENEMY_NORMAL_H_