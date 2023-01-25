#pragma once
//===============================================
//ボスパターン基本クラス
// 製作者：ヤノショウタ
// 制作日：1/24
//===============================================

class Boss;

class BossPattern
{
public:
	virtual ~BossPattern(){}
	virtual void Update(Boss* pBoss) = 0;
};

class BossPatternNone :public BossPattern
{
public:
	virtual ~BossPatternNone() {}
	virtual void Update(Boss* pBoss)override {}
};