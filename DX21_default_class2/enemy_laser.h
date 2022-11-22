//=======================================
// ���[�U�[�̓G�֌W(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#pragma once

#ifndef _ENEMY_LASER_H_
#define _ENEMY_LASER_H_

#include "main.h"
#include "draw_object.h"
#include "game_object.h"

class EnemyLaser:public GameObject
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
	static const int LASER_BETWEEN = 300;	//���[�U�[�̔��ˊԊu

	//cpp�ŏ�����
	static const float SPEED_X;			//�G�̃X�s�[�hY
	static const float SPEED_Y;			//�G�̃X�s�[�hY
	static const int HP_MAX;			//�G��HP�ő�l

//�����o�ϐ�
private:
	int m_laser_count = 0;				//�e�𔭎˂���܂ł̃J�E���g
	bool m_laser_make = false;			//�e����邩�ۂ�

	float m_move_width = 0.0f;			//�G����������cos�J�[�u
	float m_init_posx = 0.0f;			//�G�̏����ʒuX

	bool m_enemyitem_make = false;		//�A�C�e������邩�ۂ�

	int m_laser_index = -1;	//���[�U�[�ԍ�

	int m_hp = HP_MAX;					//�G�̌��݂�HP

//�����o�֐�
public:
	EnemyLaser(){}		//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	EnemyLaser(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:GameObject(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y)), m_init_posx(pos.x) {}

	~EnemyLaser()override{}	//�f�X�g���N�^

	void Update(void);	//�X�V����

	//�e����邩�ۂ��̃t���O��Ԃ�
	bool GetFlagBulletMake()const { return m_laser_make; }

	//�e�������
	void BulletMake() { m_laser_make = false; }

	//�G�̃A�C�e������邩�ۂ��̃t���O��Ԃ�
	bool GetFlagEnemyItemMake()const { return m_enemyitem_make; }

	//�G�̃A�C�e���������
	void EnemyItemMake() { m_enemyitem_make = false; }

	//���[�U�[�ԍ����Z�b�g
	void SetLaserIndex(int num) { m_laser_index = num; }

	//���[�U�[�ԍ���Ԃ�
	int GetLaserIndex() const { return m_laser_index; }
};

#endif // !_ENEMY_LASER_H_