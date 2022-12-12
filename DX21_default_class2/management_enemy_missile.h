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
//#include "enemy_missile.h"
#include "bullet.h"
#include "draw_object.h"

class EnemyMissileManagement :public EnemyManagement
{
	//�萔
private:
	//�����ŏ�����
	//�G���g
	static const int ENEMY_NUM = 10;		//�G���o�������鐔
	static const int BULLET_BREAK_TIME = 200;	//�z�[�~���O�e�����鎞��

	//cpp�ŏ�����
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

	int m_EnemyItem_num = 0;	//�G�̃A�C�e���̐�

	//�G�̔z��
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
										D3DXVECTOR2(52.5f + (105 *  1), -EnemyNormal::SIZE_Y / 2),
										D3DXVECTOR2(52.5f + (105 * 10), -EnemyNormal::SIZE_Y / 2),
										D3DXVECTOR2(52.5f + (105 *  0), -EnemyNormal::SIZE_Y / 2),
										D3DXVECTOR2(52.5f + (105 * 11), -EnemyNormal::SIZE_Y / 2),
										D3DXVECTOR2(52.5f + (105 *  2), -EnemyNormal::SIZE_Y / 2),
										D3DXVECTOR2(52.5f + (105 *  9), -EnemyNormal::SIZE_Y / 2),
										D3DXVECTOR2(52.5f + (105 *  6), -EnemyNormal::SIZE_Y / 2),
										D3DXVECTOR2(52.5f + (105 *  7), -EnemyNormal::SIZE_Y / 2),
										D3DXVECTOR2(52.5f + (105 *  8), -EnemyNormal::SIZE_Y / 2),
										D3DXVECTOR2(52.5f + (105 *  9), -EnemyNormal::SIZE_Y / 2)
										
	};
	//�G���o������
	int m_SetEnemyTime[ENEMY_NUM] = {
								60 * 15,
								60 * 15 + 1,
								60 * 50,
								60 * 50 + 1,
								60 * 70,
								60 * 70 + 1,
								60 * 85,
								60 * 85 + 1,
								60 * 85 + 2,
								60 * 85 + 3,
	};
	//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	EnemyMissileManagement() {
		m_pEnemyMissile = new EnemyNormal[ENEMY_NUM];
		m_pBullet = new Bullet[ENEMY_NUM];
	}

	//�����t���R���X�g���N�^
	EnemyMissileManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2);

	//�f�X�g���N�^
	~EnemyMissileManagement()override { delete[] m_pEnemyMissile; delete[] m_pBullet; }

	//�X�V����
	void Update(const D3DXVECTOR2& PlayerPos);

	//�`�揈��
	void Draw(void)const;

	//�w�肵����HP�����炷
	bool ReduceHP(int index_num, int reduceHP)override;

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
};

#endif // !_ENEMY_NORMAL_MISSILE_H_