//=======================================
// 動きを止める敵の管理関係(cppファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#include "management_enemy_poorvision.h"
#include "sound.h"

//==========================
// 定数の初期化
//==========================
const float EnemyPoorvisionManagement::BULLET_SIZE_X = 100.0f;
const float EnemyPoorvisionManagement::BULLET_SIZE_Y = 200.0f;
const float EnemyPoorvisionManagement::BULLET_SPEED = 2.5f;

//=========================
// 引数付きコンストラクタ
//=========================
EnemyPoorvisionManagement::EnemyPoorvisionManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2)
	:EnemyManagement(EnemyManagement::TYPE::POORVISION, ENEMY_NUM, ATTACK, BULLET_ATTACK),
	m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBullet(pDrawObject2)
{
	m_pEnemy = new EnemyStop[ENEMY_NUM];
	m_pBullet = new Bullet[BULLET_NUM];

	//冷気を出す音
	//m_SE_11 = LoadSound((char*)"data\\SE\\1_11.wav");
	//SetVolume(m_SE_06, 0.4f);
}

//======================
// 更新処理
//======================
void EnemyPoorvisionManagement::Update(void)
{
	m_FlameNum++; //フレーム数を増加

	if (m_FlameNum == m_SetEnemyTime[m_EnemyNum])
	{
		EnemyStop temp(m_pDrawObjectEnemy, m_SetEnemy[m_EnemyNum], D3DXVECTOR2(40.0f, 60.0f));
		m_pEnemy[GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		m_EnemyNum++;
	}

	if (m_EnemyNum == ENEMY_NUM)
	{
		m_tutorial_clear = true;
	}
	//今いる敵の処理
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_tutorial_clear = false;
		m_pEnemy[i].Update();

		//弾を作る
		if (m_pEnemy[i].GetFlagBulletMake())
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemy[i].GetPos() + D3DXVECTOR2(0, 100),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0.0f, 3.0f));
						   // 弾の大きさ	
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemy[i].BulletMake();

			//PlaySound(m_SE_11, 0);
		}

		//画面外から出たら消す
		if (m_pEnemy[i].GetScreenOut()) {
			DeleteObj(i);
			break;
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
void EnemyPoorvisionManagement::Draw(void)const
{
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemy[i].Draw();
	}

	SetBlendState(BLEND_MODE_ADD);

	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		m_pBullet[i].DrawDouble();
	}
	SetBlendState(BLEND_MODE_ALPHABLEND);

}

//======================
// 敵のHPを減らす
//======================
bool EnemyPoorvisionManagement::ReduceHP(int index_num, int reduceHP)
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
void EnemyPoorvisionManagement::DeleteObj(int index_num)
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
void EnemyPoorvisionManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < EnemyManagement::GetBulletNum() - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	EnemyManagement::IncreaseBulletNum(-1);
}
