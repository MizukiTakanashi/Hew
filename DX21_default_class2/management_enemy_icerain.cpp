//=======================================
// •’Ê‚Ì“G‚ÌŠÇ—ŠÖŒW(cppƒtƒ@ƒCƒ‹)
// ì¬“úF2022/09/13
// ì¬ÒF‚—œ…Šó
//=======================================
#include "management_enemy_icerain.h"
#include "sound.h"

//==========================
// ’è”‚Ì‰Šú‰»
//==========================
const int EnemyIceRainManagement::ENEMY_NUM[(int)STAGE::NUM] = { 0, 7, 11, 0, 0 };
const float EnemyIceRainManagement::BULLET_SIZE_X = 20.0f;
const float EnemyIceRainManagement::BULLET_SIZE_Y = 50.0f;
const float EnemyIceRainManagement::BULLET_SPEED = 2.5f;

//=========================
// ˆø”•t‚«ƒRƒ“ƒXƒgƒ‰ƒNƒ^
//=========================
EnemyIceRainManagement::EnemyIceRainManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, int stage)
	:EnemyManagement(EnemyManagement::TYPE::ICERAIN, ENEMY_NUM[stage], ATTACK, BULLET_ATTACK),
	m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBullet(pDrawObject2), m_stage_num(stage)
{
	m_pEnemyIceRain = new EnemyIceRain[ENEMY_NUM[stage]];
	m_pBullet = new Bullet[BULLET_NUM];

	//•X’Œ‚ğ~‚ç‚¹‚é‰¹
	m_SE_13 = LoadSound((char*)"data\\SE\\1_13.wav");
	//SetVolume(m_SE_06, 0.4f);
}

//======================
// XVˆ—
//======================
void EnemyIceRainManagement::Update(const D3DXVECTOR2& PlayerPos)
{
	m_FlameNum++; //ƒtƒŒ[ƒ€”‚ğ‘‰Á

	if (m_FlameNum == m_SetEnemyTime[m_stage_num][m_EnemyNum] && m_EnemyNum < ENEMY_NUM[m_stage_num])
	{
		EnemyIceRain temp(m_pDrawObjectEnemy, m_SetEnemy[m_stage_num][m_EnemyNum]);
		m_pEnemyIceRain[GetObjNum()] = temp;
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
		m_pEnemyIceRain[i].Update();

		//’e‚ğì‚é
		if (m_pEnemyIceRain[i].GetFlagBulletMake() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyIceRain[i].GetPos(),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 10.0f), 0.0f); 
			// ’e‚Ì‘å‚«‚³								’e‚ğŒ‚‚Â•ûŒü		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyIceRain[i].BulletMake();

			PlaySound(m_SE_13, 0);
		}

		//‰æ–ÊŠO‚Éo‚½‚çÁ‚·
		if (m_pEnemyIceRain[i].GetScreenOut()) {
			DeleteObj(i);
			break;
		}

		//…¯‚ÌƒXƒe[ƒW‚Å‚ ‚ê‚ÎAˆê”­‚µ‚©o‚³‚È‚¢
		if (m_stage_num == (int)STAGE::MERCURY) {
			continue;
		}

		//’e‚ğì‚é
		if (m_pEnemyIceRain[i].GetFlagBulletMake1() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyIceRain[i].GetPos() + D3DXVECTOR2(30.0f, 0.0f), 
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 10.0f), 0.0f);
			// ’e‚Ì‘å‚«‚³								’e‚ğŒ‚‚Â•ûŒü		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyIceRain[i].BulletMake1();
		}
		//’e‚ğì‚é
		if (m_pEnemyIceRain[i].GetFlagBulletMake2() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyIceRain[i].GetPos() + D3DXVECTOR2(-30.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 10.0f), 0.0f);
			// ’e‚Ì‘å‚«‚³								’e‚ğŒ‚‚Â•ûŒü		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyIceRain[i].BulletMake2();
		}
		//’e‚ğì‚é
		if (m_pEnemyIceRain[i].GetFlagBulletMake3() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyIceRain[i].GetPos() + D3DXVECTOR2(50.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 10.0f), 0.0f);
			// ’e‚Ì‘å‚«‚³								’e‚ğŒ‚‚Â•ûŒü		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyIceRain[i].BulletMake3();
		}
		//’e‚ğì‚é
		if (m_pEnemyIceRain[i].GetFlagBulletMake4() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyIceRain[i].GetPos() + D3DXVECTOR2(-50.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 10.0f), 0.0f);
			// ’e‚Ì‘å‚«‚³								’e‚ğŒ‚‚Â•ûŒü		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyIceRain[i].BulletMake4();
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
void EnemyIceRainManagement::Draw(void)const
{
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemyIceRain[i].Draw();
	}

	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		m_pBullet[i].Draw();
	}
}

//======================
// “G‚ÌHP‚ğŒ¸‚ç‚·
//======================
bool EnemyIceRainManagement::ReduceHP(int index_num, int reduceHP)
{
	m_pEnemyIceRain[index_num].ReduceHP(reduceHP);

	if (m_pEnemyIceRain[index_num].GetHP() <= 0)
	{//HP‚ª‚OˆÈ‰º‚È‚ç“G‚ğÁ‚·


		return true;
	}
	return false;
}

//==========================
// “G‚ğÁ‚·
//==========================
void EnemyIceRainManagement::DeleteObj(int index_num)
{
	m_delete_enemy++;
	//“G‚ğÁ‚·
	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemyIceRain[i] = m_pEnemyIceRain[i + 1];
	}

	//Œp³Œ³‚Ì“G‚ğÁ‚·‚ğŒÄ‚Ô
	EnemyManagement::DeleteObj(index_num);

	if (m_delete_enemy == ENEMY_NUM[m_stage_num]) {
		m_tutorial_clear = true;
	}
}

//======================
// ’e‚ğÁ‚·
//======================
void EnemyIceRainManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < EnemyManagement::GetBulletNum() - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	EnemyManagement::IncreaseBulletNum(-1);
}