#include "BossPatternE.h"
#include "BossPatternF.h"
#include "boss.h"
#include "BulletPatternD.h"
BossPatternE::BossPatternE(Boss* pBoss)
{
	//pBoss->ChangeBulletPattern(new BulletPatternD);
}
void BossPatternE::Update(Boss* pBoss)
{
	//Å‘åƒ‰ƒCƒt‚Ì6Š„‚É‚È‚Á‚½‚çF‚ÉˆÚs
	if (pBoss->GetHP() == pBoss->GetMaxLife() * 0.2) {
		pBoss->ChangeBossPattern(new BossPatternF(pBoss));
	}
}
