//=======================================
// 普通の敵の管理関係(cppファイル)
// 作成日：2022/09/13
// 作成者：高梨水希
//=======================================
#include "EnemyGatoringManagement.h"
#define _USE_MATH_DEFINES
#include <math.h>

//==========================
// 定数の初期化
//==========================
const float EnemyGatoringManagement::BULLET_SIZE_X = 40.0f;
const float EnemyGatoringManagement::BULLET_SIZE_Y = 40.0f;
const float EnemyGatoringManagement::BULLET_SPEED = 2.5f;

//=========================
// 引数付きコンストラクタ
//=========================
EnemyGatoringManagement::EnemyGatoringManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, EnemySetPos& pEnemySetPos)
	:m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBullet(pDrawObject2), m_pEnemySetPos(pEnemySetPos)
{
	m_pEnemyNormal = new EnemyNormal[MAX_NUM];
	m_pBullet = new Bullet[MAX_NUM];
}

//======================
// 更新処理
//======================
void EnemyGatoringManagement::Update(const D3DXVECTOR2& PlayerPos)
{
	//時間が来たら敵を配置
	if (m_count++ > APPEARANCE_TIME && m_enemy_num != MAX_NUM) {
		//ランダムで出現位置を決める
		float x = rand() % (SCREEN_WIDTH - (int)EnemyNormal::SIZE_X / 2) + EnemyNormal::SIZE_X / 2;

		//フラグに応じて敵を作る
		if (m_pEnemySetPos.SetEnemy(D3DXVECTOR2(x, EnemyNormal::STOP_POS_Y), D3DXVECTOR2(EnemyNormal::SIZE_X + EnemyNormal::RANGE * 2, EnemyNormal::SIZE_Y))) {
			EnemyNormal temp(m_pDrawObjectEnemy, D3DXVECTOR2(x, -EnemyNormal::SIZE_Y / 2));
			m_pEnemyNormal[m_enemy_num] = temp;
			m_enemy_num++;
		}

		m_count = 0;
	}

	//今いる敵の処理
	for (int i = 0; i < m_enemy_num; i++) {
		m_pEnemyNormal[i].Update();

		//弾を作る
		if (m_pEnemyNormal[i].GetFlagBulletMake() && m_bullet_num != MAX_NUM) {
			//プレイヤーの後を追うようにして、弾を生成
			D3DXVECTOR2 movTemp = PlayerPos - m_pEnemyNormal[i].GetPos();
			D3DXVECTOR2 rotposTemp = m_pEnemyNormal[i].GetPos() - PlayerPos;
			D3DXVec2Normalize(&movTemp, &movTemp);
			movTemp *= BULLET_SPEED;

			float rotTemp = atan2(rotposTemp.y, rotposTemp.x) * (180 / M_PI) + 180.0f;

			Bullet temp(m_pDrawObjectBullet, m_pEnemyNormal[i].GetPos(),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), movTemp, rotTemp);
			m_pBullet[m_bullet_num] = temp;

			m_bullet_num++;

			m_pEnemyNormal[i].BulletMake();
		}
	}

	//今いる弾の処理
	for (int i = 0; i < m_bullet_num; i++) {
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
void EnemyGatoringManagement::Draw(void)const
{
	for (int i = 0; i < m_enemy_num; i++) {
		m_pEnemyNormal[i].Draw();
	}

	for (int i = 0; i < m_bullet_num; i++) {
		m_pBullet[i].Draw();
	}
}

//======================
// 敵を消す
//======================
void EnemyGatoringManagement::DeleteEnemy(int index_num)
{
	m_pEnemySetPos.DeleteEnemy(m_pEnemyNormal[index_num].GetPos());

	for (int i = index_num; i < m_enemy_num - 1; i++) {
		m_pEnemyNormal[i] = m_pEnemyNormal[i + 1];
	}
	m_enemy_num--;
}

//======================
// 弾を消す
//======================
void EnemyGatoringManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < m_bullet_num - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	m_bullet_num--;
}