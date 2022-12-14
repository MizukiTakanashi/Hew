//=======================================
// ���ʂ̓G�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/12/02
// �쐬�ҁF����đ�
//=======================================
#pragma once

#include "main.h"
#include "inh_enemy.h"

class EnemyAttack :public Inh_Enemy
{
//�萔
public:
	//cpp�ŏ�����
	static const float SIZE_X;			//�T�C�YX
	static const float SIZE_Y;			//�T�C�YY
	static const float STOP_POS_Y;		//�G���~�܂�ꏊ
	static const float RANGE;			//�G�������͈�

private:
	//�����ŏ�����
	static const int ATTACK_TIME = 300;	//�e�̔��ˊԊu
	static const int HP_MAX = 1;			//�G��HP�ő�l

	//cpp�ŏ�����
	static const float SPEED_X;			//�G�̃X�s�[�hY
	static const float SPEED_Y;			//�G�̃X�s�[�hY

//�����o�ϐ�
private:
	D3DXVECTOR2 m_mov = D3DXVECTOR2(0.0f, 0.0f);	//�ړ���
	int m_time = 0;					//�e���o���Ă���̌o�ߎ���
	int m_attack_count = 0;			//�ˌ�����܂ł̃J�E���g
	bool m_shot = false;			//�ˌ����邩�ۂ�
	int explosion_time = 0;			//�ˌ����Ă��甚������܂ł̎��Ԍv�Z
	bool m_explosion = false;		//�������邩�ۂ�


//�����o�֐�
public:
	EnemyAttack() {}		//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	EnemyAttack(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:Inh_Enemy(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y), HP_MAX) {}

	~EnemyAttack()override {}	//�f�X�g���N�^

	void Update(void);	//�X�V����

	//�e����邩�ۂ��̃t���O��Ԃ�
	bool GetFlagAttack()const { return m_shot; }
	bool GetFlagExplosion()const { return m_explosion; }

	//�e�̈ړ����ăZ�b�g(�z�[�~���O�e�p���ȁH)
	void SetMove(const D3DXVECTOR2& mov) { m_mov = mov; }

	//�ˌ����Ă���̎��Ԃ�Ԃ�
	int GetAttackTime(void)const { return m_explosion; }
};