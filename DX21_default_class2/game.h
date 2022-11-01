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
#include "DrawObject.h"
#include "EnemySetPos.h"
#include "EnemyNormalManagement.h"
#include "enemylasermanagement.h"
#include "texture_useful.h"
#include "PlayerHP.h"
#include "ExplosionManagement.h"
#include "PlayerEnemyNormalCollision.h"
#include "playerenemylasercollision.h"
#include "number.h"
#include "playerleft.h"
#include "playerright.h"
#include "ItemManagement.h"
#include "ArmEnemyCollision.h"
#include "EnemyManagement.h"
#include "AllEnemyManagement.h"

class Game
{
//定数
private:
	//ここで初期化
	static const int NUMBER_DIGIT = 3;

	//cppで初期化
	static const D3DXVECTOR2 NUMBER_SIZE;	//数字のサイズ
	static const D3DXVECTOR2 NUMBER_POS;	//数字の位置

	enum class TEXTURE_TYPE :int
	{
		TEXTURE_TYPE_PLAYER,
		TEXTURE_TYPE_PLAYER_ARM,
		TEXTURE_TYPE_PLAYER_HP,
		TEXTURE_TYPE_ENEMY1,
		TEXTURE_TYPE_BULLET,
		TEXTURE_TYPE_LASER,
		TEXTURE_TYPE_EXPLOSION,
		TEXTURE_TYPE_NUM
	};

	enum class DRAW_TYPE :int
	{
		DRAW_TYPE_PLAYER,
		DRAW_TYPE_PLAYER_BULLET,
		DRAW_TYPE_PLAYER_ARM_RIGHT,
		DRAW_TYPE_PLAYER_ARM_LEFT,
		DRAW_TYPE_PLAYER_HP,
		DRAW_TYPE_PLAYER_HP_FRAME,
		DRAW_TYPE_ENEMY_ITEM_EXPLOSION,
		DRAW_TYPE_ENEMY1,
		DRAW_TYPE_ENEMY1_BULLET,
		DRAW_TYPE_ENEMY2,
		DRAW_TYPE_ENEMY2_LASER,
		DRAW_TYPE_BULLET,
		DRAW_TYPE_LASER,
		DRAW_TYPE_EXPLOSION,
		DRAW_TYPE_NUM
	};


//メンバ変数
private:
	int m_BGM = 0;

	TextureUseful* m_pTexUseful = nullptr;
	DrawObject* m_pDrawObject = nullptr;

	Number* m_pNumber = nullptr;

	BG* m_pBG = nullptr;
	Player* m_pPlayer = nullptr;
	EnemySetPos* m_pEnemySetPos = nullptr;
	EnemyNormalManagement* m_pEnemyNormalManagement = nullptr;
	EnemyLaserManagement* m_pEnemyLaserManagement = nullptr;
	PlayerHP* m_pPlayerHP = nullptr;
	ExplosionManagement* m_pExplosionManagement = nullptr;
	ItemManagement* m_pItemManagement = nullptr;
	PlayerEnemyNormalCollision* m_pPlayerEnemyNormalCol = nullptr;
	PlayerEnemyLaserCollision* m_pPlayerEnemyLaserCol = nullptr;

	ArmEnemyCollision* m_ArmEnemyCollision = nullptr;

	PlayerLeft* m_pPlayerLeft = nullptr;
	PlayerRight* m_pPlayerRight = nullptr;

	EnemyManagement* m_pEnemyManagement[2];	//敵の管理用
	AllEnemyManagement* m_pAllEnemyManagement = nullptr;
	
public:
	Game();	//デフォルトコンストラクタ

	Game(Number* pNumber);

	~Game();	//デストラクタ

	//更新
	void Update(void);

	//描画
	void Draw(void)const;
};
#endif // !_GAME_H_
