//=======================================
// 継承用のステージ関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#pragma once

#include "main.h"
#include "sprite.h"
#include "texture_useful.h"
#include "draw_object.h"
#include "BG.h"
#include "bg_planet.h"
#include "number.h"
#include "score.h"
#include "player.h"
#include "player_hp.h"
#include "player_left.h"
#include "player_right.h"
#include "player_center.h"
#include "player_arm_change.h"
#include "Bom.h"
#include "management_item.h"
#include "management_explosion.h"
#include "management_meteo.h"


class InhStage
{
//定数
protected:
	//ここで初期化
	static const int NUMBER_DIGIT = 5;		//数字の桁

	//cppで初期化
	static const D3DXVECTOR2 NUMBER_SIZE;	//数字のサイズ
	static const D3DXVECTOR2 NUMBER_POS;	//数字の位置

	enum class TEXTURE_TYPE :int
	{
		NUMBER,
		MULTIPLY,
		FRAME,
		PLAYER,
		PLAYER_HP,
		EXPLOSION,

		ENEMY_ITEM,
		ENEMY_NORMAL,
		ENEMY_LASER,
		ENEMY_GATORING,
		ENEMY_MEGUMIN,
		ENEMY_BARRIER,
		ENEMY_FIREBALL,
		ENEMY_GREANADE,
		ENEMY_METEO,
		ENEMY_ICE,	//氷の敵のテクスチャセット
		ENEMY_STOP,

		BULLET_CIRCLE_RED,
		BULLET_CIRCLE_GREEN,
		BULLET_SQUARE_GREEN,
		BULLET_LASER,
		BULLET_STOP,
		BULLET_ICE,	//氷の弾のテクスチャセット
		BULLET_FIREBALL,
		BULLET_MEGUMIN,
		BULLET_BARRIER,
		NUM
	};

	enum class DRAW_TYPE :int
	{
		PLAYER,
		PLAYER_HP_BAR,
		NUMBER,
		MULTIPLY,
		BOMB,						//爆弾
		FRAME,
		EXPLOSION,

		ENEMY_ITEM,
		ENEMY_METEO,
		ENEMY_NORMAL,
		ENEMY_LASER,
		ENEMY_GATORING,
		ENEMY_MEGUMIN,
		ENEMY_FIREBALL,
		ENEMY_ICE,
		ENEMY_STOP,
		ENEMY_GRENADE,
		ENEMY_BARRIER,
		ENEMY_GRENADE_EXPLOSION,

		BULLET_STOP,
		BULLET_FIREBALL,
		BULLET_MEGUMIN,
		BULLET_LASER,
		BULLET_ENEMY,
		BULLET_ENEMY_ICE,
		BULLET_BARRIER,

		PLAYER_ARM_ENEMY,
		PLAYER_ARM_BULLET,
		PLAYER_ARM_LASER,
		PLAYER_ARM_GRENADE_EXPLOSION,
		PLAYER_BULLET,

		NUM
	};


//メンバ変数
protected:
	int m_StopFlame = 0;
	bool m_isBossDown = false;

	int m_BGM = 0;

	Score* m_pScore = nullptr;
	TextureUseful* m_pTexUseful = nullptr;
	DrawObject* m_pDrawObject = nullptr;
	BG* m_pBG = nullptr;
	BGPlanet* m_pBG_Moon = nullptr;
	Player* m_pPlayer = nullptr;
	PlayerHP* m_pPlayerHP = nullptr;
	ExplosionManagement* m_pExplosionManagement = nullptr;
	ItemManagement* m_pItemManagement = nullptr;
	PlayerLeft* m_pPlayerLeft = nullptr;
	PlayerRight* m_pPlayerRight = nullptr;
	PlayerCenter* m_pPlayerCenter = nullptr;
	UI* m_pFrame = nullptr;
	UI* m_pMultiply = nullptr;
	Number* m_pComboNum = nullptr;
	PlayerArmChange* m_pPlayerArmChange = nullptr;	//腕の交換
	Bom* m_pBom = nullptr;					//ボム
	Management_Meteo* m_pMeteoManagement = nullptr;

//メンバ関数
public:
	InhStage(Score* pNumber);

	~InhStage();	//デストラクタ

	//更新
	virtual void Update(void) = 0;

	//描画
	virtual void Draw(void)const = 0;

	//スコアを返す
	int GetScore(void)const { return m_pScore->GetNumber(); }

	void HitStop(int flame) { m_StopFlame = flame; }
	void BossDown() { m_isBossDown = true; }
};

