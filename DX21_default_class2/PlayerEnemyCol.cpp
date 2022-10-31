//===============================================
// �v���C���[�ƓG�̓����蔻��֌W(cpp�t�@�C��)
// �쐬���F2022/10/31
// �쐬�ҁF��������
//===============================================
#include "PlayerEnemyCol.h"
#include "collision.h"

int PlayerEnemyCol::Collision(void)
{
	//�v���C���[���g���󂯂��_���[�W��
	int attacked = 0;

	for (int k = 0; k < m_EnemyNum; k++) {
	//�v���C���[�̕�
	//�G�̕�

		//�e
		//���g
		for (int i = 0; i < m_pPlayer->GetBulletNum(); i++) {
			for (int j = 0; j < (m_pEnemy + k)->GetObjNum(); j++) {

				//��������ʊO�ɂ�����󂹂Ȃ��悤�ɂ���
				if (!ScreenOut::GetScreenOut((m_pEnemy + k)->GetObjPos(j),
					(m_pEnemy + k)->GetObjSize())) {

					//��������������
					if (Collision::ColBox(m_pPlayer->GetBulletPos(i), (m_pEnemy + k)->GetObjPos(j),
						m_pPlayer->GetBulletSize(), (m_pEnemy + k)->GetObjSize())) {
						//�������Z�b�g
						m_pExplosion->SetExplosion((m_pEnemy + k)->GetObjPos(j));
						//�G�A�C�e���̃h���b�v
						m_pItem->SetItem((m_pEnemy + k)->GetObjPos(j), 1);

						//�v���C���[�̒e������
						m_pPlayer->DeleteBullet(i);
						i--;
						//�G������
						(m_pEnemy + k)->DeleteObj(j);
						j--;

						//�|�����G�̐��𑝂₷
						m_pNumber->AddNumber(1);
					}
				}
			}
		}

		//�e
		//�e
		for (int i = 0; i < m_pPlayer->GetBulletNum(); i++) {
			for (int j = 0; j < (m_pEnemy + k)->GetBulletNum(); j++) {
				if (Collision::ColBox(m_pPlayer->GetBulletPos(i), (m_pEnemy + k)->GetBulletPos(j),
					m_pPlayer->GetBulletSize(), (m_pEnemy + k)->GetBulletSize())) {
					//�������Z�b�g
					m_pExplosion->SetExplosion((m_pEnemy + k)->GetBulletPos(j));

					//�v���C���[�̒e������
					m_pPlayer->DeleteBullet(i);
					i--;
					//�G�̒e������
					(m_pEnemy + k)->DeleteBullet(j);
					j--;
				}
			}
		}

		//���g
		//�e
		for (int j = 0; j < (m_pEnemy + k)->GetBulletNum(); j++) {
			if (Collision::ColBox(m_pPlayer->GetPos(), (m_pEnemy + k)->GetBulletPos(j),
				m_pPlayer->GetSize(), (m_pEnemy + k)->GetBulletSize())) {

				//�G�̒e������
				(m_pEnemy + k)->DeleteBullet(j);
				j--;
				//�_���[�W���𑝂₷
				attacked += (m_pEnemy + k)->GetBulletAttack();
			}
		}

		//���g
		//���g
		for (int j = 0; j < (m_pEnemy + k)->GetObjNum(); j++) {
			D3DXVECTOR2 Hoge = (m_pEnemy + k)->GetObjPos(0);

			if (Collision::ColBox(m_pPlayer->GetPos(), (m_pEnemy + k)->GetObjPos(0),
				m_pPlayer->GetSize(), (m_pEnemy + k)->GetObjSize())) {
				//��x����Ă��炶��Ȃ��Ƃ�����x������������ɂ͂Ȃ�Ȃ�
				if (!m_PlayerEnemyCol) {
					//�Ԃ������t���O���I��
					m_PlayerEnemyCol = true;

					//�_���[�W���𑝂₷
					attacked += (m_pEnemy + k)->GetBulletAttack();
				}
			}
			else {
				m_PlayerEnemyCol = false;
			}
		}

		return attacked;
	}
}
