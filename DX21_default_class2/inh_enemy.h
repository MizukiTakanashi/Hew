//=======================================
// �p���p�G�N���X(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#pragma once

#ifndef _INH_ENEMY_H_
#define _INH_ENEMY_H_

#include "game_object.h"

class Inh_Enemy :public GameObject
{
//�萔
public:

private:
	//cpp�ŏ�����
	static const int INVINCIBLE_FLAME = 30;			//�G�̖��G����

//�����o�ϐ�
private:
	bool m_enemyitem_make = false;		//�A�C�e������邩�ۂ�
	int m_hp = 0;						//�G�̌��݂�HP

protected:
	int m_bullet_count = 0;				//�e�𔭎˂���܂ł̃J�E���g
	bool m_bullet_make = false;			//�e����邩�ۂ�
	float m_move_width = 0.0f;			//�G����������cos�J�[�u
	int m_invincible_flame = 0;			//���G���Ԃ̎c��
	float m_init_posx = 0.0f;			//�G�̏����ʒuX

//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	Inh_Enemy() {}		

	//�����t���R���X�g���N�^
	Inh_Enemy(DrawObject& pDrawObject, const D3DXVECTOR2& pos, D3DXVECTOR2 size, int hp)
		:GameObject(pDrawObject, pos, size), m_hp(hp), m_init_posx(pos.x) {}

	//�f�X�g���N�^
	~Inh_Enemy()override {}	

	//�X�V����
	virtual void Update(void) {}	

	//�e����邩�ۂ��̃t���O��Ԃ�
	bool GetFlagBulletMake()const { return m_bullet_make; }

	//�e�������
	void BulletMake() { m_bullet_make = false; }

	//�G�̃A�C�e������邩�ۂ��̃t���O��Ԃ�
	bool GetFlagEnemyItemMake()const { return m_enemyitem_make; }

	//�G�̃A�C�e���������
	void EnemyItemMake() { m_enemyitem_make = false; }

	//HP�����炷
	bool ReduceHP(int amount) 
	{
		if (m_invincible_flame <= 0)
		{
			m_hp -= amount;
			m_invincible_flame = INVINCIBLE_FLAME;

			return true;
		}
		else
		{
			return false;
		}
	}

	//HP��Ԃ�
	int GetHP(void) { return m_hp; }

};

#endif // !_INH_ENEMY_H_