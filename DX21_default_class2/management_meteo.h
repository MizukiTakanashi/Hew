//=======================================
// 覐΂̊Ǘ��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/11/22
// �쐬�ҁF����đ�
//=======================================
#pragma once
#include"meteo.h"
#include "draw_object.h"
#include "management.h"
//#include"enemy_set_pos.h"
#include "management_enemy.h"
class Management_Meteo:public EnemyManagement
{
public:
	//�G���g
	static const int ATTACK = 1;			//�U���l
private:
	//�G���g
	static const int ENEMY_NUM = 2;				//�G�̍ő吔
	static const int APPEARANCE_TIME = 200;		//�G�̏o���X�s�[�h
	//�����o�ϐ�
	Meteo* m_pMeteo = nullptr;
	DrawObject m_pDrawObjectMeteo;
	//EnemySetPos m_pEnemySetPos;

	//�G�̔z��
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
										D3DXVECTOR2(52.5f + (105 *  0), -Meteo::SIZE_Y / 2),
										D3DXVECTOR2(52.5f + (105 * 11), -Meteo::SIZE_Y / 2)
	};

	int m_SetEnemyTime[ENEMY_NUM] = {
								60 * 3,
								60 * 6,
	};
public:
	//�f�t�H���g�R���X�g���N�^
	Management_Meteo() {
		m_pMeteo = new Meteo[ENEMY_NUM];
	}

	//�����t���R���X�g���N�^
	Management_Meteo(DrawObject& pDrawObject);

	//�f�X�g���N�^
	~Management_Meteo() override { delete[]m_pMeteo; }

	//�X�V����
	void Update(void);

	//�`�揈��
	void Draw(void)const;

	//�w�肵���G������
	bool ReduceHP(int index_num, int reduceHP)override;

	//�w�肵���e������
	void DeleteBullet(int index_num)override{}

	//�w�肵���ԍ��̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjPos(int index_num)const override { return m_pMeteo[index_num].GetPos(); }

	//�w�肵���ԍ��̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override { return m_pMeteo[index_num].GetSize(); }

	//�w�肵���ԍ��̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return m_pMeteo[index_num].GetPos(); }

	//�w�肵���ԍ��̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override { return m_pMeteo[index_num].GetSize(); }

};

