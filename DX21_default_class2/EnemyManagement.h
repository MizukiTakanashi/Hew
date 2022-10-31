#pragma once
//====================================================
// �G�̊Ǘ��֌W(�|�����[�t�B�Y���p)(�w�b�_�t�@�C��)
// �쐬���F2022/10/31
// �쐬�ҁF��������
//====================================================

#ifndef _ENEMY_MANAGEMENT_H_
#define _ENEMY_MANAGEMENT_H_

#include "main.h"

class EnemyManagement
{
private:
	int m_obj_max_num = 0;			//�I�u�W�F�N�g�̍ő吔
	int m_obj_num = 0;				//���݂̃I�u�W�F�N�g��
	int m_bullet_max_num = 0;		//�e�̍ő吔
	int m_bullet_num = 0;			//���݂̒e��
	int m_bullet_attack = 0;		//�e���^����U����

public:
	//�f�t�H���g�R���X�g���N�^
	EnemyManagement() {}

	//�����t���R���X�g���N�^
	EnemyManagement(int enemy_max_num, int bullet_max_num, int bullet_attack) 
		:m_obj_max_num(enemy_max_num), m_bullet_max_num(bullet_max_num), m_bullet_attack(bullet_attack) {}

	//�f�X�g���N�^
	virtual ~EnemyManagement() {}

	//�w�肵���ԍ��̃I�u�W�F�N�g������
	virtual void DeleteObj(int index_num) = 0;

	//�w�肵���ԍ��̃I�u�W�F�N�g������
	virtual void DeleteBullet(int index_num) = 0;

	//���݂̃I�u�W�F�N�g���𑝂₷
	void IncreaseObjNum(int num = 1) { m_obj_num += num; }

	//���݂̒e���𑝂₷
	void IncreaseBulletNum(int num = 1) { m_obj_num += num; }

	//���݂̃I�u�W�F�N�g�̐���Ԃ�
	int GetObjNum(void)const { return m_obj_num; }

	//���݂̒e�̐���Ԃ�
	int GetBulletNum(void)const { return m_bullet_num; }
	
	//�e�̍U���͂�Ԃ�
	int GetBulletAttack(void)const { return m_bullet_attack; }

	//�w�肵���ԍ��̓G�̍��W��Ԃ�(�I�[�o�[���C�h�p)
	virtual const D3DXVECTOR2& GetObjPos(int index_num)const = 0;

	//�w�肵���ԍ��̓G�̃T�C�Y��Ԃ�(�I�[�o�[���C�h�p)
	virtual const D3DXVECTOR2& GetObjSize(int index_num = 0)const = 0;

	//�w�肵���ԍ��̒e�̍��W��Ԃ�(�I�[�o�[���C�h�p)
	virtual const D3DXVECTOR2& GetBulletPos(int index_num)const = 0;

	//�w�肵���ԍ��̒e�̃T�C�Y��Ԃ�(�I�[�o�[���C�h�p)
	virtual const D3DXVECTOR2& GetBulletSize(int index_num = 0)const = 0;
};

#endif // !_ENEMY_MANAGEMENT_H_