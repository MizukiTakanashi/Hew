//=================================================
// �v���C���[�̘r�̃O���l�[�h�֌W(�w�b�_�t�@�C��)
// �쐬���F2023/01/13
// �쐬�ҁF��������
//=================================================

#include "player_arm_grenade.h"
#define _USE_MATH_DEFINES
#include <math.h>

//==========================
// �萔�̏�����
//==========================
//public
const D3DXVECTOR2 PlayerArmGrenade::BULLET_SIZE = D3DXVECTOR2(21.0f, 21.0f);
const D3DXVECTOR2 PlayerArmGrenade::FIND_BULLET_SIZE = D3DXVECTOR2(20.0f, 20.0f);
const D3DXVECTOR2 PlayerArmGrenade::FIND_RANGE = D3DXVECTOR2(100.0f, 100.0f);

//private
const float PlayerArmGrenade::BULLET_SPEED = 15.0f;
const D3DXVECTOR2 PlayerArmGrenade::EXPLOSION_RANGE = D3DXVECTOR2(200.0f, 200.0f);

//==========================
// �f�t�H���g�R���X�g���N�^
//==========================
PlayerArmGrenade::PlayerArmGrenade()
{
	for (int i = 0; i < BULLET_SHOOT_MAX; i++) {
		m_pBullet[i] = nullptr;
		m_pExplosionDraw[i] = nullptr;
		m_attack_count[i] = -1;
	}
}

//==========================
// �����t���R���X�g���N�^
//==========================
PlayerArmGrenade::PlayerArmGrenade(DrawObject bulletdraw, DrawObject explosiondraw, 
	bool right, int type)
	:inhPlayerArm(BULLET_NUM_MAX, right, type), m_bulletdraw(bulletdraw), m_explosiondraw(explosiondraw) {
	for (int i = 0; i < BULLET_SHOOT_MAX; i++) {
		m_pBullet[i] = nullptr;
		m_pExplosionDraw[i] = nullptr;
		m_attack_count[i] = -1;
	}
}

//==========================
// �f�X�g���N�^
//==========================
PlayerArmGrenade::~PlayerArmGrenade()
{
	for (int i = 0; i < BULLET_SHOOT_MAX; i++) {
		if (m_pBullet[i] != nullptr) {
			delete m_pBullet[i];
		}

		if (m_pExplosionDraw[i] != nullptr) {
			delete m_pExplosionDraw[i];
		}
	}
}

//==========================
// �X�V����
//==========================
void PlayerArmGrenade::Update(const D3DXVECTOR2& arm_pos)
{
	bool none_enemy = false;
	//�_���G�����Ȃ�������...
	if (inhPlayerArm::GetSomethingPos() == D3DXVECTOR2(0.0f, 0.0f)) {
		//�t���O���I���ɂ���
		none_enemy = true;
	}

	//������e�̏���
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		//�e�̍X�V����
		m_pBullet[i]->Update();

		//��ʊO����o����A���Ԍo�߂�����...
		if (m_pBullet[i]->GetScreenOut() || m_pBullet[i]->GetTime() > BULLET_BREAK_TIME) {
			DeleteBullet(i);
		}

		//�U���J�n���Ă����...
		if (m_attack_count[i] >= 0) {
			//�������ԂɂȂ�����...
			if (m_pBullet[i]->GetTime() - m_attack_count[i] > EXPLOSION_WAIT_TIME &&
				m_pExplosionDraw[i] == nullptr) {
				m_pBullet[i]->SetSize(EXPLOSION_RANGE);
				m_pExplosionDraw[i] = new Explosion(m_explosiondraw, m_pBullet[i]->GetPos());
				m_pExplosionDraw[i]->SetSize(EXPLOSION_RANGE);
			}
		}

		//����������΍X�V�������s��
		if (m_pExplosionDraw[i] != nullptr) {
			m_pExplosionDraw[i]->Update();

			//�������I�������...
			if (m_pExplosionDraw[i]->GetEndAnimation()) {
				DeleteBullet(i);a
			}
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
				movTemp = inhPlayerArm::GetSomethingPos() - arm_pos;
				D3DXVECTOR2 rotposTemp = arm_pos - inhPlayerArm::GetSomethingPos();
				D3DXVec2Normalize(&movTemp, &movTemp);
				movTemp *= BULLET_SPEED;

				rotTemp = atan2(rotposTemp.y, rotposTemp.x) * (180 / M_PI) + 180.0f;
			}

			m_pBullet[inhPlayerArm::GetBulletNum()] = new Bullet(m_bulletdraw, arm_pos, 
				FIND_BULLET_SIZE, movTemp, rotTemp);

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
void PlayerArmGrenade::PlayerArmDraw()const
{
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		//����
		if (m_pExplosionDraw[i] != nullptr) {
			m_pExplosionDraw[i]->Draw();
		}
		else {
			//�e
			m_pBullet[i]->Draw();
		}
	}
}

//==========================
// �w�肵���ԍ��̒e������
//==========================
void PlayerArmGrenade::DeleteBullet(int index_num)
{
	if (m_pExplosionDraw[index_num] != nullptr) {
		if (!m_pExplosionDraw[index_num]->GetEndAnimation()) {
			return;
		}
	}

	delete m_pBullet[index_num];
	m_pBullet[index_num] = nullptr;

	if (m_pExplosionDraw[index_num] != nullptr) {
		delete m_pExplosionDraw[index_num];
		m_pExplosionDraw[index_num] = nullptr;
	}

	//�e������
	for (int i = index_num; i < inhPlayerArm::GetBulletNum() - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
		m_pBullet[i + 1] = nullptr;

		m_pExplosionDraw[i] = m_pExplosionDraw[i + 1];
		m_pExplosionDraw[i + 1] = nullptr;

		m_attack_count[i] = m_attack_count[i + 1];
		m_attack_count[i + 1] = -1;
	}
	inhPlayerArm::IncreaseBulletNum(-1);
}

//==========================================================
// �A�N�V�������N����(�w�肵���ԍ��̒e�̔������Z�b�g)
//==========================================================s
void PlayerArmGrenade::Action(int index_num)
{
	m_pBullet[index_num]->SetSize(BULLET_SIZE);
	m_attack_count[index_num] = m_pBullet[index_num]->GetTime();
	m_pBullet[index_num]->SetMove(D3DXVECTOR2(0.0f, 0.0f));
}