#pragma once
//===============================================
//�{�X�p�^�[����{�N���X
// ����ҁF���m�V���E�^
// ������F1/24
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