#pragma once
#include "enemy_public.h"
#include "draw_object.h"
#include "management.h"
#include "management_enemy.h"

class Management_EnemyPublic :public EnemyManagement
{
//�萔
public:
	//�G���g
	static const int ATTACK = 1;			//�U���l
	//�e
	static const int BULLET_ATTACK = 1;		//�U���l

private:
	//�G���g
	static const int ENEMY_NUM = 12;				//�G�̍ő吔
	

//�����o�ϐ�
private:
	EnemyPublic* m_pEnemyPublic = nullptr;
	DrawObject m_pDrawObjectEnemyPublic;

	//�G�̔z��
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
		D3DXVECTOR2(71.0f + (142 * 0), -EnemyPublic::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 2), -EnemyPublic::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 6), -EnemyPublic::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 8), -EnemyPublic::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 1), -EnemyPublic::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 7), -EnemyPublic::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 2), -EnemyPublic::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 6), -EnemyPublic::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 0), -EnemyPublic::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 8), -EnemyPublic::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 1), -EnemyPublic::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 7), -EnemyPublic::SIZE_Y / 2)
	};

	int m_SetEnemyTime[ENEMY_NUM] = {
		60 * 1,
		60 * 1 + 1,
		60 * 1 + 2,
		60 * 1 + 3,
		60 * 80,
		60 * 80 + 1,
		60 * 85,
		60 * 85 + 1,
		60 * 155,
		60 * 155 + 1,
		60 * 160,
		60 * 160 + 1
	};

public:
	//�f�t�H���g�R���X�g���N�^
	Management_EnemyPublic() {
		m_pEnemyPublic = new EnemyPublic[ENEMY_NUM];
	}

	//�����t���R���X�g���N�^
	Management_EnemyPublic(DrawObject& pDrawObject);

	//�f�X�g���N�^
	~Management_EnemyPublic() override { delete[]m_pEnemyPublic; }

	//�X�V����
	void Update(void);

	//�`�揈��
	void Draw(void)const;

	//�w�肵���G��HP�����炷
	bool ReduceHP(int index_num, int reduceHP)override;

	//�w�肵���G������
	void DeleteObj(int index_num)override;

	//�w�肵���e������
	void DeleteBullet(int index_num)override {}
	
	//�w�肵���ԍ��̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjPos(int index_num)const override { return m_pEnemyPublic[index_num].GetPos(); }

	//�w�肵���ԍ��̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override { return m_pEnemyPublic[index_num].GetSize(); }
	
	//�w�肵���ԍ��̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return D3DXVECTOR2(-30.0f, -30.0f); }

	//�w�肵���ԍ��̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override { return D3DXVECTOR2(0.0f, 0.0f); }

	//�w�肵���ԍ��̓G���~�߂�
	void StopEnemy(int index_num, int time) override { m_pEnemyPublic[index_num].StopEnemy(time); }


};

