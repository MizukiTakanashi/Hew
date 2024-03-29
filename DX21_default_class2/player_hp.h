//=======================================
// プレイヤーのHP関係(ヘッダファイル)
// 作成日：2022/09/17
// 作成者：高梨水希
//=======================================
#pragma once

#ifndef _PLAYER_HP_H_
#define _PLAYER_HP_H_

#include "draw_object.h"
#include "UI.h"
#include "management_explosion.h"
#include "player.h"

class InhStage;

//======================
// マクロ定義
//======================
#define PLAYER_HP_POS_Y (PLAYER_HP_SIZE_Y / 2 + PLAYER_HP_POS_SPACE_X)

class PlayerHP :public UI
{
//定数
private:
	//cppで初期化
	static const float HP_MAX;			//最大HP
	static const D3DXVECTOR2 SIZE;		//サイズX
	static const float POS_X;			//表示位置
	static const float POS_Y;			//表示位置
	static const float BET_X;			//ハートの表示間隔

	static const float FIRE_REDUCE;		//炎状態の際のHPの減少具合

	//ここで初期化
	static const int INVINCIBLE__FRAME = 60 * 3;	//無敵時間
	static const int NONE_DRAW_INTERVAL = 10;		//プレイヤーを消す
	static const int FIRE_DAMAGE_SOUND_INTERVAL = 60 * 3;	//炎ダメージの音の間隔時間

//メンバー変数
private:
	Player* m_pPlayer = nullptr;	//プレイヤーのポインタ
	bool m_HP0 = false;				//プレイヤーのHPが0か判断
	float m_hp = HP_MAX;			//プレイヤーのHP
	int m_invincible = 0;			//無敵時間
	ExplosionManagement* m_pExplosionManagement = nullptr; //爆発管理のポインタ

	InhStage* m_pStage = nullptr;	//ヒットストップ用のステージのポインタ

	int m_nodraw = NONE_DRAW_INTERVAL;	//プレイヤーを表示するか否か

	bool m_fire = false;			//炎状態フラグ
	int m_sound_interval = 60 * 1;	//炎状態の際の音の間隔	

	int m_SE_04 = 0;				//プレイヤーダメージ音
	int m_SE_24 = 0;				//プレイヤー炎ダメージ音

//メンバー関数
public:
	//引数付きコンストラクタ
	PlayerHP(DrawObject& DrawObject1, ExplosionManagement* pEM, Player* pPlayer, InhStage* pStage);

	~PlayerHP()override {}							//デストラクタ

	//更新処理
	void Update(void);

	//HPを減らす
	void ReduceHP(float reduce_num);

	//HPを回復
	void HeelHP(float heel_num);

	//描画
	void DrawHP(void);

	//HPが0になったかどうかのフラグを返す
	bool GetHP0Flag(void)const { return m_HP0; }

	//無敵時間開始
	void SetInvincibleFrame(void) { m_invincible = INVINCIBLE__FRAME; }

	//無敵かどうかを返す true:無敵じゃない  false:無敵
	bool IsPlayerInvincible(void) { 
		if (m_invincible <= 0) { return true; }
		return false; 
	}

	bool IsDrawPlayer(void) { 
		if (m_invincible > 0 && m_nodraw < 0) { return false; }
		return true;
	}

	//炎状態をセットする
	void SetFire(bool fire) { m_fire = fire; }

	//炎状態かどうかを返す
	bool IsFire(void)const { return m_fire; }
};

#endif // !_PLAYER_HP_H_