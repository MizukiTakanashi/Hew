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
//�����o�ϐ�
private:
	//�G���g
	int m_obj_num = 0;				//���݂̃I�u�W�F�N�g��
	int m_obj_delete_index = 0;		//�������I�u�W�F�N�g�̔ԍ�
	int m_obj_attack = 0;			//�G���g���Ԃ����ė^����U����
	
	//�e
	int m_bullet_num = 0;			//���݂̒e��
	int m_bullet_max_num = 0;		//�e�̍ő吔
	int m_bullet_attack = 0;		//�e���^����U����

	//�ʃI�u�W�F�N�g
	int m_other_num = 0;			//���݂̕ʃI�u�W�F�N�g��
	int m_other_attack = 0;			//�ʃI�u�W�F�N�g���^����U����

protected:
	int m_EnemyNum = 0;				//�o���������G�̐�
	int m_FlameNum = 0;				//���݂̃t���[����


//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	EnemyManagement() {}

	//�����t���R���X�g���N�^
	EnemyManagement(int bullet_max_num, int obj_attack, int bullet_attack, int other_attack = 0)
		:m_bullet_max_num(bullet_max_num), m_obj_attack(obj_attack), m_bullet_attack(bullet_attack), 
		m_other_attack(other_attack) {}

	//�f�X�g���N�^
	virtual ~EnemyManagement() {}

	//�w�肵���ԍ��̃I�u�W�F�N�g��HP�����炷 �G�����񂾂�true��Ԃ�
	virtual bool ReduceHP(int index_num, int reduceHP) { return false; }

	//�w�肵���ԍ��̕ʃI�u�W�F�N�g��HP�����炷 �G�����񂾂�true��Ԃ�
	//(�I�[�o�[���C�h�p)
	virtual bool ReduceOtherHP(int index_num, int reduceHP) { return false; }

	//�������I�u�W�F�N�g�̔ԍ���Ԃ�(�z�[�~���O�e�p)
	int GetDeleteObjIndex(void)const { return m_obj_delete_index; }

	//�����o�ϐ��ɏ������I�u�W�F�N�g�̔ԍ����L�^�����Ă���
	//���݂̃I�u�W�F�N�g��������炷
	virtual void DeleteObj(int index_num) { m_obj_delete_index = index_num; m_obj_num--; }
	
	//�w�肵���ԍ��̒e������ 
	virtual void DeleteBullet(int index_num) = 0;

	//�w�肵���ԍ��̕ʃI�u�W�F�N�g������ 
	virtual void DeleteOther(int index_num) { m_other_num--; }

	//���݂̃I�u�W�F�N�g���𑝂₷
	void IncreaseObjNum(int num) { m_obj_num += num; }

	//���݂̒e���𑝂₷
	void IncreaseBulletNum(int num) { m_bullet_num += num; }

	//���݂̕ʃI�u�W�F�N�g���𑝂₷
	void IncreaseOtherNum(int num) { m_other_num += num; }

	//���݂̃I�u�W�F�N�g�̐���Ԃ�
	int GetObjNum(void)const { return m_obj_num; }

	//���݂̒e�̐���Ԃ�
	int GetBulletNum(void)const { return m_bullet_num; }

	//���݂̕ʃI�u�W�F�N�g�̐���Ԃ�
	int GetOtherNum(void)const { return m_other_num; }
	
	//�G���g���Ԃ��������̍U���͂�Ԃ�
	int GetObjAttack(void)const { return m_obj_attack; }

	//�e�̍U���͂�Ԃ�
	int GetBulletAttack(void)const { return m_bullet_attack; }

	//�ʃI�u�W�F�N�g�̍U���͂�Ԃ�
	int GetOtherAttack(void)const { return m_other_attack; }

	//�w�肵���ԍ��̓G�̍��W��Ԃ�(�I�[�o�[���C�h�p)
	virtual const D3DXVECTOR2& GetObjPos(int index_num)const = 0;

	//�w�肵���ԍ��̓G�̃T�C�Y��Ԃ�(�I�[�o�[���C�h�p)
	virtual const D3DXVECTOR2& GetObjSize(int index_num = 0)const = 0;

	//�w�肵���ԍ��̒e�̍��W��Ԃ�(�I�[�o�[���C�h�p)
	virtual const D3DXVECTOR2& GetBulletPos(int index_num)const = 0;

	//�w�肵���ԍ��̒e�̃T�C�Y��Ԃ�(�I�[�o�[���C�h�p)
	virtual const D3DXVECTOR2& GetBulletSize(int index_num = 0)const = 0;

	//�w�肵���ԍ��̕ʃI�u�W�F�N�g�̍��W��Ԃ�(�I�[�o�[���C�h�p)
	virtual const D3DXVECTOR2& GetOtherPos(int index_num)const { return D3DXVECTOR2(-30.0f, -30.0f); };

	//�w�肵���ԍ��̕ʃI�u�W�F�N�g�̃T�C�Y��Ԃ�(�I�[�o�[���C�h�p)
	virtual const D3DXVECTOR2& GetOtherSize(int index_num = 0)const{ return D3DXVECTOR2(0.0f, 0.0f); };

};

#endif // !_ENEMY_MANAGEMENT_H_