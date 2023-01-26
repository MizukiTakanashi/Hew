//=======================================
// 普通の敵の管理関係(cppファイル)
// 作成日：2022/09/13
// 作成者：高梨水希
//=======================================
#include "management_enemy_fire.h"
#include "sound.h"

//==========================
// 定数の初期化
//==========================
const int EnemyFireManagement::ENEMY_NUM[(int)STAGE::NUM] = { 0, 0, 9, 0, 0 };
const float EnemyFireManagement::BULLET_SIZE_X = 20.0f;
const float EnemyFireManagement::BULLET_SIZE_Y = 20.0f;
const float EnemyFireManagement::BULLET_SPEED = 5.0f;

//=========================
// 引数付きコンストラクタ
//=========================
EnemyFireManagement::EnemyFireManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, int stage)
	:EnemyManagement(EnemyManagement::TYPE::FIRE, ENEMY_NUM[stage], ATTACK, BULLET_ATTACK),
	m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBullet(pDrawObject2)
{
	m_stage_num = stage;
	m_pEnemy = new EnemyNormal[ENEMY_NUM[stage]];
	m_pBullet = new Bullet[BULLET_NUM];

	//発射音
	m_SE_15_1 = LoadSound((char*)"data\\SE\\1_15_1.wav");
}

//======================
// 更新処理
//======================
void EnemyFireManagement::Update()
{
	m_FlameNum++; //フレーム数を増加

	if (m_FlameNum == m_SetEnemyTime[m_stage_num][m_EnemyNum] &&
		m_EnemyNum < ENEMY_NUM[m_stage_num])
	{
		EnemyNormal temp(m_pDrawObjectEnemy, m_SetEnemy[m_stage_num][m_EnemyNum]);
		m_pEnemy[GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		m_EnemyNum++;
	}

	if (m_EnemyNum == ENEMY_NUM[m_stage_num])
	{
		m_tutorial_clear = true;
	}
	//今いる敵の処理
	for (int i = 0; i < GetObjNum(); i++) {
		m_tutorial_clear = false;
		m_pEnemy[i].Update();

		//退出時間来たら...
		if (m_pEnemy[i].GetAppearanceTime() > EXIT_TIME &&
			m_FlameNum < m_SetEnemyTime[m_stage_num][ENEMY_NUM[m_stage_num] - 1]) {
			//消えてく
			m_pEnemy[i].OnAlphaFlag();
			if (m_pEnemy[i].GetAlpha() <= 0.0f) {
				DeleteObj(i);
			}
			continue;
		}

		//弾を作る
		if (m_pEnemy[i].GetFlagBulletMake()) {
			Bullet temp(m_pDrawObjectBullet, m_pEnemy[i].GetPos(),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0.0f, BULLET_SPEED), 0.0f);
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemy[i].BulletMake();

			PlaySound(m_SE_15_1, 0);
		}

		//画面外に出たら消す
		if (m_pEnemy[i].GetScreenOut()) {
			DeleteObj(i);
			break;
		}
	}

	//今いる弾の処理
	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		//弾の更新処理
		m_pBullet[i].Update();

		//画面外から出たら、時間経過したら...
		if (m_pBullet[i].GetScreenOut() || m_pBullet[i].GetTime() > BULLET_BREAK_TIME) {
			//弾を消す
			DeleteBullet(i);
		}
	}
}

//==========================
// 描画処理
//==========================
void EnemyFireManagement::Draw(void)const
{
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemy[i].Draw();
	}

	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		m_pBullet[i].Draw();
	}
}

//======================
// 敵のHPを減らす
//======================
bool EnemyFireManagement::ReduceHP(int index_num, int reduceHP)
{
	m_pEnemy[index_num].ReduceHP(reduceHP);

	if (m_pEnemy[index_num].GetHP() <= 0)
	{//HPが０以下なら敵を消す

		return true;
	}
	return false;
}

//======================
// 敵を消す
//======================
void EnemyFireManagement::DeleteObj(int index_num)
{
	m_delete_enemy++;
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
// 弾を消す
//======================
void EnemyFireManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < EnemyManagement::GetBulletNum() - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	EnemyManagement::IncreaseBulletNum(-1);
}