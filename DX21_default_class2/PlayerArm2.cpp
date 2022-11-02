//=======================================
// �v���C���[�̘r2�֌W(cpp�t�@�C��)
// �쐬���F2022/00/00
// �쐬�ҁF��������
//=======================================
#include "PlayerArm2.h"

#include <math.h>
#include "input.h"

//==========================
// �萔�̏�����
//==========================
const float PlayerArm2::BULLET_SIZE_X = 40.0f;
const float PlayerArm2::BULLET_SIZE_Y = 40.0f;
const float PlayerArm2::BULLET_SPEED = 2.5f;
const float PlayerArm2::SPEED_Y = 15.0f;

void PlayerArm2::Update(const D3DXVECTOR2& arm_pos)
{
	//�{�^���������ꂽ��
	if ((inhPlayerArm::GetRightLeft() && GetKeyboardPress(DIK_RIGHT)) || (!inhPlayerArm::GetRightLeft() && GetKeyboardPress(DIK_LEFT))) {
		//���˂ł��鎞�ԂɂȂ�����...
		if (++m_bullet_interval_count > BULLET_INTERVAL) {
			Laser temp(m_laser_draw, arm_pos,
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), &m_pEnemyLaser[i]);
			m_pLaser[inhPlayerArm::GetBulletNum()] = temp;
			
			//���݂̒e�̐��𑝂₷
			inhPlayerArm::IncreaseBulletNum();

			//������e�̂�k�}�𑝂₷
			inhPlayerArm::IncreaseBulletMaked();
		}
	}

	//���݂̒e�̏���
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		//���[�U�[�̎c�莞�Ԍ���
		m_lasertime--;

		if (m_pLaser[i].GetSize().y > SCREEN_HEIGHT) //���[�U�[���\���Ȓ����ɂȂ�����
		{
			if (m_lasertime < 0) //���[�U�[�̎ˏo���Ԃ��I�������
			{
				//���[�U�[��Z������
				m_pLaser[i].SetSize(D3DXVECTOR2(m_pLaser[i].GetSize().x, m_pLaser[i].GetSize().y - BULLET_SPEED * 2));
			}
			//���[�U�[��X���W���v���C���[�ɍ��킹��
			m_pLaser[i].SetPos(D3DXVECTOR2(m_pPlayer->GetPos().x, m_pLaser[i].GetPos().y));
		}
		else
		{
			//���[�U�[�𒷂�����
			m_pLaser[i].SetSize(D3DXVECTOR2(m_pLaser[i].GetSize().x, m_pLaser[i].GetSize().y - BULLET_SPEED * 2));
			//���[�U�[��X���W���G�l�~�[�ɍ��킹��
			m_pLaser[i].SetPos(D3DXVECTOR2(m_pPlayer->GetPos().x, m_pLaser[i].GetPos().y - BULLET_SPEED));
		}
	}
}

void PlayerArm2::PlayerArmDraw()const
{
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		m_pLaser[i].Draw();
	}
}