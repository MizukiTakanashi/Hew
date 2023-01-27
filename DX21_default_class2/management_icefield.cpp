#include "management_icefield.h"
#include "screen_out.h"

//==========================
// 引数付きコンストラクタ
//==========================
Management_IceField::Management_IceField(DrawObject& pDrawObject)
	:m_pDrawObjectIceField(pDrawObject)
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		m_pIceField[i] = nullptr;
	}
}

//==========================
// 更新処理
//==========================
void Management_IceField::Update()
{
	m_FlameNum++; //フレーム数を増加

	if (m_FlameNum == m_SetEnemyTime[m_EnemyMakedNum])
	{
		m_pIceField[m_EnemyNum] = new IceField(m_pDrawObjectIceField, m_SetEnemy[m_EnemyMakedNum]);
		m_EnemyNum++;

		m_EnemyMakedNum++;
	}

	//今ある隕石の処理
	for (int i = 0; i < m_EnemyNum; i++)
	{
		m_pIceField[i]->Update();

		//画面外に出たら消す
		if (m_pIceField[i]->GetScreenOut()) {
			DeleteObj(i);
		}
	}
}

//==========================
// 描画処理
//==========================
void Management_IceField::Draw(void) const
{
	SetBlendState(BLEND_MODE_ADD);
	for (int i = 0; i < m_EnemyNum; i++) {
		m_pIceField[i]->Draw();
	}
	SetBlendState(BLEND_MODE_ALPHABLEND);
}
