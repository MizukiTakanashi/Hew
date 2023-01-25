#include "BossPatternA.h"
#include "BossPatternB.h"
#include "boss.h"
const float BossPatternA::STOP_POS_Y = 100.0f;
const float BossPatternA::SPEED_Y = 2.5f;
void BossPatternA::Update(Boss* pBoss)
{
	//�~�܂�ꏊ�܂ňړ�����
	if (pBoss->GetPos().y < STOP_POS_Y) {
		pBoss->MovePos(D3DXVECTOR2(0.0f, SPEED_Y));
	}
	//�~�܂�ꏊ�܂ŗ�����p�^�[��B�Ɉڍs
	if (pBoss->GetPos().y == STOP_POS_Y) {
		pBoss->ChangeBossPattern(new BossPatternB(pBoss));
	}
}
