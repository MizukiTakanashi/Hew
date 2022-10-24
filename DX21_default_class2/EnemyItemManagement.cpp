//=======================================
// 普通の敵の管理関係(cppファイル)
// 作成日：2022/09/13
// 作成者：高梨水希
//=======================================
#include "EnemyItemManagemant.h"
#define _USE_MATH_DEFINES
#include <math.h>

//==========================
// 定数の初期化
//==========================
const float EnemyItemManagement::ENEMYITEM_SIZE_X = 40.0f;
const float EnemyItemManagement::ENEMYITEM_SIZE_Y = 40.0f;
const float EnemyItemManagement::ENEMYITEM_SPEED = 2.5f;

//=========================
// 引数付きコンストラクタ
//=========================
EnemyItemManagement::EnemyItemManagement(DrawObject& pDrawObject3, EnemySetPos& pEnemySetPos) 
	: m_pDrawObjectEnemyItem(pDrawObject3), m_pEnemySetPos(pEnemySetPos)
{
	m_pEnemyItem = new EnemyItem[MAX_NUM];
}

//======================
// 更新処理
//======================
void EnemyItemManagement::Update(const D3DXVECTOR2& PlayerPos)
{

	//今いる敵のアイテムの処理
	for (int i = 0; i < m_bullet_num; i++) {
		m_pEnemyItem[i].Update();
		//画面外から出たら...
		if (m_pEnemyItem[i].GetScreenOut()) {
			//敵のアイテムを消す
			DeleteEnemyItem(i);
		}
	}
}

//==========================
// 敵のアイテムの描画処理
//==========================
void EnemyItemManagement::Draw(void)const
{
	for (int i = 0; i < m_enemyitem_num; i++) {
		m_pEnemyItem[i].Draw();
	}
}


//======================
// 敵のアイテムを消す
//======================
void EnemyItemManagement::DeleteEnemyItem(int index_num)
{
	for (int i = index_num; i < m_bullet_num - 1; i++) {
		m_pEnemyItem[i] = m_pEnemyItem[i + 1];
	}
	m_bullet_num--;
}