//=======================================
// �v���C���[�̘r1�֌W(cpp�t�@�C��)
// �쐬���F2022/10/30
// �쐬�ҁF��������
//=======================================
#include "PlayerArm1.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "input.h"

//==========================
// �萔�̏�����
//==========================
const float PlayerArm1::BULLET_SIZE_X = 40.0f;
const float PlayerArm1::BULLET_SIZE_Y = 40.0f;
const float PlayerArm1::BULLET_SPEED = 2.5f;

//==========================
// �X�V����
//==========================
void PlayerArm1::Update(const D3DXVECTOR2& arm_pos)
{
	//���ˊԊu�J�E���g
	m_interval_count++;

	//�{�^���������ꂽ��
	if ((inhPlayerArm::GetRightLeft() && GetKeyboardPress(DIK_RIGHT)) || 
		(!inhPlayerArm::GetRightLeft() && GetKeyboardPress(DIK_LEFT))) {
		//���ˊԊu�����ȏ�ɂȂ�����
		if (m_interval_count > BULLET_INTERVAL) {
			//�J�E���g�����Z�b�g
			m_interval_count = 0;

			//�v���C���[�̌��ǂ��悤�ɂ��āA�e�𐶐�
			D3DXVECTOR2 movTemp = inhPlayerArm::GetSomethingPos() - arm_pos;
			D3DXVECTOR2 rotposTemp = arm_pos - inhPlayerArm::GetSomethingPos();
			D3DXVec2Normalize(&movTemp, &movTemp);
			movTemp *= BULLET_SPEED;

			float rotTemp = atan2(rotposTemp.y, rotposTemp.x) * (180 / M_PI) + 180.0f;

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

	//������e�̏���
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		//�v���C���[�̌��ǂ�(�z�[�~���O�e)
		D3DXVECTOR2 movTemp = inhPlayerArm::GetSomethingPos() - m_pBullet[i].GetPos();
		D3DXVECTOR2 rotposTemp = m_pBullet[i].GetPos() - inhPlayerArm::GetSomethingPos();
		D3DXVec2Normalize(&movTemp, &movTemp);
		movTemp *= BULLET_SPEED;

		float rotTemp = atan2(rotposTemp.y, rotposTemp.x) * (180 / M_PI) + 180.0f;

		m_pBullet[i].SetRot(rotTemp);
		m_pBullet[i].SetMove(movTemp);

		//�e�̍X�V����
		m_pBullet[i].Update();

		//��ʊO����o����A���Ԍo�߂�����...
		if (m_pBullet[i].GetScreenOut() || m_pBullet[i].GetTime() > BULLET_BREAK_TIME) {
			DeleteBullet(i);
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