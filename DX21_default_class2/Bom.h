#pragma once

//=======================================
// ボム関係(ヘッダファイル)
// 作成日：2022/12/07
// 作成者：高梨水希
//=======================================

#ifndef _BOM_H_
#define _BOM_H_

#include "game_object.h"
#include "draw_object.h"
#include "sound.h"

class Bom :public GameObject
{
//定数
private:
	//ここで初期化
	static const int TIME_LIMIT = 60;	//ボムを出してる時間
	static const int ATTACK = 5;		//ボムの攻撃力
	static const int SAME_TIME = 30;	//R2とL2同時押しの範囲


//メンバ変数
private:
	int m_time = -1;	//ボムが出来てからの経過時間
	int m_num = 0;		//ボムの現在の数
	int m_num_max = 0;	//ボムの最大数
	int m_SE_17 = 0;	//爆発音2
	int m_right = 0;	//R2での押し間隔
	int m_left = 0;		//L2での押し間隔

//メンバ関数
public:
	//デフォルトコンストラクタ
	Bom() { 
		m_SE_17 = LoadSound((char*)"data\\SE\\1_17.wav");
	}	

	//引数付きコンストラクタ
	Bom(DrawObject& pDrawObject, int num_max)
		:GameObject(pDrawObject, D3DXVECTOR2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), 
			D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT), 0.0f), m_num_max(num_max) {
		m_SE_17 = LoadSound((char*)"data\\SE\\1_17.wav");
	}

	~Bom()override {}	//デストラクタ

	//更新処理
	void Update(void);

	//描画処理
	void BomDraw(void);

	//ボムが終わっているかどうかのフラグを返す
	bool IsBomb(void)const { 
		if (m_time == -1) {
			return false;
		}
		return true;
	}

	//ボムの攻撃力を返す
	int GetBombAttack(void)const { return ATTACK; }
};

#endif // !_BOM_H_