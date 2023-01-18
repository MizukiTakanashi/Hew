#pragma once
//=======================================
// 火星のステージ関係(ヘッダファイル)
// 作成日：2022/12/15
// 作成者：高梨水希
//=======================================

#ifndef _STAGE_MARS_H_
#define _STAGE_MARS_H_

#include "inh_stage.h"

#include "management_enemy_barrier.h"
#include "management_enemy_missile.h"
#include "management_enemy_icerain.h"
#include "management_enemy_stop.h"
#include "management_enemy_grenade.h"
#include "all_enemy_management.h"
#include "mars_collision_all.h"
#include "boss.h"

class StageMars : public InhStage
{
	//メンバ変数
private:
	EnemyBarrierManagement* m_pEnemyBarrierManagement = nullptr;
	EnemyIceRainManagement* m_pEnemyIceRainManagement = nullptr;
	EnemyStopManagement* m_pEnemyStopManagement = nullptr;
	EnemyMissileManagement* m_pEnemyMissileManagement = nullptr;
	EnemyGrenadeManagement* m_pEnemyGrenadeManagement = nullptr;

	AllEnemyManagement* m_pAllEnemyManagement = nullptr;
	MarsCollisionAll* m_pColAll = nullptr;		//全ての当たり判定
	Boss* m_pBoss = nullptr;

	//メンバ関数
public:
	StageMars(Score* pNumber);

	~StageMars();	//デストラクタ

	//更新
	void Update(void);

	//描画
	void Draw(void)const;

	//スコアを返す
	int GetScore(void)const { return m_pScore->GetNumber(); }
};

#endif // !_STAGE_MARS_H_