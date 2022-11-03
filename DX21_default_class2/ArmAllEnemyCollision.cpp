#include"ArmAllEnemyCollision.h"
#include"collision.h"

int ArmAllEnemyCollision::Update()
{
	//レーザー敵と右腕の当たり判定
	for (int i = 0; i < m_rEnemyLaserManagement->GetObjNum(); i++)
	{
		if (Collision::ColBox(m_rplayerright->GetPos(), m_rEnemyLaserManagement->GetObjPos(i),
			m_rplayerright->GetSize(), m_rEnemyLaserManagement->GetObjPos(i)))
		{
			m_rplayerright->SetType(0);
			m_rEnemyLaserManagement->DeleteObj(i);
		}
	}
	//レーザー敵と左腕の当たり判定
	for (int i = 0; i < m_rEnemyLaserManagement->GetObjNum(); i++)
	{
		if (Collision::ColBox(m_rplayerleft->GetPos(), m_rEnemyLaserManagement->GetObjPos(i),
			m_rplayerleft->GetSize(), m_rEnemyLaserManagement->GetObjPos(i)))
		{
			m_rplayerleft->SetType(0);
			m_rEnemyLaserManagement->DeleteObj(i);
		}
	}
	//マシンガン敵と右腕の当たり判定
	for (int i = 0; i < m_rEnemyGatoringManagement->GetObjNum(); i++)
	{
		if (Collision::ColBox(m_rplayerright->GetPos(), m_rEnemyGatoringManagement->GetObjPos(i),
			m_rplayerright->GetSize(), m_rEnemyGatoringManagement->GetObjPos(i)))
		{
			m_rplayerright->SetType(0);
			m_rEnemyGatoringManagement->DeleteObj(i);
		}
	}
	//マシンガン敵と左腕の当たり判定
	for (int i = 0; i < m_rEnemyGatoringManagement->GetObjNum(); i++)
	{
		if (Collision::ColBox(m_rplayerleft->GetPos(), m_rEnemyGatoringManagement->GetObjPos(i),
			m_rplayerleft->GetSize(), m_rEnemyGatoringManagement->GetObjPos(i)))
		{
			m_rplayerleft->SetType(0);
			m_rEnemyGatoringManagement->DeleteObj(i);
		}
	}
	//ホーミング敵と右腕の当たり判定
	for (int i = 0; i < m_rEnemyManagement->GetObjNum(); i++)
	{
		if (Collision::ColBox(m_rplayerright->GetPos(), m_rEnemyManagement->GetObjPos(i),
			m_rplayerright->GetSize(), m_rEnemyManagement->GetObjPos(i)))
		{
			m_rplayerright->SetType(0);
			m_rEnemyManagement->DeleteObj(i);
		}
	}
	//ホーミング敵と左腕の当たり判定
	for (int i = 0; i < m_rEnemyManagement->GetObjNum(); i++)
	{
		if (Collision::ColBox(m_rplayerleft->GetPos(), m_rEnemyManagement->GetObjPos(i),
			m_rplayerleft->GetSize(), m_rEnemyManagement->GetObjPos(i)))
		{
			m_rplayerleft->SetType(0);
			m_rEnemyManagement->DeleteObj(i);
		}
	}
	return 0;
}