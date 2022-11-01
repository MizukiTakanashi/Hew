#pragma once
#include "player_left.h"
#include "player_right.h"
#include "item_management.h"
class ArmEnemyCollision
{
private:
	PlayerLeft* m_rplayerleft = nullptr;
	PlayerRight* m_rplayerright = nullptr;
	ItemManagement* m_rItemManagement = nullptr;
	bool m_playerleft = false;				//左手とアイテムの当たり判定フラグ
	bool m_playerright = false;				//右手とアイテムの当たり判定フラグ
public:
	ArmEnemyCollision() {}	//デフォルトコンストラクタ
	//引数付きコンストラクタ
	ArmEnemyCollision(PlayerLeft* rplayerleft, PlayerRight* rplayerright, ItemManagement* rItemManagement)
		:m_rplayerleft(rplayerleft), m_rplayerright(rplayerright), m_rItemManagement(rItemManagement) {}

	~ArmEnemyCollision() {}		//デストラクタ

	//更新処理
	int Update(void);
};