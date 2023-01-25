#pragma once
//=====================================
//ボスパターンF
// 製作者：矢野翔大
// 制作日：1/24
//=====================================
#include "BossPattern.h"
class BossPatternF : public BossPattern
{
public:
	explicit BossPatternF(Boss* pEnemy);
	virtual ~BossPatternF();
	virtual void Update(Boss* pEnemy) override;

private: // デフォルトコンストラクタの封印
	BossPatternF() {};

};