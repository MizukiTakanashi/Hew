//=======================================
// 敵の配置場所関係(ヘッダファイル)
// 作成日：2022/09/14
// 作成者：高梨水希
//=======================================
#pragma once

#ifndef _ENEMY_SET_POS_H_
#define _ENEMY_SET_POS_H_

#include "main.h"
#include "collision.h"

class EnemySetPos
{
private:
	//定数
	static const int ENEMY_SET_POS_MAX_NUM = 150;

private:
	D3DXVECTOR2 m_pos[ENEMY_SET_POS_MAX_NUM];
	D3DXVECTOR2 m_size[ENEMY_SET_POS_MAX_NUM];
	int m_index_num = 0;

public:
	EnemySetPos(){}		//デフォルトコンストラクタ

	~EnemySetPos(){}	//デストラクタ

	//敵を配置
	bool SetEnemy(const D3DXVECTOR2& pos, const D3DXVECTOR2& size);

	//敵を削除
	void DeleteEnemy(const D3DXVECTOR2& pos);
};

#endif // !_ENEMY_SET_POS_H_