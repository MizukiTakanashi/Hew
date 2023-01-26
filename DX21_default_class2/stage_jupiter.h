#pragma once
//=======================================
// 木星のステージ関係(ヘッダファイル)
// 作成日：2023/01/26
// 作成者：高梨水希
//=======================================

#ifndef _STAGE_JUPITER_H_
#define _STAGE_JUPITER_H_

#include "inh_stage.h"
#include "collision_all.h"
#include "all_enemy_management.h"
#include "management_enemy_laser.h"
#include "management_enemy_missile.h"
#include "management_enemy_barrier.h"
#include "management_enemy_public.h"

class StageJupiter : public InhStage
{
//メンバ変数
private:
	//敵
	Management_EnemyPublic* m_pEnemyPublic = nullptr;
	EnemyMissileManagement* m_pEnemyMissile = nullptr;
	EnemyLaserManagement* m_pEnemyLaser = nullptr;
	EnemyBarrierManagement* m_pEnemyBarrier = nullptr;
	AllEnemyManagement* m_pAllEnemyManagement = nullptr;
	CollisionAll* m_pColAll = nullptr;


//メンバ関数
public:
	StageJupiter(Score* pNumber);

	~StageJupiter()override;	//デストラクタ

	//更新
	void Update(void);

	//描画
	void Draw(void)const;

	//スコアを返す
	int GetScore(void)const { return m_pScore->GetNumber(); }
};

#endif // !_STAGE_JUPITER_H_