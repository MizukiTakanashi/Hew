//=======================================
// 隕石の管理関係(cppファイル)
// 作成日：2023/01/03
// 作成者：高梨水希
//=======================================
#include "management_poisonfield.h"
#include "screen_out.h"

//==========================
// 引数付きコンストラクタ
//==========================
Management_PoisonField::Management_PoisonField(DrawObject& pDrawObject)
	:m_pDrawObjectPoisonField(pDrawObject)
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		m_pPoisonField[i] = nullptr;
	}
}

//==========================
// 更新処理
//==========================
void Management_PoisonField::Update()
{
	m_FlameNum++; //フレーム数を増加

	if (m_FlameNum == m_SetEnemyTime[m_EnemyMakedNum])
	{
		m_pPoisonField[m_EnemyNum] = new PoisonField(m_pDrawObjectPoisonField, m_SetEnemy[m_EnemyMakedNum]);
		m_EnemyNum++;

		m_EnemyMakedNum++;
	}

	//今ある隕石の処理
	for (int i = 0; i < m_EnemyNum; i++)
	{
		m_pPoisonField[i]->Update();
	}
}

//==========================
// 描画処理
//==========================
void Management_PoisonField::Draw(void) const
{
	for (int i = 0; i < m_EnemyNum; i++) {
		m_pPoisonField[i]->Draw();
	}
}