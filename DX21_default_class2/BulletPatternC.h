#pragma once
//=====================================
//弾のパターンC
//製作者：矢野翔大
//制作日：1/25
//=====================================
#include "BulletPattern.h"

class BulletPattern;
class  BulletPatternC :public BulletPattern
{
public:
	BulletPatternC();
	virtual ~BulletPatternC();
	virtual void Update(Boss* pBoss)override;
private:

};

