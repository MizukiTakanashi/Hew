#pragma once
//=======================================
// �����̉��M�~�b�N�̊Ǘ��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/11/22
// �쐬�ҁF����đ�
//=======================================
#include "firefield.h"
#include "draw_object.h"

class Management_FireField
{
	//�萔
public:
	//�G���g
	static const int ATTACK = 1;			//�U���l

private:
	//�G���g
	static const int ENEMY_NUM = 9;				//�G�̍ő吔


	//�����o�ϐ�
private:
	FireField* m_pFireField[ENEMY_NUM];
	DrawObject m_pDrawObjectFireField;

	int m_FlameNum = 0;						//���݂̃t���[����
	int m_EnemyNum = 0;						//���݂̓G�̐�
	int m_EnemyMakedNum = 0;

	//�G�̔z��
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
		D3DXVECTOR2(71.0f + (142 * 1), -FireField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 0), -FireField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 1), -FireField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 7), -FireField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 8), -FireField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 0), -FireField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 6), -FireField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 4), -FireField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 5), -FireField::SIZE_Y / 2)
	};

	int m_SetEnemyTime[ENEMY_NUM] = {
		60 * 15,
		60 * 45,
		60 * 45 + 1,
		60 * 45 + 2,
		60 * 45 + 3,
		60 * 85,
		60 * 85 + 1,
		60 * 130,
		60 * 155
	};


	//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	Management_FireField() {
		for (int i = 0; i < ENEMY_NUM; i++) {
			m_pFireField[i] = nullptr;
		}
	}

	//�����t���R���X�g���N�^
	Management_FireField(DrawObject& pDrawObject);

	//�f�X�g���N�^
	~Management_FireField() {
		for (int i = 0; i < ENEMY_NUM; i++) {
			if (m_pFireField[i] != nullptr) {
				delete m_pFireField[i];
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
		delete m_pFireField[index_num];
		m_pFireField[index_num] = nullptr;
		for (int i = index_num; i < m_EnemyNum - 1; i++) {
			m_pFireField[i] = m_pFireField[i + 1];
			m_pFireField[i + 1] = nullptr;
		}

		m_EnemyNum--;
	}

	//�w�肵���ԍ��̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjPos(int index_num)const { return m_pFireField[index_num]->GetPos(); }

	//�w�肵���ԍ��̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const { return m_pFireField[index_num]->GetSize(); }

	//�w�肵���ԍ��̓G���~�߂�
	void StopEnemy(int index_num, int time) { m_pFireField[index_num]->StopEnemy(time); }
};
