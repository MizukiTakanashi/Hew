//=======================================
// 覐΂̊Ǘ��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/11/22
// �쐬�ҁF����đ�
//=======================================
#pragma once

#ifndef _MANAGEMENT_METEO_H_
#define _MANAGEMENT_METEO_H_

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
	static const int ENEMY_NUM = 6;				//�G�̍ő吔


	//�����o�ϐ�
private:
	PoisonField* m_pPoisonField[ENEMY_NUM];
	DrawObject m_pDrawObjectPoisonField;

	int m_FlameNum = 0;						//���݂̃t���[����
	int m_EnemyNum = 0;						//���݂̓G�̐�
	int m_EnemyMakedNum = 0;

	//�G�̔z��
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
		D3DXVECTOR2(52.5f + (105 * 1), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 9), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 1), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 9), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 1), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 9), -PoisonField::SIZE_Y / 2)
	};

	int m_SetEnemyTime[ENEMY_NUM] = {
		60 * 35,
		60 * 35 + 1,
		60 * 55,
		60 * 55 + 1,
		60 * 70,
		60 * 70 + 1,
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
			delete m_pPoisonField[i];
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
		for (int i = index_num; i < m_EnemyNum - 1; i++) {
			m_pPoisonField[i] = m_pPoisonField[i + 1];
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

#endif // !_MANAGEMENT_METEO_H_