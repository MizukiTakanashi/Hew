#pragma once
#include "main.h"
#include "management_enemy.h"
#include "enemy_attack.h"
#include "draw_object.h"
#include "bullet.h"

class EnemyAttackManagement :public EnemyManagement
{
	//�萔
private:
	//�����ŏ�����
	static const int ENEMY_NUM = 12;		//�G���o�������鐔
	static const int BULLET_NUM = 20;		//�����ɏo����e

	//cpp�ŏ�����
	static const float ATTACK_SPEED;		//�X�s�[�h
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
	EnemyAttack* m_pEnemyAttack = nullptr;		//�G�̃N���X
	Bullet* m_pBullet = nullptr;				//�e�̃N���X
	DrawObject m_pDrawObjectEnemy;				//�G�̕`��I�u�W�F�N�g
	DrawObject m_pDrawObjectBullet;				//�e�̕`��I�u�W�F�N�g

	int m_EnemyItem_num = 0;	//�G�̃A�C�e���̐�

	//�G�̔z��
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
		D3DXVECTOR2(52.5f + (105 *  0), -EnemyAttack::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 11), -EnemyAttack::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 *  1), -EnemyAttack::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 *  9), -EnemyAttack::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 *  9), -EnemyAttack::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 *  2), -EnemyAttack::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 *  1), -EnemyAttack::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 10), -EnemyAttack::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 *  0), -EnemyAttack::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 *  1), -EnemyAttack::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 10), -EnemyAttack::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 11), -EnemyAttack::SIZE_Y / 2)
	};
	//�G���o������
	int m_SetEnemyTime[ENEMY_NUM] = {
		60 * 10,
		60 * 10 + 1,
		60 * 15,
		60 * 20,
		60 * 30,
		60 * 40 + 1,
		60 * 60,
		60 * 60 + 1,
		60 * 70,
		60 * 70 + 1,
		60 * 70 + 2,
		60 * 70 + 3
	};
	//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	EnemyAttackManagement() {
		m_pEnemyAttack = new EnemyAttack[ENEMY_NUM];
		m_pBullet = new Bullet[ENEMY_NUM];
	}

	//�����t���R���X�g���N�^
	EnemyAttackManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2);

	//�f�X�g���N�^
	~EnemyAttackManagement()override {  }

	//�X�V����
	void Update(const D3DXVECTOR2& PlayerPos);

	//�`�揈��
	void Draw(void)const;

	//�w�肵����HP�����炷
	bool ReduceHP(int index_num, int reduceHP)override;

	//�w�肵���ԍ��̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjPos(int index_num)const override { return m_pEnemyAttack[index_num].GetPos(); }

	//�w�肵���ԍ��̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override { return m_pEnemyAttack[index_num].GetSize(); }

	//�w�肵���ԍ��̒e�̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return m_pBullet[index_num].GetPos(); }

	//�w�肵���ԍ��̒e�̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override { return m_pBullet[0].GetSize(); }
	//�w�肵���G������
	void DeleteObj(int index_num)override;

	//�w�肵���e������
	void DeleteBullet(int index_num)override;

	//�w�肵���ԍ��̓G���~�߂�
	void StopEnemy(int index_num, int time) override { m_pEnemyAttack[index_num].StopEnemy(time); }

};
