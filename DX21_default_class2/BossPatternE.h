#pragma once
//=====================================
//�{�X�p�^�[��E
// ����ҁF����đ�
// ������F1/24
//=====================================
#include "BossPattern.h"
class Boss;

class BossPatternE : public BossPattern
{
public:
	BossPatternE(Boss* pBoss);
	virtual ~BossPatternE() {};
	virtual void Update(Boss* pBoss) override;

private:
	BossPatternE() {}
};