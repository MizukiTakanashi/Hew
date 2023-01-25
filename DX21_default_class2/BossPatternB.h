#pragma once
//=====================================
//ボスパターンB
// 製作者：矢野翔大
// 制作日：1/24
//=====================================
#include "BossPattern.h"
#include "game_object.h"
class Boss;
class InhStage;
class BossPatternB : public BossPattern
{
protected:
	float m_move_width = 0.0f;			//敵が動く時のcosカーブ
public:
	BossPatternB(Boss* pBoss);
	virtual ~BossPatternB() {};
	virtual void Update(Boss* pBoss) override;

private:
	BossPatternB(){}
};