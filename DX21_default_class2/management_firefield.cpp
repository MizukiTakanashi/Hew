#include "management_firefield.h"
#include "screen_out.h"

//==========================
// 引数付きコンストラクタ
//==========================
Management_FireField::Management_FireField(DrawObject& pDrawObject)
	:m_pDrawObjectFireField(pDrawObject)
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		m_pFireField[i] = nullptr;
	}
}

//==========================
// 更新処理
//==========================
void Management_FireField::Update()
{
	m_FlameNum++; //フレーム数を増加

	if (m_FlameNum == m_SetEnemyTime[m_EnemyMakedNum])
	{
		m_pFireField[m_EnemyNum] = new FireField(m_pDrawObjectFireField, m_SetEnemy[m_EnemyMakedNum]);
		m_EnemyNum++;

		m_EnemyMakedNum++;
	}

	//今ある隕石の処理
	for (int i = 0; i < m_EnemyNum; i++)
	{
		m_pFireField[i]->Update();

		//画面外に出たら消す
		if (m_pFireField[i]->GetScreenOut()) {
			DeleteObj(i);
		}
	}
}

//==========================
// 描画処理
//==========================
void Management_FireField::Draw(void) const
{
	SetBlendState(BLEND_MODE_ADD);
	for (int i = 0; i < m_EnemyNum; i++) {
		m_pFireField[i]->Draw();
	}
	SetBlendState(BLEND_MODE_ALPHABLEND);
}
