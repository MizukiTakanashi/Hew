//============================================================
// PlayerEnemyGatoringCollision.cpp
// �쐬���F2022/11/01
// �쐬�ҁF���� �@
//============================================================
#include "PlayerEnemyGatoringCollision.h"
#include "collision.h"
#include "ScreenOut.h"

//======================
// �X�V����
//======================
int PlayerEnemyGatoringCollision::Update(void)
{
	//�v���C���[�̕�
	//�G�̕�

	//�e
	//���g
	for (int i = 0; i < m_rPlayer->GetBulletNum(); i++) {
		for (int j = 0; j < m_rEnemyGatoringManagement->GetObjNum(); j++) {

			//��������ʊO�ɂ�����󂹂Ȃ��悤�ɂ���
			if (!ScreenOut::GetScreenOut(m_rEnemyGatoringManagement->GetObjPos(j),
				m_rEnemyGatoringManagement->GetObjSize())) {
				
				//��������������
				if (Collision::ColBox(m_rPlayer->GetBulletPos(i), m_rEnemyGatoringManagement->GetObjPos(j),
						m_rPlayer->GetBulletSize(), m_rEnemyGatoringManagement->GetObjSize())) {
					//�������Z�b�g
					m_rExplosionManagement->SetExplosion(m_rEnemyGatoringManagement->GetObjPos(j));
					//�G�A�C�e���̃h���b�v
					m_rItemManagement->SetItem(m_rEnemyGatoringManagement->GetObjPos(j), 0);

					//�v���C���[�̒e������
					m_rPlayer->DeleteBullet(i);
					i--;
					//�G������
					m_rEnemyGatoringManagement->DeleteObj(j);
					j--;

					m_pNumber->AddNumber(1);
				}
			}
		}
	}

	//�e
	//�e
	for (int i = 0; i < m_rPlayer->GetBulletNum(); i++) {
		for (int j = 0; j < m_rEnemyGatoringManagement->GetBulletNum(); j++) {
			if (Collision::ColBox(m_rPlayer->GetBulletPos(i), m_rEnemyGatoringManagement->GetBulletPos(j),
				m_rPlayer->GetBulletSize(), m_rEnemyGatoringManagement->GetBulletSize())) {
				//�������Z�b�g
				m_rExplosionManagement->SetExplosion(m_rEnemyGatoringManagement->GetBulletPos(j));

				//�v���C���[�̒e������
				m_rPlayer->DeleteBullet(i);
				i--;
				//�G�̒e������
				m_rEnemyGatoringManagement->DeleteBullet(j);
				j--;
			}
		}
	}

	//�v���C���[���g���󂯂��_���[�W��
	int attacked = 0;

	//���g
	//�e
	for (int j = 0; j < m_rEnemyGatoringManagement->GetBulletNum(); j++) {
		if (Collision::ColBox(m_rPlayer->GetPos(), m_rEnemyGatoringManagement->GetBulletPos(j),
			m_rPlayer->GetSize(), m_rEnemyGatoringManagement->GetBulletSize())) {
			//�������Z�b�g
			m_rExplosionManagement->SetExplosion(m_rEnemyGatoringManagement->GetBulletPos(j));

			//�G�̒e������
			m_rEnemyGatoringManagement->DeleteBullet(j);
			j--;
			//�_���[�W���𑝂₷
			attacked = 1 * EnemyGatoringManagement::BULLET_ATTACK;
		}
	}

	//���g
	//���g
	for (int j = 0; j < m_rEnemyGatoringManagement->GetObjNum(); j++) {
		if (Collision::ColBox(m_rPlayer->GetPos(), m_rEnemyGatoringManagement->GetObjPos(j),
			m_rPlayer->GetSize(), m_rEnemyGatoringManagement->GetObjSize())) {
			//��x����Ă��炶��Ȃ��Ƃ�����x������������ɂ͂Ȃ�Ȃ�
			if (!m_PlayerEnemyGatoringCol) {
				//�Ԃ������t���O���I��
				m_PlayerEnemyGatoringCol = true;

				//�_���[�W���𑝂₷
				attacked = 1 * EnemyGatoringManagement::ATTACK;
			}
		}
		else {
			m_PlayerEnemyGatoringCol = false;
		}
	}

	return attacked;
}