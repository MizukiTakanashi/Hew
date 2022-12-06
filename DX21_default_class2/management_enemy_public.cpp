#include "management_enemy_public.h"

Management_EnemyPublic::Management_EnemyPublic(DrawObject& pDrawObject, EnemySetPos& pEnemySetPos)
	:EnemyManagement(MAX_NUM, ATTACK, 0), m_pDrawObjectEnemyPublic(pDrawObject), m_pEnemySetPos(pEnemySetPos)
{
	m_pEnemyPublic = new EnemyPublic[MAX_NUM];
}

void Management_EnemyPublic::Update()
{
	m_FlameNum++; //�t���[�����𑝉�

	if (m_FlameNum == m_SetEnemyTime[m_EnemyNum])
	{
		EnemyPublic temp(m_pDrawObjectEnemyPublic, m_SetEnemy[m_EnemyNum]);
		m_pEnemyPublic[GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		m_EnemyNum++;
	}
	//������G�̏���
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

bool Management_EnemyPublic::ReduceHP(int index_num, int reduceHP)
{
	m_pEnemyPublic[index_num].ReduceHP(reduceHP);
	if (m_pEnemyPublic[index_num].GetHP() <= 0)
	{//HP���O�ȉ��Ȃ�G������

		EnemyManagement::DeleteObj(index_num);

		m_pEnemySetPos.DeleteEnemy(m_pEnemyPublic[index_num].GetPos());

		for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
			m_pEnemyPublic[i] = m_pEnemyPublic[i + 1];
		}

		return true;
	}
	return false;
}