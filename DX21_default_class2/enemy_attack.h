//=======================================
// 普通の敵関係(ヘッダファイル)
// 作成日：2022/12/02
// 作成者：矢野翔大
//=======================================
#pragma once

#include "main.h"
#include "bullet.h"
#include "draw_object.h"
#include "game_object.h"

class EnemyAttack :public GameObject
{
	//定数
public:
	//cppで初期化
	static const float SIZE_X;			//サイズX
	static const float SIZE_Y;			//サイズY

	static const float STOP_POS_Y;		//敵が止まる場所

	static const float RANGE;			//敵が動く範囲

private:
	//ここで初期化
	static const int ATTACK_TIME = 300;	//弾の発射間隔

	//cppで初期化
	static const float SPEED_X;			//敵のスピードY
	static const float SPEED_Y;			//敵のスピードY
	static const int HP_MAX;			//敵のHP最大値
	D3DXVECTOR2 m_mov = D3DXVECTOR2(0.0f, 0.0f);	//移動量
	int m_time = 0;									//弾が出来てからの経過時間
	int explosion_time = 0;


	//メンバ変数
private:
	int m_attack_count = 0;				//突撃するまでのカウント
	bool m_attack_time = false;			//突撃するか否か
	bool m_Attack_time;
	float m_move_width = 0.0f;			//敵が動く時のcosカーブ
	float m_init_posx = 0.0f;			//敵の初期位置X

	bool m_enemyitem_make = false;		//アイテムを作るか否か

	int m_hp = HP_MAX;					//敵の現在のHP

	//メンバ関数
public:
	EnemyAttack() {}		//デフォルトコンストラクタ

	//引数付きコンストラクタ
	EnemyAttack(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:GameObject(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y)), m_init_posx(pos.x) {}

	~EnemyAttack()override {}	//デストラクタ

	void Update(void);	//更新処理

	//弾を作るか否かのフラグを返す
	bool GetFlagAttack()const { return m_attack_time; }
	bool GetFlagExplosion()const { return m_Attack_time; }

	//HPを減らす
	void ReduceHP(int amount) { m_hp -= amount; }

	//HPを返す
	int GetHP(void) { return m_hp; }

	//弾の移動を再セット(ホーミング弾用かな？)
	void SetMove(const D3DXVECTOR2& mov) { m_mov = mov; }

	//弾が出来てからの経過時間を返す

	//突撃してからの時間を返す
	int GetAttackTime(void)const { return m_Attack_time; }
};