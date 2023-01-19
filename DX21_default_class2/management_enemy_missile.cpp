//=======================================
// ミサイルの管理関係(cppファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#include "management_enemy_missile.h"
#define _USE_MATH_DEFINES
#include <math.h>

//==========================
// 定数の初期化
//==========================
const int EnemyMissileManagement::ENEMY_NUM[(int)STAGE::NUM] = { 5, 6, 6, 0 };
const float EnemyMissileManagement::BULLET_SIZE_X = 20.0f;
const float EnemyMissileManagement::BULLET_SIZE_Y = 20.0f;
const float EnemyMissileManagement::BULLET_SPEED = 5.0f;

//=========================
// 引数付きコンストラクタ
//=========================
EnemyMissileManagement::EnemyMissileManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, int stage)
	:EnemyManagement(EnemyManagement::TYPE::MISSILE, ENEMY_NUM[stage], ATTACK, BULLET_ATTACK),
	m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBullet(pDrawObject2)
{
	m_stage_num = stage;
	m_pEnemyMissile = new EnemyNormal[ENEMY_NUM[stage]];
	m_pBullet = new Bullet[ENEMY_NUM[stage]];
}

//======================
// 更新処理
//======================
void EnemyMissileManagement::Update(const D3DXVECTOR2& PlayerPos)
{
	m_FlameNum++; //フレーム数を増加

	int i = m_FlameNum;
	if (m_FlameNum == m_SetEnemyTime[m_stage_num][m_EnemyNum] && 
		m_EnemyNum < ENEMY_NUM[m_stage_num])
	{
		EnemyNormal temp(m_pDrawObjectEnemy, m_SetEnemy[m_stage_num][m_EnemyNum]);
		m_pEnemyMissile[GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		m_EnemyNum++;
	}

	//今いる敵の処理
	for (int i = 0; i < GetObjNum(); i++) {
		m_pEnemyMissile[i].Update();

		//弾を作る
		if (m_pEnemyMissile[i].GetFlagBulletMake()) {
			//プレイヤーの後を追うようにして、弾を生成
			D3DXVECTOR2 movTemp = PlayerPos - m_pEnemyMissile[i].GetPos();
			D3DXVECTOR2 rotposTemp = m_pEnemyMissile[i].GetPos() - PlayerPos;
			D3DXVec2Normalize(&movTemp, &movTemp);
			movTemp *= BULLET_SPEED;


			Bullet temp(m_pDrawObjectBullet, m_pEnemyMissile[i].GetPos(),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), movTemp, 0.0f);
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyMissile[i].BulletMake();
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
void EnemyMissileManagement::Draw(void)const
{
	for (int i = 0; i < EnemyMissileManagement::GetObjNum(); i++) {
		m_pEnemyMissile[i].Draw();
	}

	for (int i = 0; i < EnemyMissileManagement::GetBulletNum(); i++) {
		m_pBullet[i].Draw();
	}
}

//======================
// 敵のHPを減らす
//======================
bool EnemyMissileManagement::ReduceHP(int index_num, int reduceHP)
{
	m_pEnemyMissile[index_num].ReduceHP(reduceHP);
	if (m_pEnemyMissile[index_num].GetHP() <= 0)
	{//HPが０以下なら敵を消す


		return true;
	}
	return false;
}

//======================
// 弾を消す
//======================
void EnemyMissileManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < EnemyMissileManagement::GetBulletNum() - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	EnemyMissileManagement::IncreaseBulletNum(-1);
}