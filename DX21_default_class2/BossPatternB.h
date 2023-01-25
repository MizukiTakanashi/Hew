#pragma once
//=====================================
//�{�X�p�^�[��B
// ����ҁF����đ�
// ������F1/24
//=====================================
#include "BossPattern.h"
#include "game_object.h"
class Boss;
class InhStage;
class BossPatternB : public BossPattern
{
protected:
	float m_move_width = 0.0f;			//�G����������cos�J�[�u
public:
	BossPatternB(Boss* pBoss);
	virtual ~BossPatternB() {};
	virtual void Update(Boss* pBoss) override;

private:
	BossPatternB(){}
};