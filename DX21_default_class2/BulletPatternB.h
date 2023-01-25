#pragma once
//=====================================
//弾のパターンB
//製作者：矢野翔大
//制作日：1/25
//=====================================
#include "BulletPattern.h"

class BulletPattern;
class  BulletPatternB :public BulletPattern
{
public:
	BulletPatternB();
	virtual ~BulletPatternB();
	virtual void Update(Boss* pBoss)override;
private:

};

