#include "BossPatternE.h"
#include "BossPatternF.h"
#include "boss.h"
#include "BulletPatternD.h"
BossPatternE::BossPatternE(Boss* pBoss)
{
	pBoss->ChangeBulletPattern(new BulletPatternD);
}
void BossPatternE::Update(Boss* pBoss)
{
	//最大ライフの6割になったらFに移行
	if (pBoss->GetHP() == pBoss->GetMaxLife() * 0.2) {
		pBoss->ChangeBossPattern(new BossPatternF(pBoss));
	}
}
