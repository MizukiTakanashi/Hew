//==============================================
// (継承用)プレイヤーの腕関係(cppファイル)
// 作成日：2022/11/02
// 作成者：高梨水希
//==============================================
#include "inhPlayerArm.h"

//==========================
// 弾が尽きたかを返す
//==========================
bool inhPlayerArm::IsBulletUsed(void)const
{
	if (m_bullet_maked_num >= m_bullet_max_num) {
		return true;
	}

	return false;
}
