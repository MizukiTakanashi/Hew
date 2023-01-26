#pragma once
//=======================================
// �����̕X�M�~�b�N�̊Ǘ��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/11/22
// �쐬�ҁF����đ�
//=======================================
#include "icefield.h"
#include "draw_object.h"

class Management_IceField
{
//�萔
public:
	//�G���g
	static const int ATTACK = 1;			//�U���l
	static const int SLOW_TIME = 60 * 3;	//�v���C���[��x�����鎞��

private:
	//�G���g
	static const int ENEMY_NUM = 13;		//�G�̍ő吔


	//�����o�ϐ�
private:
	IceField* m_pIceField[ENEMY_NUM];
	DrawObject m_pDrawObjectIceField;

	int m_FlameNum = 0;						//���݂̃t���[����
	int m_EnemyNum = 0;						//���݂̓G�̐�
	int m_EnemyMakedNum = 0;

	//�G�̔z��
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
		D3DXVECTOR2(52.5f + (105 * 7), -IceField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 3), -IceField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 4), -IceField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 5), -IceField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 2), -IceField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 8), -IceField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 0), -IceField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 1), -IceField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 2), -IceField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 6), -IceField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 7), -IceField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 8), -IceField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 3), -IceField::SIZE_Y / 2)
	};

	int m_SetEnemyTime[ENEMY_NUM] = {
		60 * 15,
		60 * 40,
		60 * 40 + 1,
		60 * 40 + 2,
		60 * 85,
		60 * 85 + 1,
		60 * 125,
		60 * 125 + 1,
		60 * 125 + 2,
		60 * 125 + 3,
		60 * 125 + 4,
		60 * 125 + 5,
		60 * 155
	};


	//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	Management_IceField() {
		for (int i = 0; i < ENEMY_NUM; i++) {
			m_pIceField[i] = nullptr;
		}
	}

	//�����t���R���X�g���N�^
	Management_IceField(DrawObject& pDrawObject);

	//�f�X�g���N�^
	~Management_IceField() {
		for (int i = 0; i < ENEMY_NUM; i++) {
			if (m_pIceField[i] != nullptr) {
				delete m_pIceField[i];
			}
		}
	}

	//�X�V����
	void Update(void);

	//�`�揈��
	void Draw(void)const;

	//覐΂̍U���l��Ԃ�
	int GetPoisonFieldAttack(void)const { return ATTACK; }

	//覐΂̐���Ԃ�
	int GetPoisonFieldNum(void)const { return m_EnemyNum; }

	//覐΂̐���ϓ�����
	void AddPoisonFieldNum(int num) { m_EnemyNum += num; }

	//�w�肵���G������
	void DeleteObj(int index_num) {
		delete m_pIceField[index_num];
		m_pIceField[index_num] = nullptr;
		for (int i = index_num; i < m_EnemyNum - 1; i++) {
			m_pIceField[i] = m_pIceField[i + 1];
			m_pIceField[i + 1] = nullptr;
		}

		m_EnemyNum--;
	}

	//�w�肵���ԍ��̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjPos(int index_num)const { return m_pIceField[index_num]->GetPos(); }

	//�w�肵���ԍ��̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const { return m_pIceField[index_num]->GetSize(); }

	//�w�肵���ԍ��̓G���~�߂�
	void StopEnemy(int index_num, int time) { m_pIceField[index_num]->StopEnemy(time); }
};