//============================================================
// �ΐ��̑S�ẴQ�[���I�u�W�F�N�g�̓����蔻��֌W(cpp�t�@�C��)
// �쐬���F2022/12/19
// �쐬�ҁF��������
//============================================================
#include "mars_collision_all.h"
#include "collision.h"
#include "inh_player_arm.h"
#include "sound.h"
#include "management_enemy_grenade.h"

//==========================
// �f�t�H���g�R���X�g���N�^
//==========================
MarsCollisionAll::MarsCollisionAll()
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		m_pEnemy[i] = nullptr;
	}

	m_SE = LoadSound((char*)"data\\SE\\bomb000.wav");	//�T�E���h�̃��[�h
}

//==========================
// �����t���R���X�g���N�^
//==========================
MarsCollisionAll::MarsCollisionAll(Player* pPlayer, inhPlayerArmBoth* pL, inhPlayerArmBoth* pR,
	ExplosionManagement* pExplosion, ItemManagement* pItem, Score* pNumber, Bom* pBom
	, EnemyGrenadeManagement* pGrenade)
	:m_pPlayer(pPlayer), m_pPlayerLeft(pL), m_pPlayerRight(pR), m_pExplosion(pExplosion),
	m_pItem(pItem), m_pScore(pNumber), m_pBom(pBom), m_pGrenade(pGrenade)
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		m_pEnemy[i] = nullptr;
	}

	//================
	// ��
	
	//�����̉�
	m_SE = LoadSound((char*)"data\\SE\\bomb000.wav");	//�T�E���h�̃��[�h

	//�o���A���e�𒵂˕Ԃ���
	m_SE_08 = LoadSound((char*)"data\\SE\\2_08.wav");
	//SetVolume(m_SE_06, 0.4f);

	//�o���A�����鉹
	m_SE_09 = LoadSound((char*)"data\\SE\\1_09.wav");
	//SetVolume(m_SE_09, 2.0f);
	
	//��C�𗁂т���
	m_SE_10 = LoadSound((char*)"data\\SE\\1_10.wav");
}

//================================================
// �����蔻��(�v���C���[��HP�����铖���蔻��)
//================================================
int MarsCollisionAll::Collision(void)
{
	//�v���C���[���g���󂯂��_���[�W��
	int attacked = 0;

	//��������炷���ۂ�
	bool explosion_sound = false;

	//=================================================
	// �G�Ɓ���

	//�G�̎�ނ̐������[�v
	for (int k = 0; k < m_enemy_num; k++) {

		//=================================================
		// �G�̐������[�v
		for (int j = 0; j < m_pEnemy[k]->GetObjNum(); j++) {
			bool next = false;

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

						//�v���C���[�̒e������
						m_pPlayer->DeleteBullet(i);
						i--;

						//�������Z�b�g
						m_pExplosion->SetExplosion(m_pEnemy[k]->GetObjPos(j));
						explosion_sound = true;

						//�G��HP�����炷
						//�G�����񂾂�...
						if (m_pEnemy[k]->ReduceHP(j, 1))
						{
							//�h���b�v����G�ł����...
							if (true) {
								if (k == (int)TYPE::NORMAL) {
									//�G�A�C�e���̃h���b�v
									m_pItem->SetItem(m_pEnemy[k]->GetObjPos(j), k);
								}
								else {
									//�G�A�C�e���̃h���b�v
									m_pItem->SetItem(m_pEnemy[k]->GetObjPos(j), k + 3);
								}
							}

							//�G������
							m_pEnemy[k]->DeleteObj(j);

							j--;
							if (j < 0) {
								next = true;
								break;
							}

							//�|�����G�̐��𑝂₷
							m_pScore->AddScore(1);
						}
					}
				}
			}

			if (next) {
				break;
			}

			//���g
			//���g
			if (Collision::ColBox(m_pPlayer->GetPos(), m_pEnemy[k]->GetObjPos(j),
				m_pPlayer->GetSize() / 3, m_pEnemy[k]->GetObjSize())) {
				//��x����Ă��炶��Ȃ��Ƃ�����x������������ɂ͂Ȃ�Ȃ�
				if (!m_player_enemy_col) {
					//�Ԃ������t���O���I��
					m_player_enemy_col = true;

					//�_���[�W���𑝂₷
					attacked += m_pEnemy[k]->GetObjAttack();

					//�R���{��r�؂ꂳ����
					m_pScore->InitCombo();
				}
			}
			else {
				m_player_enemy_col = false;
			}

			//�{��
			//���g
			if (m_pBom->IsBomb()) {
				//�������Z�b�g
				m_pExplosion->SetExplosion(m_pEnemy[k]->GetObjPos(j));
				explosion_sound = true;

				//�G��HP�����炷
				//�G�����񂾂�...
				if (m_pEnemy[k]->ReduceHP(j, m_pBom->GetBombAttack()))
				{
					//�h���b�v����G�ł����...
					if (true) {
						if (k == (int)TYPE::NORMAL) {
							//�G�A�C�e���̃h���b�v
							m_pItem->SetItem(m_pEnemy[k]->GetObjPos(j), k);
						}
						else {
							//�G�A�C�e���̃h���b�v
							m_pItem->SetItem(m_pEnemy[k]->GetObjPos(j), k + 3);
						}
					}

					//�G������
					m_pEnemy[k]->DeleteObj(j);

					j--;

					if (j < 0) {
						next = true;
						break;
					}

					//�|�����G�̐��𑝂₷
					m_pScore->AddScore(1);
				}
			}

			//=================================================
			// �v���C���[�̘r�ƓG

			//�r�̕�
			//�G�̕�

				//���g
				//���g

			//�r�̃|�C���^������Ă���(�����͍�����)
			inhPlayerArmBoth* pArm = m_pPlayerLeft;

			for (int m = 0; m < 2; m++) {
				//���˒��ł����
				if (pArm->GetType() == inhPlayerArmBoth::TYPE::TYPE_SHOOT) {
					if (Collision::ColBox(pArm->GetPos(), m_pEnemy[k]->GetObjPos(j),
						pArm->GetSize(), m_pEnemy[k]->GetObjSize(j))) {
						//TYPE_OLD�ɃZ�b�g
						pArm->SetType(inhPlayerArmBoth::TYPE::TYPE_OLD);
						//�G��HP�����炷
						//�G�����񂾂�...
						if (m_pEnemy[k]->ReduceHP(j, 1))
						{
							//�h���b�v����G�ł����...
							if (true) {
								if (k == (int)TYPE::NORMAL) {
									//�G�A�C�e���̃h���b�v
									m_pItem->SetItem(m_pEnemy[k]->GetObjPos(j), k);
								}
								else {
									//�G�A�C�e���̃h���b�v
									m_pItem->SetItem(m_pEnemy[k]->GetObjPos(j), k + 3);
								}
							}

							//�G������
							m_pEnemy[k]->DeleteObj(j);

							j--;

							if (j < 0) {
								next = true;
								break;
							}

							//�|�����G�̐��𑝂₷
							m_pScore->AddScore(1);
						}
					}
				}

				//�r�̃|�C���^������Ă���(���ڂ͉E)
				pArm = m_pPlayerRight;
			}

			if (next) {
				break;
			}

			//=================================================
			// �v���C���[�̘r�̒e�ƓG

			//�v���C���[�̘r�̒e��
			//�G�̕�

				//�e
				//���g

			//�r�ɂ��Ă���A�C�e���̃|�C���^������Ă���(�����͍�����)
			inhPlayerArm* pArmItem = m_pPlayerLeft->GetArmPointer();
			//�r�̃|�C���^������Ă���(�����͍�����)
			pArm = m_pPlayerLeft;

			//�E�ƍ��A�����s��
			for (int m = 0; m < 2; m++) {
				//�|�C���^�[���k���ł���Ώ������s��Ȃ�
				if (pArmItem != nullptr) {
					//�o���A�ł���Ή������Ȃ�
					if (pArm->GetType() == inhPlayerArmBoth::TYPE::TYPE4) {
						continue;
					}
					for (int i = 0; i < pArmItem->GetBulletNum(); i++) {
						//��������ʊO�ɂ�����󂹂Ȃ��悤�ɂ���
						if (!ScreenOut::GetScreenOut(m_pEnemy[k]->GetObjPos(j),
							m_pEnemy[k]->GetObjSize())) {

							//��������������
							if (Collision::ColBox(pArmItem->GetBulletPos(i), m_pEnemy[k]->GetObjPos(j),
								pArmItem->GetBulletSize(), m_pEnemy[k]->GetObjSize())) {

								//�r�̒e��STOP�Ȃ�
								if (pArmItem->GetType() == inhPlayerArm::TYPE::TYPE5)
								{
									//�G�̓������P�Q�OF�~�߂�
									PlaySound(m_SE_10, 0);
									m_pEnemy[k]->StopEnemy(j, 120);
									continue;
								}
								//�r�ɂ��Ă����ނ�TYPE2(���[�U�[)�łȂ����...
								if (pArmItem->GetType() != inhPlayerArm::TYPE::TYPE2) {
									//�v���C���[�̒e������
									pArmItem->DeleteBullet(i);
									i--;
								}

								//�������Z�b�g
								m_pExplosion->SetExplosion(m_pEnemy[k]->GetObjPos(j));
								explosion_sound = true;

								//�G��HP�����炷
								//�G�����񂾂�...
								if (m_pEnemy[k]->ReduceHP(j, 1))
								{
									//�h���b�v����G�ł����...
									if (true) {
										if (k == (int)TYPE::NORMAL) {
											//�G�A�C�e���̃h���b�v
											m_pItem->SetItem(m_pEnemy[k]->GetObjPos(j), k);
										}
										else {
											//�G�A�C�e���̃h���b�v
											m_pItem->SetItem(m_pEnemy[k]->GetObjPos(j), k + 3);
										}
									}

									//�G������
									m_pEnemy[k]->DeleteObj(j);

									j--;

									if (j < 0) {
										next = true;
										break;
									}

									//�|�����G�̐��𑝂₷
									m_pScore->AddScore(1);
								}
							}
						}
					}

					if (next) {
						break;
					}
				}

				//�r�ɂ��Ă���A�C�e���̃|�C���^������Ă���(���ڂ͉E)
				pArmItem = m_pPlayerRight->GetArmPointer();

				//�r�̃|�C���^������Ă���(���ڂ͉E)
				pArm = m_pPlayerRight;
			}
		}

		//=================================================
		// �G�̒e�����[�v
		for (int j = 0; j < m_pEnemy[k]->GetBulletNum(); j++) {
			bool next = false;

			//=================================================
			// �v���C���[�ƓG�̒e

			//�v���C���[�̕�
			//�G�̕�

				//�e
				//�e
			/*for (int i = 0; i < m_pPlayer->GetBulletNum(); i++) {
				if (Collision::ColBox(m_pPlayer->GetBulletPos(i), m_pEnemy[k]->GetBulletPos(j),
					m_pPlayer->GetBulletSize(), m_pEnemy[k]->GetBulletSize())) {
					//�������Z�b�g
					m_pExplosion->SetExplosion(m_pEnemy[k]->GetBulletPos(j));
					explosion_sound = true;

					//�v���C���[�̒e������
					m_pPlayer->DeleteBullet(i);
					i--;
					//�G�̒e������
					m_pEnemy[k]->DeleteBullet(j);
					j--;

					if (j < 0) {
						next = true;
						break;
					}
				}
			}*/

			//���g
			//�e
			if (Collision::ColBox(m_pPlayer->GetPos(), m_pEnemy[k]->GetBulletPos(j),
				m_pPlayer->GetSize() / 3, m_pEnemy[k]->GetBulletSize())) {

				if (k == (int)TYPE::STOP)
				{
					//�v���C���[�𓮂��Ȃ�����
					PlaySound(m_SE_10, 0);
					m_pPlayer->StopPlayer(60);
				}
				else
				{
					//�������Z�b�g
					m_pExplosion->SetExplosion(m_pEnemy[k]->GetBulletPos(j));
					explosion_sound = true;

					//�G�̒e������
					m_pEnemy[k]->DeleteBullet(j);
					j--;

				}
				//�_���[�W���𑝂₷
				attacked += m_pEnemy[k]->GetBulletAttack();
				//�R���{��r�؂ꂳ����
				m_pScore->InitCombo();

				if (j < 0) {
					next = true;
					break;
				}
			}

			//�{��
			//�e
			if (m_pBom->IsBomb()) {
				//�������Z�b�g
				m_pExplosion->SetExplosion(m_pEnemy[k]->GetBulletPos(j));
				explosion_sound = true;

				//�G�̒e������
				m_pEnemy[k]->DeleteBullet(j);
				j--;

				if (j < 0) {
					next = true;
					break;
				}
			}

			//=================================================
			// �v���C���[�̘r�̒e�ƓG

			//�v���C���[�̘r�̒e��
			//�G�̕�

				//�e
				//�e

			//�r�ɂ��Ă���A�C�e���̃|�C���^������Ă���(�����͍�����)
			inhPlayerArm* pArmItem = m_pPlayerLeft->GetArmPointer();
			//�r�̃|�C���^������Ă���(�����͍�����)
			inhPlayerArmBoth* pArm = m_pPlayerLeft;

			//�E�ƍ��A�����s��
			for (int m = 0; m < 2; m++) {
				//�|�C���^�[���k���ł���Ώ������s��Ȃ�
				//�o���A�łȂ���Ώ������s��Ȃ�
				if (pArmItem != nullptr && pArm->GetType() == inhPlayerArmBoth::TYPE::TYPE4) {
					for (int i = 0; i < pArmItem->GetBulletNum(); i++) {
						if (Collision::ColBox(pArmItem->GetBulletPos(i), m_pEnemy[k]->GetBulletPos(j),
							pArmItem->GetBulletSize(), m_pEnemy[k]->GetBulletSize())) {
							//�������Z�b�g
							m_pExplosion->SetExplosion(m_pEnemy[k]->GetBulletPos(j));
							explosion_sound = true;

							//�o���A��HP���Ȃ��Ȃ�����
							if (pArmItem->ReduceHP(m_pEnemy[k]->GetBulletAttack())) {
								//�o���A����
								pArmItem->DeleteBullet(i);
								PlaySound(m_SE_09, 0);
								i--;
							}

							//�G�̒e������
							m_pEnemy[k]->DeleteBullet(j);
							j--;

							PlaySound(m_SE_08, 0);

							if (j < 0) {
								next = true;
								break;
							}
						}
					}

					if (next) {
						break;
					}
				}

				//�r�ɂ��Ă���A�C�e���̃|�C���^������Ă���(���ڂ͉E)
				pArmItem = m_pPlayerRight->GetArmPointer();
				//�r�̃|�C���^������Ă���(���ڂ͉E)
				pArm = m_pPlayerRight;
			}
		}

		//=================================================
		// �G�̕ʃI�u�W�F�N�g�����[�v

		//�o���A
		//�O���l�[�h�G
		for (int j = 0; j < m_pEnemy[k]->GetOtherNum(); j++) {
			bool next = false;

			//=================================================
			// �v���C���[�ƓG�̕ʃI�u�W�F�N�g

			//�v���C���[
			//�G�̕ʃI�u�W�F�N�g

				//���g
				//�ʃI�u�W�F�N�g
			switch (k) {

			case (int)TYPE::BARRIER:
				if (Collision::ColBox(m_pPlayer->GetPos(), m_pEnemy[k]->GetOtherPos(j),
					m_pPlayer->GetSize() / 3, m_pEnemy[k]->GetOtherSize())) {
					if (m_pEnemy[k]->GetOtherAttack() != 0) {
						//�������Z�b�g
						m_pExplosion->SetExplosion(m_pEnemy[k]->GetOtherPos(j));
						explosion_sound = true;

						//�_���[�W���𑝂₷
						attacked += m_pEnemy[k]->GetOtherAttack();
						//�R���{��r�؂ꂳ����
						m_pScore->InitCombo();
					}
				}
				break;

			case (int)TYPE::GRENADE:
				if (Collision::ColBox(m_pPlayer->GetPos(), m_pEnemy[k]->GetOtherPos(j),
					m_pPlayer->GetSize() / 3, EnemyGrenadeManagement::OTHER_RANGE)) {
					m_pGrenade->SetExplosion(m_pEnemy[k]->GetOtherPos(j));
					m_pEnemy[k]->DeleteOther(j);
				}
				break;

			default:
				break;
			}

			//�O���l�[�h�G�ł���΂���ȍ~�̏������s��Ȃ�
			if (k == (int)TYPE::GRENADE) {
				break;
			}
				//�e
				//�ʃI�u�W�F�N�g
			for (int i = 0; i < m_pPlayer->GetBulletNum(); i++) {
				//��������ʊO�ɂ�����󂹂Ȃ��悤�ɂ���
				if (ScreenOut::GetScreenOut(m_pEnemy[k]->GetOtherPos(j),
					m_pEnemy[k]->GetOtherSize())) {
					continue;
				}

				//�������ĂȂ���Ύ��s��
				if (!Collision::ColBox(m_pPlayer->GetBulletPos(i), m_pEnemy[k]->GetOtherPos(j),
					m_pPlayer->GetBulletSize(), m_pEnemy[k]->GetOtherSize())) {
					continue;
				}

				//�v���C���[�̒e������
				m_pPlayer->DeleteBullet(i);
				i--;

				//�������Z�b�g
				m_pExplosion->SetExplosion(m_pEnemy[k]->GetOtherPos(j));
				explosion_sound = true;

				//�G�̕ʃI�u�W�F�N�g��HP�����炷
				//�G�̕ʃI�u�W�F�N�g��HP���Ȃ��Ȃ�����...
				if (m_pEnemy[k]->ReduceOtherHP(j, 1))
				{
					//�G�̕ʃI�u�W�F�N�g������
					m_pEnemy[k]->DeleteOther(j);
					PlaySound(m_SE_09, 0);

					j--;
					if (j < 0) {
						next = true;
						break;
					}
				}
				else {
					PlaySound(m_SE_08, 0);
				}
			}

			if (next) {
				break;
			}

			//=================================================
			// �v���C���[�̘r�̒e�ƓG�̕ʃI�u�W�F�N�g

			//�v���C���[�̘r�̒e��
			//�G�̕ʃI�u�W�F�N�g�̕�

			//�r�ɂ��Ă���A�C�e���̃|�C���^������Ă���(�����͍�����)
			inhPlayerArm* pArmItem = m_pPlayerLeft->GetArmPointer();
			//�r�̃|�C���^������Ă���(�����͍�����)
			inhPlayerArmBoth* pArm = m_pPlayerLeft;

			//�E�ƍ��A�����s��
			for (int m = 0; m < 2; m++) {
				//�|�C���^�[���k���ł���Ώ������s��Ȃ�
				//�o���A�ł���Ώ������s��Ȃ�
				if (pArmItem == nullptr || pArm->GetType() == inhPlayerArmBoth::TYPE::TYPE4) {
					continue;
				}

				for (int i = 0; i < pArmItem->GetBulletNum(); i++) {
					if (Collision::ColBox(pArmItem->GetBulletPos(i), m_pEnemy[k]->GetOtherPos(j),
						pArmItem->GetBulletSize(), m_pEnemy[k]->GetOtherSize())) {
						//�������Z�b�g
						m_pExplosion->SetExplosion(m_pEnemy[k]->GetOtherPos(j));
						explosion_sound = true;

						//�r�ɂ��Ă����ނ�TYPE2(���[�U�[)�łȂ����...
						if (pArmItem->GetType() != inhPlayerArm::TYPE::TYPE2) {
							//�v���C���[�̒e������
							pArmItem->DeleteBullet(i);
							i--;
						}

						//�G�̕ʃI�u�W�F�N�g��HP�����炷
						//�G�̕ʃI�u�W�F�N�g��HP���Ȃ��Ȃ�����...
						if (m_pEnemy[k]->ReduceOtherHP(j, 1))
						{
							//�G�̕ʃI�u�W�F�N�g������
							m_pEnemy[k]->DeleteOther(j);
							PlaySound(m_SE_09, 0);

							j--;
							if (j < 0) {
								next = true;
								break;
							}
						}
						else {
							PlaySound(m_SE_08, 0);
						}
					}
				}

				if (next) {
					break;
				}

				//�r�ɂ��Ă���A�C�e���̃|�C���^������Ă���(���ڂ͉E)
				pArmItem = m_pPlayerRight->GetArmPointer();
				//�r�̃|�C���^������Ă���(���ڂ͉E)
				pArm = m_pPlayerLeft;
			}
		}
	}

	//=======================================
	// �U�����󂯂���A�r�̐؂藣�����s��
	if (attacked > 0) {
		//�Е�����؂藣��
		if (m_pPlayerLeft->GetType() != inhPlayerArmBoth::TYPE::TYPE_NONE &&
			m_pPlayerLeft->GetType() != inhPlayerArmBoth::TYPE::TYPE_OLD &&
			m_pPlayerLeft->GetType() != inhPlayerArmBoth::TYPE::TYPE_SHOOT) {
			m_pPlayerLeft->SetType(inhPlayerArmBoth::TYPE::TYPE_SHOOT, false);
			attacked--;
		}
		else if (m_pPlayerRight->GetType() != inhPlayerArmBoth::TYPE::TYPE_NONE &&
			m_pPlayerRight->GetType() != inhPlayerArmBoth::TYPE::TYPE_OLD &&
			m_pPlayerRight->GetType() != inhPlayerArmBoth::TYPE::TYPE_SHOOT) {
			m_pPlayerRight->SetType(inhPlayerArmBoth::TYPE::TYPE_SHOOT, false);
			attacked--;
		}
	}

	//�����̉��̊Ԋu����莞�ԉ߂��Ă�����(�����ŃJ�E���g)...
	//���ł��������Z�b�g����Ă�����...
	if (m_SE_interval_count++ > SE_INTERVAL && explosion_sound) {

		//����炷
		PlaySound(m_SE, 0);
		SetVolume(m_SE, 0.1f);

		//�����̉��̊Ԋu�����Z�b�g
		m_SE_interval_count = 0;
	}

	//�󂯂��_���[�W��Ԃ�
	return attacked;
}

//=======================================
// �v���C���[��HP���񕜂��铖���蔻��
//=======================================
void MarsCollisionAll::HeelCollision(void)
{

	//=================================================
	// �r�Ɓ���

	//�r�̃|�C���^������Ă���(�����͍�����)
	inhPlayerArmBoth* pArm = m_pPlayerLeft;

	for (int m = 0; m < 2; m++) {
		//=================================================
		// �v���C���[�̘r�ƓG�̃A�C�e��

		//�v���C���[�̘r�̕�
		//�G�̃A�C�e���̕�

			//�r�̕�
			//�G�̕�

				//���g
				//���g

		for (int i = 0; i < m_pItem->GetItemNum(); i++) {
			if (Collision::ColBox(pArm->GetPos(), m_pItem->GetItemPos(i),
				pArm->GetSize(), m_pItem->GetItemSize()))
			{
				if (pArm->GetType() == inhPlayerArmBoth::TYPE::TYPE_NONE ||
					pArm->GetType() == inhPlayerArmBoth::TYPE::TYPE_OLD)
				{
				}
				//�^�C�v��������������c�e�����񕜂���
				if (pArm->GetType() == (inhPlayerArmBoth::TYPE)(m_pItem->GetItemType(i) + 1))
				{
					pArm->HeelBullet();
				}
				pArm->SetType((inhPlayerArmBoth::TYPE)(m_pItem->GetItemType(i) + 1));
				m_pItem->DeleteItem(i);
				i--;
			}
		}

		//�r�̃|�C���^������Ă���(���ڂ͉E)
		pArm = m_pPlayerRight;
	}

}
