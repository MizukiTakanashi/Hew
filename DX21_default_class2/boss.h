//=======================================
// �{�X�N���X(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#pragma once

#ifndef _BOSS_H_
#define _BOSS_H_

#include "game_object.h"
#include "management.h"

class Boss :public GameObject
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
	static const int HP_MAX = 100;		//�G��HP�ő�l

	//cpp�ŏ�����
	static const float POS_X;			//�|�W�V����X
	static const float POS_Y;			//�|�W�V����Y
	static const float SPEED_X;			//�G�̃X�s�[�hY
	static const float SPEED_Y;			//�G�̃X�s�[�hY
	static const int INVINCIBLE_FLAME = 30;			//�G�̖��G����
	static const float ALPHA_SPEED;		//�A���t�@�l�ύX�X�s�[�h


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
	int m_stop_time = 0; //�G�̃A�b�v�f�[�g���~�߂鎞��
	int m_appearance_time = 0;			//�o�����Ă���̃J�E���g
	float m_alpha = 1.0f;				//�A���t�@�l
	bool m_alpha_flag = false;			//�A���t�@�l��ς��Ă�����

	//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	Boss() {}

	//�����t���R���X�g���N�^
	Boss(DrawObject& pDrawObject)
		: GameObject(pDrawObject, D3DXVECTOR2(POS_X, POS_Y), D3DXVECTOR2(SIZE_X, SIZE_Y)), m_hp(HP_MAX), m_init_posx(POS_X) {}

	//�f�X�g���N�^
	~Boss()override {}

	//�X�V����
	void Update(void);

	//�e����邩�ۂ��̃t���O��Ԃ�
	bool GetFlagBulletMake()const { return m_bullet_make; }

	//�e�������
	void BulletMake() { m_bullet_make = false; }

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

	//�G���~�߂鎞�Ԃ��Z�b�g
	void StopEnemy(int time) { m_stop_time = time; }

	//�o�����Ă���̃J�E���g�𐔂���
	int GetAppearanceTime(void)const { return m_appearance_time; }

	//�A���t�@�l���A��t���O���I��
	void OnAlphaFlag(void) { m_alpha_flag = true; }

	//���݂̃A���t�@�l��Ԃ�
	float GetAlpha(void)const { return m_alpha; }

};

#endif // !_BOSS_H_