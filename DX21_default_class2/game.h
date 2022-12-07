//=======================================
// ゲーム画面関係(ヘッダファイル)
// 作成日：2022/07/14
// 作成者：高梨水希
//=======================================
#pragma once
#ifndef _GAME_H_
#define _GAME_H_

#include "main.h"
#include "sprite.h"
#include "BG.h"
#include "player.h"
#include "draw_object.h"
//#include "enemy_set_pos.h"
#include "management_enemy_normal.h"
#include "management_enemy_laser.h"
#include "management_enemy_gatoring.h"
#include "management_enemy_missile.h"
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
#include "management_meteo.h"
#include "management_enemy_public.h"
#include "player_center.h"
#include "management_enemy_attack.h"
#include "Bom.h"

class Game
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
		ENEMY_PUBLIC,
		ENEMY_ITEM,
		BULLET_CIRCLE_RED,
		BULLET_CIRCLE_GREEN,
		BULLET_SQUARE_GREEN,
		LASER,
		EXPLOSION,
		NUMBER,
		MULTIPLY,
		METEO,
		NUM
	};

	enum class DRAW_TYPE :int
	{
		PLAYER,
		PLAYER_HP_BAR,
		ENEMY_NOREMAL,
		ENEMY_LASER,
		ENEMY_GATORING,
		ENEMY_PUBLIC,
		ENEMY_METEO,
		ENEMY_ATTCK,
		ENEMY_ITEM,
		PLAYER_BULLET,
		BULLET_ENEMY,
		ENEMY_LASER_LASER,
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
		NUM
	};


	//メンバ変数
private:
	int m_BGM = 0;

	Score* m_pScore = nullptr;

	TextureUseful* m_pTexUseful = nullptr;
	DrawObject* m_pDrawObject = nullptr;

	BG* m_pBG = nullptr;
	Player* m_pPlayer = nullptr;
	EnemyNormalManagement* m_pEnemyNormalManagement = nullptr;
	EnemyLaserManagement* m_pEnemyLaserManagement = nullptr;
	EnemyGatoringManagement* m_pEnemyGatoringManagement = nullptr;
	EnemyMissileManagement* m_pEnemyMissileManagement = nullptr;
	EnemyAttackManagement* m_pEnemyAttackManagement = nullptr;
	Management_EnemyPublic* m_pEnemyPublicManagement = nullptr;
	Management_Meteo* m_pMeteoManagement = nullptr;
	PlayerHP* m_pPlayerHP = nullptr;
	ExplosionManagement* m_pExplosionManagement = nullptr;
	ItemManagement* m_pItemManagement = nullptr;

	PlayerLeft* m_pPlayerLeft = nullptr;
	PlayerRight* m_pPlayerRight = nullptr;
	PlayerCenter* m_pPlayerCenter = nullptr;

	Number* m_pRemaining_Left = nullptr;
	Number* m_pRemaining_Right = nullptr;
	Number* m_pRemaining_Center = nullptr;

	UI* m_pMultiply = nullptr;
	Number* m_pComboNum = nullptr;

	AllEnemyManagement* m_pAllEnemyManagement = nullptr;

	PlayerArmChange* m_pPlayerArmChange = nullptr;	//腕の交換

	CollisionAll* m_pColAll = nullptr;		//全ての当たり判定

	Bom* m_pBom = nullptr;					//ボム

	//メンバ関数
public:
	Game();	//デフォルトコンストラクタ

	Game(Score* pNumber);

	~Game();	//デストラクタ

	//更新
	void Update(void);

	//描画
	void Draw(void)const;

	//スコアを返す
	int GetScore(void)const { return m_pScore->GetNumber(); }
};

void HitStop(int flame);

#endif // !_GAME_H_


