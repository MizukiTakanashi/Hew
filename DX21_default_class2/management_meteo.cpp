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
	:m_pDrawObjectMeteo(pDrawObject)
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

	if (m_FlameNum == m_SetEnemyTime[m_EnemyMakedNum])
	{
		m_pMeteo[m_EnemyNum] = new Meteo(m_pDrawObjectMeteo, m_SetEnemy[m_EnemyMakedNum]);
		m_EnemyNum++;

		m_EnemyMakedNum++;
	}

	//今ある隕石の処理
	for (int i = 0; i < m_EnemyNum; i++)
	{
		m_pMeteo[i]->Update();
	}
}

//==========================
// 描画処理
//==========================
void Management_Meteo::Draw(void) const
{
	for (int i = 0; i < m_EnemyNum; i++) {
		m_pMeteo[i]->Draw();
	}
}