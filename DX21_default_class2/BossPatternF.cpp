#include "BossPatternF.h"
#include "BossPatternB.h"
#include "boss.h"
#include "BulletPatternE.h"
BossPatternF::BossPatternF(Boss* pBoss)
{
	pBoss->ChangeBulletPattern(new BulletPatternE);
}

BossPatternF::~BossPatternF()
{
}

void BossPatternF::Update(Boss* pEnemy)
{
}
