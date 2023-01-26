//=======================================
// �������~�߂�G�̊Ǘ��֌W(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#pragma once

#ifndef _ENEMY_STOP_MANAGEMENT_H_
#define _ENEMY_STOP_MANAGEMENT_H_

#include "main.h"
#include "management_enemy.h"
#include "draw_object.h"
#include "enemy_stop.h"
#include "bullet_stop.h"

class EnemyStopManagement:public EnemyManagement
{
//�萔
private:
	//�����ŏ�����
	//�G���g
	static const int ENEMY_NUM = 5;		//�G���o�������鐔
	static const int BULLET_TIME = 60;		
	static const int BULLET_NUM = 20;	//�����ɏo����e

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
	EnemyStop* m_pEnemy = nullptr;			//�G�̃N���X
	BulletStop* m_pBullet = nullptr;		//�e�̃N���X
	DrawObject m_pDrawObjectEnemy;			//�G�̕`��I�u�W�F�N�g
	DrawObject m_pDrawObjectBullet;			//�e�̕`��I�u�W�F�N�g
	int m_SE_11 = 0;						//��C���o�������̉�

	//�G�̈ʒu�z��
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
		D3DXVECTOR2(52.5f + (105 *  1), -EnemyStop::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 *  9), -EnemyStop::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 *  1), -EnemyStop::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 *  9), -EnemyStop::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 *  0), -EnemyStop::SIZE_Y / 2)
	};

	//�G���o������
	int m_SetEnemyTime[ENEMY_NUM] = {
		60 * 30,
		60 * 30 + 1,
		60 * 105,
		60 * 105 + 1,
		60 * 170
	};

//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	EnemyStopManagement() {
		m_pEnemy = new EnemyStop[ENEMY_NUM];
		m_pBullet = new BulletStop[ENEMY_NUM];
	}

	//�����t���R���X�g���N�^
	EnemyStopManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2);

	//�f�X�g���N�^
	~EnemyStopManagement()override{}

	//�X�V����
	void Update(void);

	//�`�揈��
	void Draw(void)const;

	//�w�肵����HP�����炷�@�G�����񂾂�true��Ԃ�
	bool ReduceHP(int index_num, int reduceHP)override;

	//�w�肵���G������
	void DeleteObj(int index_num)override;

	//�w�肵���e������
	void DeleteBullet(int index_num)override;

	//�w�肵���ԍ��̓G�̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjPos(int index_num)const override{ return m_pEnemy[index_num].GetPos(); }

	//�w�肵���ԍ��̓G�̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override{ return m_pEnemy[0].GetSize(); }

	//�w�肵���ԍ��̒e�̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return m_pBullet[index_num].GetPos(); }

	//�w�肵���ԍ��̒e�̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override{ return m_pBullet[0].GetSize(); }

	//�e�̍U���͂�Ԃ�
	int GetBulletAttack(void) const override { return 0; }

	//�w�肵���ԍ��̓G���~�߂�
	void StopEnemy(int index_num, int time) override { m_pEnemy[index_num].StopEnemy(time); }

};

#endif // !_ENEMY_STOP_MANAGEMENT_H_