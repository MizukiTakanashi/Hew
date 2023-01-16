#pragma once
//=======================================
// 水星のステージ関係(ヘッダファイル)
// 作成日：2022/12/15
// 作成者：高梨水希
//=======================================

#ifndef _STAGE_MERCURY_H_
#define _STAGE_MERCURY_H_

#include "main.h"
#include "sprite.h"
#include "BG.h"
#include "bg_planet.h"
#include "player.h"
#include "draw_object.h"
#include "management_enemy_barrier.h"
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
#include "collision_all.h"
#include "player_center.h"
#include "Bom.h"

class StageMercury
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
		BULLET_CIRCLE_RED,
		BULLET_CIRCLE_GREEN,
		BULLET_SQUARE_GREEN,
		BULLET_LASER,
		BARRIER,
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
		ENEMY_BARRIER,
		ENEMY_BARRIER_BARRIER,
		ENEMY_ITEM,
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
	EnemyBarrierManagement* m_pEnemyBarrierManagement = nullptr;

	PlayerHP* m_pPlayerHP = nullptr;
	ExplosionManagement* m_pExplosionManagement = nullptr;
	ItemManagement* m_pItemManagement = nullptr;

	PlayerLeft* m_pPlayerLeft = nullptr;
	PlayerRight* m_pPlayerRight = nullptr;
	PlayerCenter* m_pPlayerCenter = nullptr;

	UI* m_pMultiply = nullptr;
	UI* m_pFrame = nullptr;
	Number* m_pComboNum = nullptr;

	AllEnemyManagement* m_pAllEnemyManagement = nullptr;

	PlayerArmChange* m_pPlayerArmChange = nullptr;	//腕の交換

	CollisionAll* m_pColAll = nullptr;		//全ての当たり判定

	Bom* m_pBom = nullptr;					//ボム

	//メンバ関数
public:
	StageMercury(){}	//デフォルトコンストラクタ

	StageMercury(Score* pNumber);

	~StageMercury();	//デストラクタ

	//更新
	void Update(void);

	//描画
	void Draw(void)const;

	//スコアを返す
	int GetScore(void)const { return m_pScore->GetNumber(); }
};

void MercuryHitStop(int flame);
void MercuryBossDown();


#endif // !_STAGE_MERCURY_H_