#pragma once
//=====================================
//弾のパターンD
//製作者：矢野翔大
//制作日：1/25
//=====================================
#include "BulletPattern.h"

class BulletPattern;
class  BulletPatternD :public BulletPattern
{
public:
	BulletPatternD();
	virtual ~BulletPatternD();
	virtual void Update(Boss* pBoss)override;
private:

};

