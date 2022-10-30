//============================================================
// �v���C���[�ƃ��[�U�[�̓G�̏��X�̓����蔻��֌W(cpp�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//============================================================
#include "playerenemylasercollision.h"
#include "collision.h"
#include "ScreenOut.h"

//======================
// �X�V����
//======================
int PlayerEnemyLaserCollision::Update(void)
{
	//�v���C���[�̕�
	//�G�̕�

	//�e
	//���g
	for (int i = 0; i < m_rPlayer->GetBulletNum(); i++) {
		for (int j = 0; j < m_rEnemyNormalManagement->GetEnemyNum(); j++) {

			//��������ʊO�ɂ�����󂹂Ȃ��悤�ɂ���
			if (!ScreenOut::GetScreenOut(m_rEnemyNormalManagement->GetEnemyPos(j),
				m_rEnemyNormalManagement->GetEnemySize())) {
				
				//��������������
				if (Collision::ColBox(m_rPlayer->GetBulletPos(i), m_rEnemyNormalManagement->GetEnemyPos(j),
						m_rPlayer->GetBulletSize(), m_rEnemyNormalManagement->GetEnemySize())) {
					//�������Z�b�g
					m_rExplosionManagement->SetExplosion(m_rEnemyNormalManagement->GetEnemyPos(j));
					//�G�A�C�e���̃h���b�v
					m_rItemManagement->SetItem(m_rEnemyNormalManagement->GetEnemyPos(j), 0);

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
				//�G�̒e������
				//m_rEnemyNormalManagement->DeleteBullet(j);
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

			//�G�̒e������
			//m_rEnemyNormalManagement->DeleteBullet(j);
			//j--;
			//�_���[�W���𑝂₷
			attacked = 1 * EnemyLaserManagement::LASER_ATTACK;
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

				//�_���[�W���𑝂₷
				attacked = 1 * EnemyLaserManagement::ATTACK;
			}
		}
		else {
			m_PlayerEnemyNormalCol = false;
		}
	}

	return attacked;
}