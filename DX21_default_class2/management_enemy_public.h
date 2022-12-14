#pragma once
#include "enemy_public.h"
#include "draw_object.h"
#include "management.h"
#include "management_enemy.h"
class Management_EnemyPublic :public EnemyManagement
{
public:
	//敵自身
	static const int ATTACK = 1;			//攻撃値
private:
	//敵自身
	static const int ENEMY_NUM = 2;				//敵の最大数
	static const int APPEARANCE_TIME = 200;		//敵の出現スピード
	//メンバ変数
	EnemyPublic* m_pEnemyPublic = nullptr;
	DrawObject m_pDrawObjectEnemyPublic;

	//敵の配列
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
										D3DXVECTOR2(52.5f + (105 *  0), -EnemyPublic::SIZE_Y / 2),
										D3DXVECTOR2(52.5f + (105 * 11), -EnemyPublic::SIZE_Y / 2)
	};

	int m_SetEnemyTime[ENEMY_NUM] = {
								60 * 3,
								60 * 6,
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
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return m_pEnemyPublic[index_num].GetPos(); }

	//指定した番号のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override { return m_pEnemyPublic[index_num].GetSize(); }

	//指定した番号の敵を止める
	void StopEnemy(int index_num, int time) override { m_pEnemyPublic[index_num].StopEnemy(time); }


};

