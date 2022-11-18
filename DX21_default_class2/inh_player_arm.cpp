//==============================================
// (Œp³—p)ƒvƒŒƒCƒ„[‚Ì˜rŠÖŒW(cppƒtƒ@ƒCƒ‹)
// ì¬“úF2022/11/02
// ì¬ÒF‚—œ…Šó
//==============================================
#include "inh_player_arm.h"

//==========================
// ’e‚ªs‚«‚½‚©‚ğ•Ô‚·
//==========================
bool inhPlayerArm::IsBulletUsed(void)const
{
	if (m_bullet_maked_num >= m_bullet_max_num) {
		return true;
	}

	return m_bullet_used;
}


//==========================
// c’e”‚ğ•Ô‚·
//==========================
int inhPlayerArm::GetRemainingBullet(void)
{
	if (m_bullet_max_num == 0)
	{
		return m_bullet_max_num - m_bullet_maked_num;
	}
	else
	{
		return m_bullet_max_num - m_bullet_maked_num - 1;
	}
}