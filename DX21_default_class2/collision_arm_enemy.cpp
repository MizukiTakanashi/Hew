#include "collision_arm_enemy.h"
#include "collision.h"
int ArmEnemyCollision::Update(void)
{
    int heel = 0;
    //アイテムと腕の判定処理
    //左腕
    for (int i = 0; i < m_rItemManagement->GetItemNum(); i++)
    {
        if (Collision::ColBox(m_rPlayeLeft->GetPos(), m_rItemManagement->GetItemPos(i),
            m_rPlayeLeft->GetSize(), m_rItemManagement->GetItemSize()))
        {
            if (m_rPlayeLeft->GetType() == inhPlayerArmBoth::TYPE::TYPE_NONE)
            {
                heel++;
            }
            //タイプが同じだったら残弾数を回復する
            if (m_rPlayeLeft->GetType() == (inhPlayerArmBoth::TYPE)(m_rItemManagement->GetItemType(i) + 1))
            {
                m_rPlayeLeft->HeelBullet();
            }
            m_rPlayeLeft->SetType((inhPlayerArmBoth::TYPE)(m_rItemManagement->GetItemType(i) + 1));
            m_rItemManagement->DeleteItem(i);          
        }
    }
    //右腕
    for (int j = 0; j < m_rItemManagement->GetItemNum(); j++)
    {
        if (Collision::ColBox(m_rPlayerRight->GetPos(), m_rItemManagement->GetItemPos(j),
            m_rPlayerRight->GetSize(), m_rItemManagement->GetItemSize()))
        {
            if (m_rPlayerRight->GetType() == inhPlayerArmBoth::TYPE::TYPE_NONE);
            {
                heel++;
            }
            //タイプが同じだったら残弾数を回復する
            if (m_rPlayerRight->GetType() == (inhPlayerArmBoth::TYPE)(m_rItemManagement->GetItemType(j) + 1))
            {
                m_rPlayerRight->HeelBullet();
            }

            m_rPlayerRight->SetType((inhPlayerArmBoth::TYPE)(m_rItemManagement->GetItemType(j) + 1));
            m_rItemManagement->DeleteItem(j);            
        }
    }
    return heel;
}
