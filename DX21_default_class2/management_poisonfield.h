//=======================================
// �ŏ��̊Ǘ��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/11/22
// �쐬�ҁF����đ�
//=======================================
#pragma once


#include "poisonfield.h"
#include "draw_object.h"

class Management_PoisonField
{
	//�萔
public:
	//�G���g
	static const int ATTACK = 1;			//�U���l

private:
	//�G���g
	static const int ENEMY_NUM = 19;		//�G�̍ő吔


	//�����o�ϐ�
private:
	PoisonField* m_pPoisonField[ENEMY_NUM];
	DrawObject m_pDrawObjectPoisonField;

	int m_FlameNum = 0;						//���݂̃t���[����
	int m_EnemyNum = 0;						//���݂̓G�̐�
	int m_EnemyMakedNum = 0;

	//�G�̔z��
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
		D3DXVECTOR2(71.0f + (142.0f * 5.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 6.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 7.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 8.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 0.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 1.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 2.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 2.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 8.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 0.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 6.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 4.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 3.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 4.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 5.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 0.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 1.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 7.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 8.0f), -PoisonField::SIZE_Y / 2)
	};

	int m_SetEnemyTime[ENEMY_NUM] = {
		60 * 20,
		60 * 20 + 1,
		60 * 20 + 2,
		60 * 20 + 3,
		60 * 30,
		60 * 30 + 1,
		60 * 30 + 2,
		60 * 65,
		60 * 65 + 1,
		60 * 70,
		60 * 70 + 1,
		60 * 80
	};


	//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	Management_PoisonField() {
		for (int i = 0; i < ENEMY_NUM; i++) {
			m_pPoisonField[i] = nullptr;
		}
	}

	//�����t���R���X�g���N�^
	Management_PoisonField(DrawObject& pDrawObject);

	//�f�X�g���N�^
	~Management_PoisonField() {
		for (int i = 0; i < ENEMY_NUM; i++) {
			if (m_pPoisonField[i] != nullptr) {
				delete m_pPoisonField[i];
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
		delete m_pPoisonField[index_num];
		m_pPoisonField[index_num] = nullptr;
		for (int i = index_num; i < m_EnemyNum - 1; i++) {
			m_pPoisonField[i] = m_pPoisonField[i + 1];
			m_pPoisonField[i + 1] = nullptr;
		}

		m_EnemyNum--;
	}

	//�w�肵���ԍ��̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjPos(int index_num)const { return m_pPoisonField[index_num]->GetPos(); }

	//�w�肵���ԍ��̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const { return m_pPoisonField[index_num]->GetSize(); }

	//�w�肵���ԍ��̓G���~�߂�
	void StopEnemy(int index_num, int time) { m_pPoisonField[index_num]->StopEnemy(time); }
};
