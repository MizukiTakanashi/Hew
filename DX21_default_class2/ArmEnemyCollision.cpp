#include "ArmEnemyCollision.h"
#include "collision.h"
int ArmEnemyCollision::Update(void)
{
    //ƒAƒCƒeƒ€‚Æ˜r‚Ì”»’èˆ—
    for (int i = 0; i < m_rItemManagement->GetItemNum(); i++)
    {
        if (Collision::ColBox(m_rplayerleft->GetPos(), m_rItemManagement->GetEnemyPos(i),
            m_rplayerleft->GetSize(), m_rItemManagement->GetEnemySize()))
        {
            m_rItemManagement->DeleteItem(i);
        }
    }
    for (int j = 0; j < m_rItemManagement->GetItemNum(); j++)
    {
        if (Collision::ColBox(m_rplayerright->GetPos(), m_rItemManagement->GetEnemyPos(j),
            m_rplayerright->GetSize(), m_rItemManagement->GetEnemySize()))
        {
            m_rItemManagement->DeleteItem(j);
        }
    }
    return 0;
}
