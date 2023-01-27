//=======================================
// �~�T�C���̊Ǘ��֌W(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#pragma once

#ifndef _ENEMY_NORMAL_MISSILE_H_
#define _ENEMY_NORMAL_MISSILE_H_

#include "main.h"
#include "management_enemy.h"
#include "enemy_normal.h"
#include "bullet.h"
#include "draw_object.h"

class EnemyMissileManagement :public EnemyManagement
{
//�萔
private:
	//�����ŏ�����
	//�G���g
	static const int BULLET_BREAK_TIME = 200;	//�z�[�~���O�e�����鎞��
	static const int EXIT_TIME = 60 * 10;		//�ޏo����
	static const int BULLET_NUM = 30;			//�����ɏo����e�̐�

	//cpp�ŏ�����
	static const int ENEMY_NUM[(int)STAGE::NUM];	//�G���o�������鐔W
	//�e
	static const float BULLET_SIZE_X;		//�T�C�YX
	static const float BULLET_SIZE_Y;		//�T�C�YY
	static const float BULLET_SPEED;		//�X�s�[�h

public:
	//�����ŏ�����
	//�G���g
	static const int ATTACK = 1;			//�U���l
	//�e
	static const int BULLET_ATTACK = 1;		//�U���l


//�����o�ϐ�
private:
	EnemyNormal* m_pEnemyMissile = nullptr;
	Bullet* m_pBullet = nullptr;
	DrawObject m_pDrawObjectEnemy;
	DrawObject m_pDrawObjectBullet;

	int m_SE_22 = 0;						//�e���ˉ�

	int m_EnemyItem_num = 0;				//�G�̃A�C�e���̐�

	//�G�̔z��
	D3DXVECTOR2 m_SetEnemy[(int)STAGE::NUM][35] = {
	//�`���[�g���A��
	{
		D3DXVECTOR2(52.5f + (105 * 1), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 9), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 5), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 1), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 9), -EnemyNormal::SIZE_Y / 2)
	},
	//�ΐ�
	{
		D3DXVECTOR2(52.5f + (105 * 8), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 0), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 10), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 8), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 2), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 6), -EnemyNormal::SIZE_Y / 2)
	},
	//����
	{
		D3DXVECTOR2(71.0f + (142.0f * 0), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 8), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 2), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 6), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 0), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 4), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 6), -EnemyNormal::SIZE_Y / 2),
	},
	//�y��
	{
		// 10�b
		D3DXVECTOR2(71.0f + (142.0f * 2), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 6), -EnemyNormal::SIZE_Y / 2),
		// 15
		D3DXVECTOR2(71.0f + (142.0f * 4), -EnemyNormal::SIZE_Y / 2),
		// 25�b
		D3DXVECTOR2(71.0f + (142.0f * 1), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 3), -EnemyNormal::SIZE_Y / 2),
		// 30
		D3DXVECTOR2(71.0f + (142.0f * 5), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 7), -EnemyNormal::SIZE_Y / 2),
		// 40
		D3DXVECTOR2(71.0f + (142.0f * 1), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 3), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 7), -EnemyNormal::SIZE_Y / 2),
		// 50
		D3DXVECTOR2(71.0f + (142.0f * 3), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 6), -EnemyNormal::SIZE_Y / 2),
		// 55
		D3DXVECTOR2(71.0f + (142.0f * 4), -EnemyNormal::SIZE_Y / 2),
		// 65
		D3DXVECTOR2(71.0f + (142.0f * 1), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 3), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 5), -EnemyNormal::SIZE_Y / 2),
		// 85
		D3DXVECTOR2(71.0f + (142.0f * 2), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 7), -EnemyNormal::SIZE_Y / 2),
		// 90
		D3DXVECTOR2(71.0f + (142.0f * 4), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 6), -EnemyNormal::SIZE_Y / 2),
		// 100�b
		D3DXVECTOR2(71.0f + (142.0f * 2), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 6), -EnemyNormal::SIZE_Y / 2),
		// 105
		D3DXVECTOR2(71.0f + (142.0f * 0), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 8), -EnemyNormal::SIZE_Y / 2),
		// 120
		D3DXVECTOR2(71.0f + (142.0f * 1), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 7), -EnemyNormal::SIZE_Y / 2),
		// 140
		D3DXVECTOR2(71.0f + (142.0f * 4), -EnemyNormal::SIZE_Y / 2),
		// 145
		D3DXVECTOR2(71.0f + (142.0f * 2), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 6), -EnemyNormal::SIZE_Y / 2),
		// 160
		D3DXVECTOR2(71.0f + (142.0f * 2), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 4), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 6), -EnemyNormal::SIZE_Y / 2),
		// 170
		D3DXVECTOR2(71.0f + (142.0f * 0), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 4), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 8), -EnemyNormal::SIZE_Y / 2),
	},
	//����
	{
		D3DXVECTOR2(71.0f + (142.0f * 2), -EnemyNormal::SIZE_Y / 2),
	},
	//�ؐ�
	{
		D3DXVECTOR2(71.0f + (142.0f * 3), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 5), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 0), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 4), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 8), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 0), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 8), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 4), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 2), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 6), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 0), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 8), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 3), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 4), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 5), -EnemyNormal::SIZE_Y / 2)
	}
	};

	int m_SetEnemyTime[(int)STAGE::NUM][35] = {
	//�`���[�g���A��
	{
		60 * 40,
		60 * 40 + 1,
		60 * 45,
		60 * 80,
		60 * 80 + 1
	},
	//�ΐ�
	{
		60 * 5,
		60 * 60,
		60 * 60 + 1,
		60 * 80,
		60 * 145,
		60 * 160
	},
	//����
	{
		60 * 140,
		60 * 140 + 1,
		60 * 150,
		60 * 150 + 1,
		60 * 170,
		60 * 170 + 1,
		60 * 170 + 2
	},
	//�y��
	{
		60 * 10,
		60 * 10 + 1,
		60 + 15,
		60 * 25,
		60 * 25 + 1,
		60 * 30,
		60 * 30 + 1,
		60 * 40,
		60 * 40 + 1,
		60 * 40 + 2,
		60 * 50,
		60 * 50 + 1,
		60 * 55,
		60 * 65,
		60 * 65 + 1,
		60 * 65 + 2,
		60 * 85,
		60 * 85 + 1,
		60 * 90,
		60 * 90 + 1,
		60 * 100,
		60 * 100 + 1,
		60 * 105,
		60 * 105 + 1,
		60 * 120,
		60 * 120 + 1,
		60 * 140,
		60 * 145,
		60 * 145 + 1,
		60 * 160,
		60 * 160 + 1,
		60 * 160 + 2,
		60 * 170,
		60 * 170 + 1,
		60 * 170 + 2
	},
	//����
	{
		60 * 100,
	},
	//�ؐ�
	{
		60 * 10,
		60 * 10 + 1,
		60 * 40,
		60 * 40 + 1,
		60 * 40 + 2,
		60 * 65,
		60 * 65 + 1,
		60 * 75,
		60 * 130,
		60 * 130 + 1,
		60 * 140,
		60 * 140 + 1,
		60 * 165,
		60 * 165 + 1,
		60 * 165 + 2,
	}
	};

	//�����o�֐�
public:
	//�����t���R���X�g���N�^
	EnemyMissileManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, int stage);

	//�f�X�g���N�^
	~EnemyMissileManagement()override { delete[] m_pEnemyMissile; delete[] m_pBullet; }

	//�X�V����
	void Update(const D3DXVECTOR2& PlayerPos);

	//�`�揈��
	void Draw(void)const;

	//�w�肵����HP�����炷
	bool ReduceHP(int index_num, int reduceHP)override;

	//�w�肵���G������
	void DeleteObj(int index_num)override;

	//�w�肵���e������
	void DeleteBullet(int index_num)override;

	//�w�肵���ԍ��̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjPos(int index_num)const override { return m_pEnemyMissile[index_num].GetPos(); }

	//�w�肵���ԍ��̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override { return m_pEnemyMissile[index_num].GetSize(); }

	//�w�肵���e�̍��W��Ԃ�
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return m_pBullet[index_num].GetPos(); }

	//�e�̃T�C�Y��Ԃ�
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override { return m_pBullet[index_num].GetSize(); }

	//�w�肵���ԍ��̓G���~�߂�
	void StopEnemy(int index_num, int time) override { m_pEnemyMissile[index_num].StopEnemy(time); }

};

#endif // !_ENEMY_NORMAL_MISSILE_H_