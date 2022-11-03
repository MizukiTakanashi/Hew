#pragma once
#include "playerleft.h"
#include "playerright.h"
#include "ItemManagement.h"
#include "enemylasermanagement.h"
#include "EnemyGatoringManagement.h"
#include "EnemyManagement.h"
#include "ExplosionManagement.h"
class ArmAllEnemyCollision
{
private:
	PlayerLeft* m_rplayerleft = nullptr;
	PlayerRight* m_rplayerright = nullptr;
	EnemyLaserManagement* m_rEnemyLaserManagement = nullptr;
	EnemyGatoringManagement* m_rEnemyGatoringManagement = nullptr;
	EnemyManagement* m_rEnemyManagement = nullptr;
	ExplosionManagement* m_rExplosionManagement = nullptr;

public:
	ArmAllEnemyCollision() {}	//デフォルトコンストラクタ
	//引数付きコンストラクタ
	ArmAllEnemyCollision(PlayerLeft* rplayerleft, PlayerRight* rplayerright, EnemyLaserManagement* rEnemyLaserManagement,
		EnemyGatoringManagement* rEnemyGatoringManagements, EnemyManagement* rEnemyManagement, ExplosionManagement* rExplosionManagement)
		:m_rplayerleft(rplayerleft), m_rplayerright(rplayerright), m_rEnemyLaserManagement(rEnemyLaserManagement),
		m_rEnemyGatoringManagement(rEnemyGatoringManagements), m_rEnemyManagement(rEnemyManagement), m_rExplosionManagement(rExplosionManagement) {}

	~ArmAllEnemyCollision() {}		//デストラクタ

	//更新処理
	int Update(void);
};