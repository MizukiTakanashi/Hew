//=======================================
// ボスクラス(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#pragma once

#ifndef _BOSS_H_
#define _BOSS_H_

#include "game_object.h"

class InhStage;
class BossPattern;
class BulletPattern;

class Boss :public GameObject
{
	//定数
public:
	//cppで初期化
	static const float SIZE_X;			//サイズX
	static const float SIZE_Y;			//サイズY
	static const float STOP_POS_Y;		//敵が止まる場所
	static const float RANGE;			//敵が動く範囲
	static const float SPEED_X;			//敵のスピードY

private:
	//ここで初期化
	static const int BULLET_TIME = 200;	//弾の発射間隔


	//cppで初期化
	static const float POS_X;			//ポジションX
	static const float POS_Y;			//ポジションY
	static const float SPEED_Y;			//敵のスピードY
	static const int INVINCIBLE_FLAME = 30;			//敵の無敵時間
	static const float ALPHA_SPEED;		//アルファ値変更スピード


	//メンバ変数
private:
	bool m_enemyitem_make = false;		//アイテムを作るか否か
	int m_hp = 0;						//敵の現在のHP
	int HP_MAX = 100;		//敵のHP最大値
protected:
	int m_bullet_count = 0;				//弾を発射するまでのカウント
	bool m_bullet_make = false;			//弾を作るか否か
	float m_move_width = 0.0f;			//敵が動く時のcosカーブ
	int m_invincible_flame = 0;			//無敵時間の残り
	float m_init_posx = 0.0f;			//敵の初期位置X
	int m_stop_time = 0; //敵のアップデートを止める時間
	int m_appearance_time = 0;			//出現してからのカウント
	float m_alpha = 1.0f;				//アルファ値
	bool m_alpha_flag = false;			//アルファ値を変えていいか
	InhStage* m_pStage = nullptr; 
	BossPattern* m_pBossPattern = nullptr;
	BulletPattern* m_pBulletPattern = nullptr;
	//メンバ関数
public:
	//デフォルトコンストラクタ
	Boss() {}

	//引数付きコンストラクタ
	Boss(DrawObject& pDrawObject, InhStage* pStage)
		: GameObject(pDrawObject, D3DXVECTOR2(POS_X, POS_Y), D3DXVECTOR2(SIZE_X, SIZE_Y)), m_hp(HP_MAX), m_init_posx(POS_X), m_pStage(pStage) {}

	//デストラクタ
	~Boss()override;

	//更新処理
	void Update(void);

	//弾を作るか否かのフラグを返す
	bool GetFlagBulletMake()const { return m_bullet_make; }

	//弾を作った
	void BulletMake() { m_bullet_make = false; }

	//HPを減らす
	void ReduceHP(int amount);

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
	
	
	//↓矢野の追加枠
	//ボスの行動パターンの変更
	void ChangeBossPattern(BossPattern* pBossPattern);

	//弾のパターンの変更
	void ChangeBulletPattern(BulletPattern* pBulletPattern);
	
	//ライフの最大値を返す
	int GetMaxLife(void) { return HP_MAX; }
};

#endif // !_BOSS_H_