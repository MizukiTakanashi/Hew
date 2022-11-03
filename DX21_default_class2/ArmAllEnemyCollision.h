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

	bool m_playerleft = false;				//左手とアイテムの当たり判定フラグ
	bool m_playerright = false;				//右手とアイテムの当たり判定フラグ
public:
	ArmAllEnemyCollision() {}	//デフォルトコンストラクタ
	//引数付きコンストラクタ
	ArmAllEnemyCollision(PlayerLeft* rplayerleft, PlayerRight* rplayerright, EnemyLaserManagement* rEnemyLaserManagement,
		EnemyGatoringManagement* rEnemyGatoringManagements, EnemyManagement* rEnemyManagement)
		:m_rplayerleft(rplayerleft), m_rplayerright(rplayerright), m_rEnemyLaserManagement(rEnemyLaserManagement),
		m_rEnemyGatoringManagement(rEnemyGatoringManagements), m_rEnemyManagement(rEnemyManagement) {}

	~ArmAllEnemyCollision() {}		//デストラクタ

	//更新処理
	int Update(void);
};