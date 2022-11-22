#include "management_meteo.h"

Management_Meteo::Management_Meteo(DrawObject& pDrawObject, EnemySetPos& pEnemySetPos)
	:EnemyManagement(MAX_NUM, ATTACK,0), m_pDrawObjectMeteo(pDrawObject), m_pEnemySetPos(pEnemySetPos)
{
	m_pMeteo = new Meteo[MAX_NUM];
}

void Management_Meteo::Update() 
{
	m_FlameNum++; //ƒtƒŒ[ƒ€”‚ğ‘‰Á

	int i = m_FlameNum;
	if (m_FlameNum == m_SetEnemyTime[m_EnemyNum])
	{
		Meteo temp(m_pDrawObjectMeteo, m_SetEnemy[m_EnemyNum]);
		m_pMeteo[GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		m_EnemyNum++;
	}
	//¡‚¢‚é“G‚Ìˆ—
	for (int i = 0; i < GetObjNum(); i++)
	{
		m_pMeteo[i].Update();
	}
}

void Management_Meteo::Draw(void) const
{
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pMeteo[i].Draw();
	}
}

void Management_Meteo::DeleteObj(int index_num, int reduceHP)
{
	EnemyManagement::DeleteObj(index_num, reduceHP);

	m_pEnemySetPos.DeleteEnemy(m_pMeteo[index_num].GetPos());

	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pMeteo[i] = m_pMeteo[i + 1];
	}
	EnemyManagement::IncreaseObjNum(-1);
}
