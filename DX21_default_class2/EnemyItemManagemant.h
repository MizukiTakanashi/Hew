//=======================================
// 普通の敵の管理関係(ヘッダファイル)
// 作成日：2022/09/13
// 作成者：高梨水希
//=======================================
#pragma once

#ifndef _ENEMY_ITEM_MANAGEMENT_H_
#define _ENEMY_ITEM_MANAGEMENT_H_

#include "main.h"
#include "EnemyNormal.h"
#include "DrawObject.h"
#include "player.h"
#include "enemyitem.h"
#include "EnemySetPos.h"

class EnemyItemManagement
{
	//定数
private:
	//ここで初期化
	//敵自身
	static const int MAX_NUM = 10;			//敵の最大数
	//cppで初期化
	//敵のアイテム
	static const float ENEMYITEM_SIZE_X;	//サイズX
	static const float ENEMYITEM_SIZE_Y;	//サイズY
	static const float ENEMYITEM_SPEED;		//スピード

	//メンバ変数
	EnemyItem* m_pEnemyItem = nullptr;
	DrawObject m_pDrawObjectEnemyItem;
	EnemySetPos m_pEnemySetPos;

	int m_enemy_num = 0;		//敵の数
	int m_bullet_num = 0;		//弾の数
	int m_enemyitem_num = 0;	//敵のアイテムの数

	int m_count = 0;			//敵の出現速度

public:
	//デフォルトコンストラクタ
	EnemyItemManagement() {
		m_pEnemyItem = new EnemyItem[MAX_NUM];
	}

	//引数付きコンストラクタ
	EnemyItemManagement(DrawObject& pDrawObject3,EnemySetPos& pEnemySetPos);

	//更新処理
	void Update(const D3DXVECTOR2& PlayerPos);

	//描画処理
	void Draw(void)const;

	//=================================
	// 敵のアイテム
	// ================================
	//指定した敵のアイテムを消す
	void DeleteEnemyItem(int index_num);

	//現在の敵のアイテムを返す
	int GetEnemyItemNum(void)const { return m_enemyitem_num; }

	//指定した敵のアイテムの座標を返す
	const D3DXVECTOR2& GetEnemyItemPos(int index_num)const { return m_pEnemyItem[index_num].GetPos(); }

	//敵のアイテムのサイズを返す
	const D3DXVECTOR2& GetEnemyItemSize(void)const { return m_pEnemyItem[0].GetSize(); }
};

#endif // !_ENEMY_ITEM_MANAGEMENT_H_