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
	//Å‘åƒ‰ƒCƒt‚Ì4Š„‚É‚È‚Á‚½‚çE‚ÉˆÚs
	if (pBoss->GetHP() == pBoss->GetMaxLife() * 0.4) {
		pBoss->ChangeBossPattern(new BossPatternE(pBoss));
	}
}
