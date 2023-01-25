#pragma once
//=====================================
//弾のパターン基本
//製作者：矢野翔大
//制作日：1/25
//=====================================
class Boss;

class BulletPattern
{
public:
	virtual ~BulletPattern() {}
	virtual void Update(Boss* pBoss) = 0;
};

class BulletPatternNull :public BulletPattern
{
	virtual void Update(Boss* pBoss)override {}
};