#pragma once
#include "main.h"
#include "management_enemy.h"
#include "boss.h"
#include "bullet.h"
#include "draw_object.h"

class BossManagement :public EnemyManagement
{
	//�萔
private:
	//�����ŏ�����
	//�G���g
	static const int BULLET_NUM = 30;		//�����ɒe���o�������鐔
	static const int EXIT_TIME = 60 * 10;	//�ޏo����

	//cpp�ŏ�����
	static const int ENEMY_NUM[(int)STAGE::NUM];	//�G���o�������鐔
	//�e
	static const float BULLET_SIZE_X;		//�T�C�YX
	static const float BULLET_SIZE_Y;		//�T�C�YY
	static const float BULLET_SPEED;		//�X�s�[�h

	static const float EXIT_MOVE_SPEED_Y;	//�ޏo�X�s�[�hY

public:
	//�����ŏ�����
	//�G���g
	static const int ATTACK = 5;			//�U���l
	//�e
	static const int BULLET_ATTACK = 1;		//�U���l

	//�����o�ϐ�
private:
	Boss* m_pEnemyBoss = nullptr;	//�G�̃N���X
	Bullet* m_pBullet = nullptr;				//�e�̃N���X
	DrawObject m_pDrawObjectEnemy;				//�G�̕`��I�u�W�F�N�g
	DrawObject m_pDrawObjectBullet;				//�e�̕`��I�u�W�F�N�g
	int m_SE_21 = 0;							//�e���ˉ�


	//�G�̈ʒu�z��
	D3DXVECTOR2 m_SetEnemy[(int)STAGE::NUM][5] = {
		//�`���[�g���A��
		{
		},
		//�ΐ�
		{
			D3DXVECTOR2(52.5f + (105 * 5), -Boss::SIZE_Y / 2),
		},
		//����
		{
			D3DXVECTOR2(52.5f + (105 * 5), -Boss::SIZE_Y / 2),
		},
		//�y��
		{
			D3DXVECTOR2(52.5f + (105 * 5), -Boss::SIZE_Y / 2),
		},
		//����
		{
			D3DXVECTOR2(52.5f + (105 * 5), -Boss::SIZE_Y / 2),
		}
	};

	//�G���o������
	int m_SetEnemyTime[(int)STAGE::NUM][5] = {
		//�`���[�g���A��
		{
		},
		//�ΐ�
		{
			60 * 190,
		},
		//����
		{
			60 * 190,
		},
		//�y��
		{
			60 * 190,
		},
		//����
		{
			60 * 190,
		}
	};

	//�����o�֐�
public:
	//�����t���R���X�g���N�^
	BossManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, int stage);

	//�f�X�g���N�^
	~BossManagement()override {}

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

	//�w�肵���ԍ��̓G�̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjPos(int index_num)const override { return m_pEnemyBoss[index_num].GetPos(); }

	//�w�肵���ԍ��̓G�̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override { return m_pEnemyBoss[0].GetSize(); }

	//�w�肵���ԍ��̒e�̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return m_pBullet[index_num].GetPos(); }

	//�w�肵���ԍ��̒e�̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override { return m_pBullet[0].GetSize(); }

	//�w�肵���ԍ��̓G���~�߂�
	void StopEnemy(int index_num, int time) override { m_pEnemyBoss[index_num].StopEnemy(time); }

};

