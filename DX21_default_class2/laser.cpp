//=======================================
// ���[�U�[�֌W(cpp�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#include "laser.h"

//==========================
// �萔������
//==========================
const float Laser::SPEED_X = 15.0f;
const float Laser::SPEED_Y = 15.0f;

//==========================
// �X�V����
//==========================
void Laser::Update(const D3DXVECTOR2& pos, bool down)
{
	//���[�U�[�̎c�莞�Ԍ���
	m_lasertime--;

	if (m_lasertime < 0) //���[�U�[�̎ˏo���Ԃ��I�������
	{
		switch (m_direction) {

		case DIRECTION::NONE:
			//�������Ȃ̂ł����...
			if (down) {
				//���[�U�[�����ֈړ�
				GameObject::SetPos(D3DXVECTOR2(GameObject::GetPos().x, GameObject::GetPos().y + SPEED_Y));
			}
			//������Ȃ̂ł����...
			else {
				//���[�U�[����ֈړ�
				GameObject::SetPos(D3DXVECTOR2(GameObject::GetPos().x, GameObject::GetPos().y - SPEED_Y));
			}

			break;

		case DIRECTION::LEFT:
			//���[�U�[�����ֈړ�
			GameObject::MovePos(D3DXVECTOR2(-SPEED_X, 0.0f));

			break;

		case DIRECTION::RIGHT:
			//���[�U�[�����ֈړ�
			GameObject::MovePos(D3DXVECTOR2(SPEED_X, 0.0f));

			break;
		}
	}
	else
	{
		switch (m_direction) {

		case DIRECTION::NONE:
			//�������Ȃ̂ł����...
			if (down) {
				//���[�U�[�𒷂�����
				GameObject::SetSize(D3DXVECTOR2(GameObject::GetSize().x, GameObject::GetSize().y + SPEED_Y * 2));
				//���[�U�[��X���W���G�l�~�[�ɍ��킹��A���[�U�[�����ֈړ�
				GameObject::SetPos(D3DXVECTOR2(pos.x, pos.y + GameObject::GetSize().y / 2));
			}
			//������Ȃ̂ł����...
			else {
				//���[�U�[�𒷂�����
				GameObject::SetSize(D3DXVECTOR2(GameObject::GetSize().x, GameObject::GetSize().y + SPEED_Y * 2));
				//���[�U�[��X���W���G�l�~�[�ɍ��킹��A���[�U�[����ֈړ�
				GameObject::SetPos(D3DXVECTOR2(pos.x, pos.y - GameObject::GetSize().y / 2));
			}

			break;

		case DIRECTION::LEFT:
			//���[�U�[�𒷂�����
			GameObject::SetSize(D3DXVECTOR2(GameObject::GetSize().x + SPEED_X * 2, GameObject::GetSize().y));
			//���[�U�[��Y���W���G�l�~�[�ɍ��킹��A���[�U�[�����ֈړ�
			GameObject::SetPos(D3DXVECTOR2(pos.x - GameObject::GetSize().x / 2, pos.y));

			break;

		case DIRECTION::RIGHT:
			//���[�U�[�𒷂�����
			GameObject::SetSize(D3DXVECTOR2(GameObject::GetSize().x + SPEED_X * 2, GameObject::GetSize().y));
			//���[�U�[��Y���W���G�l�~�[�ɍ��킹��A���[�U�[���E�ֈړ�
			GameObject::SetPos(D3DXVECTOR2(pos.x + GameObject::GetSize().x / 2, pos.y));

			break;
		}
	}

}