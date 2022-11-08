#include "collision_arm_enemy.h"
#include "collision.h"
int ArmEnemyCollision::Update(void)
{
    int heel = 0;
    //ƒAƒCƒeƒ€‚Æ˜r‚Ì”»’èˆ—
    //¶˜r
    for (int i = 0; i < m_rItemManagement->GetItemNum(); i++)
    {
        if (Collision::ColBox(m_rPlayeLeft->GetPos(), m_rItemManagement->GetItemPos(i),
            m_rPlayeLeft->GetSize(), m_rItemManagement->GetItemSize()))
        {
            if ((int)PlayerLeft::TYPE::TYPE_NONE)
            {
                heel = 1;
            }
            m_rPlayeLeft->SetType(m_rItemManagement->GetItemType(i) + 1);
            m_rItemManagement->DeleteItem(i);
            m_rPlayeLeft->LeftDraw();
          
        }
    }
    //‰E˜r
    for (int j = 0; j < m_rItemManagement->GetItemNum(); j++)
    {
        if (Collision::ColBox(m_rPlayerRight->GetPos(), m_rItemManagement->GetItemPos(j),
            m_rPlayerRight->GetSize(), m_rItemManagement->GetItemSize()))
        {
            if ((int)PlayerRight::TYPE::TYPE_NONE)
            {
                heel = 1;
            }
            m_rPlayerRight->SetType(m_rItemManagement->GetItemType(j) + 1);
            m_rItemManagement->DeleteItem(j);
            m_rPlayerRight->RightDraw();
            
        }
    }
    return heel;
}
