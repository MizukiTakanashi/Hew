#pragma once
//=====================================
//�{�X�p�^�[��D
// ����ҁF����đ�
// ������F1/24
//=====================================
#include "BossPattern.h"
class Boss;

class BossPatternD : public BossPattern
{
public:
	BossPatternD(Boss* pBoss);
	virtual ~BossPatternD() {};
	virtual void Update(Boss* pBoss) override;

private:
	BossPatternD() {}
};