//=======================================
// 火球の敵の管理関係(cppファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#include "management_enemy_fireball.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "sound.h"

//==========================
// 定数の初期化
//==========================
const float EnemyFireballManagement::BULLET_SIZE_X = 200.0f;
const float EnemyFireballManagement::BULLET_SIZE_Y = 200.0f;
const float EnemyFireballManagement::BULLET_SPEED = 5.0f;

//=========================
// 引数付きコンストラクタ
//=========================
EnemyFireballManagement::EnemyFireballManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2)
	:EnemyManagement(EnemyManagement::TYPE::FIREBALL, ENEMY_NUM, ATTACK, BULLET_ATTACK), 
	m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBullet(pDrawObject2)
{
	m_pEnemyNormal = new EnemyNormal[ENEMY_NUM];
	m_pBullet = new Bullet[ENEMY_NUM];

	//発射音
	m_SE_15_2 = LoadSound((char*)"data\\SE\\2_15_3.wav");
}

//======================
// 更新処理
//======================
void EnemyFireballManagement::Update(const D3DXVECTOR2& PlayerPos)
{
	m_FlameNum++; //フレーム数を増加

	if (m_FlameNum == m_SetEnemyTime[m_EnemyNum] && 
		m_EnemyNum < ENEMY_NUM)
	{
		EnemyNormal temp(m_pDrawObjectEnemy, m_SetEnemy[m_EnemyNum], D3DXVECTOR2(100.0f, 100.0f));
		m_pEnemyNormal[GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		m_EnemyNum++;
	}

	if (m_EnemyNum == ENEMY_NUM)
	{
		m_tutorial_clear = true;
	}

	//今いる敵の処理
	for (int i = 0; i < GetObjNum(); i++) {
		m_tutorial_clear = false;
		m_pEnemyNormal[i].Update();

		//退出時間来たら...
		if (m_pEnemyNormal[i].GetAppearanceTime() > EXIT_TIME) {
			//消えてく
			m_pEnemyNormal[i].OnAlphaFlag();
			if (m_pEnemyNormal[i].GetAlpha() <= 0.0f) {
				DeleteObj(i);
			}
			continue;
		}

		//弾を作る
		if (m_pEnemyNormal[i].GetFlagBulletMake()) {
			//プレイヤーの後を追うようにして、弾を生成
			D3DXVECTOR2 movTemp = PlayerPos - m_pEnemyNormal[i].GetPos();
			D3DXVECTOR2 rotposTemp = m_pEnemyNormal[i].GetPos() - PlayerPos;
			D3DXVec2Normalize(&movTemp, &movTemp);
			movTemp *= BULLET_SPEED;

			Bullet temp(m_pDrawObjectBullet, m_pEnemyNormal[i].GetPos(),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), movTemp, 0.0f);
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyNormal[i].BulletMake();

			PlaySound(m_SE_15_2, 0);
		}

		//画面外に出たら消す
		if (m_pEnemyNormal[i].GetScreenOut()) {
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
void EnemyFireballManagement::Draw(void)const
{
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemyNormal[i].Draw();
	}

	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		m_pBullet[i].Draw();
	}
}

//======================
// 敵のHPを減らす
//======================
bool EnemyFireballManagement::ReduceHP(int index_num, int reduceHP)
{
	m_pEnemyNormal[index_num].ReduceHP(reduceHP);

	if (m_pEnemyNormal[index_num].GetHP() <= 0)
	{//HPが０以下なら敵を消す
  
		return true;
	}
	return false;
}

//======================
// 敵を消す
//======================
void EnemyFireballManagement::DeleteObj(int index_num)
{
	m_delete_enemy++;
	//敵を消す
	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemyNormal[i] = m_pEnemyNormal[i + 1];
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
void EnemyFireballManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < EnemyManagement::GetBulletNum() - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	EnemyManagement::IncreaseBulletNum(-1);
}