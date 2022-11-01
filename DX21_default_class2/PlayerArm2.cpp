#include "PlayerArm2.h"

#include <math.h>

//==========================
// �萔�̏�����
//==========================
const float PlayerArm2::BULLET_SIZE_X = 40.0f;
const float PlayerArm2::BULLET_SIZE_Y = 40.0f;
const float PlayerArm2::BULLET_SPEED = 2.5f;

void PlayerArm2::Update()
{
	//���˂ł��鎞�ԂɂȂ�����...
	if (++m_bullet_interval_count > BULLET_INTERVAL) {

		//���[�U�[�̎c�莞�Ԍ���
		m_lasertime--;

		if (GameObject::GetSize().y > SCREEN_HEIGHT) //���[�U�[���\���Ȓ����ɂȂ�����
		{
			if (m_lasertime < 0) //���[�U�[�̎ˏo���Ԃ��I�������
			{
				//���[�U�[��Z������
				GameObject::SetSize(D3DXVECTOR2(GameObject::GetSize().x, GameObject::GetSize().y - BULLET_SPEED * 2));
			}
			//���[�U�[��X���W���v���C���[�ɍ��킹��
			GameObject::SetPos(D3DXVECTOR2(m_pPlayer->GetPos().x, GameObject::GetPos().y));
		}
		else
		{
			//���[�U�[�𒷂�����
			GameObject::SetSize(D3DXVECTOR2(GameObject::GetSize().x, GameObject::GetSize().y - BULLET_SPEED * 2));
			//���[�U�[��X���W���G�l�~�[�ɍ��킹��
			GameObject::SetPos(D3DXVECTOR2(m_pPlayer->GetPos().x, GameObject::GetPos().y - BULLET_SPEED));
		}

		//���݂̒e�̐��𑝂₷
		m_bullet_num++;
	}
}
