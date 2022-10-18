//=======================================
// �G�̔z�u�ꏊ�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/09/14
// �쐬�ҁF��������
//=======================================
#pragma once

#ifndef _ENEMY_SET_POS_H_
#define _ENEMY_SET_POS_H_

#include "main.h"
#include "collision.h"

class EnemySetPos
{
private:
	//�萔
	static const int ENEMY_SET_POS_MAX_NUM = 150;

private:
	D3DXVECTOR2 m_pos[ENEMY_SET_POS_MAX_NUM];
	D3DXVECTOR2 m_size[ENEMY_SET_POS_MAX_NUM];
	int m_index_num = 0;

public:
	EnemySetPos(){}		//�f�t�H���g�R���X�g���N�^

	~EnemySetPos(){}	//�f�X�g���N�^

	//�G��z�u
	bool SetEnemy(const D3DXVECTOR2& pos, const D3DXVECTOR2& size);

	//�G���폜
	void DeleteEnemy(const D3DXVECTOR2& pos);
};

#endif // !_ENEMY_SET_POS_H_