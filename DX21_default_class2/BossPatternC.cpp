#include "BossPatternC.h"
#include "BossPatternD.h"
#include "boss.h"
#include "BulletPatternB.h"
BossPatternC::BossPatternC(Boss* pBoss)
{
	pBoss->ChangeBulletPattern(new BulletPatternB);
}
void BossPatternC::Update(Boss* pBoss)
{
	//最大ライフの6割になったらDに移行
	if (pBoss->GetHP() == pBoss->GetMaxLife() * 0.6) {
		pBoss->ChangeBossPattern(new BossPatternD(pBoss));
	}
}
