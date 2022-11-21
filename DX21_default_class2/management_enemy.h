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
	int m_obj_num = 0;				//���݂̃I�u�W�F�N�g��
	int m_obj_delete_index = 0;		//�������I�u�W�F�N�g�̔ԍ�
	int m_bullet_max_num = 0;		//�e�̍ő吔
	int m_bullet_num = 0;			//���݂̒e��
	int m_obj_attack = 0;			//�G���g���Ԃ����ė^����U����
	int m_bullet_attack = 0;		//�e���^����U����

	int m_FlameNum = 0;				//���݂̃t���[����
public:
	//�f�t�H���g�R���X�g���N�^
	EnemyManagement() {}

	//�����t���R���X�g���N�^
	EnemyManagement(int bullet_max_num, int obj_attack, int bullet_attack) 
		:m_bullet_max_num(bullet_max_num), 
		m_obj_attack(obj_attack), m_bullet_attack(bullet_attack) {}

	//�f�X�g���N�^
	virtual ~EnemyManagement() {}

	//�w�肵���ԍ��̃I�u�W�F�N�g������
	//�����o�ϐ��ɏ������I�u�W�F�N�g�̔ԍ����L�^�����Ă���
	virtual void DeleteObj(int index_num) { m_obj_delete_index = index_num; }

	//�������I�u�W�F�N�g�̔ԍ���Ԃ�(�z�[�~���O�e�p)
	int GetDeleteObjIndex(void)const { return m_obj_delete_index; }

	//�w�肵���ԍ��̃I�u�W�F�N�g������
	virtual void DeleteBullet(int index_num) = 0;

	//���݂̃I�u�W�F�N�g���𑝂₷
	void IncreaseObjNum(int num) { m_obj_num += num; }

	//���݂̒e���𑝂₷
	void IncreaseBulletNum(int num) { m_bullet_num += num; }

	//���݂̃I�u�W�F�N�g�̐���Ԃ�
	int GetObjNum(void)const { return m_obj_num; }

	//���݂̒e�̐���Ԃ�
	int GetBulletNum(void)const { return m_bullet_num; }
	
	//�G���g���Ԃ��������̍U���͂�Ԃ�
	int GetObjAttack(void)const { return m_obj_attack; }

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

	//�t���[�����𑝉�
	void AddFlame(void) { m_FlameNum++; } 

	//���݂̃t���[������Ԃ�
	int GetFlameNum(void) { return m_FlameNum; }
};

#endif // !_ENEMY_MANAGEMENT_H_