//============================================================
// �S�ẴQ�[���I�u�W�F�N�g�̓����蔻��֌W(cpp�t�@�C��)
// �쐬���F2022/11/10
// �쐬�ҁF��������
//============================================================
#include "collision_all.h"
#include "collision.h"

//==========================
// �f�t�H���g�R���X�g���N�^
//==========================
CollisionAll::CollisionAll()
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		m_pEnemy[i] = nullptr;
	}
}

//==========================
// �����t���R���X�g���N�^
//==========================
CollisionAll::CollisionAll(Player* pPlayer, ExplosionManagement* pExplosion,
	ItemManagement* pItem, Score* pNumber)
	:m_pPlayer(pPlayer), m_pExplosion(pExplosion), m_pItem(pItem), m_pNumber(pNumber)
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		m_pEnemy[i] = nullptr;
	}
}

//==========================
// �����蔻��
//==========================
int CollisionAll::Collision(void)
{
	//�v���C���[���g���󂯂��_���[�W��
	int attacked = 0;

	//=================================================
	// �G�Ɓ���

	//�G�̎�ނ̐������[�v
	for (int k = 0; k < m_enemy_num; k++) {

		//=================================================
		// �G�̐������[�v
		for (int j = 0; j < m_pEnemy[k]->GetObjNum(); j++) {

			//=================================================
			// �v���C���[�ƓG

			//�v���C���[�̕�
			//�G�̕�

				//�e
				//���g
			for (int i = 0; i < m_pPlayer->GetBulletNum(); i++) {
				//��������ʊO�ɂ�����󂹂Ȃ��悤�ɂ���
				if (!ScreenOut::GetScreenOut(m_pEnemy[k]->GetObjPos(j),
					m_pEnemy[k]->GetObjSize())) {

					//��������������
					if (Collision::ColBox(m_pPlayer->GetBulletPos(i), m_pEnemy[k]->GetObjPos(j),
						m_pPlayer->GetBulletSize(), m_pEnemy[k]->GetObjSize())) {
						//�������Z�b�g
						m_pExplosion->SetExplosion(m_pEnemy[k]->GetObjPos(j));
						//�G�A�C�e���̃h���b�v
						m_pItem->SetItem(m_pEnemy[k]->GetObjPos(j), k);

						//�v���C���[�̒e������
						m_pPlayer->DeleteBullet(i);
						i--;
						//�G������
						m_pEnemy[k]->DeleteObj(j);
						j--;

						//�|�����G�̐��𑝂₷
						m_pNumber->AddScore(1);
					}
				}
			}

				//���g
				//���g
			if (Collision::ColBox(m_pPlayer->GetPos(), m_pEnemy[k]->GetObjPos(0),
				m_pPlayer->GetSize(), m_pEnemy[k]->GetObjSize())) {
				//��x����Ă��炶��Ȃ��Ƃ�����x������������ɂ͂Ȃ�Ȃ�
				if (!m_player_enemy_col) {
					//�Ԃ������t���O���I��
					m_player_enemy_col = true;

					//�_���[�W���𑝂₷
					attacked += m_pEnemy[k]->GetObjAttack();
				}
			}
			else {
				m_player_enemy_col = false;
			}

			//=================================================
			// �v���C���[�̘r�ƓG

			//�E�r
			//if (m_pPlayerRight->GetType() == inhPlayerArmBoth::TYPE::TYPE_SHOOT) {
			//	//�r�̕�
			//	//�G�̕�

			//		//���g
			//		//���g
			//	if (Collision::ColBox(m_pPlayerRight->GetPos(), m_pEnemy[k]->GetObjPos(j),
			//		m_pPlayerRight->GetSize(), m_pEnemy[k]->GetObjSize(j))){
			//		//TYPE_OLD�ɃZ�b�g
			//		m_pPlayerRight->SetType(inhPlayerArmBoth::TYPE::TYPE_OLD);
			//		//�G���폜
			//		m_pEnemy[k]->DeleteObj(j);
			//		//�������Z�b�g
			//		m_pExplosion->SetExplosion(m_pEnemy[k]->GetObjPos(j));
			//	}
			//}
		}

		//=================================================
		// �G�̒e�����[�v
		for (int j = 0; j < m_pEnemy[k]->GetBulletNum(); j++) {

			//=================================================
			// �v���C���[�ƓG�̒e

			//�v���C���[�̕�
			//�G�̕�
			
				//�e
				//�e
			for (int i = 0; i < m_pPlayer->GetBulletNum(); i++) {
				if (Collision::ColBox(m_pPlayer->GetBulletPos(i), m_pEnemy[k]->GetBulletPos(j),
					m_pPlayer->GetBulletSize(), m_pEnemy[k]->GetBulletSize())) {
					//�������Z�b�g
					m_pExplosion->SetExplosion(m_pEnemy[k]->GetBulletPos(j));

					//�v���C���[�̒e������
					m_pPlayer->DeleteBullet(i);
					i--;
					//�G�̒e������
					m_pEnemy[k]->DeleteBullet(j);
					j--;
				}
			}

				//���g
				//�e
			if (Collision::ColBox(m_pPlayer->GetPos(), m_pEnemy[k]->GetBulletPos(j),
				m_pPlayer->GetSize(), m_pEnemy[k]->GetBulletSize())) {

				//�G�̒e������
				m_pEnemy[k]->DeleteBullet(j);
				j--;
				//�_���[�W���𑝂₷
				attacked += m_pEnemy[k]->GetBulletAttack();
			}
		}
	}

	return attacked;
}
