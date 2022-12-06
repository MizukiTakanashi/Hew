#pragma once
#include "enemy_public.h"
#include "draw_object.h"
#include "management.h"
#include"enemy_set_pos.h"
#include "management_enemy.h"
class Management_EnemyPublic :public EnemyManagement
{
public:
	//�G���g
	static const int ATTACK = 1;			//�U���l
private:
	//�G���g
	static const int MAX_NUM = 12;				//�G�̍ő吔
	static const int APPEARANCE_TIME = 200;		//�G�̏o���X�s�[�h
	//�����o�ϐ�
	EnemyPublic* m_pEnemyPublic = nullptr;
	DrawObject m_pDrawObjectEnemyPublic;
	EnemySetPos m_pEnemySetPos;

	//�G�̔z��
	D3DXVECTOR2 m_SetEnemy[MAX_NUM] = { D3DXVECTOR2(52.5f + (105 * (1 - 1)), -EnemyPublic::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * (2 - 1)), -EnemyPublic::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * (3 - 1)), -EnemyPublic::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * (4 - 1)), -EnemyPublic::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * (5 - 1)), -EnemyPublic::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * (6 - 1)), -EnemyPublic::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * (7 - 1)), -EnemyPublic::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * (8 - 1)), -EnemyPublic::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * (9 - 1)), -EnemyPublic::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * (10 - 1)), -EnemyPublic::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * (11 - 1)), -EnemyPublic::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * (12 - 1)), -EnemyPublic::SIZE_Y / 2) };

	int m_SetEnemyTime[MAX_NUM] = { 60 * 3,
								60 * 6,
								60 * 9,
								60 * 12,
								60 * 15,
								60 * 18,
								60 * 21,
								60 * 24,
								60 * 27,
								60 * 30,
								60 * 33,
								60 * 36 };

public:
	//�f�t�H���g�R���X�g���N�^
	Management_EnemyPublic() {
		m_pEnemyPublic = new EnemyPublic[MAX_NUM];
	}

	//�����t���R���X�g���N�^
	Management_EnemyPublic(DrawObject& pDrawObject, EnemySetPos& pEnemySetPos);

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
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return m_pEnemyPublic[index_num].GetPos(); }

	//�w�肵���ԍ��̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override { return m_pEnemyPublic[index_num].GetSize(); }

};

