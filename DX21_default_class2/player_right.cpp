//=======================================
// ���@�̉E(�w�b�_)
// �쐬���F2022/10/25
// �쐬�ҁF�R�{����
//=======================================
#include "player_right.h"

//#include "input.h"
#include "inputx.h"
#include "keyboard.h"

#include "player_arm_1.h"
#include "player_arm_2.h"
#include "player_arm_3.h"

//==========================
// �萔�̏�����
//==========================
const D3DXVECTOR2 PlayerRight::SIZE = D3DXVECTOR2(50.0f, 50.0f);
const float PlayerRight::SHOT_SPEED = 5.0f;
const D3DXVECTOR2 PlayerRight::FROM_PLAYER_POS = D3DXVECTOR2(30.0f, 0.0f);

//==========================
// �X�V����
//==========================
void PlayerRight::Update(const D3DXVECTOR2& player_pos, const D3DXVECTOR2& enemy_pos)
{
	//�p�b�hR�{�^������������...
	//�L�[�{�[�hR����������...
	if (InputGetKeyDown(KK_R) || IsButtonTriggered(0, XINPUT_GAMEPAD_RIGHT_SHOULDER))
	{
		if (m_type != TYPE::TYPE_NONE && m_type != TYPE::TYPE_OLD) {
			//�������g�𔭎�
			m_shot = true;

			m_type = TYPE::TYPE_SHOOT;
		}
	}

	//�������g�𔭎�
	if (m_shot)
	{
		MovePos(D3DXVECTOR2(0.0f, -SHOT_SPEED));

		//��ʊO�ɏo����...
		if (GetScreenOut())
		{
			m_type = TYPE::TYPE_OLD;

			//�ʒu�����ɖ߂�
			SetPos(player_pos + FROM_PLAYER_POS);

			//���˂̃t���O���I�t
			m_shot = false;
		}

		//�������O�̃^�C�v�̒e���c���Ă�����
		if (m_type == TYPE::TYPE_SHOOT) {
			//�r�ɂ��Ă���A�C�e���̏���
			if (m_pEnemyItem != nullptr) {
				//�z�[�~���O�p�̓G�̈ʒu���擾(PlayerArm1)
				m_pEnemyItem->SetSomethingPos(enemy_pos);

				//�r�ɂ��Ă�A�C�e���̏���
				m_pEnemyItem->Update(GameObject::GetPos());
			}
		}
	}
	//���ˈȊO�̎��̓v���C���[�̉��ɂ��Ēe�𔭎˂���
	else
	{
		//�ړ�
		SetPos(player_pos + FROM_PLAYER_POS);

		//�r�ɂ��Ă���A�C�e���̏���
		if (m_pEnemyItem != nullptr) {
			//=======================
			// �X�V�����̑O�̏���
			//�z�[�~���O�p�̓G�̈ʒu���擾(PlayerArm1)
			m_pEnemyItem->SetSomethingPos(enemy_pos);

			//�{�^�������ꂽ�����f
			switch (m_type) {

				//Arm2�̓g���K�[�ɂȂ��Ă�
			case TYPE::TYPE2:
				m_pEnemyItem->SetButtonPush(InputGetKeyDown(KK_RIGHT) ||
					GetRightTriggerTriggered(0, TRIGGER));
				break;

			default:
				m_pEnemyItem->SetButtonPush(InputGetKey(KK_RIGHT) ||
					GetRightTrigger(0) > TRIGGER);
				break;
			}


			//�r�ɂ��Ă�A�C�e���̏���
			m_pEnemyItem->Update(GameObject::GetPos());

			//�e���g���؂�����؂藣��
			if (m_pEnemyItem->IsBulletUsed() && m_type != TYPE::TYPE_OLD && m_type != TYPE::TYPE_SHOOT) {
				m_shot = true;
				m_type = TYPE::TYPE_SHOOT;
			}
		}
	}
}

//==========================
// �`�揈��
//==========================
void PlayerRight::RightDraw(void)const
{
	//�r�ɂȂɂ����Ă���Ε`��
	if (m_type != TYPE::TYPE_NONE)
	{
		if (m_type != TYPE::TYPE_OLD) {
			//�r�ɂ��Ă���A�C�e�����g�̕`��
			Draw();
		}

		if (m_pEnemyItem != nullptr) {
			//�r�ɂ��Ă���A�C�e���̒e���`��
			m_pEnemyItem->PlayerArmDraw();
		}
	}
}

//==========================
// �^�C�v���Z�b�g
//==========================
void PlayerRight::SetType(int type, bool newtype)
{
	//���˒��ł���΃Z�b�g���Ȃ�
	if (m_shot) {
		return;
	}

	//���Ƀ^�C�v�����Ă���΃Z�b�g���Ȃ�
	if (m_type != TYPE::TYPE_NONE && m_type != TYPE::TYPE_OLD) {
		//newtype��false�Ȃ狭���I�Ƀ^�C�v���Z�b�g�iplayaer_arm_change�p�j
		if (newtype) {
			return;
		}
	}

	//�^�C�v���Z�b�g
	m_type = (TYPE)type;

	//�e�N�X�`�����^�C�v�ɍ��킹�ăZ�b�g
	GameObject::SetAnimationNum((float)m_type - 1.0f);

	if (newtype) {
		//�O�̃^�C�v�̃C���X�^���X���폜
		delete m_pEnemyItem;
		m_pEnemyItem = nullptr;

		//�^�C�v�ɉ����Ęr�̃A�C�e�����Z�b�g
		switch (m_type) {

		case TYPE::TYPE1:
			m_pEnemyItem = new PlayerArm1(m_bullet_draw, true, (int)m_type - 1);
			break;

		case TYPE::TYPE2:
			m_pEnemyItem = new PlayerArm2(m_laser_draw, true, (int)m_type - 1);
			break;

		case TYPE::TYPE3:
			m_pEnemyItem = new PlayerArm3(m_bullet_draw, true, (int)m_type - 1);
			break;

		default:
			break;
		}
	}
}