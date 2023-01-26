#pragma once
//=======================================
// 水星の炎ギミックの管理関係(ヘッダファイル)
// 作成日：2022/11/22
// 作成者：矢野翔大
//=======================================
#include "firefield.h"
#include "draw_object.h"

class Management_FireField
{
	//定数
public:
	//敵自身
	static const int ATTACK = 1;			//攻撃値

private:
	//敵自身
	static const int ENEMY_NUM = 9;				//敵の最大数


	//メンバ変数
private:
	FireField* m_pFireField[ENEMY_NUM];
	DrawObject m_pDrawObjectFireField;

	int m_FlameNum = 0;						//現在のフレーム数
	int m_EnemyNum = 0;						//現在の敵の数
	int m_EnemyMakedNum = 0;

	//敵の配列
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
		D3DXVECTOR2(71.0f + (142 * 1), -FireField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 0), -FireField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 1), -FireField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 7), -FireField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 8), -FireField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 0), -FireField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 6), -FireField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 4), -FireField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 5), -FireField::SIZE_Y / 2)
	};

	int m_SetEnemyTime[ENEMY_NUM] = {
		60 * 15,
		60 * 45,
		60 * 45 + 1,
		60 * 45 + 2,
		60 * 45 + 3,
		60 * 85,
		60 * 85 + 1,
		60 * 130,
		60 * 155
	};


	//メンバ関数
public:
	//デフォルトコンストラクタ
	Management_FireField() {
		for (int i = 0; i < ENEMY_NUM; i++) {
			m_pFireField[i] = nullptr;
		}
	}

	//引数付きコンストラクタ
	Management_FireField(DrawObject& pDrawObject);

	//デストラクタ
	~Management_FireField() {
		for (int i = 0; i < ENEMY_NUM; i++) {
			if (m_pFireField[i] != nullptr) {
				delete m_pFireField[i];
			}
		}
	}

	//更新処理
	void Update(void);

	//描画処理
	void Draw(void)const;

	//隕石の攻撃値を返す
	int GetPoisonFieldAttack(void)const { return ATTACK; }

	//隕石の数を返す
	int GetPoisonFieldNum(void)const { return m_EnemyNum; }

	//隕石の数を変動する
	void AddPoisonFieldNum(int num) { m_EnemyNum += num; }

	//指定した敵を消す
	void DeleteObj(int index_num) {
		delete m_pFireField[index_num];
		m_pFireField[index_num] = nullptr;
		for (int i = index_num; i < m_EnemyNum - 1; i++) {
			m_pFireField[i] = m_pFireField[i + 1];
			m_pFireField[i + 1] = nullptr;
		}

		m_EnemyNum--;
	}

	//指定した番号の座標を返す(オーバーライド)
	const D3DXVECTOR2& GetObjPos(int index_num)const { return m_pFireField[index_num]->GetPos(); }

	//指定した番号のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const { return m_pFireField[index_num]->GetSize(); }

	//指定した番号の敵を止める
	void StopEnemy(int index_num, int time) { m_pFireField[index_num]->StopEnemy(time); }
};
