#pragma once
//=====================================
//ボスパターンC
// 製作者：矢野翔大
// 制作日：1/24
//=====================================
#include "BossPattern.h"
class Boss;

class BossPatternC : public BossPattern
{
public:
	BossPatternC(Boss* pBoss);
	virtual ~BossPatternC() {};
	virtual void Update(Boss* pBoss) override;

private:
	BossPatternC() {}
};