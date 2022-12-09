#pragma once
#include "main.h"
#include "management_enemy.h"
#include "enemy_attack.h"
#include "draw_object.h"


class EnemyAttackManagement :public EnemyManagement
{
	//�萔
private:
	//�����ŏ�����
	//�G���g
	static const int ENEMY_NUM = 12;		//�G���o�������鐔

	static const float ATTACK_SPEED;		//�X�s�[�h

public:
	//�����ŏ�����
	//�G���g
	static const int ATTACK = 1;			//�U���l


	//�����o�ϐ�
private:
	EnemyAttack* m_pEnemyAttack = nullptr;
	DrawObject m_pDrawObjectEnemy;

	int m_EnemyItem_num = 0;	//�G�̃A�C�e���̐�

	//�G�̔z��
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
										 D3DXVECTOR2(52.5f + (105 * 1 - 1), -EnemyAttack::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 12 - 1), -EnemyAttack::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 2 - 1), -EnemyAttack::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 10 - 1), -EnemyAttack::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 10 - 1), -EnemyAttack::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 3 - 1), -EnemyAttack::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 2 - 1), -EnemyAttack::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 11 - 1), -EnemyAttack::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 1 - 1), -EnemyAttack::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 2 - 1), -EnemyAttack::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 11 - 1), -EnemyAttack::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 12 - 1), -EnemyAttack::SIZE_Y / 2)
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
	}

	//�����t���R���X�g���N�^
	EnemyAttackManagement(DrawObject& pDrawObject1);

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
	//�w�肵���e�̍��W��Ԃ�
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return D3DXVECTOR2(-330, -300); }

	//�e�̃T�C�Y��Ԃ�
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override { return D3DXVECTOR2(-330, -300); }

	//�w�肵���G������
	void DeleteObj(int index_num)override;

	//�w�肵���e������
	void DeleteBullet(int index_num)override {}
};