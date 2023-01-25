#pragma once
//=====================================
//弾のパターンA
//製作者：矢野翔大
//制作日：1/25
//=====================================
#include "BulletPattern.h"

class BulletPattern;
class  BulletPatternA:public BulletPattern
{
public:
	 BulletPatternA();
	virtual ~ BulletPatternA();
	virtual void Update(Boss* pBoss)override;
private:

};

