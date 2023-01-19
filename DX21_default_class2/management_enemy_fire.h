//=======================================
// ���ʂ̓G�̊Ǘ��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/09/13
// �쐬�ҁF��������
//=======================================
#pragma once

#ifndef _ENEMY_NORMAL_MANAGEMENT_H_
#define _ENEMY_NORMAL_MANAGEMENT_H_

#include "main.h"
#include "management_enemy.h"
#include "enemy_normal.h"
#include "bullet.h"
#include "draw_object.h"

class EnemyFireManagement :public EnemyManagement
{
//�萔
private:
	//�����ŏ�����
	//�G���g
	static const int BULLET_BREAK_TIME = 200;	//�z�[�~���O�e�����鎞��
	static const int EXIT_TIME = 60 * 10;		//�ޏo����

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
	EnemyNormal* m_pEnemy = nullptr;
	Bullet* m_pBullet = nullptr;

	DrawObject m_pDrawObjectEnemy;
	DrawObject m_pDrawObjectBullet;

	int m_SE_15_1 = 0;						//���ˉ�


	//�G�̔z��
	D3DXVECTOR2 m_SetEnemy[(int)STAGE::NUM][6] = {
	//�`���[�g���A��
	{
		D3DXVECTOR2(0.0f, 0.0f),
		D3DXVECTOR2(0.0f, 0.0f),
		D3DXVECTOR2(0.0f, 0.0f),
		D3DXVECTOR2(0.0f, 0.0f),
		D3DXVECTOR2(0.0f, 0.0f)
	},
	//�ΐ�
	{
		D3DXVECTOR2(0.0f, 0.0f),
		D3DXVECTOR2(0.0f, 0.0f),
		D3DXVECTOR2(0.0f, 0.0f),
		D3DXVECTOR2(0.0f, 0.0f),
		D3DXVECTOR2(0.0f, 0.0f)
	},
	//����
	{
		D3DXVECTOR2(71.0f + (142 * 2), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 3), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 2), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 2), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 2), -EnemyNormal::SIZE_Y / 2)
	},
	//�y��
	{
		D3DXVECTOR2(0.0f, 0.0f),
		D3DXVECTOR2(0.0f, 0.0f),
		D3DXVECTOR2(0.0f, 0.0f),
		D3DXVECTOR2(0.0f, 0.0f),
		D3DXVECTOR2(0.0f, 0.0f)
	}

	};

	int m_SetEnemyTime[(int)STAGE::NUM][6] = {
	{//�`���[�g���A��
		0, 0, 0, 0, 0, 0
	},

	{//�ΐ�
		0, 0, 0, 0, 0, 0
	},

	{//����
		60 * 5,
		60 * 60,
		60 * 60 + 1,
		60 * 80,
		60 * 145,
		60 * 160
	},

	{//�y��
		0, 0, 0, 0, 0, 0
	}

	};


//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	EnemyFireManagement() {}

	//�����t���R���X�g���N�^
	EnemyFireManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, int stage);

	//�f�X�g���N�^
	~EnemyFireManagement()override { delete[] m_pEnemy; delete[] m_pBullet; }

	//�X�V����
	void Update();

	//�`�揈��
	void Draw(void)const;

	//�w�肵����HP�����炷
	bool ReduceHP(int index_num, int reduceHP)override;

	//�w�肵���G������
	void DeleteObj(int index_num)override;

	//�w�肵���e������
	void DeleteBullet(int index_num)override;

	//�w�肵���ԍ��̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjPos(int index_num)const override { return m_pEnemy[index_num].GetPos(); }

	//�w�肵���ԍ��̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override { return m_pEnemy[index_num].GetSize(); }

	//�w�肵���e�̍��W��Ԃ�
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return m_pBullet[index_num].GetPos(); }

	//�e�̃T�C�Y��Ԃ�
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override { return m_pBullet[index_num].GetSize(); }

	//�w�肵���ԍ��̓G���~�߂�
	void StopEnemy(int index_num, int time) override { m_pEnemy[index_num].StopEnemy(time); }

};

#endif // !_ENEMY_NORMAL_MANAGEMENT_H_