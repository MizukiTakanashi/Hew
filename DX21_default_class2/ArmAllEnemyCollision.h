#pragma once
#include "playerleft.h"
#include "playerright.h"
#include "ItemManagement.h"
#include "enemylasermanagement.h"
#include "EnemyGatoringManagement.h"
#include "EnemyManagement.h"

class ArmAllEnemyCollision
{
private:
	PlayerLeft* m_rplayerleft = nullptr;
	PlayerRight* m_rplayerright = nullptr;
	EnemyLaserManagement* m_rEnemyLaserManagement = nullptr;
	EnemyGatoringManagement* m_rEnemyGatoringManagement = nullptr;
	EnemyManagement* m_rEnemyManagement = nullptr;

	bool m_playerleft = false;				//����ƃA�C�e���̓����蔻��t���O
	bool m_playerright = false;				//�E��ƃA�C�e���̓����蔻��t���O
public:
	ArmAllEnemyCollision() {}	//�f�t�H���g�R���X�g���N�^
	//�����t���R���X�g���N�^
	ArmAllEnemyCollision(PlayerLeft* rplayerleft, PlayerRight* rplayerright, EnemyLaserManagement* rEnemyLaserManagement,
		EnemyGatoringManagement* rEnemyGatoringManagements, EnemyManagement* rEnemyManagement)
		:m_rplayerleft(rplayerleft), m_rplayerright(rplayerright), m_rEnemyLaserManagement(rEnemyLaserManagement),
		m_rEnemyGatoringManagement(rEnemyGatoringManagements), m_rEnemyManagement(rEnemyManagement) {}

	~ArmAllEnemyCollision() {}		//�f�X�g���N�^

	//�X�V����
	int Update(void);
};