#pragma once
//=====================================
//ボスパターンD
// 製作者：矢野翔大
// 制作日：1/24
//=====================================
#include "BossPattern.h"
class Boss;

class BossPatternD : public BossPattern
{
public:
	BossPatternD(Boss* pBoss);
	virtual ~BossPatternD() {};
	virtual void Update(Boss* pBoss) override;

private:
	BossPatternD() {}
};