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

	static const float STOP_POS_Y;		//�G���~�܂�ꏊ

	static const float RANGE;			//�G�������͈�

private:
	//�����ŏ�����
	static const int BULLET_TIME = 200;	//�e�̔��ˊԊu

	//cpp�ŏ�����
	static const float SPEED_X;			//�G�̃X�s�[�hY
	static const float SPEED_Y;			//�G�̃X�s�[�hY


//�����o�ϐ�
private:
	int m_bullet_count = 0;				//�e�𔭎˂���܂ł̃J�E���g
	bool m_bullet_make = false;			//�e����邩�ۂ�

	float m_move_width = 0.0f;			//�G����������cos�J�[�u
	float m_init_posx = 0.0f;			//�G�̏����ʒuX

	bool m_enemyitem_make = false;		//�A�C�e������邩�ۂ�


//�����o�֐�
public:
	EnemyNormal(){}		//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	EnemyNormal(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:GameObject(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y)), m_init_posx(pos.x) {}

	~EnemyNormal(){}	//�f�X�g���N�^

	void Update(void);	//�X�V����

	//�e����邩�ۂ��̃t���O��Ԃ�
	bool GetFlagBulletMake()const { return m_bullet_make; }

	//�e�������
	void BulletMake() { m_bullet_make = false; }

	//�G�̃A�C�e������邩�ۂ��̃t���O��Ԃ�
	bool GetFlagEnemyItemMake()const { return m_enemyitem_make; }

	//�G�̃A�C�e���������
	void EnemyItemMake() { m_enemyitem_make = false; }
};

#endif // !_ENEMY_NORMAL_H_