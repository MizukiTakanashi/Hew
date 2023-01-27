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
#include "poorvision.h"


class InhStage
{
//定数
protected:
	//ここで初期化
	static const int NUMBER_DIGIT = 5;		//数字の桁
	static const int HIT_STOP_UNION = 30;	//合体したときのヒットストップ時間
	static const int HIT_STOP_TIME = 60 * 3;		//ゲームオーバーかゲームクリアしたときの時間
	static const int HIT_STOP_SLOW_INTERVAL = 7;	//ゆっくりになる

	//cppで初期化
	static const D3DXVECTOR2 NUMBER_SIZE;	//数字のサイズ
	static const D3DXVECTOR2 NUMBER_POS;	//数字の位置

	enum class TEXTURE_TYPE :int
	{//スラッシュが付いているところはInhStageで読み込み済み(各ステージで読み込む必要はない)
		NUMBER,//
		MULTIPLY,//
		FRAME,//
		PLAYER,//
		PLAYER_FIRE,
		PLAYER_HP,//
		EXPLOSION,//
		MOON,//月
		MARCURY,//水星
		VENUS,//金星
		MARS,//火星
		JUPITOR,//木星
		SATAURN,//土星
		SUN,//太陽

		ITEM_MISSILE,//
		ITEM_GATORING,//
		ITEM_LASER,//
		ITEM_BARRIER,//
		ITEM_ACID,//
		ITEM_STOP,//
		ITEM_HOTAIRLASER,//
		ITEM_ICERAIN,//
		ITEM_GRENADE,//
		ITEM_ICE,//
		ITEM_POISONLASER,//
		ITEM_FIRE,//
		ITEM_FIREBALL,//

		ENEMY_ITEM,//
		ENEMY_NORMAL,//
		ENEMY_LASER,//
		ENEMY_GATORING,//
		ENEMY_BARRIER,//
		ENEMY_ICE,//
		ENEMY_STOP,//
		ENEMY_MEGUMIN,
		ENEMY_FIREBALL,
		ENEMY_GREANADE,
		ENEMY_METEO,
		ENEMY_POOR,
		ENEMY_SPEEDDOWN,
		ENEMY_ACID,
		ENEMY_FIRE,
		ENEMY_PUBLIC,
		POISON,
		FIREFIELD,
		ICEFIELD,

		BULLET_CIRCLE_RED,//
		BULLET_CIRCLE_GREEN,//
		BULLET_LASER,
		BULLET_BARRIER,//
		BULLET_STOP,//
		BULLET_ICE,//
		BULLET_FIREBALL,
		BULLET_FIRE,
		BULLET_MIST,
		BULLET_MEGUMIN,
		BULLET_ACID,

		GIMMICK_MARS,
		BOM,

		NUM
	};

	enum class DRAW_TYPE :int
	{
		PLAYER,//
		PLAYER_FIRE,
		PLAYER_HP_BAR,//
		NUMBER,//
		MULTIPLY,//
		BOMB,//
		FRAME,//
		EXPLOSION,//
		MOON,//月
		MARCURY,//水星
		VENUS,//金星
		MARS,//火星
		JUPITOR,//木星
		SATAURN,//土星
		SUN,//太陽

		ITEM_MISSILE,//
		ITEM_GATORING,//
		ITEM_LASER,//
		ITEM_BARRIER,//
		ITEM_ACID,//
		ITEM_STOP,//
		ITEM_HOTAIRLASER,//
		ITEM_ICERAIN,//
		ITEM_GRENADE,//
		ITEM_ICE,//
		ITEM_POISONLASER,//
		ITEM_FIRE,//
		ITEM_FIREBALL,//

		ENEMY_ITEM,//
		ENEMY_NORMAL,//
		ENEMY_LASER,//
		ENEMY_GATORING,//
		ENEMY_BARRIER,//
		ENEMY_ICE,//
		ENEMY_STOP,//
		ENEMY_METEO,
		ENEMY_MEGUMIN,
		ENEMY_FIREBALL,
		ENEMY_ACID,
		ENEMY_FIRE,
		ENEMY_POOR,
		ENEMY_SPEEDDOWN,
		ENEMY_GRENADE,
		ENEMY_GRENADE_EXPLOSION,
		ENEMY_PUBLIC,
		POISON,
		FIREFIELD,
		ICEFIELD,

		BULLET_ENEMY,//
		BULLET_LASER,
		BULLET_BARRIER,//
		BULLET_STOP,//
		BULLET_ICE,//
		BULLET_FIREBALL,
		BULLET_MIST,
		BULLET_SPEEDDOWN,
		BULLET_ACID,
		BULLET_FIRE,
		BULLET_MEGUMIN,

		PLAYER_ARM_BULLET,//
		PLAYER_ARM_LASER,//
		PLAYER_BULLET,//
		PLAYER_ARM_GRENADE_EXPLOSION,

		GIMMICK_MARS,

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
	PoorVision* m_pPoorvision = nullptr;
	Player* m_pPlayer = nullptr;
	PlayerHP* m_pPlayerHP = nullptr;
	ExplosionManagement* m_pExplosionManagement = nullptr;
	ItemManagement* m_pItemManagement = nullptr;
	PlayerLeft* m_pPlayerLeft = nullptr;
	PlayerRight* m_pPlayerRight = nullptr;
	PlayerCenter* m_pPlayerCenter = nullptr;
	UI* m_pFrame = nullptr;
	UI* m_pMultiply = nullptr;
	UI* m_pStageMoon = nullptr;//月
	UI* m_pStageMarcury = nullptr;//水星
	UI* m_pStageVenus = nullptr;//金星
	UI* m_pStageMars = nullptr;//火星
	UI* m_pStageJupitor = nullptr;//木星
	UI* m_pStageSataurn = nullptr;//土星
	UI* m_pStageSun = nullptr;//太陽
	Number* m_pComboNum = nullptr;
	PlayerArmChange* m_pPlayerArmChange = nullptr;	//腕の交換
	Bom* m_pBom = nullptr;					//ボム
	Management_Meteo* m_pMeteoManagement = nullptr;

	//ゲームオーバーかクリア時
	bool m_GameoverHitstop = true;	//ゲームオーバー時のヒットストップ
	bool m_GameclearHitstop = true;	//ゲームクリア時のヒットストップ
	int m_HitStopSlow = -1;			//ちょっとゆっくりになる

//メンバ関数
public:
	InhStage(Score* pNumber);

	virtual ~InhStage();	//デストラクタ

	//更新
	virtual void Update(void) = 0;

	//描画
	virtual void Draw(void)const = 0;

	//スコアを返す
	int GetScore(void)const { return m_pScore->GetNumber(); }

	void HitStop(int flame) { m_StopFlame = flame; }
	void BossDown() { m_isBossDown = true; }

	void SetPoorVision() { m_pPoorvision->SetPV(); }
};

