//=======================================
// �_���J�̓G�̊Ǘ��֌W(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#pragma once

#include "main.h"
#include "management_enemy.h"
#include "enemy_stop.h"
#include "bullet.h"
#include "draw_object.h"

class EnemyAcidManagement:public EnemyManagement
{
//�萔
private:
	//�����ŏ�����
	//�G���g
	static const int ENEMY_NUM = 4;			//�G���o�������鐔
	static const int BULLET_NUM = 20;		//�����ɒe���o�������鐔
	static const int EXIT_TIME = 60 * 10;	//�ޏo����

	//cpp�ŏ�����
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
	EnemyStop* m_pEnemyGatoring = nullptr;	//�G�̃N���X
	Bullet* m_pBullet = nullptr;				//�e�̃N���X
	DrawObject m_pDrawObjectEnemy;				//�G�̕`��I�u�W�F�N�g
	DrawObject m_pDrawObjectBullet;				//�e�̕`��I�u�W�F�N�g

	//�G�̈ʒu�z��
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
		D3DXVECTOR2(71.0f + (142 * 0), -EnemyStop::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 4), -EnemyStop::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 8), -EnemyStop::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 4), -EnemyStop::SIZE_Y / 2)
	};

	//�G���o������
	int m_SetEnemyTime[ENEMY_NUM] = {
		60 * 100,
		60 * 100 + 1,
		60 * 100 + 2,
		60 * 145
	};

//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	EnemyAcidManagement() {
		m_pEnemyGatoring = new EnemyStop[ENEMY_NUM];
		m_pBullet = new Bullet[ENEMY_NUM];
	}

	//�����t���R���X�g���N�^
	EnemyAcidManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2);

	//�f�X�g���N�^
	~EnemyAcidManagement()override{}

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
	const D3DXVECTOR2& GetObjPos(int index_num)const override{ return m_pEnemyGatoring[index_num].GetPos(); }

	//�w�肵���ԍ��̓G�̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override{ return m_pEnemyGatoring[0].GetSize(); }

	//�w�肵���ԍ��̒e�̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return m_pBullet[index_num].GetPos(); }

	//�w�肵���ԍ��̒e�̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override{ return m_pBullet[0].GetSize(); }

	//�w�肵���ԍ��̓G���~�߂�
	void StopEnemy(int index_num, int time) override { m_pEnemyGatoring[index_num].StopEnemy(time); }

};
