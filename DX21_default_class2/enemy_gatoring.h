//=======================================
// ���ʂ̓G�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/09/13
// �쐬�ҁF��������
//=======================================
#pragma once

#ifndef _ENEMY_GATORING_H_
#define _ENEMY_GATORING_H_

#include "main.h"
#include "bullet.h"
#include "draw_object.h"
#include "game_object.h"

class EnemyGatoring :public GameObject
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
	static const int BULLET_TIME = 30;	//�e�̔��ˊԊu
	static const int INVINCIBLE_FLAME = 30;	//�G�̖��G����

	//cpp�ŏ�����
	static const float SPEED_X;			//�G�̃X�s�[�hY
	static const float SPEED_Y;			//�G�̃X�s�[�hY
	static const int HP_MAX = 1;		//�G��HP�ő�l

	//�����o�ϐ�
private:
	int m_bullet_count = 0;				//�e�𔭎˂���܂ł̃J�E���g
	bool m_bullet_make = false;			//�e����邩�ۂ�

	float m_move_width = 0.0f;			//�G����������cos�J�[�u
	float m_init_posx = 0.0f;			//�G�̏����ʒuX

	bool m_enemyitem_make = false;		//�A�C�e������邩�ۂ�

	int m_hp = HP_MAX;					//�G�̌��݂�HP
	int m_invincible_flame = 0;			//���G���Ԃ̎c��

	//�����o�֐�
public:
	EnemyGatoring() {}		//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	EnemyGatoring(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:GameObject(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y)), m_init_posx(pos.x) {}

	~EnemyGatoring()override {}	//�f�X�g���N�^

	void Update(void);	//�X�V����

	//�e����邩�ۂ��̃t���O��Ԃ�
	bool GetFlagBulletMake()const { return m_bullet_make; }

	//�e�������
	void BulletMake() { m_bullet_make = false; }

	//HP�����炷
	void ReduceHP(int amount)
	{
		if (m_invincible_flame <= 0)
		{
			m_hp -= amount;
			m_invincible_flame = INVINCIBLE_FLAME;
		}
	}

	//HP��Ԃ�
	int GetHP(void) { return m_hp; }

};

#endif // !_ENEMY_GATORING_H_