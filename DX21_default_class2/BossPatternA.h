#pragma once
//=====================================
//�{�X�p�^�[��A
// ����ҁF����đ�
// ������F1/24
//=====================================
#include "BossPattern.h"
#include "inh_stage.h"
class BossPatternA : public BossPattern
{
private:
	static const float STOP_POS_Y;		//�G���~�܂�ꏊ
	static const float SPEED_Y;			//�G�̃X�s�[�hY
public:
	virtual ~BossPatternA() {};
	virtual void Update(Boss* pBoss) override;

};