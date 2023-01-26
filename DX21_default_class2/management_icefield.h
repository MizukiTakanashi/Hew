#pragma once
//=======================================
// 水星の氷ギミックの管理関係(ヘッダファイル)
// 作成日：2022/11/22
// 作成者：矢野翔大
//=======================================
#include "icefield.h"
#include "draw_object.h"

class Management_IceField
{
//定数
public:
	//敵自身
	static const int ATTACK = 1;			//攻撃値
	static const int SLOW_TIME = 60 * 3;	//プレイヤーを遅くする時間

private:
	//敵自身
	static const int ENEMY_NUM = 13;		//敵の最大数


	//メンバ変数
private:
	IceField* m_pIceField[ENEMY_NUM];
	DrawObject m_pDrawObjectIceField;

	int m_FlameNum = 0;						//現在のフレーム数
	int m_EnemyNum = 0;						//現在の敵の数
	int m_EnemyMakedNum = 0;

	//敵の配列
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
		D3DXVECTOR2(52.5f + (105 * 7), -IceField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 3), -IceField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 4), -IceField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 5), -IceField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 2), -IceField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 8), -IceField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 0), -IceField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 1), -IceField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 2), -IceField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 6), -IceField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 7), -IceField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 8), -IceField::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 3), -IceField::SIZE_Y / 2)
	};

	int m_SetEnemyTime[ENEMY_NUM] = {
		60 * 15,
		60 * 40,
		60 * 40 + 1,
		60 * 40 + 2,
		60 * 85,
		60 * 85 + 1,
		60 * 125,
		60 * 125 + 1,
		60 * 125 + 2,
		60 * 125 + 3,
		60 * 125 + 4,
		60 * 125 + 5,
		60 * 155
	};


	//メンバ関数
public:
	//デフォルトコンストラクタ
	Management_IceField() {
		for (int i = 0; i < ENEMY_NUM; i++) {
			m_pIceField[i] = nullptr;
		}
	}

	//引数付きコンストラクタ
	Management_IceField(DrawObject& pDrawObject);

	//デストラクタ
	~Management_IceField() {
		for (int i = 0; i < ENEMY_NUM; i++) {
			if (m_pIceField[i] != nullptr) {
				delete m_pIceField[i];
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
		delete m_pIceField[index_num];
		m_pIceField[index_num] = nullptr;
		for (int i = index_num; i < m_EnemyNum - 1; i++) {
			m_pIceField[i] = m_pIceField[i + 1];
			m_pIceField[i + 1] = nullptr;
		}

		m_EnemyNum--;
	}

	//指定した番号の座標を返す(オーバーライド)
	const D3DXVECTOR2& GetObjPos(int index_num)const { return m_pIceField[index_num]->GetPos(); }

	//指定した番号のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const { return m_pIceField[index_num]->GetSize(); }

	//指定した番号の敵を止める
	void StopEnemy(int index_num, int time) { m_pIceField[index_num]->StopEnemy(time); }
};