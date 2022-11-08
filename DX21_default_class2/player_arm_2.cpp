//=======================================
// �v���C���[�̘r2�֌W(cpp�t�@�C��)
// �쐬���F2022/00/00
// �쐬�ҁF��������
//=======================================
#include "player_arm_2.h"

//==========================
// �萔�̏�����
//==========================
const float PlayerArm2::BULLET_SIZE_X = 20.0f;
const float PlayerArm2::BULLET_SIZE_Y = 0.0f;
const float PlayerArm2::BULLET_SPEED = 2.5f;
const float PlayerArm2::SPEED_Y = 15.0f;

//==========================
// �X�V����
//==========================
void PlayerArm2::Update(const D3DXVECTOR2& arm_pos)
{
	//���݂̒e�̏���
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		m_pLaser[i].Update(arm_pos, false);

		//��ʂ���o�������
		if (m_pLaser[i].GetScreenOut()) {
			DeleteBullet(i);
		}
	}

	//�������e�̐����������Ă���e�����Ȃ�
	if (inhPlayerArm::IsBulletUsed()) {
		return;
	}

	//���ˊԊu�J�E���g
	m_bullet_interval_count++;

	//�������{�^���������ꂽ��
	if ((inhPlayerArm::GetRightLeft() && inhPlayerArm::IsButtonPush()) ||
		(!inhPlayerArm::GetRightLeft() && inhPlayerArm::IsButtonPush())) {
		//���˂ł��鎞�ԂɂȂ�����...
		if (m_bullet_interval_count > BULLET_INTERVAL) {
			m_bullet_interval_count = 0;

			//�r�̐؂藣���Ɠ����ɒe�����Ȃ����߂̏���
			if (inhPlayerArm::GetBulletMaked() == BULLET_NUM_MAX - 1)
			{
				//������e�̐��𑝂₷
				inhPlayerArm::IncreaseBulletMaked();
				
				return;
			}

			Laser temp(m_laser_draw, arm_pos, D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y));
			m_pLaser[inhPlayerArm::GetBulletNum()] = temp;

			//���݂̒e�̐��𑝂₷
			inhPlayerArm::IncreaseBulletNum();

			//������e�̐��𑝂₷
			inhPlayerArm::IncreaseBulletMaked();
		}
	}
}

//==========================
// �`�揈��
//==========================
void PlayerArm2::PlayerArmDraw()const
{
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		m_pLaser[i].Draw();
	}
}

//==========================
// �w�肵���ԍ��̒e������
//==========================
void PlayerArm2::DeleteBullet(int index_num)
{
	//���[�U�[���k�߂�
	m_pLaser[index_num].DeleteLaser();

	//���[�U�[������
	for (int i = index_num; i < inhPlayerArm::GetBulletNum() - 1; i++) {
		m_pLaser[i] = m_pLaser[i + 1];
	}

	inhPlayerArm::IncreaseBulletNum(-1);
}