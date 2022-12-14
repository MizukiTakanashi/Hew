//=======================================
// ���[�U�[�̓G�֌W(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#pragma once

#include "main.h"
#include "inh_enemy.h"

class EnemyLaser:public Inh_Enemy
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
	static const int INVINCIBLE_FLAME = 30;			//�G�̖��G����
	static const int HP_MAX = 3;			//�G��HP�ő�l

	//cpp�ŏ�����
	static const float SPEED_X;			//�G�̃X�s�[�hY
	static const float SPEED_Y;			//�G�̃X�s�[�hY

//�����o�ϐ�
private:
	int m_laser_index = -1;	//���[�U�[�ԍ�


//�����o�֐�
public:
	EnemyLaser(){}		//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	EnemyLaser(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:Inh_Enemy(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y), HP_MAX) {}

	~EnemyLaser()override{}	//�f�X�g���N�^

	void Update(void);	//�X�V����

	//���[�U�[�ԍ����Z�b�g
	void SetLaserIndex(int num) { m_laser_index = num; }

	//���[�U�[�ԍ���Ԃ�
	int GetLaserIndex() const { return m_laser_index; }

};
