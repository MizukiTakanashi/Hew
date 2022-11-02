#pragma once
#include "playerleft.h"
#include "playerright.h"
#include "ItemManagement.h"

class ArmEnemyCollision
{
private:
	PlayerLeft* m_rplayerleft = nullptr;
	PlayerRight* m_rplayerright = nullptr;
	ItemManagement* m_rItemManagement = nullptr;
	
	bool m_playerleft = false;				//����ƃA�C�e���̓����蔻��t���O
	bool m_playerright = false;				//�E��ƃA�C�e���̓����蔻��t���O
public:
	ArmEnemyCollision() {}	//�f�t�H���g�R���X�g���N�^
	//�����t���R���X�g���N�^
	ArmEnemyCollision(PlayerLeft* rplayerleft, PlayerRight* rplayerright, ItemManagement* rItemManagement)
		:m_rplayerleft(rplayerleft), m_rplayerright(rplayerright), m_rItemManagement(rItemManagement) {}

	~ArmEnemyCollision() {}		//�f�X�g���N�^

	//�X�V����
	int Update(void);
};