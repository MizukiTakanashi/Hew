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
	ArmEnemyCollision() {}	//デフォルトコンストラクタ
	//引数付きコンストラクタ
	ArmEnemyCollision(inhPlayerArmBoth* rplayerleft, inhPlayerArmBoth* rplayerright, ItemManagement* rItemManagement,Player* rPlayer)
		:m_rPlayeLeft(rplayerleft), m_rPlayerRight(rplayerright), m_rItemManagement(rItemManagement),m_rPlayer(rPlayer) {}

	~ArmEnemyCollision() {}		//デストラクタ

	//更新処理
	int Update(void);
};