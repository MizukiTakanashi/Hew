#include "BossPatternB.h"
#include "BossPatternC.h"
#include "boss.h"
#include "BulletPatternA.h"
BossPatternB::BossPatternB(Boss* pBoss)
{
	pBoss->ChangeBulletPattern(new BulletPatternA);
}
void BossPatternB::Update(Boss* pBoss)
{
	//左右に動く
	float rad = D3DXToRadian(m_move_width);
	pBoss->SetPos(D3DXVECTOR2(0.0f + cosf(rad) * Boss::RANGE, pBoss->GetPos().y));
	m_move_width += Boss::SPEED_X;
	//最大ライフの８割になったらCに移行
	if (pBoss->GetHP() == pBoss->GetMaxLife() * 0.8) {
		pBoss->ChangeBossPattern(new BossPatternC(pBoss));
	}
}
