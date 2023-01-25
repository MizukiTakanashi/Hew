#pragma once
//=====================================
//ボスパターンE
// 製作者：矢野翔大
// 制作日：1/24
//=====================================
#include "BossPattern.h"
class Boss;

class BossPatternE : public BossPattern
{
public:
	BossPatternE(Boss* pBoss);
	virtual ~BossPatternE() {};
	virtual void Update(Boss* pBoss) override;

private:
	BossPatternE() {}
};