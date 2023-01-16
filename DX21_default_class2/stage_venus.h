//=======================================
// 金星のステージ関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#pragma once

#include "inh_stage.h"

#include "collision_all.h"

#include "management_enemy_fireball.h"

class StageVenus : public InhStage
{
//メンバ変数
private:
	CollisionAll* m_pColAll = nullptr;		//全ての当たり判定
	EnemyFireballManagement* m_pEnemyFireballManagement = nullptr;

	//メンバ関数
public:
	StageVenus(Score* pNumber);

	~StageVenus();	//デストラクタ

	//更新
	void Update(void) override;

	//描画
	void Draw(void)const override;

	//スコアを返す
	int GetScore(void)const { return m_pScore->GetNumber(); }
};

void VenusHitStop(int flame);
void VenusBossDown();
