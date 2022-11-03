//=============================================================
// �v���C���[�ƃ��[�U�[�̓G�̏��X�̓����蔻��֌W(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=============================================================
#pragma once

#ifndef _PLAYER_ENEMY_LASER_COLLISION_H_
#define _PLAYER_ENEMY_LASER_COLLISION_H_

#include "player.h"
#include "management_enemy_laser.h"
#include "management_explosion.h"
#include "number.h"
#include "management_item.h"
	//�G�̃A�C�e��
//static const float ENEMYITEM_SIZE_X;	//�T�C�YX
//static const float ENEMYITEM_SIZE_Y;	//�T�C�YY
//static const float ENEMYITEM_SPEED;		//�X�s�[�h
class PlayerEnemyLaserCollision
{
private:
	Player* m_rPlayer = nullptr;
	EnemyLaserManagement* m_rEnemyManagement = nullptr;
	ExplosionManagement* m_rExplosionManagement = nullptr;
	Number* m_pNumber = nullptr;
	ItemManagement* m_rItemManagement = nullptr;
	bool m_PlayerEnemyNormalCol = false;	//�v���C���[���g�ƓG���g���������Ă��邩�t���O

public:
	PlayerEnemyLaserCollision() {}	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	PlayerEnemyLaserCollision(Player* rPlayer, EnemyLaserManagement* rEnemyNormalManagement,
		ExplosionManagement* rExplosionManagement, Number* pNumber, ItemManagement* m_rItem)
		:m_rPlayer(rPlayer), m_rEnemyManagement(rEnemyNormalManagement),
		m_rExplosionManagement(rExplosionManagement), m_pNumber(pNumber), m_rItemManagement(m_rItem) {}

	~PlayerEnemyLaserCollision() {}	//�f�X�g���N�^

	//�X�V����
	int Update(void);
};

#endif // !_PLAYER_ENEMY_LASER_COLLISION_H_