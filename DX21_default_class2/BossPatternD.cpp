#include "BossPatternD.h"
#include "BossPatternE.h"
#include "boss.h"
#include "BulletPatternC.h"
BossPatternD::BossPatternD(Boss* pBoss)
{
	//pBoss->ChangeBulletPattern(new BulletPatternC);
}
void BossPatternD::Update(Boss* pBoss)
{
	//最大ライフの4割になったらEに移行
	if (pBoss->GetHP() == pBoss->GetMaxLife() * 0.4) {
		pBoss->ChangeBossPattern(new BossPatternE(pBoss));
	}
}
