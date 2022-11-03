#pragma once
//=================================================
// �v���C���[�ƓG�̓����蔻��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/10/31
// �쐬�ҁF��������
//=================================================

#ifndef _PLAYER_ENEMY_COL_H_
#define _PLAYER_ENEMY_COL_H_

#include "player.h"
#include "enemy_management.h"
#include "explosion_management.h"
#include "item_management.h"
#include "number.h"

class PlayerEnemyCol
{
private:
	Player* m_pPlayer = nullptr;					//�v���C���[
	EnemyManagement* m_pEnemy = nullptr;			//�S�G
	ExplosionManagement* m_pExplosion = nullptr;	//����
	ItemManagement* m_pItem = nullptr;				//�A�C�e��
	Number* m_pNumber = nullptr;					//�|�����G�̐��\��

	int m_EnemyNum = 0;								//�G�̎�ނ̐�
	bool m_PlayerEnemyCol = false;					//�G���g�ƃv���C���[���g�̓�����t���O

public:
	//�f�t�H���g�R���X�g���N�^
	PlayerEnemyCol(){}

	//�����t���R���X�g���N�^
	PlayerEnemyCol(Player* pPlayer, EnemyManagement* pEnemy, ExplosionManagement* pExplosion,
		ItemManagement* pItem, Number* pNumber, int EnemyNum)
		:m_pPlayer(pPlayer), m_pEnemy(pEnemy), m_pExplosion(pExplosion), 
		m_pItem(pItem), m_pNumber(pNumber), m_EnemyNum(EnemyNum) {}

	//�f�X�g���N�^
	~PlayerEnemyCol(){}

	//�S�Ă̓G�ƃv���C���[�̓����蔻��
	//�v���C���[�̍�ꂽHP�̒l��Ԃ�
	int Collision(void);

};

#endif // !_PLAYER_ENEMY_COL_H_