//=======================================
// 普通の敵関係(ヘッダファイル)
// 作成日：2022/12/02
// 作成者：矢野翔大
//=======================================
#pragma once

#include "main.h"
#include "inh_enemy.h"

class EnemyAttack :public Inh_Enemy
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
	static const int HP_MAX = 1;			//敵のHP最大値

	//cppで初期化
	static const float SPEED_X;			//敵のスピードY
	static const float SPEED_Y;			//敵のスピードY

//メンバ変数
private:
	D3DXVECTOR2 m_mov = D3DXVECTOR2(0.0f, 0.0f);	//移動量
	int m_time = 0;					//弾が出来てからの経過時間
	int m_attack_count = 0;			//突撃するまでのカウント
	bool m_shot = false;			//突撃するか否か
	int explosion_time = 0;			//突撃してから爆発するまでの時間計算
	bool m_explosion = false;		//爆発するか否か
  
	//メンバ関数
public:
	EnemyAttack() {}		//デフォルトコンストラクタ

	//引数付きコンストラクタ
	EnemyAttack(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:Inh_Enemy(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y), HP_MAX) {}

	~EnemyAttack()override {}	//デストラクタ

	void Update(void);	//更新処理

	//弾を作るか否かのフラグを返す
	bool GetFlagAttack()const { return m_shot; }
	bool GetFlagExplosion()const { return m_explosion; }

	//弾の移動を再セット(ホーミング弾用かな？)
	void SetMove(const D3DXVECTOR2& mov) { m_mov = mov; }

	//突撃してからの時間を返す
	int GetAttackTime(void)const { return m_explosion; }
	//弾を作った
	void BulletMake() { m_bullet_make = false; }
	//弾を作るか否かのフラグを返す
	bool GetFlagBulletMake()const { return m_bullet_make; }
};