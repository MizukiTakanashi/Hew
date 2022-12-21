//=======================================
// �v���C���[�̘r1�֌W(cpp�t�@�C��)
// �쐬���F2022/10/30
// �쐬�ҁF��������
//=======================================
#include "player_arm_barrier.h"

//==========================
// �萔�̏�����
//==========================
const float PlayerArmBarrier::BULLET_SIZE_X = 80.0f;
const float PlayerArmBarrier::BULLET_SIZE_Y = 10.0f;
const D3DXVECTOR2 PlayerArmBarrier::RIGHT_BARRIER_INTERVAL_POS = D3DXVECTOR2(-30.0f, -45.0f);
const D3DXVECTOR2 PlayerArmBarrier::LEFT_BARRIER_INTERVAL_POS = D3DXVECTOR2(30.0f, -45.0f);

//==========================
// �X�V����
//==========================
void PlayerArmBarrier::Update(const D3DXVECTOR2& arm_pos)
{
	//�o���A�̏���
	if (inhPlayerArm::GetBulletNum() == 1) {
		//���Ă���̂��E�ł����
		if (inhPlayerArm::GetRightLeft()) {
			m_pBullet->SetPos(arm_pos + RIGHT_BARRIER_INTERVAL_POS);
		}
		//���ł����
		else {
			m_pBullet->SetPos(arm_pos + LEFT_BARRIER_INTERVAL_POS);
		}
	}

	//�������e�̐����������Ă���o���A�����Ȃ�
	//�o���A���������łɍ���Ă�����
	if (inhPlayerArm::IsBulletUsed() || inhPlayerArm::GetBulletNum() == 1) {
		return;
	}

	//�{�^���������ꂽ��
	if ((inhPlayerArm::GetRightLeft() && inhPlayerArm::IsButtonTrigger()) ||
		(!inhPlayerArm::GetRightLeft() && inhPlayerArm::IsButtonTrigger())) {
		//�r�̐؂藣���Ɠ����ɒe�����Ȃ����߂̏���
		if (inhPlayerArm::GetBulletMaked() == BULLET_NUM_MAX - 1)
		{
			//������e�̐��𑝂₷
			inhPlayerArm::IncreaseBulletMaked();

			return;
		}

		//�o���A�����
		m_pBullet = new Bullet(m_bulletdraw, arm_pos,
			D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0.0f, 0.0f), 0.0f);

		//���݂̒e�̐��𑝂₷
		inhPlayerArm::IncreaseBulletNum();

		//������e�̐��𑝂₷
		inhPlayerArm::IncreaseBulletMaked();
	}
}

//==========================
// �`�揈��
//==========================
void PlayerArmBarrier::PlayerArmDraw()const
{
	if (inhPlayerArm::GetBulletNum() == 1) {
		m_pBullet->Draw();
	}
}

//==========================
// �w�肵���ԍ��̒e������
//==========================
void PlayerArmBarrier::DeleteBullet(int index_num)
{
	//�e������
	delete m_pBullet;

	inhPlayerArm::IncreaseBulletNum(-1);
}
