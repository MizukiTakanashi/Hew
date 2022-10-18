//============================================================
// �v���C���[�ƕ��ʂ̓G�̏��X�̓����蔻��֌W(cpp�t�@�C��)
// �쐬���F2022/09/22
// �쐬�ҁF��������
//============================================================
#include "PlayerEnemyNormalCollision.h"
#include "collision.h"

//======================
// �X�V����
//======================
int PlayerEnemyNormalCollision::Update(void)
{
	//�v���C���[�̕�
	//�G�̕�

	//�e
	//���g
	for (int i = 0; i < m_rPlayer->GetBulletNum(); i++) {
		for (int j = 0; j < m_rEnemyNormalManagement->GetEnemyNum(); j++) {
			if (Collision::ColBox(m_rPlayer->GetBulletPos(i), m_rEnemyNormalManagement->GetEnemyPos(j),
				m_rPlayer->GetBulletSize(), m_rEnemyNormalManagement->GetEnemySize())) {
				//�������Z�b�g
				m_rExplosionManagement->SetExplosion(m_rEnemyNormalManagement->GetEnemyPos(j));

				//�v���C���[�̒e������
				m_rPlayer->DeleteBullet(i);
				i--;
				//�G������
				m_rEnemyNormalManagement->DeleteEnemy(j);
				j--;

				m_pNumber->AddNumber(1);
			}
		}
	}

	//�e
	//�e
	for (int i = 0; i < m_rPlayer->GetBulletNum(); i++) {
		for (int j = 0; j < m_rEnemyNormalManagement->GetBulletNum(); j++) {
			if (Collision::ColBox(m_rPlayer->GetBulletPos(i), m_rEnemyNormalManagement->GetBulletPos(j),
				m_rPlayer->GetBulletSize(), m_rEnemyNormalManagement->GetBulletSize())) {
				//�������Z�b�g
				m_rExplosionManagement->SetExplosion(m_rEnemyNormalManagement->GetBulletPos(j));

				//�v���C���[�̒e������
				m_rPlayer->DeleteBullet(i);
				i--;
				//�G������
				m_rEnemyNormalManagement->DeleteBullet(j);
				j--;
			}
		}
	}

	//�v���C���[���g���󂯂��_���[�W��
	int attacked = 0;

	//���g
	//�e
	for (int j = 0; j < m_rEnemyNormalManagement->GetBulletNum(); j++) {
		if (Collision::ColBox(m_rPlayer->GetPos(), m_rEnemyNormalManagement->GetBulletPos(j),
			m_rPlayer->GetSize(), m_rEnemyNormalManagement->GetBulletSize())) {
			//�������Z�b�g
			m_rExplosionManagement->SetExplosion(m_rEnemyNormalManagement->GetBulletPos(j));
			
			//�G������
			m_rEnemyNormalManagement->DeleteBullet(j);
			j--;
			//�_���[�W���𑝂₷
			attacked = 1 * EnemyNormalManagement::BULLET_ATTACK;
		}
	}

	//���g
	//���g
	for (int j = 0; j < m_rEnemyNormalManagement->GetEnemyNum(); j++) {
		if (Collision::ColBox(m_rPlayer->GetPos(), m_rEnemyNormalManagement->GetEnemyPos(j),
			m_rPlayer->GetSize(), m_rEnemyNormalManagement->GetEnemySize())) {
			//��x����Ă��炶��Ȃ��Ƃ�����x������������ɂ͂Ȃ�Ȃ�
			if (!m_PlayerEnemyNormalCol) {
				//�Ԃ������t���O���I��
				m_PlayerEnemyNormalCol = true;

				//�������Z�b�g
				m_rExplosionManagement->SetExplosion(m_rPlayer->GetPos());

				//�_���[�W���𑝂₷
				attacked = 1 * EnemyNormalManagement::ATTACK;
			}
		}
		else {
			m_PlayerEnemyNormalCol = false;
		}
	}

	return attacked;
}