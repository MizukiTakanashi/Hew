//=======================================
// 隕石の管理関係(ヘッダファイル)
// 作成日：2022/11/22
// 作成者：矢野翔大
//=======================================
#pragma once

#ifndef _MANAGEMENT_METEO_H_
#define _MANAGEMENT_METEO_H_

#include "meteo.h"
#include "draw_object.h"

class Management_Meteo
{
//定数
public:
	//敵自身
	static const int ATTACK = 1;			//攻撃値

private:
	//敵自身
	static const int ENEMY_NUM = 6;				//敵の最大数


//メンバ変数
private:	
	Meteo* m_pMeteo[ENEMY_NUM];
	DrawObject m_pDrawObjectMeteo;

	int m_FlameNum = 0;						//現在のフレーム数
	int m_EnemyNum = 0;						//現在の敵の数
	int m_EnemyMakedNum = 0;

	//敵の配列
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
		D3DXVECTOR2(52.5f + (105 * 1), -Meteo::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 9), -Meteo::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 1), -Meteo::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 9), -Meteo::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 1), -Meteo::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 9), -Meteo::SIZE_Y / 2)
	};

	int m_SetEnemyTime[ENEMY_NUM] = {
		60 * 35,
		60 * 35 + 1,
		60 * 55,
		60 * 55 + 1,
		60 * 70,
		60 * 70 + 1,
	};


//メンバ関数
public:
	//デフォルトコンストラクタ
	Management_Meteo() {
		for (int i = 0; i < ENEMY_NUM; i++) {
			m_pMeteo[i] = nullptr;
		}
	}

	//引数付きコンストラクタ
	Management_Meteo(DrawObject& pDrawObject);

	//デストラクタ
	~Management_Meteo() {
		for (int i = 0; i < ENEMY_NUM; i++) {
			if (m_pMeteo[i] != nullptr) {
				delete m_pMeteo[i];
			}
		}
	}

	//更新処理
	void Update(void);

	//描画処理
	void Draw(void)const;

	//隕石の攻撃値を返す
	int GetMeteoAttack(void)const { return ATTACK; }

	//隕石の数を返す
	int GetMeteoNum(void)const { return m_EnemyNum; }

	//隕石の数を変動する
	void AddMeteoNum(int num) { m_EnemyNum += num; }

	//指定した敵を消す
	void DeleteObj(int index_num) {
		delete m_pMeteo[index_num];
		m_pMeteo[index_num] = nullptr;
		for (int i = index_num; i < m_EnemyNum - 1; i++) {
			m_pMeteo[i] = m_pMeteo[i + 1];
			m_pMeteo[i + 1] = nullptr;
		}

		m_EnemyNum--;
	}

	//指定した番号の座標を返す(オーバーライド)
	const D3DXVECTOR2& GetObjPos(int index_num)const { return m_pMeteo[index_num]->GetPos(); }

	//指定した番号のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const { return m_pMeteo[index_num]->GetSize(); }

	//指定した番号の敵を止める
	void StopEnemy(int index_num, int time) { m_pMeteo[index_num]->StopEnemy(time); }
};

#endif // !_MANAGEMENT_METEO_H_