#pragma once
#include "inh_player_arm_both.h"
#include "management_item.h"

class ArmEnemyCollision
{
private:
	inhPlayerArmBoth* m_rPlayeLeft = nullptr;
	inhPlayerArmBoth* m_rPlayerRight = nullptr;
	ItemManagement* m_rItemManagement = nullptr;


public:
	ArmEnemyCollision() {}	//�f�t�H���g�R���X�g���N�^
	//�����t���R���X�g���N�^
	ArmEnemyCollision(inhPlayerArmBoth* rplayerleft, inhPlayerArmBoth* rplayerright, ItemManagement* rItemManagement)
		:m_rPlayeLeft(rplayerleft), m_rPlayerRight(rplayerright), m_rItemManagement(rItemManagement) {}

	~ArmEnemyCollision() {}		//�f�X�g���N�^

	//�X�V����
	int Update(void);
};