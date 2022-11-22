//============================================================
// �v���C���[�ƕ��ʂ̓G�̏��X�̓����蔻��֌W(cpp�t�@�C��)
// �쐬���F2022/09/22
// �쐬�ҁF��������
//============================================================
#include "collision_player_enemy_normal.h"
#include "collision.h"
#include "screen_out.h"
#include "item_p.h"

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
		for (int j = 0; j < m_rEnemyNormalManagement->GetObjNum(); j++) {

			//��������ʊO�ɂ�����󂹂Ȃ��悤�ɂ���
			if (!ScreenOut::GetScreenOut(m_rEnemyNormalManagement->GetObjPos(j),
				m_rEnemyNormalManagement->GetObjSize())) {
				
				//��������������
				if (Collision::ColBox(m_rPlayer->GetBulletPos(i), m_rEnemyNormalManagement->GetObjPos(j),
						m_rPlayer->GetBulletSize(), m_rEnemyNormalManagement->GetObjSize())) {
					//�������Z�b�g
					m_rExplosionManagement->SetExplosion(m_rEnemyNormalManagement->GetObjPos(j));
					//�G�A�C�e���̃h���b�v
					m_rItemManagement->SetItem(m_rEnemyNormalManagement->GetObjPos(j),0);

					//�v���C���[�̒e������
					m_rPlayer->DeleteBullet(i);
					i--;
					//�G������
					m_rEnemyNormalManagement->DeleteObj(j);
					j--;

					m_pScore->AddScore(1);
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

			//�G�̒e������
			m_rEnemyNormalManagement->DeleteBullet(j);
			j--;
			//�_���[�W���𑝂₷
			attacked = 1 * EnemyNormalManagement::BULLET_ATTACK;
		}
	}

	//���g
	//���g
	for (int j = 0; j < m_rEnemyNormalManagement->GetObjNum(); j++) {
		D3DXVECTOR2 Hoge = m_rEnemyNormalManagement->GetObjPos(0);

		if (Collision::ColBox(m_rPlayer->GetPos(), m_rEnemyNormalManagement->GetObjPos(0),
			m_rPlayer->GetSize(), m_rEnemyNormalManagement->GetObjSize())) {
			//��x����Ă��炶��Ȃ��Ƃ�����x������������ɂ͂Ȃ�Ȃ�
			if (!m_PlayerEnemyNormalCol) {
				//�Ԃ������t���O���I��
				m_PlayerEnemyNormalCol = true;

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