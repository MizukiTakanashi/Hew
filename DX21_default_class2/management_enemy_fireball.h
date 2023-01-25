//=======================================
// �΋��̓G�̊Ǘ��֌W(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#pragma once

#ifndef _ENEMY_FIREBALL_MANAGEMENT_H_
#define _ENEMY_FIREBALL_MANAGEMENT_H_

#include "main.h"
#include "management_enemy.h"
#include "enemy_normal.h"
#include "bullet.h"
#include "draw_object.h"

class EnemyFireballManagement :public EnemyManagement
{
//�萔
private:
	//�����ŏ�����
	//�G���g
	static const int BULLET_BREAK_TIME = 200;	//�z�[�~���O�e�����鎞��
	static const int EXIT_TIME = 60 * 10;		//�ޏo����

	//cpp�ŏ�����
	static const int ENEMY_NUM = 14;		//�G���o�������鐔W
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

	int m_SE_15_2 = 0;

	//�G�̔z��
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
		D3DXVECTOR2(71.0f + (142 * 2), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 0), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 3), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 3), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 5), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 0), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 8), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 0), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 8), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 3), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 5), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 3), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 5), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 6), -EnemyNormal::SIZE_Y / 2)
	};

	int m_SetEnemyTime[ENEMY_NUM] = {
		60 * 10,
		60 * 25,
		60 * 25 + 1,
		60 * 65,
		60 * 65 + 1,
		60 * 75,
		60 * 75 + 1,
		60 * 120,
		60 * 120 + 1,
		60 * 125,
		60 * 125 + 1,
		60 * 155,
		60 * 155 + 1,
		60 * 170
	};

//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	EnemyFireballManagement() {}

	//�����t���R���X�g���N�^
	EnemyFireballManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2);

	//�f�X�g���N�^
	~EnemyFireballManagement()override { delete[] m_pEnemyNormal; delete[] m_pBullet; }

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

	//�w�肵���ԍ��̓G���~�߂�
	void StopEnemy(int index_num, int time) override { m_pEnemyNormal[index_num].StopEnemy(time); }

};

#endif // !_ENEMY_FIREBALL_MANAGEMENT_H_