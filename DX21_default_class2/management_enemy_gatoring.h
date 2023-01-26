//=======================================
// �������˂̓G�̊Ǘ��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/09/13
// �쐬�ҁF��������
//=======================================
#pragma once

#ifndef _ENEMY_GATORING_MANAGEMENT_H_
#define _ENEMY_GATORING_MANAGEMENT_H_

#include "main.h"
#include "management_enemy.h"
#include "enemy_gatoring.h"
#include "bullet.h"
#include "draw_object.h"

class EnemyGatoringManagement:public EnemyManagement
{
//�萔
private:
	//�����ŏ�����
	//�G���g
	static const int BULLET_NUM = 30;		//�����ɒe���o�������鐔
	static const int EXIT_TIME = 60 * 10;	//�ޏo����

	//cpp�ŏ�����
	static const int ENEMY_NUM[(int)STAGE::NUM];	//�G���o�������鐔
	//�e
	static const float BULLET_SIZE_X;		//�T�C�YX
	static const float BULLET_SIZE_Y;		//�T�C�YY
	static const float BULLET_SPEED;		//�X�s�[�h

	static const float EXIT_MOVE_SPEED_Y;	//�ޏo�X�s�[�hY

public:
	//�����ŏ�����
	//�G���g
	static const int ATTACK = 5;			//�U���l
	//�e
	static const int BULLET_ATTACK = 1;		//�U���l

//�����o�ϐ�
private:
	EnemyGatoring* m_pEnemyGatoring = nullptr;	//�G�̃N���X
	Bullet* m_pBullet = nullptr;				//�e�̃N���X
	DrawObject m_pDrawObjectEnemy;				//�G�̕`��I�u�W�F�N�g
	DrawObject m_pDrawObjectBullet;				//�e�̕`��I�u�W�F�N�g
	int m_SE_21 = 0;							//�e���ˉ�


	//�G�̈ʒu�z��
	D3DXVECTOR2 m_SetEnemy[(int)STAGE::NUM][18] = {
		//�`���[�g���A��
		{
			D3DXVECTOR2(52.5f + (105 * 5), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 2), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 8), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 3), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 7), -EnemyGatoring::SIZE_Y / 2)
		},
		//�ΐ�
		{
			D3DXVECTOR2(52.5f + (105 * 5), -EnemyGatoring::SIZE_Y / 2),
		},
		//����
		{
			D3DXVECTOR2(52.5f + (105 * 1), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 2), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 3), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 4), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 5), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 6), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 7), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 8), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 9), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 10), -EnemyGatoring::SIZE_Y / 2),

		},
		//�y��
		{
			// 5�b
			D3DXVECTOR2(71.0f + (142 * 3), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142 * 5), -EnemyGatoring::SIZE_Y / 2),
			// 25�b
			D3DXVECTOR2(71.0f + (142 * 0), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142 * 3), -EnemyGatoring::SIZE_Y / 2),
			// 40�b
			D3DXVECTOR2(71.0f + (142 * 2), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142 * 5), -EnemyGatoring::SIZE_Y / 2),
			// 60�b
			D3DXVECTOR2(71.0f + (142 * 2), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142 * 6), -EnemyGatoring::SIZE_Y / 2),
			// 90�b
			D3DXVECTOR2(71.0f + (142 * 0), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142 * 8), -EnemyGatoring::SIZE_Y / 2),
			// 110�b
			D3DXVECTOR2(71.0f + (142 * 1), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142 * 7), -EnemyGatoring::SIZE_Y / 2),
			// 150�b
			D3DXVECTOR2(71.0f + (142 * 3), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142 * 5), -EnemyGatoring::SIZE_Y / 2),
			// 155�b
			D3DXVECTOR2(71.0f + (142 * 0), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142 * 8), -EnemyGatoring::SIZE_Y / 2),
			// 170�b
			D3DXVECTOR2(71.0f + (142 * 2), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142 * 6), -EnemyGatoring::SIZE_Y / 2),
		},
		//����
		{
			D3DXVECTOR2(71.0f + (142 * 1), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142 * 7), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142 * 0), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142 * 4), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142 * 8), -EnemyGatoring::SIZE_Y / 2)
		}
	};

	//�G���o������
	int m_SetEnemyTime[(int)STAGE::NUM][18] = {
		//�`���[�g���A��
		{
			60 * 15,
			60 * 20,
			60 * 20 + 1,
			60 * 80,
			60 * 80 + 1
		},
		//�ΐ�
		{
			60 * 0,
		},
		//����
		{
			60 * 10,
			60 * 20,
			60 * 30,
			60 * 40,
			60 * 50,
			60 * 60,
			60 * 70,
			60 * 80+5 ,
			60 * 90,
			60 * 100
		},
		//�y��
		{
			60 * 5,
			60 * 5 + 1,
			60 * 25,
			60 * 25 + 1,
			60 * 40,
			60 * 40 + 1,
			60 * 60,
			60 * 60 + 1,
			60 * 90,
			60 * 90 + 1,
			60 * 110,
			60 * 110 + 1,
			60 * 150,
			60 * 150 + 1,
			60 * 155,
			60 * 155 + 1,
			60 * 170,
			60 * 170 + 1,
		},
		//����
		{
			60 * 145,
			60 * 145 + 1,
			60 * 170,
			60 * 170 + 1,
			60 * 170 + 2
		}
	};

//�����o�֐�
public:
	//�����t���R���X�g���N�^
	EnemyGatoringManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, int stage);

	//�f�X�g���N�^
	~EnemyGatoringManagement()override{}

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

	//�w�肵���ԍ��̓G�̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjPos(int index_num)const override{ return m_pEnemyGatoring[index_num].GetPos(); }

	//�w�肵���ԍ��̓G�̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override{ return m_pEnemyGatoring[0].GetSize(); }

	//�w�肵���ԍ��̒e�̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return m_pBullet[index_num].GetPos(); }

	//�w�肵���ԍ��̒e�̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override{ return m_pBullet[0].GetSize(); }

	//�w�肵���ԍ��̓G���~�߂�
	void StopEnemy(int index_num, int time) override { m_pEnemyGatoring[index_num].StopEnemy(time); }

};

#endif // !_ENEMY_Gatoring_MANAGEMENT_H_