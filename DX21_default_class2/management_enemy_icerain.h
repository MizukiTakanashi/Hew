//=======================================
// �������˂̓G�̊Ǘ��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/09/13
// �쐬�ҁF��������
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
private:
	//�����ŏ�����
	//�G���g
	static const int ENEMY_NUM = 5;		//�G���o�������鐔

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
	EnemyIceRain* m_pEnemyIceRain = nullptr;	//�G�̃N���X
	Bullet* m_pBullet = nullptr;				//�e�̃N���X
	DrawObject m_pDrawObjectEnemy;				//�G�̕`��I�u�W�F�N�g
	DrawObject m_pDrawObjectBullet;				//�e�̕`��I�u�W�F�N�g

	//�G�̈ʒu�z��
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
		D3DXVECTOR2(52.5f + (105 * 6), -EnemyIceRain::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 4), -EnemyIceRain::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 3), -EnemyIceRain::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 2), -EnemyIceRain::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 7), -EnemyIceRain::SIZE_Y / 2)
	};

	//�G���o������
	int m_SetEnemyTime[ENEMY_NUM] = {
								60 * 15,
								60 * 20,
								60 * 20 + 1,
								60 * 80,
								60 * 80 + 1
	};

	//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	EnemyIceRainManagement() {
		m_pEnemyIceRain = new EnemyIceRain[ENEMY_NUM];
		m_pBullet = new Bullet[ENEMY_NUM];
	}

	//�����t���R���X�g���N�^
	EnemyIceRainManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2);

	//�f�X�g���N�^
	~EnemyIceRainManagement()override {}

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
	const D3DXVECTOR2& GetObjPos(int index_num)const override { return m_pEnemyIceRain[index_num].GetPos(); }

	//�w�肵���ԍ��̓G�̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override { return m_pEnemyIceRain[0].GetSize(); }

	//�w�肵���ԍ��̒e�̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return m_pBullet[index_num].GetPos(); }

	//�w�肵���ԍ��̒e�̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override { return m_pBullet[0].GetSize(); }
};
#endif //!_ENEMY_ICERAIN_MANAGEMENT_H_