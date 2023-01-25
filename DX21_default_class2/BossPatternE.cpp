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
	//�ő僉�C�t��6���ɂȂ�����F�Ɉڍs
	if (pBoss->GetHP() == pBoss->GetMaxLife() * 0.2) {
		pBoss->ChangeBossPattern(new BossPatternF(pBoss));
	}
}
