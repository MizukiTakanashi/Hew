#include "management_boss.h"
#include "sound.h"

//==========================
// 定数の初期化
//==========================
const int BossManagement::ENEMY_NUM[(int)STAGE::NUM] = { 1, 1, 1, 1, 1 };
const float BossManagement::BULLET_SIZE_X = 20.0f;
const float BossManagement::BULLET_SIZE_Y = 50.0f;
const float BossManagement::BULLET_SPEED = 2.5f;
const float BossManagement::EXIT_MOVE_SPEED_Y = 5.0f;
//=========================
// 引数付きコンストラクタ
//=========================
BossManagement::BossManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, int stage)
	:EnemyManagement(EnemyManagement::TYPE::BOSS, ENEMY_NUM[stage], ATTACK, BULLET_ATTACK),
	m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBullet(pDrawObject2)
{
	m_stage_num = stage;
	m_pEnemyBoss = new Boss[ENEMY_NUM[stage]];
	m_pBullet = new Bullet[BULLET_NUM];

	m_SE_21 = LoadSound((char*)"data\\SE\\2_20.wav");
	SetVolume(m_SE_21, 0.1f);
}

//======================
// 更新処理
//======================
void BossManagement::Update()
{
	m_FlameNum++; //フレーム数を増加

	if (m_FlameNum == m_SetEnemyTime[m_stage_num][m_EnemyNum] &&
		m_EnemyNum < ENEMY_NUM[m_stage_num])
	{
		Boss temp(m_pDrawObjectEnemy, m_SetEnemy[m_stage_num][m_EnemyNum]);
		m_pEnemyBoss[GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		m_EnemyNum++;
	}

	if (m_EnemyNum == ENEMY_NUM[m_stage_num])
	{
		m_tutorial_clear = true;
	}

	//今いる敵の処理
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_tutorial_clear = false;
		m_pEnemyBoss[i].Update();
		//HPが半分を超えたとき
		if (m_pEnemyBoss[i].GetHP() > Boss::HP_MAX * 0.75f) {
			BossPatternC();
		}
		//HPが半分を切った時
		if (m_pEnemyBoss[i].GetHP() <= Boss::HP_MAX * 0.75f&&m_pEnemyBoss[i].GetHP() > Boss::HP_MAX * 0.5f) {
			BossPatternA();

		}
		//HPが半分を切った時
		if (m_pEnemyBoss[i].GetHP() <= Boss::HP_MAX * 0.5f && m_pEnemyBoss[i].GetHP() > Boss::HP_MAX * 0.25f) {
			BossPatternD();
		}
		//HPが半分を切った時
		if (m_pEnemyBoss[i].GetHP() <= Boss::HP_MAX * 0.25f && m_pEnemyBoss[i].GetHP() > Boss::HP_MAX * 0.0f) {
			BossPatternB();
		}
		//画面外に出たら消す
		if (m_pEnemyBoss[i].GetScreenOut()) {
			DeleteObj(i);
			break;
		}

	}

	//今いる弾の処理
	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		m_pBullet[i].Update();
		//画面外から出たら...
		if (m_pBullet[i].GetScreenOut()) {
			//弾を消す
			DeleteBullet(i);
		}
	}
}


//==========================
// 描画処理
//==========================
void BossManagement::Draw(void)const
{
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemyBoss[i].Draw();
	}

	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		m_pBullet[i].Draw();
	}
}

//======================
// 敵のHPを減らす
//======================
bool BossManagement::ReduceHP(int index_num, int reduceHP)
{
	m_pEnemyBoss[index_num].ReduceHP(reduceHP);

	if (m_pEnemyBoss[index_num].GetHP() <= 0)
	{//HPが０以下なら敵を消す


		return true;
	}
	return false;
}

//==========================
// 敵を消す
//==========================
void BossManagement::DeleteObj(int index_num)
{
	//敵を消す
	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemyBoss[i] = m_pEnemyBoss[i + 1];
	}

	//継承元の敵を消すを呼ぶ
	EnemyManagement::DeleteObj(index_num);

	//if (m_EnemyNum == ENEMY_NUM) {
	//	m_tutorial_clear = true;
	//}
}

//======================
// 弾を消す
//======================
void BossManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < EnemyManagement::GetBulletNum() - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	EnemyManagement::IncreaseBulletNum(-1);
}

void BossManagement::BossPatternA()
{
	//五本の弾が正面に飛ぶ
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		//弾を作る
		if (m_pEnemyBoss[i].GetFlagBulletMake() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyBoss[i].GetPos(),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 12.0f), 0.0f);
			// 弾の大きさ								弾を撃つ方向		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyBoss[i].BulletMake();

			PlaySound(m_SE_21, 0);
		}

		//弾を作る
		if (m_pEnemyBoss[i].GetFlagBulletMake1() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyBoss[i].GetPos() + D3DXVECTOR2(60.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 11.0f), 0.0f);
			// 弾の大きさ								弾を撃つ方向		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyBoss[i].BulletMake1();
		}
		//弾を作る
		if (m_pEnemyBoss[i].GetFlagBulletMake2() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyBoss[i].GetPos() + D3DXVECTOR2(-60.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 11.0f), 0.0f);
			// 弾の大きさ								弾を撃つ方向		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyBoss[i].BulletMake2();
		}
		//弾を作る
		if (m_pEnemyBoss[i].GetFlagBulletMake3() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyBoss[i].GetPos() + D3DXVECTOR2(100.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 10.0f), 0.0f);
			// 弾の大きさ								弾を撃つ方向		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyBoss[i].BulletMake3();
		}
		//弾を作る
		if (m_pEnemyBoss[i].GetFlagBulletMake4() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyBoss[i].GetPos() + D3DXVECTOR2(-100.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 10.0f), 0.0f);
			// 弾の大きさ								弾を撃つ方向		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyBoss[i].BulletMake4();
		}

	}
}

void BossManagement::BossPatternB()
{
	//五本の弾が放射状に飛ぶ
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		//弾を作る
		if (m_pEnemyBoss[i].GetFlagBulletMake() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyBoss[i].GetPos(),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 25.0f), 0.0f);
			// 弾の大きさ								弾を撃つ方向		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyBoss[i].BulletMake();

			PlaySound(m_SE_21, 0);
		}

		//弾を作る
		if (m_pEnemyBoss[i].GetFlagBulletMake1() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyBoss[i].GetPos() + D3DXVECTOR2(30.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(10.0f, 20.0f), -30.0f);
			// 弾の大きさ								弾を撃つ方向		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyBoss[i].BulletMake1();
		}
		//弾を作る
		if (m_pEnemyBoss[i].GetFlagBulletMake2() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyBoss[i].GetPos() + D3DXVECTOR2(-30.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(-10.0f, 20.0f), 30.0f);
			// 弾の大きさ								弾を撃つ方向		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyBoss[i].BulletMake2();
		}
		//弾を作る
		if (m_pEnemyBoss[i].GetFlagBulletMake3() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyBoss[i].GetPos() + D3DXVECTOR2(50.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(20.0f, 20.0f), -45.0f);
			// 弾の大きさ								弾を撃つ方向		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyBoss[i].BulletMake3();
		}
		//弾を作る
		if (m_pEnemyBoss[i].GetFlagBulletMake4() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyBoss[i].GetPos() + D3DXVECTOR2(-50.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(-20.0f, 20.0f), 45.0f);
			// 弾の大きさ								弾を撃つ方向		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyBoss[i].BulletMake4();
		}
	}
}

void BossManagement::BossPatternC()
{
	//三本の弾が正面に飛ぶ
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		//弾を作る
		if (m_pEnemyBoss[i].GetFlagBulletMake() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyBoss[i].GetPos(),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 6.0f), 0.0f);
			// 弾の大きさ								弾を撃つ方向		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyBoss[i].BulletMake();

			PlaySound(m_SE_21, 0);
		}

		//弾を作る
		if (m_pEnemyBoss[i].GetFlagBulletMake1() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyBoss[i].GetPos() + D3DXVECTOR2(60.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 5.0f), 0.0f);
			// 弾の大きさ								弾を撃つ方向		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyBoss[i].BulletMake1();
		}
		//弾を作る
		if (m_pEnemyBoss[i].GetFlagBulletMake2() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyBoss[i].GetPos() + D3DXVECTOR2(-60.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 5.0f), 0.0f);
			// 弾の大きさ								弾を撃つ方向		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyBoss[i].BulletMake2();
		}
	}
}

void BossManagement::BossPatternD()
{
	//五本の弾が正面に飛ぶ
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		//弾を作る
		if (m_pEnemyBoss[i].GetFlagBulletMake() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyBoss[i].GetPos(),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 12.5f), 0.0f);
			// 弾の大きさ								弾を撃つ方向		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyBoss[i].BulletMake();

			PlaySound(m_SE_21, 0);
		}

		//弾を作る
		if (m_pEnemyBoss[i].GetFlagBulletMake1() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyBoss[i].GetPos() + D3DXVECTOR2(60.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 25.0f), 0.0f);
			// 弾の大きさ								弾を撃つ方向		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyBoss[i].BulletMake1();
		}
		//弾を作る
		if (m_pEnemyBoss[i].GetFlagBulletMake2() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyBoss[i].GetPos() + D3DXVECTOR2(-60.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 25.0f), 0.0f);
			// 弾の大きさ								弾を撃つ方向		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyBoss[i].BulletMake2();
		}
		//弾を作る
		if (m_pEnemyBoss[i].GetFlagBulletMake3() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyBoss[i].GetPos() + D3DXVECTOR2(100.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 12.5f), 0.0f);
			// 弾の大きさ								弾を撃つ方向		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyBoss[i].BulletMake3();
		}
		//弾を作る
		if (m_pEnemyBoss[i].GetFlagBulletMake4() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyBoss[i].GetPos() + D3DXVECTOR2(-100.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 12.5f), 0.0f);
			// 弾の大きさ								弾を撃つ方向		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyBoss[i].BulletMake4();
		}

	}
}