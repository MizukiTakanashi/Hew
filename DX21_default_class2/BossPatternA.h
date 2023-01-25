#pragma once
//=====================================
//ボスパターンA
// 製作者：矢野翔大
// 制作日：1/24
//=====================================
#include "BossPattern.h"
#include "inh_stage.h"
class BossPatternA : public BossPattern
{
private:
	static const float STOP_POS_Y;		//敵が止まる場所
	static const float SPEED_Y;			//敵のスピードY
public:
	virtual ~BossPatternA() {};
	virtual void Update(Boss* pBoss) override;

};