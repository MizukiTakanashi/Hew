//=========================================================
// 飛んでいる最中の腕と敵の当たり判定関係(ヘッダファイル)
// 作成日：2022/11/11
// 作成者：高梨水希
//=========================================================

#include"collision_arm_all_enemy.h"
#include "inh_player_arm_both.h"
#include"collision.h"

void ArmAllEnemyCollision::Update()
{
	//=========================
	// 左腕

	//下記以外のタイプであれば処理
	if (m_rplayerleft->GetType() == PlayerLeft::TYPE::TYPE_SHOOT) {
		//ホーミング敵
		for (int n = 0; n < m_rEnemyManagement->GetObjNum(); n++)
		{
			if (Collision::ColBox(m_rplayerleft->GetPos(), m_rEnemyManagement->GetObjPos(n),
				m_rplayerleft->GetSize(), m_rEnemyManagement->GetObjSize(n)))
			{
				m_rplayerleft->SetType(inhPlayerArmBoth::TYPE::TYPE_OLD);
				m_rEnemyManagement->DeleteObj(n);
				//爆発をセット
				m_rExplosionManagement->SetExplosion(m_rEnemyManagement->GetObjPos(n));
			}
		}

		//レーザー敵
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

		//マシンガン敵
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
	// 右腕

	//下記以外のタイプであれば処理
	if (m_rplayerright->GetType() == PlayerRight::TYPE::TYPE_SHOOT) {
		//ホーミング敵
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

		//レーザー敵
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

		//マシンガン敵
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