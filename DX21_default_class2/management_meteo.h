//=======================================
// 隕石の管理関係(ヘッダファイル)
// 作成日：2022/11/22
// 作成者：矢野翔大
//=======================================
#pragma once
#include"meteo.h"
#include "draw_object.h"
#include "management.h"
#include"enemy_set_pos.h"
#include "management_enemy.h"
class Management_Meteo:public EnemyManagement
{
public:
	//敵自身
	static const int ATTACK = 1;			//攻撃値
private:
	//敵自身
	static const int MAX_NUM = 12;				//敵の最大数
	static const int APPEARANCE_TIME = 200;		//敵の出現スピード
	//メンバ変数
	Meteo* m_pMeteo = nullptr;
	DrawObject m_pDrawObjectMeteo;
	EnemySetPos m_pEnemySetPos;

	//敵の配列
	D3DXVECTOR2 m_SetEnemy[MAX_NUM] = { D3DXVECTOR2(52.5f + (105 * 1 - 1), -Meteo::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 2 - 1), -Meteo::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 3 - 1), -Meteo::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 4 - 1), -Meteo::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 5 - 1), -Meteo::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 6 - 1), -Meteo::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 7 - 1), -Meteo::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 8 - 1), -Meteo::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 9 - 1), -Meteo::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 10 - 1), -Meteo::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 11 - 1), -Meteo::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 12 - 1), -Meteo::SIZE_Y / 2) };

	int m_SetEnemyTime[MAX_NUM] = { 60 * 3,
								60 * 6,
								60 * 9,
								60 * 12,
								60 * 15,
								60 * 18,
								60 * 21,
								60 * 24,
								60 * 27,
								60 * 30,
								60 * 33,
								60 * 36 };
public:
	//デフォルトコンストラクタ
	Management_Meteo() {
		m_pMeteo = new Meteo[MAX_NUM];
	}

	//引数付きコンストラクタ
	Management_Meteo(DrawObject& pDrawObject, EnemySetPos& pEnemySetPos);

	//デストラクタ
	~Management_Meteo() override { delete[]m_pMeteo; }

	//更新処理
	void Update(void);

	//描画処理
	void Draw(void)const;

	//指定した敵を消す
	bool ReduceHP(int index_num, int reduceHP)override;

	//指定した弾を消す
	void DeleteBullet(int index_num)override{}

	//指定した番号の座標を返す(オーバーライド)
	const D3DXVECTOR2& GetObjPos(int index_num)const override { return m_pMeteo[index_num].GetPos(); }

	//指定した番号のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override { return m_pMeteo[index_num].GetSize(); }

	//指定した番号の座標を返す(オーバーライド)
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return m_pMeteo[index_num].GetPos(); }

	//指定した番号のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override { return m_pMeteo[index_num].GetSize(); }

};

