//===============================================
// �r����o��e�ƓG�̓����蔻��(cpp�t�@�C��)
// �쐬���F2022/11/01
// �쐬�ҁF�R�{����
//===============================================
#include "collision_player_arm_enemy.h"
#include "collision.h"

PlayerArmEnemyCol::PlayerArmEnemyCol(EnemyManagement* p1, EnemyManagement* p2, EnemyManagement* p3,
	ExplosionManagement* pExplosion, ItemManagement* pItem, Score* pNumber) 
	:m_pExplosion(pExplosion), m_pItem(pItem), m_pScore(pNumber)
{
	m_pEnemy[0] = p1;
	m_pEnemy[1] = p2;
	m_pEnemy[2] = p3;
}

void PlayerArmEnemyCol::Collision(void)
{
	//�������r�̃|�C���^�ɉ����Ȃ���ΏI��
	if (m_pArm == nullptr){
		return;
	}

	for (int k = 0; k < ENEMY_NUM; k++) {
		//�r�̒e�̕�
		//�G�̕�

		//�e
		//���g
		for (int i = 0; i < m_pArm->GetBulletNum(); i++) {
			for (int j = 0; j < m_pEnemy[k]->GetObjNum(); j++) {

				//��������ʊO�ɂ�����󂹂Ȃ��悤�ɂ���
				if (!ScreenOut::GetScreenOut(m_pEnemy[k]->GetObjPos(j),
					m_pEnemy[k]->GetObjSize())) {

					//��������������
					if (Collision::ColBox(m_pArm->GetBulletPos(i), m_pEnemy[k]->GetObjPos(j),
						m_pArm->GetBulletSize(), m_pEnemy[k]->GetObjSize())) {
						//�������Z�b�g
						m_pExplosion->SetExplosion(m_pEnemy[k]->GetObjPos(j));
						//�G�A�C�e���̃h���b�v
						m_pItem->SetItem(m_pEnemy[k]->GetObjPos(j), 1);

						//�r�ɂ��Ă����ނ�TYPE2(���[�U�[)�łȂ����...
						if (m_pArm->GetType() != inhPlayerArm::TYPE::TYPE2) {
							//�v���C���[�̒e������
							m_pArm->DeleteBullet(i);
							i--;
						}
						
						//�G������
						m_pEnemy[k]->DeleteObj(j);
						j--;

						//�|�����G�̐��𑝂₷
						m_pScore->AddScore(1);
					}
				}
			}
		}

		//�e
		//�e
		for (int i = 0; i < m_pArm->GetBulletNum(); i++) {
			for (int j = 0; j < m_pEnemy[k]->GetBulletNum(); j++) {
				if (Collision::ColBox(m_pArm->GetBulletPos(i), m_pEnemy[k]->GetBulletPos(j),
					m_pArm->GetBulletSize(), m_pEnemy[k]->GetBulletSize())) {
					//�������Z�b�g
					m_pExplosion->SetExplosion(m_pEnemy[k]->GetBulletPos(j));

					//�r�ɂ��Ă����ނ�TYPE2(���[�U�[)�łȂ����...
					if (m_pArm->GetType() != inhPlayerArm::TYPE::TYPE2) {
						//�v���C���[�̒e������
						m_pArm->DeleteBullet(i);
						i--;
					}

					//�G�̒e������
					m_pEnemy[k]->DeleteBullet(j);
					j--;
				}
			}
		}
	}
}
