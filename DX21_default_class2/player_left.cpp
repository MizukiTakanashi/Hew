//=======================================
// ���@�̍�(�w�b�_)
// �쐬���F2022/10/25
// �쐬�ҁF���� �@
//=======================================
#include "player_left.h"
#include "input.h"

#include "player_arm_1.h"
#include "player_arm_2.h"
#include "player_arm_3.h"

//==========================
// �萔�̏�����
//==========================
const D3DXVECTOR2 PlayerLeft::SIZE = D3DXVECTOR2(50.0f, 50.0f);
const float PlayerLeft::SHOT_SPEED = 5.0f;
const D3DXVECTOR2 PlayerLeft::FROM_PLAYER_POS = D3DXVECTOR2(-30.0f, 0.0f);

//==========================
// �X�V����
//==========================
void PlayerLeft::Update(const D3DXVECTOR2& player_pos, const D3DXVECTOR2& enemy_pos)
{
	//  R�L�[�������Ƙr�ɑ������Ă���G�𔭎˂���
	if (GetKeyboardTrigger(DIK_E))	
	{
		m_shot = true;	// ���˂���

		m_type = TYPE::TYPE_SHOOT;
	}

	// �������g�𔭎˂���
	if (m_shot)
	{
		MovePos(D3DXVECTOR2(0.0f, -SHOT_SPEED));	// �����ۂɕK�v
		
		// ��ʊO�ɏo����...
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
				//�X�V�����̑O�̊e�X�̏���
				//�z�[�~���O�p�̓G�̈ʒu���擾
				m_pEnemyItem->SetSomethingPos(enemy_pos);

				//�r�ɂ��Ă�A�C�e���̏���
				m_pEnemyItem->Update(GameObject::GetPos());
			}
		}
	}
	//���ˈȊO�̎��̓v���C���[�̉��ɂ��Ēe�𔭎˂���
	else
	{
		// �ړ�
		SetPos(player_pos + FROM_PLAYER_POS);

		//�r�ɂ��Ă���A�C�e���̏���
		if (m_pEnemyItem != nullptr) {
			//�X�V�����̑O�̊e�X�̏���
			switch (m_type) {

			case TYPE::TYPE1:
				//�z�[�~���O�p�̓G�̈ʒu���擾
				m_pEnemyItem->SetSomethingPos(enemy_pos);
				break;

			default:
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
void PlayerLeft::LeftDraw(void)const
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
void PlayerLeft::SetType(int type)
{
	//���˒��ł���΃Z�b�g���Ȃ�
	if (m_shot) {
		return;
	}

	//���Ƀ^�C�v�����Ă���΃Z�b�g���Ȃ�
	if (m_type != TYPE::TYPE_NONE && m_type != TYPE::TYPE_OLD) {
		return;
	}

	//�O�̃^�C�v�̃C���X�^���X���폜
	delete m_pEnemyItem;
	m_pEnemyItem = nullptr;

	//�^�C�v���Z�b�g
	m_type = (TYPE)type;

	//�e�N�X�`�����^�C�v�ɍ��킹�ăZ�b�g
	GameObject::SetAnimationNum((float)m_type - 1.0f);

	//�^�C�v�ɉ����Ęr�̃A�C�e�����Z�b�g
	switch (m_type) {

	case TYPE::TYPE1:
		m_pEnemyItem = new PlayerArm1(m_bullet_draw, false);
		break;

	case TYPE::TYPE2:
		m_pEnemyItem = new PlayerArm2(m_laser_draw, false);
		break;

	case TYPE::TYPE3:
		m_pEnemyItem = new PlayerArm3(m_bullet_draw, false);
		break;

	default:
		break;
	}
}