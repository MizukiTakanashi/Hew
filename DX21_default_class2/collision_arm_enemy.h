#pragma once
#include "inh_player_arm_both.h"
#include "management_item.h"
#include "player.h"
class ArmEnemyCollision
{
private:
	inhPlayerArmBoth* m_rPlayeLeft = nullptr;
	inhPlayerArmBoth* m_rPlayerRight = nullptr;
	ItemManagement* m_rItemManagement = nullptr;
	Player* m_rPlayer = nullptr;

public:
	ArmEnemyCollision() {}	//�f�t�H���g�R���X�g���N�^
	//�����t���R���X�g���N�^
	ArmEnemyCollision(inhPlayerArmBoth* rplayerleft, inhPlayerArmBoth* rplayerright, ItemManagement* rItemManagement,Player* rPlayer)
		:m_rPlayeLeft(rplayerleft), m_rPlayerRight(rplayerright), m_rItemManagement(rItemManagement),m_rPlayer(rPlayer) {}

	~ArmEnemyCollision() {}		//�f�X�g���N�^

	//�X�V����
	int Update(void);
};