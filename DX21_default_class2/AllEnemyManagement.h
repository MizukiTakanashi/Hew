#pragma once
//=======================================
// �S�Ă̓G�̊Ǘ��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/10/30
// �쐬�ҁF��������
//=======================================

#ifndef _ALL_ENEMY_MANAGEMENT_H_
#define _ALL_ENEMY_MANAGEMENT_H_

#include "management.h"

class AllEnemyManagement
{
private:
	Management* m_pEnemy = nullptr;	//�G�S�N���X

public:
	//�f�t�H���g�R���X�g���N�^
	AllEnemyManagement(){}

	//�����t���R���X�g���N�^
	AllEnemyManagement(Management* p[]) :m_pEnemy(p[0]){}

	//�f�X�g���N�^
	~AllEnemyManagement(){}
};

#endif // !_ALL_ENEMY_MANAGEMENT_H_