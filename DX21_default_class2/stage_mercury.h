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

class StageMercury : public InhStage
{
//定数
private:


	
//メンバ変数
private:
	//敵のレーザー
	EnemyLaserManagement* m_pEnemyLaser = nullptr;


//メンバ関数
public:
	StageMercury(Score* pNumber);

	~StageMercury();	//デストラクタ

	//更新
	void Update(void);

	//描画
	void Draw(void)const;

	//スコアを返す
	int GetScore(void)const { return m_pScore->GetNumber(); }
};

void MercuryHitStop(int flame);
void MercuryBossDown();


#endif // !_STAGE_MERCURY_H_