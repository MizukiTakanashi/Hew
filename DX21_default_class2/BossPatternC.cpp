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
	//Å‘åƒ‰ƒCƒt‚Ì6Š„‚É‚È‚Á‚½‚çD‚ÉˆÚs
	if (pBoss->GetHP() == pBoss->GetMaxLife() * 0.6) {
		pBoss->ChangeBossPattern(new BossPatternD(pBoss));
	}
}
