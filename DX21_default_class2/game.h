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
#include "texture_useful.h"
#include "PlayerHP.h"
#include "ExplosionManagement.h"
#include "PlayerEnemyNormalCollision.h"
#include "number.h"
#include "playerleft.h"
#include "playerright.h"

class Game
{
//定数
private:
	//ここで初期化
	static const int NUMBER_DIGIT = 3;

	//cppで初期化
	static const D3DXVECTOR2 NUMBER_SIZE;	//数字のサイズ
	static const D3DXVECTOR2 NUMBER_POS;	//数字の位置


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
	PlayerHP* m_pPlayerHP = nullptr;
	ExplosionManagement* m_pExplosionManagement = nullptr;

	PlayerEnemyNormalCollision* m_pPlayerEnemyNormalCol = nullptr;

	PlayerLeft* m_pPlayerLeft = nullptr;
	PlayerRight* m_pPlayerRight = nullptr;

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
