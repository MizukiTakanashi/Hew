#pragma once
//=====================================
//弾のパターンE
//製作者：矢野翔大
//制作日：1/25
//=====================================
#include "BulletPattern.h"

class BulletPattern;
class  BulletPatternE :public BulletPattern
{
public:
	BulletPatternE();
	virtual ~BulletPatternE();
	virtual void Update(Boss* pBoss)override;
private:

};

