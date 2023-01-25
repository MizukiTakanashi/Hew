#pragma once
//=====================================
//�{�X�p�^�[��C
// ����ҁF����đ�
// ������F1/24
//=====================================
#include "BossPattern.h"
class Boss;

class BossPatternC : public BossPattern
{
public:
	BossPatternC(Boss* pBoss);
	virtual ~BossPatternC() {};
	virtual void Update(Boss* pBoss) override;

private:
	BossPatternC() {}
};