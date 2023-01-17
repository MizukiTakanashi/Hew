#pragma once
//=======================================
// 土星のステージ関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================

#ifndef _STAGE_SATURN_H_
#define _STAGE_SATURN_H_

#include "main.h"
#include "sprite.h"
#include "BG.h"
#include "bg_planet.h"
#include "player.h"
#include "draw_object.h"
#include "texture_useful.h"
#include "player_hp.h"
#include "management_explosion.h"
#include "score.h"
#include "number.h"
#include "player_left.h"
#include "player_right.h"
#include "management_item.h"
#include "all_enemy_management.h"
#include "player_arm_change.h"
#include "player_center.h"
#include "Bom.h"

#include "saturn_collision_all.h"

#include "management_enemy_laser.h"
#include "management_enemy_megumin.h"

class StageSaturn
{
//定数
private:
	//ここで初期化
	static const int NUMBER_DIGIT = 10;		//数字の桁

	//cppで初期化
	static const D3DXVECTOR2 NUMBER_SIZE;	//数字のサイズ
	static const D3DXVECTOR2 NUMBER_POS;	//数字の位置

	enum class TEXTURE_TYPE :int
	{
		PLAYER,
		PLAYER_HP,
		ENEMY,
		ENEMY_ITEM,
		ENEMY_BARRIER,
		ENEMY_MEGUMIN,
		BULLET_MEGUMIN,
		BULLET_CIRCLE_RED,
		BULLET_CIRCLE_GREEN,
		BULLET_SQUARE_GREEN,
		ENEMY_LASER,
		BULLET_LASER,
		EXPLOSION,
		NUMBER,
		MULTIPLY,
		FRAME,
		NUM
	};

	enum class DRAW_TYPE :int
	{
		PLAYER,
		PLAYER_HP_BAR,
		ENEMY_BARRIER_BARRIER,
		ENEMY_ITEM,
		ENEMY_LASER,
		ENEMY_MEGUMIN,
		BULLET_MEGUMIN,
		BULLET_LASER,
		PLAYER_BULLET,
		BULLET_ENEMY,
		EXPLOSION,
		PLAYER_ARM_LEFT,
		PLAYER_ARM_LEFT_BULLET,
		PLAYER_ARM_LEFT_LASER,
		PLAYER_ARM_RIGHT,
		PLAYER_ARM_RIGHT_BULLET,
		PLAYER_ARM_RIGHT_LASER,
		PLAYER_ARM_CENTER,
		PLAYER_ARM_CENTTER_BULLET,
		PLAYER_ARM_CENTER_LASER,
		NUMBER,
		MULTIPLY,
		BOMB,						//爆弾
		FRAME,
		NUM
	};


//メンバ変数
private:
	int m_BGM = 0;

	Score* m_pScore = nullptr;

	TextureUseful* m_pTexUseful = nullptr;
	DrawObject* m_pDrawObject = nullptr;

	BG* m_pBG = nullptr;
	BGPlanet* m_pBG_Moon = nullptr;
	Player* m_pPlayer = nullptr;

	//敵
	EnemyLaserManagement* m_pEnemyLaserManagement = nullptr;
	EnemyMeguminManagement* m_pEnemyMeguminManagement = nullptr;

	PlayerHP* m_pPlayerHP = nullptr;
	ExplosionManagement* m_pExplosionManagement = nullptr;
	ItemManagement* m_pItemManagement = nullptr;

	PlayerLeft* m_pPlayerLeft = nullptr;
	PlayerRight* m_pPlayerRight = nullptr;
	PlayerCenter* m_pPlayerCenter = nullptr;

	UI* m_pFrame = nullptr;
	UI* m_pMultiply = nullptr;
	Number* m_pComboNum = nullptr;

	AllEnemyManagement* m_pAllEnemyManagement = nullptr;

	PlayerArmChange* m_pPlayerArmChange = nullptr;	//腕の交換

	SaturnCollisionAll* m_pColAll = nullptr;		//全ての当たり判定

	Bom* m_pBom = nullptr;					//ボム


//メンバ関数
public:
	StageSaturn(){}	//デフォルトコンストラクタ

	StageSaturn(Score* pNumber);

	~StageSaturn();	//デストラクタ

	//更新
	void Update(void);

	//描画
	void Draw(void)const;

	//スコアを返す
	int GetScore(void)const { return m_pScore->GetNumber(); }
};

void SaturnHitStop(int flame);
void SaturnBossDown();


#endif // !_STAGE_SATURN_H_