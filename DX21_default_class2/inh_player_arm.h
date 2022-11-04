#pragma once
//==============================================
// (�p���p)�v���C���[�̘r�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/10/28
// �쐬�ҁF��������
//==============================================

#ifndef _INH_PLAYER_ARM_H_
#define _INH_PLAYER_ARM_H_

#include "game_object.h"

class inhPlayerArm:public GameObject
{
//�����o�ϐ�
private:
	int m_BulletNum = 0;		//���݂̒e�̐�
	int m_bullet_maked_num = 0;	//���܂ō��ꂽ�e�̐�(�A�C�e���̏����)
	int m_bullet_max_num = 0;	//�A�C�e�����o���ő�e��
	bool m_right = false;		//�E�ɂ��Ă邩���ɂ��Ă邩
	bool m_button_push = false;	//�{�^���������ꂽ��

	//�Ƃ�����W�擾�p
	//���݂�PlayerArm1�̃z�[�~���O�e�̓G�̈ʒu�擾�p
	D3DXVECTOR2 m_something_pos = D3DXVECTOR2(0.0f, 0.0f);	

//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	inhPlayerArm(){}

	//�����t���R���X�g���N�^
	inhPlayerArm(int bullet_max_num, bool right)
		:m_bullet_max_num(bullet_max_num), m_right(right) {}

	//�f�X�g���N�^
	~inhPlayerArm(){}

	//=========================
	// �I�[�o�[���C�h�p
	
	//�X�V����(�I�[�o�[���C�h)
	virtual void Update(const D3DXVECTOR2& arm_pos) = 0;

	//�`�揈��(�I�[�o�[���C�h)
	virtual void PlayerArmDraw(void)const = 0;

	//�w�肵���ԍ��̒e������(�I�[�o�[���C�h�p)
	virtual void DeleteBullet(int index_num) = 0;

	//�w�肵���ԍ��̒e�̍��W��Ԃ�(�I�[�o�[���C�h�p)
	virtual const D3DXVECTOR2& GetBulletPos(int index_num)const = 0;

	//�w�肵���ԍ��̒e�̃T�C�Y��Ԃ�(�I�[�o�[���C�h�p)
	virtual const D3DXVECTOR2& GetBulletSize(int index_num = 0)const = 0;


	//�e���s��������Ԃ�
	// true�F�g���I������@false�F�܂��g���I����ĂȂ�
	bool IsBulletUsed(void)const;

	//������e�̐��𑝂₷
	void IncreaseBulletMaked(int num = 1) { m_bullet_maked_num += num; }

	//���݂̒e���𑝂₷
	void IncreaseBulletNum(int num = 1) { m_BulletNum += num; }

	//�e�̐����擾
	int GetBulletNum(void)const { return m_BulletNum; }

	//���Ă���̂��E�r�����r����Ԃ�
	bool GetRightLeft(void)const { return m_right; }

	//�{�^���������ꂽ���t���O���Z�b�g
	void SetButtonPush(bool push) { m_button_push = push; }

	//�{�^���������ꂽ����Ԃ�
	bool IsButtonPush(void)const { return m_button_push; }

	//�Ƃ�����W�Z�b�g�p(�ڍׂ̓����o�ϐ���m_something_pos�̃R�����g��)
	void SetSomethingPos(const D3DXVECTOR2& pos) { m_something_pos = pos; }

	//�Ƃ�����W�擾�p(�ڍׂ̓����o�ϐ���m_something_pos�̃R�����g��)
	const D3DXVECTOR2& GetSomethingPos(void)const { return m_something_pos; }
};

#endif // !_INH_PLAYER_ARM_H_