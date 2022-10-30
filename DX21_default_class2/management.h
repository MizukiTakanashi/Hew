#pragma once
//=======================================
// �}�l�W�����g�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/10/28
// �쐬�ҁF��������
//=======================================

#ifndef _MANAGEMENT_H_
#define _MANAGEMENT_H_

#include "GameObject.h"

class Management
{
private:
	GameObject* m_pObj = nullptr;	//�I�u�W�F�N�g
	int m_obj_max_num = 0;			//�I�u�W�F�N�g�̍ő吔
	int m_obj_num = 0;				//���݂̃I�u�W�F�N�g��

public:
	//�f�t�H���g�R���X�g���N�^
	Management(){}

	//�����t���R���X�g���N�^
	Management(GameObject* pObj, int max_num):m_pObj(pObj), m_obj_max_num(max_num) {}
	
	//�f�X�g���N�^
	virtual ~Management(){}

	//���݂̃I�u�W�F�N�g�̐���Ԃ�
	int GetObjNum(void)const { return m_obj_num; }

	//���݂̃I�u�W�F�N�g���𑝂₷
	void IncreaseObjNum(int num = 1) { m_obj_num += num; }

	//�I�u�W�F�N�g��`�悷��
	void DrawObj(void)const {
		for (int i = 0; i < m_obj_num; i++) {
			(m_pObj + i)->Draw();
		}
	}

	//�w�肵���ԍ��̕�������
	void Delete(int index_num);

	//�w�肵���ԍ��̍��W��Ԃ�
	const D3DXVECTOR2& GetObjPos(int index_num)const { return (m_pObj + index_num)->GetPos(); }

	//�w�肵���ԍ��̃T�C�Y��Ԃ�
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const { return (m_pObj + index_num)->GetSize(); }
};

#endif // !_MANAGEMENT_H_