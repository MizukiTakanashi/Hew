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
	int m_obj_max_num = 0;			//�I�u�W�F�N�g�̍ő吔
	int m_obj_num = 0;				//���݂̃I�u�W�F�N�g��

public:
	//�f�t�H���g�R���X�g���N�^
	Management(){}

	//�����t���R���X�g���N�^
	Management(int max_num) :m_obj_max_num(max_num) {}
	
	//�f�X�g���N�^
	virtual ~Management(){}

	//���݂̃I�u�W�F�N�g�̐���Ԃ�
	int GetObjNum(void)const { return m_obj_num; }

	//�w�肵���ԍ��̍��W��Ԃ�(�I�[�o�[���C�h�p)
	virtual const D3DXVECTOR2& GetObjPos(int index_num) = 0;

	//�w�肵���ԍ��̃T�C�Y��Ԃ�(�I�[�o�[���C�h�p)
	virtual const D3DXVECTOR2& GetObjPos(int index_num = 0) = 0;

	//���݂̃I�u�W�F�N�g���𑝂₷
	void IncreaseObjNum(int num = 1) { m_obj_num += num; }
};

#endif // !_MANAGEMENT_H_