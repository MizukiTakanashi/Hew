#pragma once
//=======================================
// �S�Ă̓G�̊Ǘ��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/10/30
// �쐬�ҁF��������
//=======================================

#ifndef _ALL_ENEMY_MANAGEMENT_H_
#define _ALL_ENEMY_MANAGEMENT_H_

#include "enemy_management.h"

class AllEnemyManagement
{
private:
	EnemyManagement* m_pEnemy = nullptr;	//�G�S�N���X

public:
	//�f�t�H���g�R���X�g���N�^
	AllEnemyManagement(){}

	//�����t���R���X�g���N�^
	AllEnemyManagement(EnemyManagement* p[]) :m_pEnemy(p[0]){}

	//�f�X�g���N�^
	~AllEnemyManagement(){}
};

#endif // !_ALL_ENEMY_MANAGEMENT_H_