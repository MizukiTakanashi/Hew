#pragma once
//=======================================
// 土星のステージ関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================

#ifndef _STAGE_SATURN_H_
#define _STAGE_SATURN_H_

#include "inh_stage.h"

#include "all_enemy_management.h"
#include "collision_all.h"
#include "management_enemy_laser.h"
#include "management_enemy_megumin.h"
#include "management_enemy_gatoring.h"
#include "management_enemy_missile.h"
#include "management_poisonfield.h"

class StageSaturn : public InhStage
{
//メンバ変数
private:
	EnemyLaserManagement* m_pEnemyLaserManagement = nullptr;
	EnemyMeguminManagement* m_pEnemyMeguminManagement = nullptr;
	EnemyGatoringManagement* m_pEnemyGatoring = nullptr;
	EnemyMissileManagement* m_pEnemyMissile = nullptr;
	AllEnemyManagement* m_pAllEnemyManagement = nullptr;
	CollisionAll* m_pColAll = nullptr;		//全ての当たり判定
	Management_PoisonField* m_pPoisonField = nullptr;

//メンバ関数
public:
	StageSaturn(Score* pNumber);

	~StageSaturn()override;	//デストラクタ

	//更新
	void Update(void);

	//描画
	void Draw(void)const;

	//スコアを返す
	int GetScore(void)const { return m_pScore->GetNumber(); }
};

#endif // !_STAGE_SATURN_H_