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

class EnemyNormalManagement :public EnemyManagement
{
//�萔
private:
	//�X�e�[�W
	enum class STAGE :int {
		TUTORIAL,
		MARS,
		NUM
	};

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
	EnemyNormal* m_pEnemyNormal = nullptr;
	Bullet* m_pBullet = nullptr;

	DrawObject m_pDrawObjectEnemy;
	DrawObject m_pDrawObjectBullet;

	bool m_tutorial_clear = false;	//�Ō�̓G��|�������ǂ���(�`���[�g���A��)

	int m_stage_num = 0;			//�X�e�[�W

	//�G�̔z��
	D3DXVECTOR2 m_SetEnemy[(int)STAGE::NUM][6] = {
	{//�`���[�g���A��
		D3DXVECTOR2(52.5f + (105 * 1), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 9), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 5), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 1), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 9), -EnemyNormal::SIZE_Y / 2)
	},

	{//�ΐ�
		D3DXVECTOR2(52.5f + (105 *  8), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 *  0), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 10), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 *  8), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 *  2), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 *  6), -EnemyNormal::SIZE_Y / 2)
	}

	};

	int m_SetEnemyTime[(int)STAGE::NUM][6] = {
	{//�`���[�g���A��
		60 * 40,
		60 * 40 + 1,
		60 * 45,
		60 * 80,
		60 * 80 + 1
	},

	{//�ΐ�
		60 * 5,
		60 * 60,
		60 * 60 + 1,
		60 * 80,
		60 * 145,
		60 * 160
	}

	};

//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	EnemyNormalManagement() {}

	//�����t���R���X�g���N�^
	EnemyNormalManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, int stage);

	//�f�X�g���N�^
	~EnemyNormalManagement()override { delete[] m_pEnemyNormal; delete[] m_pBullet; }

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
	const D3DXVECTOR2& GetObjPos(int index_num)const override { return m_pEnemyNormal[index_num].GetPos(); }

	//�w�肵���ԍ��̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override { return m_pEnemyNormal[index_num].GetSize(); }

	//�w�肵���e�̍��W��Ԃ�
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return m_pBullet[index_num].GetPos(); }

	//�e�̃T�C�Y��Ԃ�
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override { return m_pBullet[index_num].GetSize(); }

	//�`���[�g���A���̃N���A����
	bool IsClear(void)const { return m_tutorial_clear; }

	//�w�肵���ԍ��̓G���~�߂�
	void StopEnemy(int index_num, int time) override { m_pEnemyNormal[index_num].StopEnemy(time); }

};

#endif // !_ENEMY_NORMAL_MANAGEMENT_H_