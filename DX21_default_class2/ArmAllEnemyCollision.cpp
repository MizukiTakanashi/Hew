#include"ArmAllEnemyCollision.h"
#include"collision.h"

int ArmAllEnemyCollision::Update()
{
	//レーザー敵と右腕の当たり判定
	for (int i = 0; i < m_rEnemyLaserManagement->GetObjNum(); i++)
	{
		if (Collision::ColBox(m_rplayerright->GetPos(), m_rEnemyLaserManagement->GetObjPos(i),
			m_rplayerright->GetSize(), m_rEnemyLaserManagement->GetObjSize(i)))
		{
			m_rplayerright->SetType(0);
			
			m_rEnemyLaserManagement->DeleteObj(i);
			m_rExplosionManagement->SetExplosion(m_rEnemyLaserManagement->GetObjPos(i));
		}
	}
	//レーザー敵と左腕の当たり判定
	for (int j = 0; j < m_rEnemyLaserManagement->GetObjNum(); j++)
	{
		if (Collision::ColBox(m_rplayerleft->GetPos(), m_rEnemyLaserManagement->GetObjPos(j),
			m_rplayerleft->GetSize(), m_rEnemyLaserManagement->GetObjSize(j)))
		{
			m_rplayerleft->SetType(0);
			m_rEnemyLaserManagement->DeleteObj(j);
			m_rExplosionManagement->SetExplosion(m_rEnemyLaserManagement->GetObjPos(j));
		}
	}
	//マシンガン敵と右腕の当たり判定
	for (int k = 0; k < m_rEnemyGatoringManagement->GetObjNum(); k++)
	{
		if (Collision::ColBox(m_rplayerright->GetPos(), m_rEnemyGatoringManagement->GetObjPos(k),
			m_rplayerright->GetSize(), m_rEnemyGatoringManagement->GetObjSize(k)))
		{
			m_rplayerright->SetType(0);
			m_rEnemyGatoringManagement->DeleteObj(k);
			m_rExplosionManagement->SetExplosion(m_rEnemyGatoringManagement->GetObjPos(k));
		}
	}
	//マシンガン敵と左腕の当たり判定
	for (int l = 0; l < m_rEnemyGatoringManagement->GetObjNum(); l++)
	{
		if (Collision::ColBox(m_rplayerleft->GetPos(), m_rEnemyGatoringManagement->GetObjPos(l),
			m_rplayerleft->GetSize(), m_rEnemyGatoringManagement->GetObjSize(l)))
		{
			m_rplayerleft->SetType(0);
			m_rEnemyGatoringManagement->DeleteObj(l);

			m_rExplosionManagement->SetExplosion(m_rEnemyGatoringManagement->GetObjPos(l));
		}
	}
	//ホーミング敵と右腕の当たり判定
	for (int m = 0; m < m_rEnemyManagement->GetObjNum(); m++)
	{
		if (Collision::ColBox(m_rplayerright->GetPos(), m_rEnemyManagement->GetObjPos(m),
			m_rplayerright->GetSize(), m_rEnemyManagement->GetObjSize(m)))
		{
			m_rplayerright->SetType(0);
			m_rEnemyManagement->DeleteObj(m);

			m_rExplosionManagement->SetExplosion(m_rEnemyManagement->GetObjPos(m));
		}
	}
	//ホーミング敵と左腕の当たり判定
	for (int n = 0; n < m_rEnemyManagement->GetObjNum(); n++)
	{
		if (Collision::ColBox(m_rplayerleft->GetPos(), m_rEnemyManagement->GetObjPos(n),
			m_rplayerleft->GetSize(), m_rEnemyManagement->GetObjSize(n)))
		{
			m_rplayerleft->SetType(0);
			m_rEnemyManagement->DeleteObj(n);
			//爆発をセット
			m_rExplosionManagement->SetExplosion(m_rEnemyManagement->GetObjPos(n));
		}
	}
	return 0;
}