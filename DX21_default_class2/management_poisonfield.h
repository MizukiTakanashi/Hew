//=======================================
// 毒沼の管理関係(ヘッダファイル)
// 作成日：2022/11/22
// 作成者：矢野翔大
//=======================================
#pragma once


#include "poisonfield.h"
#include "draw_object.h"

class Management_PoisonField
{
	//定数
public:
	//敵自身
	static const int ATTACK = 1;			//攻撃値

private:
	//敵自身
	static const int ENEMY_NUM = 19;		//敵の最大数


	//メンバ変数
private:
	PoisonField* m_pPoisonField[ENEMY_NUM];
	DrawObject m_pDrawObjectPoisonField;

	int m_FlameNum = 0;						//現在のフレーム数
	int m_EnemyNum = 0;						//現在の敵の数
	int m_EnemyMakedNum = 0;

	//敵の配列
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
		D3DXVECTOR2(71.0f + (142.0f * 5.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 6.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 7.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 8.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 0.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 1.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 2.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 2.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 8.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 0.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 6.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 4.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 3.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 4.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 5.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 0.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 1.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 7.0f), -PoisonField::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 8.0f), -PoisonField::SIZE_Y / 2)
	};

	int m_SetEnemyTime[ENEMY_NUM] = {
		60 * 20,
		60 * 20 + 1,
		60 * 20 + 2,
		60 * 20 + 3,
		60 * 30,
		60 * 30 + 1,
		60 * 30 + 2,
		60 * 65,
		60 * 65 + 1,
		60 * 70,
		60 * 70 + 1,
		60 * 80
	};


	//メンバ関数
public:
	//デフォルトコンストラクタ
	Management_PoisonField() {
		for (int i = 0; i < ENEMY_NUM; i++) {
			m_pPoisonField[i] = nullptr;
		}
	}

	//引数付きコンストラクタ
	Management_PoisonField(DrawObject& pDrawObject);

	//デストラクタ
	~Management_PoisonField() {
		for (int i = 0; i < ENEMY_NUM; i++) {
			if (m_pPoisonField[i] != nullptr) {
				delete m_pPoisonField[i];
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
		delete m_pPoisonField[index_num];
		m_pPoisonField[index_num] = nullptr;
		for (int i = index_num; i < m_EnemyNum - 1; i++) {
			m_pPoisonField[i] = m_pPoisonField[i + 1];
			m_pPoisonField[i + 1] = nullptr;
		}

		m_EnemyNum--;
	}

	//指定した番号の座標を返す(オーバーライド)
	const D3DXVECTOR2& GetObjPos(int index_num)const { return m_pPoisonField[index_num]->GetPos(); }

	//指定した番号のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const { return m_pPoisonField[index_num]->GetSize(); }

	//指定した番号の敵を止める
	void StopEnemy(int index_num, int time) { m_pPoisonField[index_num]->StopEnemy(time); }
};
