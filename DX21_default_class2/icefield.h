#pragma once
// �����̕X�M�~�b�N�̃X�e�[�W�M�~�b�N
//����ҁF����đ�

#include "inh_enemy.h"
#include "main.h"

class IceField :public Inh_Enemy
{
	//�萔
public:
	//cpp�ŏ�����
	static const float SIZE_X;			//�T�C�YX
	static const float SIZE_Y;			//�T�C�YY

private:
	static const int INVINCIBLE_FLAME = 30;	//�G�̖��G����

	//cpp�ŏ�����
	static const float SPEED_X;			//�G�̃X�s�[�hY
	static const float SPEED_Y;			//�G�̃X�s�[�hY
	static const int HP_MAX = 1000;		//�G��HP�ő�l


	//�����o�ϐ�
private:
	float m_move_width = 0.0f;			//�G����������cos�J�[�u
	float m_init_posx = 0.0f;			//�G�̏����ʒuX

	int m_hp = HP_MAX;					//�G�̌��݂�HP
	int m_invincible_flame = 0;			//���G���Ԃ̎c��


	//�����o�֐�
public:
	IceField() {}	//�f�t�H���g�R���X�g���N�^

	IceField(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:Inh_Enemy(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y), HP_MAX) {}

	~IceField()override {}

	void Update(void);	//�X�V����

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