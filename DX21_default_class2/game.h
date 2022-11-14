//=======================================
// ゲーム画面関係(ヘッダファイル)
// 作成日：2022/07/14
// 作成者：高梨水希
//=======================================

#ifndef _GAME_H_
#define _GAME_H_

#include "main.h"
#include "sprite.h"
#include "BG.h"
#include "player.h"
#include "draw_object.h"
#include "enemy_set_pos.h"
#include "management_enemy_normal.h"
#include "management_enemy_laser.h"
#include "management_enemy_gatoring.h"
#include "texture_useful.h"
#include "player_hp.h"
#include "management_explosion.h"
#include "score.h"
#include "player_left.h"
#include "player_right.h"
#include "management_item.h"
//#include "collision_arm_enemy.h"
#include "all_enemy_management.h"
//#include "collision_player_arm_enemy.h"
//#include "collision_arm_all_enemy.h"
#include "player_arm_change.h"
#include "collision_all.h"

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
		ENEMY_ITEM,
		BULLET,
		LASER,
		EXPLOSION,
		NUM
	};

	enum class DRAW_TYPE :int
	{
		PLAYER,
		PLAYER_HP_BAR,
		PLAYER_HP_FRAME,
		ENEMY_NOREMAL,
		ENEMY_LASER,
		ENEMY_GATORING,
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
		NUM
	};


//メンバ変数
private:
	int m_BGM = 0;

	TextureUseful* m_pTexUseful = nullptr;
	DrawObject* m_pDrawObject = nullptr;

	Score* m_pNumber = nullptr;

	BG* m_pBG = nullptr;
	Player* m_pPlayer = nullptr;
	EnemySetPos* m_pEnemySetPos = nullptr;
	EnemyNormalManagement* m_pEnemyNormalManagement = nullptr;
	EnemyLaserManagement* m_pEnemyLaserManagement = nullptr;
	EnemyGatoringManagement* m_pEnemyGatoringManagement = nullptr;
	PlayerHP* m_pPlayerHP = nullptr;
	ExplosionManagement* m_pExplosionManagement = nullptr;
	ItemManagement* m_pItemManagement = nullptr;
	//ArmAllEnemyCollision* m_pArmAllEnemyCollision = nullptr;
	//ArmEnemyCollision* m_ArmEnemyCollision = nullptr;

	PlayerLeft* m_pPlayerLeft = nullptr;
	PlayerRight* m_pPlayerRight = nullptr;

	AllEnemyManagement* m_pAllEnemyManagement = nullptr;

	//PlayerArmEnemyCol* m_pArmEnemyCol = nullptr;	//プレイヤーの腕と全敵の当たり判定
	PlayerArmChange* m_pPlayerArmChange = nullptr;	//腕の交換

	CollisionAll* m_pColAll = nullptr;				//全ての当たり判定

//メンバ関数
public:
	Game();	//デフォルトコンストラクタ

	Game(Score* pNumber);

	~Game();	//デストラクタ

	//更新
	void Update(void);

	//描画
	void Draw(void)const;
};
#endif // !_GAME_H_
