//=======================================
// ���[�U�[�̓G�̊Ǘ��֌W(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#pragma once

#ifndef _ENEMY_LASER_MANAGEMENT_H_
#define _ENEMY_LASER_MANAGEMENT_H_

#include "main.h"
#include "enemylaser.h"
#include "laser.h"
#include "DrawObject.h"
#include "EnemySetPos.h"

class EnemyLaserManagement
{
//�萔
private:
	//�����ŏ�����
	//�G���g
	static const int MAX_NUM = 10;			//�G�̍ő吔
	static const int APPEARANCE_TIME = 350;	//�G�̏o���X�s�[�h

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
	EnemySetPos m_pEnemySetPos;

	int m_enemy_num = 0;	//�G�̐�
	int m_laser_num = 0;	//�e�̐�
	int m_EnemyItem_num = 0;	//�G�̃A�C�e���̐�

	int m_count = 0;		//�G�̏o�����x

public:
	//�f�t�H���g�R���X�g���N�^
	EnemyLaserManagement(){
		m_pEnemyLaser = new EnemyLaser[MAX_NUM];
		m_pLaser = new Laser[MAX_NUM];
	}	

	//�����t���R���X�g���N�^
	EnemyLaserManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2,
		EnemySetPos& pEnemySetPos );

	//�X�V����
	void Update();

	//�`�揈��
	void Draw(void)const;			


	//�w�肵���G������
	void DeleteEnemy(int index_num);

	//���݂̓G�̐���Ԃ�
	int GetEnemyNum(void)const { return m_enemy_num; }

	//�w�肵���G�̍��W��Ԃ�
	const D3DXVECTOR2& GetEnemyPos(int index_num)const { return m_pEnemyLaser[index_num].GetPos(); }

	//�G�̃T�C�Y��Ԃ�
	const D3DXVECTOR2& GetEnemySize(void)const { return m_pEnemyLaser[0].GetSize(); }


	//�w�肵���e������
	void DeleteBullet(int index_num);
	
	//���݂̒e�̐���Ԃ�
	int GetBulletNum(void)const { return m_laser_num; }

	//�w�肵���e�̍��W��Ԃ�
	const D3DXVECTOR2& GetBulletPos(int index_num)const { return m_pLaser[index_num].GetPos(); }

	//�e�̃T�C�Y��Ԃ�
	const D3DXVECTOR2& GetBulletSize(void)const { return m_pLaser[0].GetSize(); }


};

#endif // !_ENEMY_LASER_MANAGEMENT_H_