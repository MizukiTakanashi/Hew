#pragma once
#include "main.h"
#include "management_enemy.h"
#include "enemy_attack.h"
#include "draw_object.h"


class EnemyAttackManagement :public EnemyManagement
{
	//定数
private:
	//ここで初期化
	//敵自身
	static const int ENEMY_NUM = 12;		//敵を出現させる数

	static const float ATTACK_SPEED;		//スピード

public:
	//ここで初期化
	//敵自身
	static const int ATTACK = 1;			//攻撃値


	//メンバ変数
private:
	EnemyAttack* m_pEnemyAttack = nullptr;
	DrawObject m_pDrawObjectEnemy;

	int m_EnemyItem_num = 0;	//敵のアイテムの数

	//敵の配列
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
										 D3DXVECTOR2(52.5f + (105 * 1 - 1), -EnemyAttack::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 12 - 1), -EnemyAttack::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 2 - 1), -EnemyAttack::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 10 - 1), -EnemyAttack::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 10 - 1), -EnemyAttack::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 3 - 1), -EnemyAttack::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 2 - 1), -EnemyAttack::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 11 - 1), -EnemyAttack::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 1 - 1), -EnemyAttack::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 2 - 1), -EnemyAttack::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 11 - 1), -EnemyAttack::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 12 - 1), -EnemyAttack::SIZE_Y / 2)
	};
	//敵を出す時間
	int m_SetEnemyTime[ENEMY_NUM] = {
								60 * 10,
								60 * 10 + 1,
								60 * 15,
								60 * 20,
								60 * 30,
								60 * 40 + 1,
								60 * 60,
								60 * 60 + 1,
								60 * 70,
								60 * 70 + 1,
								60 * 70 + 2,
								60 * 70 + 3
	};
	//メンバ関数
public:
	//デフォルトコンストラクタ
	EnemyAttackManagement() {
		m_pEnemyAttack = new EnemyAttack[ENEMY_NUM];
	}

	//引数付きコンストラクタ
	EnemyAttackManagement(DrawObject& pDrawObject1);

	//デストラクタ
	~EnemyAttackManagement()override {  }

	//更新処理
	void Update(const D3DXVECTOR2& PlayerPos);

	//描画処理
	void Draw(void)const;

	//指定したのHPを減らす
	bool ReduceHP(int index_num, int reduceHP)override;

	//指定した番号の座標を返す(オーバーライド)
	const D3DXVECTOR2& GetObjPos(int index_num)const override { return m_pEnemyAttack[index_num].GetPos(); }

	//指定した番号のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override { return m_pEnemyAttack[index_num].GetSize(); }
	//指定した弾の座標を返す
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return D3DXVECTOR2(-330, -300); }

	//弾のサイズを返す
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override { return D3DXVECTOR2(-330, -300); }

	//指定した敵を消す
	void DeleteObj(int index_num)override;

	//指定した弾を消す
	void DeleteBullet(int index_num)override {}
};
