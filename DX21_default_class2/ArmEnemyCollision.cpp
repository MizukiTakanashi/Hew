#include "ArmEnemyCollision.h"
#include "collision.h"
int ArmEnemyCollision::Update(void)
{
    //�A�C�e���Ƙr�̔��菈��
    for (int i = 0; i < m_rItemManagement->GetItemNum(); i++)
    {
        if (Collision::ColBox(m_rplayerleft->GetPos(), m_rItemManagement->GetItemPos(i),
            m_rplayerleft->GetSize(), m_rItemManagement->GetItemSize()))
        {
            m_rItemManagement->DeleteItem(i);
            m_rplayerleft->Draw();
        }
    }
    for (int j = 0; j < m_rItemManagement->GetItemNum(); j++)
    {
        if (Collision::ColBox(m_rplayerright->GetPos(), m_rItemManagement->GetItemPos(j),
            m_rplayerright->GetSize(), m_rItemManagement->GetItemSize()))
        {
            m_rItemManagement->DeleteItem(j);
            m_rplayerright->Draw();
        }
    }
    return 0;
}
