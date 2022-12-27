//=======================================
// �O���|���̓G�̊Ǘ��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/12/27
// �쐬�ҁF��������
//=======================================
#pragma once

#ifndef _ENEMY_GRENADE_MANAGEMENT_H_
#define _ENEMY_GRENADE_MANAGEMENT_H_

#include "main.h"
#include "management_enemy.h"
#include "enemy_grenade.h"
#include "bullet.h"
#include "draw_object.h"

class EnemyGrenadeManagement :public EnemyManagement
{
	//�萔
private:
	//�X�e�[�W
	enum class STAGE :int {
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
	EnemyGrenade* m_pEnemy = nullptr;
	Bullet* m_pBullet = nullptr;

	DrawObject m_pDrawObjectEnemy;
	DrawObject m_pDrawObjectBullet;

	int m_stage_num = 0;			//�X�e�[�W

	//�G�̔z��
	D3DXVECTOR2 m_SetEnemy[(int)STAGE::NUM][5] = {
	{//�`���[�g���A��
		D3DXVECTOR2(52.5f + (105 * 4), -EnemyGrenade::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 6), -EnemyGrenade::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 4), -EnemyGrenade::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 6), -EnemyGrenade::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 8), -EnemyGrenade::SIZE_Y / 2)
	}

	};

	int m_SetEnemyTime[(int)STAGE::NUM][5] = {
	{//�`���[�g���A��
		60 * 25,
		60 * 25 + 1,
		60 * 100,
		60 * 100 + 1,
		60 * 145
	}

	};

	//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	EnemyGrenadeManagement() {}

	//�����t���R���X�g���N�^
	EnemyGrenadeManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, int stage);

	//�f�X�g���N�^
	~EnemyGrenadeManagement()override { delete[] m_pEnemy; delete[] m_pBullet; }

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
	const D3DXVECTOR2& GetObjPos(int index_num)const override { return m_pEnemy[index_num].GetPos(); }

	//�w�肵���ԍ��̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override { return m_pEnemy[index_num].GetSize(); }

	//�w�肵���e�̍��W��Ԃ�
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return m_pBullet[index_num].GetPos(); }

	//�e�̃T�C�Y��Ԃ�
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override { return m_pBullet[index_num].GetSize(); }
};

#endif // !_ENEMY_GRENADE_MANAGEMENT_H_