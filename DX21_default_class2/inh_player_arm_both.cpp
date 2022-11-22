//===================================================
// �v���C���[�̘r�̉E���֌W(�p���p)(cpp�t�@�C��)
// �쐬���F2022/11/08
// �쐬�ҁF��������
//===================================================
#include "inh_player_arm_both.h"
#include "player_arm_1.h"
#include "player_arm_2.h"
#include "player_arm_3.h"

//==========================
// �萔�̏�����
//==========================
const D3DXVECTOR2 inhPlayerArmBoth::SIZE = D3DXVECTOR2(50.0f, 50.0f);
const float inhPlayerArmBoth::SHOT_SPEED = 5.0f;
const D3DXVECTOR2 inhPlayerArmBoth::ICON_SIZE = D3DXVECTOR2(50.0f, 50.0f);


//==========================
// �X�V����
//==========================
int inhPlayerArmBoth::Update(const D3DXVECTOR2& player_pos, const D3DXVECTOR2& enemy_pos)
{
	int hp_reduce = 0;

	//�p�b�hL�{�^������������...
	//�L�[�{�[�hE����������...
	if (m_separation_button)
	{
		if (m_type != TYPE::TYPE_NONE && m_type != TYPE::TYPE_OLD) {
			//�������g�𔭎�
			m_shot = true;

			//�e���o���������t���O���Z�b�g
			if (m_pEnemyItem)
			{
				m_pEnemyItem->SetBulletUsed(true);
			}
			m_type = TYPE::TYPE_SHOOT;

			//HP��-1�����
			hp_reduce++;
		}
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
			SetPos(player_pos + m_from_player);

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
		// �ړ�
		SetPos(player_pos + m_from_player);

		//�r�ɂ��Ă���A�C�e���̏���
		if (m_pEnemyItem != nullptr) {
			//=======================
			// �X�V�����̑O�̏���
			//�z�[�~���O�p�̓G�̈ʒu���擾(PlayerArm1)
			m_pEnemyItem->SetSomethingPos(enemy_pos);

			//m_pEnemyItem->SetButtonTrigger(false);
			//m_pEnemyItem->SetButtonPush(false);
			//�{�^�������ꂽ�����f
			switch (m_type) {

				//Arm2�̓g���K�[�ɂȂ��Ă�
			case TYPE::TYPE2:
				m_pEnemyItem->SetButtonTrigger(m_bullet_shot_trigger);
				break;

			default: 
				m_pEnemyItem->SetButtonPush(m_bullet_shot);
				break;
			}


			//�r�ɂ��Ă�A�C�e���̏���
			m_pEnemyItem->Update(GameObject::GetPos());

			//�e���g���؂�����؂藣��
			if (m_pEnemyItem->IsBulletUsed() && m_type != TYPE::TYPE_OLD && m_type != TYPE::TYPE_SHOOT) {
				m_shot = true;
				m_type = TYPE::TYPE_SHOOT;
				//HP��-1�����
				hp_reduce++;
			}
		}
	}

	//�c�e�����X�V
	if (m_pRemaining_Bullet && m_pEnemyItem)
	{
		m_pRemaining_Bullet->SetNumber(m_pEnemyItem->GetRemainingBullet());
	}

	return hp_reduce;
}

//==========================
// �`�揈��
//==========================
void inhPlayerArmBoth::ArmDraw(void) const
{
	//�r�ɂȂɂ����Ă���Ε`��
	if (m_type != TYPE::TYPE_NONE)
	{
		if (m_type != TYPE::TYPE_OLD) {
			//�r�ɂ��Ă���A�C�e�����g�̕`��
			Draw();
			//�c�e�����̓G�A�C�R���\��
			Draw(m_Remaining_Bullet_Pos, ICON_SIZE);
		}

		if (m_pEnemyItem != nullptr) {
			//�r�ɂ��Ă���A�C�e���̒e���`��
			m_pEnemyItem->PlayerArmDraw();
		}
	}
}

//==========================
// �r�̃^�C�v��ݒ�
//==========================
void inhPlayerArmBoth::SetType(TYPE type, bool newtype)
{
	//���˒��ł���΃Z�b�g���Ȃ�
	if (m_shot/*m_type == TYPE::TYPE_SHOOT*/) {
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
	m_type = type;

	//���˒����Z�b�g���ꂽ�ꍇ�̓e�N�X�`����ς��Ȃ�
	if (m_type != TYPE::TYPE_SHOOT) {
		//�e�N�X�`�����^�C�v�ɍ��킹�ăZ�b�g
		GameObject::SetAnimationNum((float)m_type - 1.0f);
	}//���˒����Z�b�g���ꂽ�ꍇ�͔��˒��̃t���O���I��
	else {
		//�e���o���������t���O���Z�b�g
		if (m_pEnemyItem)
		{
			m_pEnemyItem->SetBulletUsed(true);
		}
		m_shot = true;
	}

	//newtype��false�Ȃ�C���X�^���X�͏����Ȃ��ŕۑ��iplayaer_arm_change�p�j
	if (newtype) {
		//�O�̃^�C�v�̃C���X�^���X���폜
		delete m_pEnemyItem;
		m_pEnemyItem = nullptr;

		//�^�C�v�ɉ����Ęr�̃A�C�e�����Z�b�g
		switch (m_type) {

		case TYPE::TYPE1:
			m_pEnemyItem = new PlayerArm1(m_bullet_draw, false, (int)m_type - 1);
			break;

		case TYPE::TYPE2:
			m_pEnemyItem = new PlayerArm2(m_laser_draw, false, (int)m_type - 1);
			break;

		case TYPE::TYPE3:
			m_pEnemyItem = new PlayerArm3(m_bullet_draw, false, (int)m_type - 1);
			break;

		default:
			break;
		}
	}
}