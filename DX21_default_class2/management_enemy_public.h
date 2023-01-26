#pragma once
#include "enemy_public.h"
#include "draw_object.h"
#include "management.h"
#include "management_enemy.h"

class Management_EnemyPublic :public EnemyManagement
{
//定数
public:
	//敵自身
	static const int ATTACK = 1;			//攻撃値
	//弾
	static const int BULLET_ATTACK = 1;		//攻撃値

private:
	//敵自身
	static const int ENEMY_NUM = 12;				//敵の最大数
	

//メンバ変数
private:
	EnemyPublic* m_pEnemyPublic = nullptr;
	DrawObject m_pDrawObjectEnemyPublic;

	//敵の配列
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
		D3DXVECTOR2(71.0f + (142 * 0), -EnemyPublic::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 2), -EnemyPublic::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 6), -EnemyPublic::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 8), -EnemyPublic::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 1), -EnemyPublic::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 7), -EnemyPublic::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 2), -EnemyPublic::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 6), -EnemyPublic::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 0), -EnemyPublic::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 8), -EnemyPublic::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 1), -EnemyPublic::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 7), -EnemyPublic::SIZE_Y / 2)
	};

	int m_SetEnemyTime[ENEMY_NUM] = {
		60 * 1,
		60 * 1 + 1,
		60 * 1 + 2,
		60 * 1 + 3,
		60 * 80,
		60 * 80 + 1,
		60 * 85,
		60 * 85 + 1,
		60 * 155,
		60 * 155 + 1,
		60 * 160,
		60 * 160 + 1
	};

public:
	//デフォルトコンストラクタ
	Management_EnemyPublic() {
		m_pEnemyPublic = new EnemyPublic[ENEMY_NUM];
	}

	//引数付きコンストラクタ
	Management_EnemyPublic(DrawObject& pDrawObject);

	//デストラクタ
	~Management_EnemyPublic() override { delete[]m_pEnemyPublic; }

	//更新処理
	void Update(void);

	//描画処理
	void Draw(void)const;

	//指定した敵のHPを減らす
	bool ReduceHP(int index_num, int reduceHP)override;

	//指定した敵を消す
	void DeleteObj(int index_num)override;

	//指定した弾を消す
	void DeleteBullet(int index_num)override {}
	
	//指定した番号の座標を返す(オーバーライド)
	const D3DXVECTOR2& GetObjPos(int index_num)const override { return m_pEnemyPublic[index_num].GetPos(); }

	//指定した番号のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override { return m_pEnemyPublic[index_num].GetSize(); }
	
	//指定した番号の座標を返す(オーバーライド)
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return D3DXVECTOR2(-30.0f, -30.0f); }

	//指定した番号のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override { return D3DXVECTOR2(0.0f, 0.0f); }

	//指定した番号の敵を止める
	void StopEnemy(int index_num, int time) override { m_pEnemyPublic[index_num].StopEnemy(time); }


};

