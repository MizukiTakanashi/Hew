#pragma once
//============================================================
// �S�ẴQ�[���I�u�W�F�N�g�̓����蔻��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/11/10
// �쐬�ҁF��������
//============================================================

#ifndef _COLLISION_ALL_H_
#define _COLLISION_ALL_H_

#include "player.h"
#include "management_enemy.h"

class CollisionAll
{
//�萔
private:
	//�����ŏ�����
	static const int ENEMY_NUM = 10;		//�S�G�̎�ސ��̐�����	

//�����o�ϐ�
private:
	Player* m_pPlayer = nullptr;			//�v���C���[

	int m_enemy_num = 0;					//�G�̎�ނ̐�
	EnemyManagement* m_pEnemy[ENEMY_NUM];	//�G�S�N���X

//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	CollisionAll();

	//�����t���R���X�g���N�^
	CollisionAll(Player* pPlayer):m_pPlayer(pPlayer);

	//�f�X�g���N�^
	~CollisionAll(){}
};

#endif // !_COLLISION_ALL_H_