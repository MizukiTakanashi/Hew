//==============================================
// (Œp³—p)ƒvƒŒƒCƒ„[‚Ì˜rŠÖŒW(cppƒtƒ@ƒCƒ‹)
// ì¬“úF2022/11/02
// ì¬ŽÒF‚—œ…Šó
//==============================================
#include "inh_player_arm.h"

//==========================
// ’e‚ªs‚«‚½‚©‚ð•Ô‚·
//==========================
bool inhPlayerArm::IsBulletUsed(void)const
{
	if (m_bullet_maked_num >= m_bullet_max_num) {
		return true;
	}

	return m_bullet_used;
}


//==========================
// Žc’e”‚ð•Ô‚·
//==========================
int inhPlayerArm::GetRemainingBullet(void)
{
	if (m_bullet_maked_num >= m_bullet_max_num)
	{
		return m_bullet_max_num - m_bullet_maked_num;
	}
	else
	{
		return m_bullet_max_num - m_bullet_maked_num - 1;
	}
}