#pragma once
//=======================================
// 水星のステージ関係(ヘッダファイル)
// 作成日：2022/12/15
// 作成者：高梨水希
//=======================================

#ifndef _STAGE_MERCURY_H_
#define _STAGE_MERCURY_H_

#include "inh_stage.h"
#include "management_enemy_laser.h"
#include "management_enemy_icerain.h"
#include "management_enemy_fire.h"
#include "management_enemy_missile.h"
#include "collision_all.h"
#include "management_firefield.h"
#include "management_icefield.h"
#include "all_enemy_management.h"
#include "management_boss.h"
class StageMercury : public InhStage
{	
//メンバ変数
private:
	//敵
	EnemyLaserManagement* m_pEnemyLaser = nullptr;
	EnemyIceRainManagement* m_pEnemyIce = nullptr;
	EnemyFireManagement* m_pEnemyFire = nullptr;
	EnemyMissileManagement* m_pEnemyMissile = nullptr;
	Management_IceField* m_pManagement_IceField = nullptr;
	Management_FireField* m_pManagement_FireField = nullptr;
	AllEnemyManagement* m_pAllEnemyManagement = nullptr;
	CollisionAll* m_pColAll = nullptr;
	BossManagement* m_pBossManagement = nullptr;
//メンバ関数
public:
	StageMercury(Score* pNumber);

	~StageMercury()override;	//デストラクタ

	//更新
	void Update(void);

	//描画
	void Draw(void)const;

	//スコアを返す
	int GetScore(void)const { return m_pScore->GetNumber(); }
};

#endif // !_STAGE_MERCURY_H_