#include "BossPatternA.h"
#include "BossPatternB.h"
#include "boss.h"
const float BossPatternA::STOP_POS_Y = 100.0f;
const float BossPatternA::SPEED_Y = 2.5f;
void BossPatternA::Update(Boss* pBoss)
{
	//Ž~‚Ü‚éêŠ‚Ü‚ÅˆÚ“®‚·‚é
	if (pBoss->GetPos().y < STOP_POS_Y) {
		pBoss->MovePos(D3DXVECTOR2(0.0f, SPEED_Y));
	}
	//Ž~‚Ü‚éêŠ‚Ü‚Å—ˆ‚½‚çƒpƒ^[ƒ“B‚ÉˆÚs
	if (pBoss->GetPos().y == STOP_POS_Y) {
		pBoss->ChangeBossPattern(new BossPatternB(pBoss));
	}
}
