#include "management_meteo.h"

Management_Meteo::Management_Meteo(DrawObject& pDrawObject)
	:EnemyManagement(MAX_NUM, ATTACK,0), m_pDrawObjectMeteo(pDrawObject)
{
	m_pMeteo = new Meteo[MAX_NUM];
}

void Management_Meteo::Update() 
{
	m_FlameNum++; //ƒtƒŒ[ƒ€”‚ğ‘‰Á

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

bool Management_Meteo::ReduceHP(int index_num, int reduceHP)
{
	m_pMeteo[index_num].ReduceHP(reduceHP);
	if (m_pMeteo[index_num].GetHP() <= 0)
	{//HP‚ª‚OˆÈ‰º‚È‚ç“G‚ğÁ‚·

		EnemyManagement::DeleteObj(index_num);

		//m_pEnemySetPos.DeleteEnemy(m_pMeteo[index_num].GetPos());

		for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
			m_pMeteo[i] = m_pMeteo[i + 1];
		}

		return true;
	}
	return false;
}
