//==============================================
// (継承用)プレイヤーの腕関係(cppファイル)
// 作成日：2022/11/02
// 作成者：高梨水希
//==============================================
#include "inh_player_arm.h"

//==========================
// 弾が尽きたかを返す
//==========================
bool inhPlayerArm::IsBulletUsed(void)const
{
	if (m_bullet_maked_num >= m_bullet_max_num) {
		return true;
	}

	return m_bullet_used;
}


//==========================
// 残弾数を返す
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