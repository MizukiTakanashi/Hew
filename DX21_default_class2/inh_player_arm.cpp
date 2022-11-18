//==============================================
// (�p���p)�v���C���[�̘r�֌W(cpp�t�@�C��)
// �쐬���F2022/11/02
// �쐬�ҁF��������
//==============================================
#include "inh_player_arm.h"

//==========================
// �e���s��������Ԃ�
//==========================
bool inhPlayerArm::IsBulletUsed(void)const
{
	if (m_bullet_maked_num >= m_bullet_max_num) {
		return true;
	}

	return m_bullet_used;
}


//==========================
// �c�e����Ԃ�
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