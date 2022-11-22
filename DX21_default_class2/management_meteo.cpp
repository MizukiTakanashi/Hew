#include "management_meteo.h"

Management_Meteo::Management_Meteo(DrawObject& pDrawObject, EnemySetPos& pEnemySetPos)
{
	m_pMeteo = new Meteo[MAX_NUM];
}

void Management_Meteo::Update() 
{
	//時間が来たら敵を配置
	if (m_count++ > APPEARANCE_TIME && GetObjNum() != MAX_NUM) {
		//ランダムで出現位置を決める
		float x = rand() % (SCREEN_WIDTH - (int)Meteo::SIZE_X / 2) + Meteo::SIZE_X / 2;

		//フラグに応じて敵を作る
		if (m_pEnemySetPos.SetEnemy(D3DXVECTOR2(x, -50), D3DXVECTOR2(Meteo::SIZE_X + 20.0f * 2, Meteo::SIZE_Y))) {
			Meteo temp(m_pDrawObjectMeteo, D3DXVECTOR2(x, -Meteo::SIZE_Y / 2));
			m_pMeteo[GetObjNum()] = temp;
			EnemyManagement::IncreaseObjNum(1);
		}
		m_count = 0;
	}
}

void Management_Meteo::Draw(void) const
{
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pMeteo[i].Draw();
	}
}

void Management_Meteo::DeleteObj(int index_num)
{
	EnemyManagement::DeleteObj(index_num);

	m_pEnemySetPos.DeleteEnemy(m_pMeteo[index_num].GetPos());

	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pMeteo[i] = m_pMeteo[i + 1];
	}
	EnemyManagement::IncreaseObjNum(-1);
}
