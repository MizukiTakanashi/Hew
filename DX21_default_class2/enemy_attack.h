//=======================================
// ���ʂ̓G�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/12/02
// �쐬�ҁF����đ�
//=======================================
#pragma once

#include "main.h"
#include "bullet.h"
#include "draw_object.h"
#include "game_object.h"

class EnemyAttack :public GameObject
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

	//cpp�ŏ�����
	static const float SPEED_X;			//�G�̃X�s�[�hY
	static const float SPEED_Y;			//�G�̃X�s�[�hY
	static const int HP_MAX;			//�G��HP�ő�l
	D3DXVECTOR2 m_mov = D3DXVECTOR2(0.0f, 0.0f);	//�ړ���
	int m_time = 0;									//�e���o���Ă���̌o�ߎ���
	int explosion_time = 0;


	//�����o�ϐ�
private:
	int m_attack_count = 0;				//�ˌ�����܂ł̃J�E���g
	bool m_attack_time = false;			//�ˌ����邩�ۂ�
	bool m_Attack_time;
	float m_move_width = 0.0f;			//�G����������cos�J�[�u
	float m_init_posx = 0.0f;			//�G�̏����ʒuX

	bool m_enemyitem_make = false;		//�A�C�e������邩�ۂ�

	int m_hp = HP_MAX;					//�G�̌��݂�HP

	//�����o�֐�
public:
	EnemyAttack() {}		//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	EnemyAttack(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:GameObject(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y)), m_init_posx(pos.x) {}

	~EnemyAttack()override {}	//�f�X�g���N�^

	void Update(void);	//�X�V����

	//�e����邩�ۂ��̃t���O��Ԃ�
	bool GetFlagAttack()const { return m_attack_time; }
	bool GetFlagExplosion()const { return m_Attack_time; }

	//HP�����炷
	void ReduceHP(int amount) { m_hp -= amount; }

	//HP��Ԃ�
	int GetHP(void) { return m_hp; }

	//�e�̈ړ����ăZ�b�g(�z�[�~���O�e�p���ȁH)
	void SetMove(const D3DXVECTOR2& mov) { m_mov = mov; }

	//�e���o���Ă���̌o�ߎ��Ԃ�Ԃ�

	//�ˌ����Ă���̎��Ԃ�Ԃ�
	int GetAttackTime(void)const { return m_Attack_time; }
};