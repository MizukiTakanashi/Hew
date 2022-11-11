//=========================================================
// ���ł���Œ��̘r�ƓG�̓����蔻��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/11/11
// �쐬�ҁF��������
//=========================================================

#include"collision_arm_all_enemy.h"
#include "inh_player_arm_both.h"
#include"collision.h"

void ArmAllEnemyCollision::Update()
{
	//=========================
	// ���r

	//���L�ȊO�̃^�C�v�ł���Ώ���
	if (m_rplayerleft->GetType() == PlayerLeft::TYPE::TYPE_SHOOT) {
		//�z�[�~���O�G
		for (int n = 0; n < m_rEnemyManagement->GetObjNum(); n++)
		{
			if (Collision::ColBox(m_rplayerleft->GetPos(), m_rEnemyManagement->GetObjPos(n),
				m_rplayerleft->GetSize(), m_rEnemyManagement->GetObjSize(n)))
			{
				m_rplayerleft->SetType(inhPlayerArmBoth::TYPE::TYPE_OLD);
				m_rEnemyManagement->DeleteObj(n);
				//�������Z�b�g
				m_rExplosionManagement->SetExplosion(m_rEnemyManagement->GetObjPos(n));
			}
		}

		//���[�U�[�G
		for (int j = 0; j < m_rEnemyLaserManagement->GetObjNum(); j++)
		{
			if (Collision::ColBox(m_rplayerleft->GetPos(), m_rEnemyLaserManagement->GetObjPos(j),
				m_rplayerleft->GetSize(), m_rEnemyLaserManagement->GetObjSize(j)))
			{
				m_rplayerleft->SetType(inhPlayerArmBoth::TYPE::TYPE_OLD);
				m_rEnemyLaserManagement->DeleteObj(j);
				m_rExplosionManagement->SetExplosion(m_rEnemyLaserManagement->GetObjPos(j));
			}
		}

		//�}�V���K���G
		for (int l = 0; l < m_rEnemyGatoringManagement->GetObjNum(); l++)
		{
			if (Collision::ColBox(m_rplayerleft->GetPos(), m_rEnemyGatoringManagement->GetObjPos(l),
				m_rplayerleft->GetSize(), m_rEnemyGatoringManagement->GetObjSize(l)))
			{
				m_rplayerleft->SetType(inhPlayerArmBoth::TYPE::TYPE_OLD);
				m_rEnemyGatoringManagement->DeleteObj(l);

				m_rExplosionManagement->SetExplosion(m_rEnemyGatoringManagement->GetObjPos(l));
			}
		}
	}

	//=========================
	// �E�r

	//���L�ȊO�̃^�C�v�ł���Ώ���
	if (m_rplayerright->GetType() == PlayerRight::TYPE::TYPE_SHOOT) {
		//�z�[�~���O�G
		for (int m = 0; m < m_rEnemyManagement->GetObjNum(); m++)
		{
			if (Collision::ColBox(m_rplayerright->GetPos(), m_rEnemyManagement->GetObjPos(m),
				m_rplayerright->GetSize(), m_rEnemyManagement->GetObjSize(m)))
			{
				m_rplayerright->SetType(inhPlayerArmBoth::TYPE::TYPE_OLD);
				m_rEnemyManagement->DeleteObj(m);

				m_rExplosionManagement->SetExplosion(m_rEnemyManagement->GetObjPos(m));
			}
		}

		//���[�U�[�G
		for (int i = 0; i < m_rEnemyLaserManagement->GetObjNum(); i++)
		{
			if (Collision::ColBox(m_rplayerright->GetPos(), m_rEnemyLaserManagement->GetObjPos(i),
				m_rplayerright->GetSize(), m_rEnemyLaserManagement->GetObjSize(i)))
			{
				m_rplayerright->SetType(inhPlayerArmBoth::TYPE::TYPE_OLD);

				m_rEnemyLaserManagement->DeleteObj(i);
				m_rExplosionManagement->SetExplosion(m_rEnemyLaserManagement->GetObjPos(i));
			}
		}

		//�}�V���K���G
		for (int k = 0; k < m_rEnemyGatoringManagement->GetObjNum(); k++)
		{
			if (Collision::ColBox(m_rplayerright->GetPos(), m_rEnemyGatoringManagement->GetObjPos(k),
				m_rplayerright->GetSize(), m_rEnemyGatoringManagement->GetObjSize(k)))
			{
				m_rplayerright->SetType(inhPlayerArmBoth::TYPE::TYPE_OLD);
				m_rEnemyGatoringManagement->DeleteObj(k);
				m_rExplosionManagement->SetExplosion(m_rEnemyGatoringManagement->GetObjPos(k));
			}
		}
	}
}