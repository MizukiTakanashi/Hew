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
//�萔
public:
	// �r�ɒ����G�̎��
	enum class TYPE :int
	{
		TYPE1,		//�z�[�~���O
		TYPE2,		//���[�U�[
		TYPE3,		//�K�g�����O
		TYPE4,		//�o���A
		TYPE5,
		TYPE6,
		TYPE7,
		TYPE8,
		TYPE_NUM,
	};

//�����o�ϐ�
private:
	int m_BulletNum = 0;		//���݂̒e�̐�
	int m_bullet_maked_num = 0;	//���܂ō��ꂽ�e�̐�(�A�C�e���̏����)
	int m_bullet_max_num = 0;	//�A�C�e�����o���ő�e��
	
	int m_bullet_hp = 0;		//���݂̒e��HP
	
	bool m_right = false;		//�E�ɂ��Ă邩���ɂ��Ă邩
	bool m_center = false;		//�����ɂ��Ă��邩

	bool m_button_push = false;	//�{�^���������ꂽ��
	bool m_button_trigger = false;	//�{�^���������ꂽ��(�g���K�[)
	
	bool m_bullet_used = false;	//�e���s�������ǂ���
	
	TYPE m_type = TYPE::TYPE1;	//�����̃^�C�v

	//�Ƃ�����W�擾�p
	//���݂�PlayerArm1�̃z�[�~���O�e�̓G�̈ʒu�擾�p
	D3DXVECTOR2 m_something_pos = D3DXVECTOR2(0.0f, 0.0f);	

//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	inhPlayerArm(){}

	//�����t���R���X�g���N�^
	inhPlayerArm(int bullet_max_num, bool right, int type, int hp_max = 0)
		:m_bullet_max_num(bullet_max_num), m_right(right), m_type((TYPE)type),
		m_bullet_hp(hp_max) {}

	//�f�X�g���N�^
	virtual ~inhPlayerArm()override{}

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

	
	//=====================
	// �e
	
	//�e���s��������Ԃ�
	// true�F�g���I������@false�F�܂��g���I����ĂȂ�
	bool IsBulletUsed(void)const;

	//�e���s�������ǂ������Z�b�g
	void SetBulletUsed(bool used) { m_bullet_used = used; }

	//������e�̐��𑝂₷
	void IncreaseBulletMaked(int num = 1) { m_bullet_maked_num += num; }

	//������e�̐���Ԃ�
	int GetBulletMaked(void) { return m_bullet_maked_num; }

	//���݂̒e���𑝂₷
	void IncreaseBulletNum(int num = 1) { m_BulletNum += num; }

	//�e�̐����擾
	int GetBulletNum(void)const { return m_BulletNum; }

	//==========================
	// �ǂ��̘r�ɂ��Ă��邩
	
	//���Ă���̂��E�r�����r����Ԃ�
	bool GetRightLeft(void)const { return m_right; }

	//�E�r�����r�����Z�b�g����
	void SetRightLeft(bool right) { m_right = right; }

	//�����ɂ��Ă��邩
	bool IsCenter(void)const { return m_center; }

	//�����ɂ��Ă��邩�t���O���Z�b�g
	void SetCenter(bool center) { m_center = center; }

	//=====================
	// �{�^��
	
	//�{�^���������ꂽ���t���O���Z�b�g
	void SetButtonPush(bool push) { m_button_push = push; }

	//�{�^���������ꂽ����Ԃ�
	bool IsButtonPush(void)const { return m_button_push; }

	//�{�^���������ꂽ���t���O���Z�b�g�@�g���K�[
	void SetButtonTrigger(bool push) { m_button_trigger = push; }

	//�{�^���������ꂽ����Ԃ��@�g���K�[
	bool IsButtonTrigger(void)const { return m_button_trigger; }


	//�^�C�v��Ԃ�
	TYPE GetType(void)const { return m_type; }

	//=====================
	// �Ƃ�����W
	
	//�Ƃ�����W�Z�b�g�p(�ڍׂ̓����o�ϐ���m_something_pos�̃R�����g��)
	void SetSomethingPos(const D3DXVECTOR2& pos) { m_something_pos = pos; }

	//�Ƃ�����W�擾�p(�ڍׂ̓����o�ϐ���m_something_pos�̃R�����g��)
	const D3DXVECTOR2& GetSomethingPos(void)const { return m_something_pos; }

	//=====================
	// �c�e��
	
	//�c�e����
	void HeelBullet(void) { m_bullet_maked_num = 0; }

	//�c�e����Ԃ�
	int GetRemainingBullet(void);

	//=====================
	// HP
	
	//HP�����炷�AHP��0�ȉ��ɂȂ�����true��Ԃ�
	bool ReduceHP(int num) {
		m_bullet_hp -= num;
		if (m_bullet_hp <= 0) {
			return true;
		}
		return false;
	}
};

#endif // !_INH_PLAYER_ARM_H_