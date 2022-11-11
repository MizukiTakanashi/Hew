#pragma once
//=========================================================
// 飛んでいる最中の腕と敵の当たり判定関係(ヘッダファイル)
// 作成日：2022/11/11
// 作成者：高梨水希
//=========================================================

#include "player_left.h"
#include "player_right.h"
#include "management_item.h"
#include "management_enemy_laser.h"
#include "management_enemy_gatoring.h"
#include "management_enemy.h"
#include "management_explosion.h"

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
	void Update(void);
};