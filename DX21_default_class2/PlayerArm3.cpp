//=======================================
// �v���C���[�̘r1�֌W(cpp�t�@�C��)
// �쐬���F2022/10/30
// �쐬�ҁF��������
//=======================================
#include "PlayerArm3.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "input.h"

//==========================
// �萔�̏�����
//==========================
const float PlayerArm3::BULLET_SIZE_X = 40.0f;
const float PlayerArm3::BULLET_SIZE_Y = 40.0f;
const float PlayerArm3::BULLET_SPEED = 2.5f;

//==========================
// �X�V����
//==========================
void PlayerArm3::Update(const D3DXVECTOR2& arm_pos)
{
	//�{�^���������ꂽ��
	if ((inhPlayerArm::GetRightLeft() && GetKeyboardPress(DIK_RIGHT)) || 
		(!inhPlayerArm::GetRightLeft() && GetKeyboardPress(DIK_LEFT))) {
		//���˂ł��鎞�ԂɂȂ�����...
		if (++m_bullet_interval_count > BULLET_INTERVAL) {
			m_bullet_interval_count = 0;

			//�e�����
			Bullet temp(m_bulletdraw, GetPos(),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0.0f, -BULLET_SPEED), 0.0f);

			m_pBullet[inhPlayerArm::GetBulletNum()] = temp;

			//���݂̒e�̐��𑝂₷
			inhPlayerArm::IncreaseBulletNum();

			//������e�̐��𑝂₷
			inhPlayerArm::IncreaseBulletMaked();
		}
	}

	//������e�̏���
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		//�e�̍X�V����
		m_pBullet[i].Update();

		//��ʊO����o����...
		if (m_pBullet[i].GetScreenOut()){
			DeleteBullet(i);
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