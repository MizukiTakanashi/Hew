#pragma once
//=====================================
//�{�X�p�^�[��F
// ����ҁF����đ�
// ������F1/24
//=====================================
#include "BossPattern.h"
class BossPatternF : public BossPattern
{
public:
	explicit BossPatternF(Boss* pEnemy);
	virtual ~BossPatternF();
	virtual void Update(Boss* pEnemy) override;

private: // �f�t�H���g�R���X�g���N�^�̕���
	BossPatternF() {};

};