#include "management_enemy_attack.h"
#define _USE_MATH_DEFINES
#include <math.h>

//==========================
// ’è”‚Ì‰Šú‰»
//==========================
const float EnemyAttackManagement::BULLET_SIZE_X = 100.0f;
const float EnemyAttackManagement::BULLET_SIZE_Y = 100.0f;
const float EnemyAttackManagement::BULLET_SPEED = 0.0f;

const float EnemyAttackManagement::ATTACK_SPEED = 5.0f;
//=========================
// ˆø”•t‚«ƒRƒ“ƒXƒgƒ‰ƒNƒ^
//=========================
EnemyAttackManagement::EnemyAttackManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2)
	:EnemyManagement(EnemyManagement::TYPE::ATTACK, ENEMY_NUM, ATTACK, BULLET_ATTACK), m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBullet(pDrawObject2)
{
	m_pEnemyAttack = new EnemyAttack[ENEMY_NUM];

	m_pBullet = new Bullet[ENEMY_NUM];
}

//======================
// XVˆ—
//======================
void EnemyAttackManagement::Update(const D3DXVECTOR2& PlayerPos)
{
	m_FlameNum++; //ƒtƒŒ[ƒ€”‚ğ‘‰Á

	if (m_FlameNum == m_SetEnemyTime[m_EnemyNum])
	{
		EnemyAttack temp(m_pDrawObjectEnemy, m_SetEnemy[m_EnemyNum]);
		m_pEnemyAttack[GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		m_EnemyNum++;
	}

	if (m_EnemyNum == ENEMY_NUM)
	{
		m_tutorial_clear = true;
	}

	//¡‚¢‚é“G‚Ìˆ—
	for (int i = 0; i < GetObjNum(); i++) {
		m_tutorial_clear = false;
		m_pEnemyAttack[i].Update();
		if (m_pEnemyAttack[i].GetFlagExplosion() == false) {
			//ŠÔ‚É‚È‚Á‚½‚ç“Ë‚Á‚Ş
			if (m_pEnemyAttack[i].GetFlagAttack()) {
				//ƒvƒŒƒCƒ„[‚ÌŒã‚ğ’Ç‚¤(ƒz[ƒ~ƒ“ƒO’e)
				D3DXVECTOR2 movTemp = PlayerPos - m_pEnemyAttack[i].GetPos();
				D3DXVECTOR2 rotposTemp = m_pEnemyAttack[i].GetPos() - PlayerPos;
				D3DXVec2Normalize(&movTemp, &movTemp);
				movTemp *= ATTACK_SPEED;
				m_pEnemyAttack[i].MovePos(movTemp);
			}
		}
		if (m_pEnemyAttack[i].GetFlagExplosion()==true)
		{
			//’e‚ğì‚é
			if (m_pEnemyAttack[i].GetFlagBulletMake())
			{
				Bullet temp(m_pDrawObjectBullet, m_pEnemyAttack[i].GetPos(),
					D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 0.0f), 0.0f);
				// ’e‚Ì‘å‚«‚³								’e‚ğŒ‚‚Â•ûŒü		
				m_pBullet[EnemyManagement::GetBulletNum()] = temp;

				EnemyManagement::IncreaseBulletNum(1);

				m_pEnemyAttack[i].BulletMake();
			}
			m_pEnemyAttack[i].MovePos(D3DXVECTOR2(0.0f, 0.0f));
			DeleteObj(i);
		}

		//‰æ–ÊŠO‚Éo‚½‚çÁ‚·
		if (m_pEnemyAttack[i].GetScreenOut()) {
			DeleteObj(i);
			break;
		}
	}
	//¡‚¢‚é’e‚Ìˆ—
	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		m_pBullet[i].Update();
		if (m_pBullet[i].GetTime() == 120)
		{
			//’e‚ğÁ‚·
			DeleteBullet(i);
		}
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
void EnemyAttackManagement::Draw(void)const
{
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemyAttack[i].Draw();
	}

	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		m_pBullet[i].Draw();
	}
}

//======================
// “G‚ÌHP‚ğŒ¸‚ç‚·
//======================
bool EnemyAttackManagement::ReduceHP(int index_num, int reduceHP)
{
	m_pEnemyAttack[index_num].ReduceHP(reduceHP);
	if (m_pEnemyAttack[index_num].GetHP() <= 0)
	{//HP‚ª‚OˆÈ‰º‚È‚ç“G‚ğÁ‚·

		return true;
	}
	return false;
}
//==========================
// “G‚ğÁ‚·
//==========================
void EnemyAttackManagement::DeleteObj(int index_num)
{
	//“G‚ğÁ‚·
	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemyAttack[i] = m_pEnemyAttack[i + 1];
	}

	//Œp³Œ³‚Ì“G‚ğÁ‚·‚ğŒÄ‚Ô
	EnemyManagement::DeleteObj(index_num);
}

//======================
// ’e‚ğÁ‚·
//======================
void EnemyAttackManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < EnemyManagement::GetBulletNum() - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	EnemyManagement::IncreaseBulletNum(-1);
}