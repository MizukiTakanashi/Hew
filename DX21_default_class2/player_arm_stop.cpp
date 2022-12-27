//=======================================
// �v���C���[�̘r(STOP)�֌W(cpp�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#include "player_arm_stop.h"

//==========================
// �萔�̏�����
//==========================
const float PlayerArmStop::BULLET_SIZE_X = 100.0f;
const float PlayerArmStop::BULLET_SIZE_Y = 300.0f;

//==========================
// �X�V����
//==========================
void PlayerArmStop::Update(const D3DXVECTOR2& arm_pos)
{

	//������e�̏���
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		//�e�̍X�V����
		m_pBullet[i].Update();

		//��ʊO����o����...
		if (m_pBullet[i].GetScreenOut() || m_pBullet[i].GetTime() > BULLET_TIME) {
			DeleteBullet(i);
		}
	}

	//�������e�̐����������Ă���e�����Ȃ�
	if (inhPlayerArm::IsBulletUsed()) {
		return;
	}

	//���ˊԊu�J�E���g
	m_bullet_interval_count++;

	//�{�^���������ꂽ��
	if ((inhPlayerArm::GetRightLeft() && inhPlayerArm::IsButtonPush()) ||
		(!inhPlayerArm::GetRightLeft() && inhPlayerArm::IsButtonPush())) 
	{
		//���˂ł��鎞�ԂɂȂ�����...
		if (m_bullet_interval_count > BULLET_INTERVAL)
		{
			m_bullet_interval_count = 0;

			//�r�̐؂藣���Ɠ����ɒe�����Ȃ����߂̏���
			if (inhPlayerArm::GetBulletMaked() == BULLET_NUM_MAX - 1)
			{
				//������e�̐��𑝂₷
				inhPlayerArm::IncreaseBulletMaked();

				return;
			}

			//�e�����
			BulletStop temp(m_bulletdraw, arm_pos - D3DXVECTOR2(0, 300), D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y));

			m_pBullet[inhPlayerArm::GetBulletNum()] = temp;

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
void PlayerArmStop::PlayerArmDraw()const
{
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		m_pBullet[i].Draw();
	}
}

//==========================
// �w�肵���ԍ��̒e������
//==========================
void PlayerArmStop::DeleteBullet(int index_num)
{
	//�e������
	for (int i = index_num; i < inhPlayerArm::GetBulletNum(); i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	inhPlayerArm::IncreaseBulletNum(-1);
}
