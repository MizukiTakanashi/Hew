#pragma once
#include "player_left.h"
#include "player_right.h"
#include "management_item.h"

class ArmEnemyCollision
{
private:
	PlayerLeft* m_rPlayeLeft = nullptr;
	PlayerRight* m_rPlayerRight = nullptr;
	ItemManagement* m_rItemManagement = nullptr;


public:
	ArmEnemyCollision() {}	//デフォルトコンストラクタ
	//引数付きコンストラクタ
	ArmEnemyCollision(PlayerLeft* rplayerleft, PlayerRight* rplayerright, ItemManagement* rItemManagement)
		:m_rPlayeLeft(rplayerleft), m_rPlayerRight(rplayerright), m_rItemManagement(rItemManagement) {}

	~ArmEnemyCollision() {}		//デストラクタ

	//更新処理
	int Update(void);
};