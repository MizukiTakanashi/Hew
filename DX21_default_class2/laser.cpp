//=======================================
// ���[�U�[�֌W(cpp�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#include "laser.h"

//==========================
// �萔������
//==========================
const float Laser::SPEED_Y = 15.0f;
const int Laser::LASER_TIME = 150;

void Laser::Update(const D3DXVECTOR2& pos, bool down)
{
	//���[�U�[�̎c�莞�Ԍ���
	m_lasertime--;

	if (m_lasertime < 0) //���[�U�[�̎ˏo���Ԃ��I�������
	{
		//�������Ȃ̂ł����...
		if(down){
			//���[�U�[�����ֈړ�
			GameObject::SetPos(D3DXVECTOR2(GameObject::GetPos().x, GameObject::GetPos().y + SPEED_Y));
		}
		//������Ȃ̂ł����...
		else {
			//���[�U�[����ֈړ�
			GameObject::SetPos(D3DXVECTOR2(GameObject::GetPos().x, GameObject::GetPos().y - SPEED_Y));
		}
	}
	else
	{
		//�������Ȃ̂ł����...
		if (down) {
			//���[�U�[�𒷂�����
			GameObject::SetSize(D3DXVECTOR2(GameObject::GetSize().x, GameObject::GetSize().y + SPEED_Y * 2));
			//���[�U�[��X���W���G�l�~�[�ɍ��킹��A���[�U�[�����ֈړ�
			GameObject::SetPos(D3DXVECTOR2(pos.x, GameObject::GetPos().y + SPEED_Y));
		}
		//������Ȃ̂ł����...
		else {
			//���[�U�[�𒷂�����
			GameObject::SetSize(D3DXVECTOR2(GameObject::GetSize().x, GameObject::GetSize().y + SPEED_Y * 2));
			//���[�U�[��X���W���G�l�~�[�ɍ��킹��A���[�U�[����ֈړ�
			GameObject::SetPos(D3DXVECTOR2(pos.x, GameObject::GetPos().y - SPEED_Y));
		}
	}

}