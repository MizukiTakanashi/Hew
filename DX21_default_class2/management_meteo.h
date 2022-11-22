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
	static const int MAX_NUM = 10;				//敵の最大数
	static const int APPEARANCE_TIME = 200;		//敵の出現スピード
	//メンバ変数
	Meteo* m_pMeteo = nullptr;
	DrawObject m_pDrawObjectMeteo;
	EnemySetPos m_pEnemySetPos;

	int m_count = 0;		//敵の出現速度

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
	void DeleteObj(int index_num, int reduceHP)override;

	//指定した番号の座標を返す(オーバーライド)
	const D3DXVECTOR2& GetObjPos(int index_num)const override { return m_pMeteo[index_num].GetPos(); }

	//指定した番号のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override { return m_pMeteo[index_num].GetSize(); }

};

