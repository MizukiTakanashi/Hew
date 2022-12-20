

//=======================================
// •’Ê‚Ì“G‚ÌŠÇ—ŠÖŒW(cppƒtƒ@ƒCƒ‹)
// ì¬“úF2022/09/13
// ì¬ÒF‚—œ…Šó
//=======================================
#include "management_enemy_icerain.h"
#define _USE_MATH_DEFINES
#include <math.h>

//==========================
// ’è”‚Ì‰Šú‰»
//==========================
const float EnemyIceRainManagement::BULLET_SIZE_X = 20.0f;
const float EnemyIceRainManagement::BULLET_SIZE_Y = 50.0f;
const float EnemyIceRainManagement::BULLET_SPEED = 2.5f;

//=========================
// ˆø”•t‚«ƒRƒ“ƒXƒgƒ‰ƒNƒ^
//=========================
EnemyIceRainManagement::EnemyIceRainManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2)
	:EnemyManagement(ENEMY_NUM, ATTACK, BULLET_ATTACK), m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBullet(pDrawObject2)
{
	m_pEnemyIceRain = new EnemyIceRain[ENEMY_NUM];
	m_pBullet = new Bullet[ENEMY_NUM];
}

//======================
// XVˆ—
//======================
void EnemyIceRainManagement::Update(const D3DXVECTOR2& PlayerPos)
{
	m_FlameNum++; //ƒtƒŒ[ƒ€”‚ğ‘‰Á

	if (m_FlameNum == m_SetEnemyTime[m_EnemyNum])
	{
		EnemyIceRain temp(m_pDrawObjectEnemy, m_SetEnemy[m_EnemyNum]);
		m_pEnemyIceRain[GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		m_EnemyNum++;
	}

	//¡‚¢‚é“G‚Ìˆ—
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemyIceRain[i].Update();

		//’e‚ğì‚é
		if (m_pEnemyIceRain[i].GetFlagBulletMake())
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyIceRain[i].GetPos(),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 10.0f), 0.0f); 
			//Bullet temp(m_pDrawObjectBullet, m_pEnemyGatoring[i].GetPos(),
					//D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 10.0f), 0.0f);
			// ’e‚Ì‘å‚«‚³								’e‚ğŒ‚‚Â•ûŒü		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyIceRain[i].BulletMake();
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
	//“G‚ğÁ‚·
	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemyIceRain[i] = m_pEnemyIceRain[i + 1];
	}

	//Œp³Œ³‚Ì“G‚ğÁ‚·‚ğŒÄ‚Ô
	EnemyManagement::DeleteObj(index_num);
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