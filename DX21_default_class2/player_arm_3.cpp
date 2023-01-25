//===================================================
// �v���C���[�̘r�A�K�g�����O�E���֌W(cpp�t�@�C��)
// �쐬���F2022/10/30
// �쐬�ҁF��������
//===================================================
#include "player_arm_3.h"

//==========================
// �萔�̏�����
//==========================
const float PlayerArm3::BULLET_SIZE_X = 20.0f;
const float PlayerArm3::BULLET_SIZE_Y = 20.0f;
const float PlayerArm3::BULLET_SPEED = 20.0f;
const float PlayerArm3::FIRE_SPEED = 10.0f;
const float PlayerArm3::ACID_SPEED = 5.0f;
const float PlayerArm3::FIREBALL_SPEED = 5.0f;

//==========================
// �X�V����
//==========================
void PlayerArm3::Update(const D3DXVECTOR2& arm_pos)
{
	//������e�̏���
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		//�e�̍X�V����
		m_pBullet[i].Update();

		//��ʊO����o����...
		if (m_pBullet[i].GetScreenOut()){
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
		(!inhPlayerArm::GetRightLeft() && inhPlayerArm::IsButtonPush())) {
		//���˂ł��鎞�ԂɂȂ�����...
		if (m_bullet_interval_count > m_interval) {
			m_bullet_interval_count = 0;

			//�r�̐؂藣���Ɠ����ɒe�����Ȃ����߂̏���
			if (inhPlayerArm::GetBulletMaked() == BULLET_NUM_MAX - 1)
			{
				//������e�̐��𑝂₷
				inhPlayerArm::IncreaseBulletMaked();

				return;
			}

			float temp_speed = 0.0f;
			if (m_type == TYPE::GATORING) {
				temp_speed = BULLET_SPEED;
			}
			else if (m_type == TYPE::FIRE) {
				temp_speed = FIRE_SPEED;
			}
			else if (m_type == TYPE::ACID)
			{
				temp_speed = ACID_SPEED;
			}
			else if (m_type == TYPE::FIREBALL)
			{
				temp_speed = FIREBALL_SPEED;
			}

			//�e�����
			Bullet temp;
			if (m_type == TYPE::ACID)
			{
				temp = Bullet(m_bulletdraw, arm_pos,
					D3DXVECTOR2(100.0f, 200.0f), D3DXVECTOR2(0.0f, -temp_speed), 0.0f);

			}
			else if (m_type == TYPE::FIREBALL)
			{
				temp = Bullet(m_bulletdraw, arm_pos,
					D3DXVECTOR2(200.0f, 200.0f), D3DXVECTOR2(0.0f, -temp_speed), 0.0f);
			}
			else
			{
				temp = Bullet(m_bulletdraw, arm_pos,
					D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0.0f, -temp_speed), 0.0f);

			}

			m_pBullet[inhPlayerArm::GetBulletNum()] = temp;

			//���݂̒e�̐��𑝂₷
			inhPlayerArm::IncreaseBulletNum();

			//������e�̐��𑝂₷
			inhPlayerArm::IncreaseBulletMaked();

			//����炷
			if (m_type == TYPE::GATORING) {
				PlaySound(m_SE_21, 0);
			}
			else if (m_type == TYPE::FIRE) {
				PlaySound(m_SE_15_1, 0);
			}
		}
	}
}

//==========================
// �`�揈��
//==========================
void PlayerArm3::PlayerArmDraw()const
{
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		m_pBullet[i].Draw();
	}
}

//==========================
// �w�肵���ԍ��̒e������
//==========================
void PlayerArm3::DeleteBullet(int index_num)
{
	//�e������
	for (int i = index_num; i < inhPlayerArm::GetBulletNum(); i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	inhPlayerArm::IncreaseBulletNum(-1);
}