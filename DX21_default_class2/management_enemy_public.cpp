#include "management_enemy_public.h"

Management_EnemyPublic::Management_EnemyPublic(DrawObject& pDrawObject, EnemySetPos& pEnemySetPos)
	:EnemyManagement(MAX_NUM, ATTACK, 0), m_pDrawObjectEnemyPublic(pDrawObject), m_pEnemySetPos(pEnemySetPos)
{
	m_pEnemyPublic = new EnemyPublic[MAX_NUM];
}

void Management_EnemyPublic::Update()
{
	m_FlameNum++; //ƒtƒŒ[ƒ€”‚ğ‘‰Á

	int i = m_FlameNum;
	if (m_FlameNum == m_SetEnemyTime[m_EnemyNum])
	{
		EnemyPublic temp(m_pDrawObjectEnemyPublic, m_SetEnemy[m_EnemyNum]);
		m_pEnemyPublic[GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		m_EnemyNum++;
	}
	//¡‚¢‚é“G‚Ìˆ—
	for (int i = 0; i < GetObjNum(); i++)
	{
		m_pEnemyPublic[i].Update();
	}
}

void Management_EnemyPublic::Draw(void) const
{
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemyPublic[i].Draw();
	}
}

void Management_EnemyPublic::DeleteObj(int index_num)
{
	EnemyManagement::DeleteObj(index_num);

	m_pEnemySetPos.DeleteEnemy(m_pEnemyPublic[index_num].GetPos());

	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemyPublic[i] = m_pEnemyPublic[i + 1];
	}
	EnemyManagement::IncreaseObjNum(-1);
}