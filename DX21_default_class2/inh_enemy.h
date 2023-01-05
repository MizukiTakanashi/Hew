//=======================================
// 継承用敵クラス(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#pragma once

#ifndef _INH_ENEMY_H_
#define _INH_ENEMY_H_

#include "game_object.h"

class Inh_Enemy :public GameObject
{
//定数
public:

private:
	//cppで初期化
	static const int INVINCIBLE_FLAME = 30;			//敵の無敵時間

//メンバ変数
private:
	bool m_enemyitem_make = false;		//アイテムを作るか否か
	int m_hp = 0;						//敵の現在のHP

protected:
	int m_bullet_count = 0;				//弾を発射するまでのカウント
	bool m_bullet_make = false;			//弾を作るか否か
	bool m_bullet_make1 = false;		//弾を作るか否か（氷の敵で使う）
	bool m_bullet_make2 = false;		//弾を作るか否か（氷の敵で使う）
	bool m_bullet_make3 = false;		//弾を作るか否か（氷の敵で使う）
	bool m_bullet_make4 = false;		//弾を作るか否か（氷の敵で使う）
	float m_move_width = 0.0f;			//敵が動く時のcosカーブ
	int m_invincible_flame = 0;			//無敵時間の残り
	float m_init_posx = 0.0f;			//敵の初期位置X
	int m_stop_time = 0; //敵のアップデートを止める時間

	int m_appearance_time = 0;			//出現してからのカウント
	float m_alpha = 1.0f;				//アルファ値
	bool m_alpha_flag = false;			//アルファ値を変えていいか



//メンバ関数
public:
	//デフォルトコンストラクタ
	Inh_Enemy() {}		

	//引数付きコンストラクタ
	Inh_Enemy(DrawObject& pDrawObject, const D3DXVECTOR2& pos, D3DXVECTOR2 size, int hp)
		:GameObject(pDrawObject, pos, size), m_hp(hp), m_init_posx(pos.x) {}

	//デストラクタ
	~Inh_Enemy()override {}	

	//更新処理
	virtual void Update(void) {}	

	//弾を作るか否かのフラグを返す
	bool GetFlagBulletMake()const { return m_bullet_make; }
	bool GetFlagBulletMake1()const { return m_bullet_make1; } //（氷の敵で使う）
	bool GetFlagBulletMake2()const { return m_bullet_make2; } //（氷の敵で使う）
	bool GetFlagBulletMake3()const { return m_bullet_make3; } //（氷の敵で使う）
	bool GetFlagBulletMake4()const { return m_bullet_make4; } //（氷の敵で使う）

	//弾を作った
	void BulletMake() { m_bullet_make = false; }
	void BulletMake1() { m_bullet_make1 = false; }
	void BulletMake2() { m_bullet_make2 = false; }
	void BulletMake3() { m_bullet_make3 = false; }
	void BulletMake4() { m_bullet_make4 = false; }

	//敵のアイテムを作るか否かのフラグを返す
	bool GetFlagEnemyItemMake()const { return m_enemyitem_make; }

	//敵のアイテムを作った
	void EnemyItemMake() { m_enemyitem_make = false; }

	//HPを減らす
	bool ReduceHP(int amount) 
	{
		if (m_invincible_flame <= 0)
		{
			m_hp -= amount;
			m_invincible_flame = INVINCIBLE_FLAME;

			return true;
		}
		else
		{
			return false;
		}
	}

	//HPを返す
	int GetHP(void) { return m_hp; }

	//敵を止める時間をセット
	void StopEnemy(int time) { m_stop_time = time; }

	//出現してからのカウントを数える
	int GetAppearanceTime(void)const { return m_appearance_time; }

	//アルファ値を帰るフラグをオン
	void OnAlphaFlag(void) { m_alpha_flag = true; }

	//現在のアルファ値を返す
	float GetAlpha(void)const { return m_alpha; }


};

#endif // !_INH_ENEMY_H_