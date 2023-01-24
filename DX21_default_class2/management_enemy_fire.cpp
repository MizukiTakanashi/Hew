//=======================================
// •’Ê‚Ì“G‚ÌŠÇ—ŠÖŒW(cppƒtƒ@ƒCƒ‹)
// ì¬“úF2022/09/13
// ì¬ÒF‚—œ…Šó
//=======================================
#include "management_enemy_fire.h"
#include "sound.h"

//==========================
// ’è”‚Ì‰Šú‰»
//==========================
const int EnemyFireManagement::ENEMY_NUM[(int)STAGE::NUM] = { 0, 0, 9, 0 };
const float EnemyFireManagement::BULLET_SIZE_X = 20.0f;
const float EnemyFireManagement::BULLET_SIZE_Y = 20.0f;
const float EnemyFireManagement::BULLET_SPEED = 5.0f;

//=========================
// ˆø”•t‚«ƒRƒ“ƒXƒgƒ‰ƒNƒ^
//=========================
EnemyFireManagement::EnemyFireManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, int stage)
	:EnemyManagement(EnemyManagement::TYPE::FIRE, ENEMY_NUM[stage], ATTACK, BULLET_ATTACK),
	m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBullet(pDrawObject2)
{
	m_stage_num = stage;
	m_pEnemy = new EnemyNormal[ENEMY_NUM[stage]];
	m_pBullet = new Bullet[ENEMY_NUM[stage]];

	//”­Ë‰¹
	m_SE_15_1 = LoadSound((char*)"data\\SE\\1_15_1.wav");
}

//======================
// XVˆ—
//======================
void EnemyFireManagement::Update()
{
	m_FlameNum++; //ƒtƒŒ[ƒ€”‚ğ‘‰Á

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
	//¡‚¢‚é“G‚Ìˆ—
	for (int i = 0; i < GetObjNum(); i++) {
		m_tutorial_clear = false;
		m_pEnemy[i].Update();

		//‘ŞoŠÔ—ˆ‚½‚ç...
		if (m_pEnemy[i].GetAppearanceTime() > EXIT_TIME) {
			//Á‚¦‚Ä‚­
			m_pEnemy[i].OnAlphaFlag();
			if (m_pEnemy[i].GetAlpha() <= 0.0f) {
				DeleteObj(i);
			}
			continue;
		}

		//’e‚ğì‚é
		if (m_pEnemy[i].GetFlagBulletMake()) {
			Bullet temp(m_pDrawObjectBullet, m_pEnemy[i].GetPos(),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0.0f, BULLET_SPEED), 0.0f);
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemy[i].BulletMake();

			PlaySound(m_SE_15_1, 0);
		}
	}

	//¡‚¢‚é’e‚Ìˆ—
	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		//’e‚ÌXVˆ—
		m_pBullet[i].Update();

		//‰æ–ÊŠO‚©‚ço‚½‚çAŠÔŒo‰ß‚µ‚½‚ç...
		if (m_pBullet[i].GetScreenOut() || m_pBullet[i].GetTime() > BULLET_BREAK_TIME) {
			//’e‚ğÁ‚·
			DeleteBullet(i);
		}
	}
}

//==========================
// •`‰æˆ—
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
// “G‚ÌHP‚ğŒ¸‚ç‚·
//======================
bool EnemyFireManagement::ReduceHP(int index_num, int reduceHP)
{
	m_pEnemy[index_num].ReduceHP(reduceHP);

	if (m_pEnemy[index_num].GetHP() <= 0)
	{//HP‚ª‚OˆÈ‰º‚È‚ç“G‚ğÁ‚·

		return true;
	}
	return false;
}

//======================
// “G‚ğÁ‚·
//======================
void EnemyFireManagement::DeleteObj(int index_num)
{
	m_delete_enemy++;
	//“G‚ğÁ‚·
	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemy[i] = m_pEnemy[i + 1];
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
void EnemyFireManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < EnemyManagement::GetBulletNum() - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	EnemyManagement::IncreaseBulletNum(-1);
}