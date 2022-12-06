//=======================================
// ���ʂ̓G�̊Ǘ��֌W(�w�b�_�t�@�C��)
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
//#include "enemy_set_pos.h"

class EnemyGatoringManagement:public EnemyManagement
{
//�萔
private:
	//�����ŏ�����
	//�G���g
	static const int ENEMY_NUM = 9;		//�G���o�������鐔

	//cpp�ŏ�����
	//�e
	static const float BULLET_SIZE_X;		//�T�C�YX
	static const float BULLET_SIZE_Y;		//�T�C�YY
	static const float BULLET_SPEED;		//�X�s�[�h

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
	//EnemySetPos m_pEnemySetPos;					//�����ɃZ�b�g���Ă����̂��N���X

	int m_EnemyItem_num = 0;	//�G�̃A�C�e���̐�

	//�G�̈ʒu�z��
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
										 D3DXVECTOR2(52.5f + (105 *  5), -EnemyGatoring::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 *  0), -EnemyGatoring::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 11), -EnemyGatoring::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 *  4), -EnemyGatoring::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 *  7), -EnemyGatoring::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 *  2), -EnemyGatoring::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 *  3), -EnemyGatoring::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 *  4), -EnemyGatoring::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 *  5), -EnemyGatoring::SIZE_Y / 2)
	};

	//�G���o������
	int m_SetEnemyTime[ENEMY_NUM] = {
								60 * 5,
								60 * 35 + 1,
								60 * 35,
								60 * 35 + 1,
								60 * 55,
								60 * 85 + 1,
								60 * 85,
								60 * 85 + 1,
								60 * 85,
	};

//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	EnemyGatoringManagement() {
		m_pEnemyGatoring = new EnemyGatoring[ENEMY_NUM];
		m_pBullet = new Bullet[ENEMY_NUM];
	}

	//�����t���R���X�g���N�^
	EnemyGatoringManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2);

	//�f�X�g���N�^
	~EnemyGatoringManagement()override{}

	//�X�V����
	void Update(const D3DXVECTOR2& PlayerPos);

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
};

#endif // !_ENEMY_Gatoring_MANAGEMENT_H_