//=======================================
// �v���C���[�̘r1�֌W(cpp�t�@�C��)
// �쐬���F2022/10/30
// �쐬�ҁF��������
//=======================================
#include "player_arm_1.h"
#define _USE_MATH_DEFINES
#include <math.h>

//==========================
// �萔�̏�����
//==========================
const float PlayerArm1::BULLET_SIZE_X = 20.0f;
const float PlayerArm1::BULLET_SIZE_Y = 20.0f;
const float PlayerArm1::BULLET_SPEED = 15.0f;

//==========================
// �X�V����
//==========================
void PlayerArm1::Update(const D3DXVECTOR2& arm_pos)
{
	bool none_enemy = false;
	//�_���G�����Ȃ�������...
	if (inhPlayerArm::GetSomethingPos() == D3DXVECTOR2(0.0f, 0.0f)) {
		//�t���O���I���ɂ���
		none_enemy = true;
	}

	//������e�̏���
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		//�_���G�����Ȃ������牽�����Ȃ�(�܂������ɔ��ł���)
		if (!none_enemy) {
			//��ԋ߂��G�̌��ǂ�(�z�[�~���O�e)
			D3DXVECTOR2 movTemp = inhPlayerArm::GetSomethingPos() - m_pBullet[i].GetPos();
			D3DXVECTOR2 rotposTemp = m_pBullet[i].GetPos() - inhPlayerArm::GetSomethingPos();
			D3DXVec2Normalize(&movTemp, &movTemp);
			movTemp *= BULLET_SPEED;

			float rotTemp = atan2(rotposTemp.y, rotposTemp.x) * (180 / M_PI) + 180.0f;

			m_pBullet[i].SetRot(rotTemp);
			m_pBullet[i].SetMove(movTemp);
		}

		//�e�̍X�V����
		m_pBullet[i].Update();

		//��ʊO����o����A���Ԍo�߂�����...
		if (m_pBullet[i].GetScreenOut() || m_pBullet[i].GetTime() > BULLET_BREAK_TIME) {
			DeleteBullet(i);
		}
	}

	//�������e�̐����������Ă���e�����Ȃ�
	if (inhPlayerArm::IsBulletUsed()) {
		return;
	}	

	//���ˊԊu�J�E���g
	m_interval_count++;

	//�������{�^���������ꂽ��
	if ((inhPlayerArm::GetRightLeft() && inhPlayerArm::IsButtonPush()) ||
		(!inhPlayerArm::GetRightLeft() && inhPlayerArm::IsButtonPush())) {
		//���ˊԊu�����ȏ�ɂȂ�����
		if (m_interval_count > BULLET_INTERVAL) {
			//�J�E���g�����Z�b�g
			m_interval_count = 0;

			//�r�̐؂藣���Ɠ����ɒe�����Ȃ����߂̏���
			if (inhPlayerArm::GetBulletMaked() == BULLET_NUM_MAX - 1)
			{
				//������e�̐��𑝂₷
				inhPlayerArm::IncreaseBulletMaked();

				return;
			}

			D3DXVECTOR2 movTemp = D3DXVECTOR2(0.0f, -BULLET_SPEED);
			float rotTemp = 0.0f;

			//�_���G�����Ȃ������牽�����Ȃ�(�܂������ɔ��ł���)
			if (!none_enemy) {
				//��ԋ߂��G�̌��ǂ��悤�ɂ��āA�e�𐶐�
				D3DXVECTOR2 movTemp = inhPlayerArm::GetSomethingPos() - arm_pos;
				D3DXVECTOR2 rotposTemp = arm_pos - inhPlayerArm::GetSomethingPos();
				D3DXVec2Normalize(&movTemp, &movTemp);
				movTemp *= BULLET_SPEED;

				float rotTemp = atan2(rotposTemp.y, rotposTemp.x) * (180 / M_PI) + 180.0f;
			}
			
			//�e�����
			Bullet temp(m_bulletdraw, arm_pos,
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), movTemp, rotTemp);

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
void PlayerArm1::PlayerArmDraw()const
{
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		m_pBullet[i].Draw();
	}
}

//==========================
// �w�肵���ԍ��̒e������
//==========================
void PlayerArm1::DeleteBullet(int index_num)
{
	//�e������
	for (int i = index_num; i < inhPlayerArm::GetBulletNum() - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	inhPlayerArm::IncreaseBulletNum(-1);
 }