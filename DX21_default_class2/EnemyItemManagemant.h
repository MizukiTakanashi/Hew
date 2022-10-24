//=======================================
// ���ʂ̓G�̊Ǘ��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/09/13
// �쐬�ҁF��������
//=======================================
#pragma once

#ifndef _ENEMY_ITEM_MANAGEMENT_H_
#define _ENEMY_ITEM_MANAGEMENT_H_

#include "main.h"
#include "EnemyNormal.h"
#include "DrawObject.h"
#include "player.h"
#include "enemyitem.h"
#include "EnemySetPos.h"

class EnemyItemManagement
{
	//�萔
private:
	//�����ŏ�����
	//�G���g
	static const int MAX_NUM = 10;			//�G�̍ő吔
	//cpp�ŏ�����
	//�G�̃A�C�e��
	static const float ENEMYITEM_SIZE_X;	//�T�C�YX
	static const float ENEMYITEM_SIZE_Y;	//�T�C�YY
	static const float ENEMYITEM_SPEED;		//�X�s�[�h

	//�����o�ϐ�
	EnemyItem* m_pEnemyItem = nullptr;
	DrawObject m_pDrawObjectEnemyItem;
	EnemySetPos m_pEnemySetPos;

	int m_enemy_num = 0;		//�G�̐�
	int m_bullet_num = 0;		//�e�̐�
	int m_enemyitem_num = 0;	//�G�̃A�C�e���̐�

	int m_count = 0;			//�G�̏o�����x

public:
	//�f�t�H���g�R���X�g���N�^
	EnemyItemManagement() {
		m_pEnemyItem = new EnemyItem[MAX_NUM];
	}

	//�����t���R���X�g���N�^
	EnemyItemManagement(DrawObject& pDrawObject3,EnemySetPos& pEnemySetPos);

	//�X�V����
	void Update(const D3DXVECTOR2& PlayerPos);

	//�`�揈��
	void Draw(void)const;

	//=================================
	// �G�̃A�C�e��
	// ================================
	//�w�肵���G�̃A�C�e��������
	void DeleteEnemyItem(int index_num);

	//���݂̓G�̃A�C�e����Ԃ�
	int GetEnemyItemNum(void)const { return m_enemyitem_num; }

	//�w�肵���G�̃A�C�e���̍��W��Ԃ�
	const D3DXVECTOR2& GetEnemyItemPos(int index_num)const { return m_pEnemyItem[index_num].GetPos(); }

	//�G�̃A�C�e���̃T�C�Y��Ԃ�
	const D3DXVECTOR2& GetEnemyItemSize(void)const { return m_pEnemyItem[0].GetSize(); }
};

#endif // !_ENEMY_ITEM_MANAGEMENT_H_