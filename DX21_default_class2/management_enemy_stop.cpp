//=======================================
// 動きを止める敵の管理関係(cppファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#include "management_enemy_stop.h"
#include "sound.h"

//==========================
// 定数の初期化
//==========================
const float EnemyStopManagement::BULLET_SIZE_X = 100.0f;
const float EnemyStopManagement::BULLET_SIZE_Y = 300.0f;
const float EnemyStopManagement::BULLET_SPEED = 2.5f;

//=========================
// 引数付きコンストラクタ
//=========================
EnemyStopManagement::EnemyStopManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2)
	:EnemyManagement(ENEMY_NUM, ATTACK, BULLET_ATTACK),m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBullet(pDrawObject2)
{
	m_pEnemy = new EnemyStop[ENEMY_NUM];
	m_pBullet = new BulletStop[ENEMY_NUM];

	//冷気を出す音
	m_SE_11 = LoadSound((char*)"data\\SE\\1_11.wav");
	//SetVolume(m_SE_06, 0.4f);
}

//======================
// 更新処理
//======================
void EnemyStopManagement::Update(void)
{
	m_FlameNum++; //フレーム数を増加

	if (m_FlameNum == m_SetEnemyTime[m_EnemyNum])
	{
		EnemyStop temp(m_pDrawObjectEnemy, m_SetEnemy[m_EnemyNum]);
		m_pEnemy[GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		m_EnemyNum++;
	}

	//今いる敵の処理
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemy[i].Update();

		//弾を作る
		if (m_pEnemy[i].GetFlagBulletMake())
		{
			BulletStop temp(m_pDrawObjectBullet, m_pEnemy[i].GetPos() + D3DXVECTOR2(0, 300),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), 0.0f);
						   // 弾の大きさ	
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemy[i].BulletMake();

			PlaySound(m_SE_11, 0);
		}
	}

	//今いる弾の処理
	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		m_pBullet[i].Update();
		//画面外から出たら...
		if (m_pBullet[i].GetScreenOut() || m_pBullet[i].GetTime() > BULLET_TIME) {
			//弾を消す
			DeleteBullet(i);
		}
	}
}

//==========================
// 描画処理
//==========================
void EnemyStopManagement::Draw(void)const
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
bool EnemyStopManagement::ReduceHP(int index_num, int reduceHP)
{
	m_pEnemy[index_num].ReduceHP(reduceHP);

	if (m_pEnemy[index_num].GetHP() <= 0)
	{//HPが０以下なら敵を消す


		return true;
	}
	return false;
}

//==========================
// 敵を消す
//==========================
void EnemyStopManagement::DeleteObj(int index_num)
{
	m_delete_enemy++;
	//敵を消す
	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemy[i] = m_pEnemy[i + 1];
	}

	//継承元の敵を消すを呼ぶ
	EnemyManagement::DeleteObj(index_num);

	if (m_delete_enemy == ENEMY_NUM) {
		m_tutorial_clear = true;
	}

}

//======================
// 弾を消す
//======================
void EnemyStopManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < EnemyManagement::GetBulletNum() - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	EnemyManagement::IncreaseBulletNum(-1);
}
