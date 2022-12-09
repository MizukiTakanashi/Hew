//=======================================
// バリアの敵の管理関係(cppファイル)
// 作成日：2022/12/08
// 作成者：高梨水希
//=======================================
#include "management_enemy_barrier.h"

//==========================
// 定数の初期化
//==========================
const D3DXVECTOR2 EnemyBarrierManagement::BARRIER_SIZE = D3DXVECTOR2(50.0f, 50.0f);

//=========================
// 引数付きコンストラクタ
//=========================
EnemyBarrierManagement::EnemyBarrierManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2)
	:EnemyManagement(ENEMY_NUM, ATTACK, 0), m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBarrier(pDrawObject2)
{
	m_pEnemy = new EnemyBarrier[ENEMY_NUM];
}

//======================
// 更新処理
//======================
void EnemyBarrierManagement::Update(const D3DXVECTOR2& PlayerPos)
{
	m_FlameNum++; //フレーム数を増加

	//セットする時間になれば...
	if (m_FlameNum == m_SetEnemyTime[m_EnemyNum])
	{
		//敵をセットする
		EnemyBarrier temp(m_pDrawObjectEnemy, m_pDrawObjectBarrier, m_SetEnemy[m_EnemyNum]);
		m_pEnemy[EnemyManagement::GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		//セットした敵の数を増やす
		m_EnemyNum++;
	}

	//今いる敵の処理
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemy[i].Update();
	}
}

//==========================
// 描画処理
//==========================
void EnemyBarrierManagement::Draw(void)const
{
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemy[i].Draw();
	}
}

//======================
// 敵のHPを減らす
//======================
bool EnemyBarrierManagement::ReduceHP(int index_num, int reduceHP)
{
	m_pEnemy[index_num].ReduceHP(reduceHP);

	//HPが0以下なら...
	if (m_pEnemy[index_num].GetHP() <= 0)
	{
		//敵が死んだフラグを返す
		return true;
	}

	//敵が死んでないフラグを返す
	return false;
}

//======================
// 敵を消す
//======================
void EnemyBarrierManagement::DeleteObj(int index_num)
{
	//敵を消す
	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemy[i] = m_pEnemy[i + 1];
	}

	//継承元の敵を消すを呼ぶ
	EnemyManagement::DeleteObj(index_num);
}

//======================
// バリア(弾)を消す
//======================
void EnemyBarrierManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < EnemyManagement::GetBulletNum() - 1; i++) {
		//m_pBarrier[i] = m_pBarrier[i + 1];
	}
	EnemyManagement::IncreaseBulletNum(-1);
}