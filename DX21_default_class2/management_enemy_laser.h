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
	static const int ENEMY_NUM = 3;		//�G���o�������鐔

	//cpp�ŏ�����
	//�e
	static const float BULLET_SIZE_X;		//�T�C�YX
	static const float BULLET_SIZE_Y;		//�T�C�YY

public:
	//�����ŏ�����
	//�G���g
	static const int ATTACK = 1;			//�U���l
	//�e
	static const int LASER_ATTACK = 1;		//�U���l


private:
	//�����o�ϐ�
	EnemyLaser* m_pEnemyLaser = nullptr;
	Laser* m_pLaser = nullptr;
	DrawObject m_pDrawObjectEnemy;
	DrawObject m_pDrawObjectLaser;
	DrawObject m_pDrawObjectLaser1;

	int m_EnemyItem_num = 0;	//�G�̃A�C�e���̐�

	//�G�̔z��
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = { 
		D3DXVECTOR2(52.5f + (105 *  4), -EnemyLaser::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 *  6), -EnemyLaser::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 *  5), -EnemyLaser::SIZE_Y / 2),
	};
	//�G���o������
	int m_SetEnemyTime[ENEMY_NUM] = { 
		60 * 60,
		60 * 60 + 1,
		60 * 80,
	};

public:
	//�f�t�H���g�R���X�g���N�^
	EnemyLaserManagement(){
		m_pEnemyLaser = new EnemyLaser[ENEMY_NUM];
		m_pLaser = new Laser[ENEMY_NUM];
	}	

	//�����t���R���X�g���N�^
	EnemyLaserManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, DrawObject& pDrawObject3);

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

};

#endif // !_ENEMY_LASER_MANAGEMENT_H_