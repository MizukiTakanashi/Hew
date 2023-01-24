//=======================================
// ���[�U�[�̓G�̊Ǘ��֌W(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#pragma once

#ifndef _ENEMY_LASER_MANAGEMENT_H_
#define _ENEMY_LASER_MANAGEMENT_H_

#include "main.h"
#include "management_enemy.h"
#include "enemy_laser.h"
#include "laser.h"
#include "draw_object.h"

class EnemyLaserManagement:public EnemyManagement
{
//�萔
private:
	//�����ŏ�����
	//�G���g
	static const int ENEMY_NUM[(int)STAGE::NUM];	//�G���o�������鐔W
	static const int EXIT_TIME = 60 * 15;	//�ޏo����

	//cpp�ŏ�����
	//�e
	static const float BULLET_SIZE_X;		//�T�C�YX
	static const float BULLET_SIZE_Y;		//�T�C�YY
	
	static const float EXIT_MOVE_SPEED_X;	//�ޏo�X�s�[�hX

public:
	//�����ŏ�����
	//�G���g
	static const int ATTACK = 1;			//�U���l
	//�e
	static const int LASER_ATTACK = 1;		//�U���l


//�����o�ϐ�
private:
	EnemyLaser* m_pEnemyLaser = nullptr;
	Laser* m_pLaser = nullptr;
	DrawObject m_pDrawObjectEnemy;
	DrawObject m_pDrawObjectLaser;

	int m_SE_06 = 0;	//�r�[����
	int m_SE_07 = 0;	//�r�[�����ˉ�
	int m_SE_14 = 0;	//�M����
	int m_SE_19 = 0;	//�K�X���ˉ�

	//�G�̔z��
	D3DXVECTOR2 m_SetEnemy[(int)STAGE::NUM][4] = {
		//��
		{
			D3DXVECTOR2(52.5f + (105 * 4), -EnemyLaser::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 6), -EnemyLaser::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 5), -EnemyLaser::SIZE_Y / 2),
		},
		//�ΐ�
		{
			D3DXVECTOR2(0.0f, 0.0f),
			D3DXVECTOR2(0.0f, 0.0f),
			D3DXVECTOR2(0.0f, 0.0f)
		},
		//����
		{
			D3DXVECTOR2(71.0f + (142.0f * 3.0f), -EnemyLaser::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 5.0f), -EnemyLaser::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 0.0f), -EnemyLaser::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 8.0f), -EnemyLaser::SIZE_Y / 2)
		},
		//�y��
		{
			D3DXVECTOR2(71.0f + (142.0f * 0.0f), -EnemyLaser::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 8.0f), -EnemyLaser::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 3.0f), -EnemyLaser::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 5.0f), -EnemyLaser::SIZE_Y / 2)
		}
	};
	//�G���o������
	int m_SetEnemyTime[(int)STAGE::NUM][4] = {
		//��
		{
			60 * 60,
			60 * 60 + 1,
			60 * 80,
		},
		//�ΐ�
		{
			0, 0, 0,
		},
		//����
		{
			60 * 60,
			60 * 60 + 1,
			60 * 100,
			60 * 100 + 1,
		},
		//�y��
		{
			60 * 1,
			60 * 40 + 1,
			60 * 165,
			60 * 165 + 1
		}
	};


//�����o�[�֐�
public:
	//�����t���R���X�g���N�^
	EnemyLaserManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, int stage);

	//�f�X�g���N�^
	~EnemyLaserManagement()override{}

	//�X�V����
	void Update();

	//�`�揈��
	void Draw(void)const;			

	//�w�肵����HP�����炷�@�G�����񂾂�true��Ԃ�
	bool ReduceHP(int index_num, int reduceHP)override;

	//�w�肵���G������
	void DeleteObj(int index_num)override;

	//�w�肵���e������
	void DeleteBullet(int index_num)override;

	//�w�肵���ԍ��̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjPos(int index_num)const override { return m_pEnemyLaser[index_num].GetPos(); }

	//�w�肵���ԍ��̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override { return m_pEnemyLaser[index_num].GetSize(); }

	//�w�肵���e�̍��W��Ԃ�
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return m_pLaser[index_num].GetPos(); }

	//�e�̃T�C�Y��Ԃ�
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override{ return m_pLaser[index_num].GetSize(); }

	//�w�肵���ԍ��̓G���~�߂�
	void StopEnemy(int index_num, int time) override { m_pEnemyLaser[index_num].StopEnemy(time); }

};

#endif // !_ENEMY_LASER_MANAGEMENT_H_