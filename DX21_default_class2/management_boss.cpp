#include "management_boss.h"
#include "sound.h"

//==========================
// ’è”‚Ì‰Šú‰»
//==========================
const int BossManagement::ENEMY_NUM[(int)STAGE::NUM] = { 5, 0, 0, 2, 5 };
const float BossManagement::BULLET_SIZE_X = 20.0f;
const float BossManagement::BULLET_SIZE_Y = 20.0f;
const float BossManagement::BULLET_SPEED = 2.5f;
const float BossManagement::EXIT_MOVE_SPEED_Y = 5.0f;
//=========================
// ˆø”•t‚«ƒRƒ“ƒXƒgƒ‰ƒNƒ^
//=========================
BossManagement::BossManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, int stage)
	:EnemyManagement(EnemyManagement::TYPE::GATORING, ENEMY_NUM[stage], ATTACK, BULLET_ATTACK),
	m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBullet(pDrawObject2)
{
	m_stage_num = stage;
	m_pEnemyBoss = new Boss[ENEMY_NUM[stage]];
	m_pBullet = new Bullet[BULLET_NUM];

	m_SE_21 = LoadSound((char*)"data\\SE\\2_20.wav");
	SetVolume(m_SE_21, 0.1f);
}

//======================
// XVˆ—
//======================
void BossManagement::Update()
{
	m_FlameNum++; //ƒtƒŒ[ƒ€”‚ğ‘‰Á

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

	//¡‚¢‚é“G‚Ìˆ—
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_tutorial_clear = false;
		m_pEnemyBoss[i].Update();

		//’e‚ğì‚é
		if (m_pEnemyBoss[i].GetFlagBulletMake() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyBoss[i].GetPos(),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 10.0f), 0.0f);
			// ’e‚Ì‘å‚«‚³								’e‚ğŒ‚‚Â•ûŒü		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyBoss[i].BulletMake();

			PlaySound(m_SE_21, 0);
		}

		//’e‚ğì‚é
		if (m_pEnemyBoss[i].GetFlagBulletMake1() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyBoss[i].GetPos() + D3DXVECTOR2(30.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(10.0f, 20.0f), 0.0f);
			// ’e‚Ì‘å‚«‚³								’e‚ğŒ‚‚Â•ûŒü		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyBoss[i].BulletMake1();
		}
		//’e‚ğì‚é
		if (m_pEnemyBoss[i].GetFlagBulletMake2() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyBoss[i].GetPos() + D3DXVECTOR2(-30.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(-10.0f, 20.0f), 0.0f);
			// ’e‚Ì‘å‚«‚³								’e‚ğŒ‚‚Â•ûŒü		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyBoss[i].BulletMake2();
		}
		//’e‚ğì‚é
		if (m_pEnemyBoss[i].GetFlagBulletMake3() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyBoss[i].GetPos() + D3DXVECTOR2(50.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(20.0f, 20.0f), 0.0f);
			// ’e‚Ì‘å‚«‚³								’e‚ğŒ‚‚Â•ûŒü		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyBoss[i].BulletMake3();
		}
		//’e‚ğì‚é
		if (m_pEnemyBoss[i].GetFlagBulletMake4() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyBoss[i].GetPos() + D3DXVECTOR2(-50.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(-20.0f, 20.0f), 0.0f);
			// ’e‚Ì‘å‚«‚³								’e‚ğŒ‚‚Â•ûŒü		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyBoss[i].BulletMake4();
		}
		//‰æ–ÊŠO‚Éo‚½‚çÁ‚·
		if (m_pEnemyBoss[i].GetScreenOut()) {
			DeleteObj(i);
			break;
		}

	}

	//¡‚¢‚é’e‚Ìˆ—
	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		m_pBullet[i].Update();
		//‰æ–ÊŠO‚©‚ço‚½‚ç...
		if (m_pBullet[i].GetScreenOut()) {
			//’e‚ğÁ‚·
			DeleteBullet(i);
		}
	}
}

//==========================
// •`‰æˆ—
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
// “G‚ÌHP‚ğŒ¸‚ç‚·
//======================
bool BossManagement::ReduceHP(int index_num, int reduceHP)
{
	m_pEnemyBoss[index_num].ReduceHP(reduceHP);

	if (m_pEnemyBoss[index_num].GetHP() <= 0)
	{//HP‚ª‚OˆÈ‰º‚È‚ç“G‚ğÁ‚·


		return true;
	}
	return false;
}

//==========================
// “G‚ğÁ‚·
//==========================
void BossManagement::DeleteObj(int index_num)
{
	//“G‚ğÁ‚·
	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemyBoss[i] = m_pEnemyBoss[i + 1];
	}

	//Œp³Œ³‚Ì“G‚ğÁ‚·‚ğŒÄ‚Ô
	EnemyManagement::DeleteObj(index_num);

	//if (m_EnemyNum == ENEMY_NUM) {
	//	m_tutorial_clear = true;
	//}
}

//======================
// ’e‚ğÁ‚·
//======================
void BossManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < EnemyManagement::GetBulletNum() - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	EnemyManagement::IncreaseBulletNum(-1);
}