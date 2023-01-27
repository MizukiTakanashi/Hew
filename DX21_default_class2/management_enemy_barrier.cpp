//=======================================
// バリアの敵の管理関係(cppファイル)
// 作成日：2022/12/08
// 作成者：高梨水希
//=======================================
#include "management_enemy_barrier.h"

//==========================
// 定数の初期化
//==========================
const int EnemyBarrierManagement::ENEMY_NUM[(int)STAGE::NUM] = { 0, 15, 0, 0, 0, 9 };
const D3DXVECTOR2 EnemyBarrierManagement::BARRIER_SIZE = D3DXVECTOR2(50.0f, 10.0f);
const D3DXVECTOR2 EnemyBarrierManagement::INTERVAL_POS = D3DXVECTOR2(0.0f, 60.0f);

//=========================
// 引数付きコンストラクタ
//=========================
EnemyBarrierManagement::EnemyBarrierManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, int stage_num)
	:EnemyManagement(EnemyManagement::TYPE::BULLET_BARRIER, ENEMY_NUM[stage_num], ATTACK, 0, BARRIER_ATTACK),
	m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBarrier(pDrawObject2)
{
	m_stage_num = stage_num;
	m_pEnemy = new EnemyBarrier[ENEMY_NUM[m_stage_num]];
	m_pBarrier = new GameObject[ENEMY_NUM[m_stage_num]];

	//バリアのHP初期化
	for (int i = 0; i < ENEMY_NUM[m_stage_num]; i++) {
		m_BarrierHP[i] = BARRIER_HP_MAX;
	}
}

//======================
// 更新処理
//======================
void EnemyBarrierManagement::Update()
{
	m_FlameNum++; //フレーム数を増加

	//セットする時間になれば...
	if (m_FlameNum == m_SetEnemyTime[m_stage_num][m_EnemyNum] &&
		m_EnemyNum < ENEMY_NUM[m_stage_num])
	{
		//敵をセットする
		EnemyBarrier temp(m_pDrawObjectEnemy, m_SetEnemy[m_stage_num][m_EnemyNum]);
		m_pEnemy[EnemyManagement::GetObjNum()] = temp;

		//バリアをセットする
		GameObject temp1(m_pDrawObjectBarrier, m_SetEnemy[m_stage_num][m_EnemyNum], BARRIER_SIZE);
		m_pBarrier[EnemyManagement::GetOtherNum()] = temp1;
		m_BarrierHP[EnemyManagement::GetOtherNum()] = BARRIER_HP_MAX;
		m_pEnemy[EnemyManagement::GetObjNum()].SetBarrierIndex(EnemyManagement::GetOtherNum());

		EnemyManagement::IncreaseObjNum(1);
		EnemyManagement::IncreaseOtherNum(1);

		//セットした敵の数を増やす
		m_EnemyNum++;
	}

	if (m_EnemyNum == ENEMY_NUM[m_stage_num])
	{
		m_tutorial_clear = true;
	}
	//今いる敵の処理
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_tutorial_clear = false;
		m_pEnemy[i].Update();

		//今あるバリアの処理
		for (int j = 0; j < EnemyManagement::GetOtherNum(); j++) {
			//敵が持っているバリアのインデックス番号と同じであれば...
			if (m_pEnemy[i].GetBarrierIndex() == j) {
				//バリアを敵の前に置く
				m_pBarrier[j].SetPos(m_pEnemy[i].GetPos() + INTERVAL_POS);
			}
		}

		//画面外に出たら消す
		if (m_pEnemy[i].GetScreenOut()) {
			DeleteObj(i);
			break;
		}
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

	for (int i = 0; i < EnemyManagement::GetOtherNum(); i++) {
		m_pBarrier[i].Draw();
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
// バリアのHPを減らす
//======================
bool EnemyBarrierManagement::ReduceOtherHP(int index_num, int reduceHP)
{
	m_BarrierHP[index_num] -= reduceHP;

	//HPが0以下なら...
	if (m_BarrierHP[index_num] <= 0)
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
	m_delete_enemy++;
	//敵に付随しているバリアがまだ壊れていなかったら...
	if (m_BarrierHP[m_pEnemy[index_num].GetBarrierIndex()] != -1) {
		//敵に付随しているバリアを消す
		DeleteOther(m_pEnemy[index_num].GetBarrierIndex());
	}

	//敵を消す
	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemy[i] = m_pEnemy[i + 1];
	}

	//継承元の敵を消すを呼ぶ
	EnemyManagement::DeleteObj(index_num);

	if (m_delete_enemy == ENEMY_NUM[m_stage_num]) {
		m_tutorial_clear = true;
	}

}

//======================
// バリアを消す
//======================
void EnemyBarrierManagement::DeleteOther(int index_num)
{
	//壊された事を記録
	m_BarrierHP[index_num] = -1;

	for (int i = index_num; i < EnemyManagement::GetOtherNum() - 1; i++) {
		m_pBarrier[i] = m_pBarrier[i + 1];

		//バリアのインデックス番号を書き換え
		for (int j = 0; j < EnemyManagement::GetObjNum(); j++) {
			if (m_pEnemy[j].GetBarrierIndex() == i + 1) {
				m_pEnemy[j].SetBarrierIndex(m_pEnemy[j].GetBarrierIndex() - 1);
			}
		}

		m_BarrierHP[i] = m_BarrierHP[i + 1];
	}

	//継承元の別オブジェクトを消すを呼ぶ
	EnemyManagement::DeleteOther(index_num);
}