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
	//�ő僉�C�t��4���ɂȂ�����E�Ɉڍs
	if (pBoss->GetHP() == pBoss->GetMaxLife() * 0.4) {
		pBoss->ChangeBossPattern(new BossPatternE(pBoss));
	}
}
