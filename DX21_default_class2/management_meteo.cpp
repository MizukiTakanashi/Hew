//=======================================
// 隕石の管理関係(cppファイル)
// 作成日：2023/01/03
// 作成者：高梨水希
//=======================================
#include "management_meteo.h"
#include "screen_out.h"

//==========================
// 引数付きコンストラクタ
//==========================
Management_Meteo::Management_Meteo(DrawObject& pDrawObject)
	:EnemyManagement(ENEMY_NUM, ATTACK,0), m_pDrawObjectMeteo(pDrawObject)
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		m_pMeteo[i] = nullptr;
	}
}

//==========================
// 更新処理
//==========================
void Management_Meteo::Update()
{
	m_FlameNum++; //フレーム数を増加

	if (m_FlameNum == m_SetEnemyTime[m_EnemyNum])
	{
		m_pMeteo[EnemyManagement::GetObjNum()] = new Meteo(m_pDrawObjectMeteo, m_SetEnemy[m_EnemyNum]);
		EnemyManagement::IncreaseObjNum(1);

		m_EnemyNum++;
	}

	//今ある隕石の処理
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++)
	{
		m_pMeteo[i]->Update();
	}
}

//==========================
// 描画処理
//==========================
void Management_Meteo::Draw(void) const
{
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pMeteo[i]->Draw();
	}
}

bool Management_Meteo::ReduceHP(int index_num, int reduceHP)
{
	m_pMeteo[index_num]->ReduceHP(reduceHP);
	if (m_pMeteo[index_num]->GetHP() <= 0)
	{//HPが０以下なら敵を消す


		return true;
	}
	return false;
}
