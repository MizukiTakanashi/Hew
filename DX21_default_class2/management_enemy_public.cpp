#include "management_enemy_public.h"
#include "screen_out.h"

Management_EnemyPublic::Management_EnemyPublic(DrawObject& pDrawObject)
	:EnemyManagement(EnemyManagement::TYPE::PUBLIC, ENEMY_NUM, ATTACK, 0), 
	m_pDrawObjectEnemyPublic(pDrawObject)
{
	m_pEnemyPublic = new EnemyPublic[ENEMY_NUM];
}

void Management_EnemyPublic::Update()
{
	m_FlameNum++; //フレーム数を増加

	if (m_FlameNum == m_SetEnemyTime[m_EnemyNum] &&
		m_EnemyNum < ENEMY_NUM)
	{
		EnemyPublic temp(m_pDrawObjectEnemyPublic, m_SetEnemy[m_EnemyNum]);
		m_pEnemyPublic[EnemyManagement::GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		m_EnemyNum++;
	}

	if (m_EnemyNum == ENEMY_NUM)
	{
		m_tutorial_clear = true;
	}
	//今いる敵の処理
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++)
	{
		m_tutorial_clear = false;
		m_pEnemyPublic[i].Update();

		//画面外に出たら消す
		if (ScreenOut::GetScreenOut(m_pEnemyPublic[i].GetPos(), m_pEnemyPublic[i].GetSize())) {
			DeleteObj(i);

			//同じやつの処理をしないためここのフレームは処理中止
			break;
		}
	}
}

//==========================
// 描画処理
//==========================
void Management_EnemyPublic::Draw(void) const
{
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemyPublic[i].Draw();
	}
}

//======================
// 敵のHPを減らす
//======================
bool Management_EnemyPublic::ReduceHP(int index_num, int reduceHP)
{
	m_pEnemyPublic[index_num].ReduceHP(reduceHP);
	if (m_pEnemyPublic[index_num].GetHP() <= 0)
	{//HPが０以下なら敵を消す
		return true;
	}
	return false;
}

//==========================
// 敵を消す
//==========================
void Management_EnemyPublic::DeleteObj(int index_num)
{
	m_delete_enemy++;

	//敵を消す
	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemyPublic[i] = m_pEnemyPublic[i + 1];
	}

	//継承元の敵を消すを呼ぶ
	EnemyManagement::DeleteObj(index_num);

	if (m_delete_enemy == ENEMY_NUM) {
		m_tutorial_clear = true;
	}
}