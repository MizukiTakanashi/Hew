//=======================================
// 普通の敵の管理関係(cppファイル)
// 作成日：2022/09/13
// 作成者：高梨水希
//=======================================
#include "management_enemy_icerain.h"
#include "sound.h"

//==========================
// 定数の初期化
//==========================
const float EnemyIceRainManagement::BULLET_SIZE_X = 20.0f;
const float EnemyIceRainManagement::BULLET_SIZE_Y = 50.0f;
const float EnemyIceRainManagement::BULLET_SPEED = 2.5f;

//=========================
// 引数付きコンストラクタ
//=========================
EnemyIceRainManagement::EnemyIceRainManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2)
	:EnemyManagement(ENEMY_NUM, ATTACK, BULLET_ATTACK), m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBullet(pDrawObject2)
{
	m_pEnemyIceRain = new EnemyIceRain[ENEMY_NUM];
	m_pBullet = new Bullet[ENEMY_NUM];

	//氷柱を降らせる音
	m_SE_13 = LoadSound((char*)"data\\SE\\1_13.wav");
	//SetVolume(m_SE_06, 0.4f);
}

//======================
// 更新処理
//======================
void EnemyIceRainManagement::Update(const D3DXVECTOR2& PlayerPos)
{
	m_FlameNum++; //フレーム数を増加

	if (m_FlameNum == m_SetEnemyTime[m_EnemyNum])
	{
		EnemyIceRain temp(m_pDrawObjectEnemy, m_SetEnemy[m_EnemyNum]);
		m_pEnemyIceRain[GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		m_EnemyNum++;
	}

	//今いる敵の処理
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemyIceRain[i].Update();

		//弾を作る
		if (m_pEnemyIceRain[i].GetFlagBulletMake())
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyIceRain[i].GetPos(),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 10.0f), 0.0f); 
			// 弾の大きさ								弾を撃つ方向		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyIceRain[i].BulletMake();

			PlaySound(m_SE_13, 0);
		}
		//弾を作る
		if (m_pEnemyIceRain[i].GetFlagBulletMake1())
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyIceRain[i].GetPos() + D3DXVECTOR2(30.0f, 0.0f), 
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 10.0f), 0.0f);
			// 弾の大きさ								弾を撃つ方向		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyIceRain[i].BulletMake1();
		}
		//弾を作る
		if (m_pEnemyIceRain[i].GetFlagBulletMake2())
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyIceRain[i].GetPos() + D3DXVECTOR2(-30.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 10.0f), 0.0f);
			// 弾の大きさ								弾を撃つ方向		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyIceRain[i].BulletMake2();
		}
		//弾を作る
		if (m_pEnemyIceRain[i].GetFlagBulletMake3())
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyIceRain[i].GetPos() + D3DXVECTOR2(50.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 10.0f), 0.0f);
			// 弾の大きさ								弾を撃つ方向		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyIceRain[i].BulletMake3();
		}
		//弾を作る
		if (m_pEnemyIceRain[i].GetFlagBulletMake4())
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyIceRain[i].GetPos() + D3DXVECTOR2(-50.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 10.0f), 0.0f);
			// 弾の大きさ								弾を撃つ方向		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyIceRain[i].BulletMake4();
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
// 敵のHPを減らす
//======================
bool EnemyIceRainManagement::ReduceHP(int index_num, int reduceHP)
{
	m_pEnemyIceRain[index_num].ReduceHP(reduceHP);

	if (m_pEnemyIceRain[index_num].GetHP() <= 0)
	{//HPが０以下なら敵を消す


		return true;
	}
	return false;
}

//==========================
// 敵を消す
//==========================
void EnemyIceRainManagement::DeleteObj(int index_num)
{
	m_delete_enemy++;
	//敵を消す
	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemyIceRain[i] = m_pEnemyIceRain[i + 1];
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
void EnemyIceRainManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < EnemyManagement::GetBulletNum() - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	EnemyManagement::IncreaseBulletNum(-1);
}