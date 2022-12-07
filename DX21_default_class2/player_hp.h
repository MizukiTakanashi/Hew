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

//======================
// マクロ定義
//======================
#define PLAYER_HP_POS_Y (PLAYER_HP_SIZE_Y / 2 + PLAYER_HP_POS_SPACE_X)

class PlayerHP :public UI
{
private:
	//定数
	//cppで初期化
	static const float HP_MAX;			//最大HP
	static const float SIZE_X;			//サイズX
	static const float SIZE_Y;			//サイズY
	static const float POS_X;			//表示位置
	static const float POS_Y;			//表示位置
	static const float BET_X;			//ハートの表示間隔

	//無敵時間
	static const int INVINCIBLE__FRAME;


private:
	Player* m_pPlayer = nullptr; //プレイヤーのポインタ
	bool m_HP0 = false;				//プレイヤーのHPが0か判断
	float m_hp = HP_MAX;			//プレイヤーのHP
	int m_invincible = 0;			//無敵時間
	ExplosionManagement* m_pExplosionManagement = nullptr; //爆発管理のポインタ
	//Score* m_pScore = nullptr; //ナンバーのポインタ

public:
	PlayerHP() { m_hp = HP_MAX; }	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	PlayerHP(DrawObject& DrawObject1, ExplosionManagement* pEM, Player* pPlayer)
		:UI(DrawObject1, D3DXVECTOR2(POS_X, POS_Y),
			D3DXVECTOR2(SIZE_X, SIZE_Y)), m_pExplosionManagement(pEM), m_pPlayer(pPlayer){}

	~PlayerHP()override {}							//デストラクタ

	//更新処理
	void Update(void);

	//HPを減らす
	void ReduceHP(float reduce_num);

	//HPを回復
	void HeelHP(float heel_num);

	//描画
	void DrawHP(void)const;

	//HPが0になったかどうかのフラグを返す
	bool GetHP0Flag(void)const { return m_HP0; }

	//無敵時間開始
	void SetInvincibleFrame(void) { m_invincible = INVINCIBLE__FRAME; }

	//無敵かどうかを返す true:無敵じゃない  false:無敵
	bool IsPlayerInvincible(void) { if (m_invincible <= 0) { return true; }return false; }

};

#endif // !_PLAYER_HP_H_