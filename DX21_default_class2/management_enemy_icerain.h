//=======================================
// �X�̓G�̊Ǘ��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/12/22
// �쐬�ҁF����đ�
//=======================================
#pragma once

#ifndef _ENEMY_ICERAIN_MANAGEMENT_H_
#define _ENEMY_ICERAIN_MANAGEMENT_H_

#include "main.h"
#include "management_enemy.h"
#include "enemy_icerain.h"
#include "bullet.h"
#include "draw_object.h"

class EnemyIceRainManagement :public EnemyManagement
{
//�萔
public:
	//�����ŏ�����
	//�G���g
	static const int ATTACK = 5;			//�U���l
	//�e
	static const int BULLET_ATTACK = 1;		//�U���l

private:
	//�����ŏ�����
	//�G���g
	static const int ENEMY_NUM[(int)STAGE::NUM];		//�G���o�������鐔
	static const int BULLET_NUM = 20;	//�����ɒe���o�������鐔

	//cpp�ŏ�����
	//�e
	static const float BULLET_SIZE_X;		//�T�C�YX
	static const float BULLET_SIZE_Y;		//�T�C�YY
	static const float BULLET_SPEED;		//�X�s�[�h


	//�����o�ϐ�
private:
	EnemyIceRain* m_pEnemyIceRain = nullptr;	//�G�̃N���X
	Bullet* m_pBullet = nullptr;				//�e�̃N���X
	DrawObject m_pDrawObjectEnemy;				//�G�̕`��I�u�W�F�N�g
	DrawObject m_pDrawObjectBullet;				//�e�̕`��I�u�W�F�N�g
	int m_SE_13 = 0;							//�X�����~�点�鉹

	int m_stage_num = 0;						//�X�e�[�W

	//�G�̈ʒu�z��
	D3DXVECTOR2 m_SetEnemy[(int)STAGE::NUM][11] = {
		//�`���[�g���A��
		{
			D3DXVECTOR2(0.0f, 0.0f),
		},
		//�ΐ�
		{                              //�}�X��
			D3DXVECTOR2(52.5f + (105 * 5), -EnemyIceRain::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 3), -EnemyIceRain::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 7), -EnemyIceRain::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 5), -EnemyIceRain::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 1), -EnemyIceRain::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 9), -EnemyIceRain::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 5), -EnemyIceRain::SIZE_Y / 2)
		},
		//����
		{
			D3DXVECTOR2(71.0f + (142.0f * 2.0f), -EnemyIceRain::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 6.0f), -EnemyIceRain::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 2.0f), -EnemyIceRain::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 6.0f), -EnemyIceRain::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 1.0f), -EnemyIceRain::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 7.0f), -EnemyIceRain::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 1.0f), -EnemyIceRain::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 7.0f), -EnemyIceRain::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 3.0f), -EnemyIceRain::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 7.0f), -EnemyIceRain::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 2.0f), -EnemyIceRain::SIZE_Y / 2),
		},
		//�y��
		{
			D3DXVECTOR2(0.0f, 0.0f),
		},
		//����
		{
			D3DXVECTOR2(0.0f, 0.0f),
		}
	};

	//�G���o������
	int m_SetEnemyTime[(int)STAGE::NUM][11] = {
		//�`���[�g���A��
		{
			0,
		},
		//�ΐ�
		{
			60 * 5,
			60 * 50,
			60 * 50 + 1,
			60 * 80,
			60 * 125,
			60 * 125 + 1,
			60 * 135,
		},
		//����
		{
			60 * 5,
			60 * 5 + 1,
			60 * 30,
			60 * 30 + 1,
			60 * 70,
			60 * 70 + 1,
			60 * 115,
			60 * 115 + 1,
			60 * 140,
			60 * 160,
			60 * 170
		},
		//�y��
		{
			0,
		},
		//����
		{
			0,
		}
	};

	//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	EnemyIceRainManagement() {}

	//�����t���R���X�g���N�^
	EnemyIceRainManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, int stage);

	//�f�X�g���N�^
	~EnemyIceRainManagement()override {}

	//�X�V����
	void Update(const D3DXVECTOR2& PlayerPos = D3DXVECTOR2(0.0f, 0.0f));

	//�`�揈��
	void Draw(void)const;

	//�w�肵����HP�����炷�@�G�����񂾂�true��Ԃ�
	bool ReduceHP(int index_num, int reduceHP)override;

	//�w�肵���G������
	void DeleteObj(int index_num)override;

	//�w�肵���e������
	void DeleteBullet(int index_num)override;

	//�w�肵���ԍ��̓G�̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjPos(int index_num)const override { return m_pEnemyIceRain[index_num].GetPos(); }

	//�w�肵���ԍ��̓G�̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override { return m_pEnemyIceRain[0].GetSize(); }

	//�w�肵���ԍ��̒e�̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return m_pBullet[index_num].GetPos(); }

	//�w�肵���ԍ��̒e�̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override { return m_pBullet[0].GetSize(); }

	//�w�肵���ԍ��̓G���~�߂�
	void StopEnemy(int index_num, int time) override { m_pEnemyIceRain[index_num].StopEnemy(time); }

};

#endif // !_ENEMY_ICERAIN_MANAGEMENT_H_