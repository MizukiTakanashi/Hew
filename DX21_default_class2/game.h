//=======================================
// ゲーム画面関係(ヘッダファイル)
// 作成日：2022/07/14
// 作成者：高梨水希
//=======================================
#pragma once
#ifndef _GAME_H_
#define _GAME_H_

#include "inh_stage.h"

#include "collision_all.h"
#include "text_management.h"
#include "management_enemy_missile.h"
#include "management_enemy_laser.h"
#include "management_enemy_gatoring.h"
#include "all_enemy_management.h"


class Game : public InhStage
{
	//メンバ変数
private:
	EnemyMissileManagement* m_pEnemyMissileManagement = nullptr;
	EnemyLaserManagement* m_pEnemyLaserManagement = nullptr;
	EnemyGatoringManagement* m_pEnemyGatoringManagement = nullptr;
	AllEnemyManagement* m_pAllEnemyManagement = nullptr;
	CollisionAll* m_pColAll = nullptr;		//全ての当たり判定
	TextManagement* m_pTextManagement = nullptr; //チュートリアルテキスト

	//メンバ関数
public:
	Game(Score* pNumber);

	~Game();	//デストラクタ

	//更新
	void Update(void);

	//描画
	void Draw(void)const;

	//スコアを返す
	int GetScore(void)const { return m_pScore->GetNumber(); }
};

//チュートリアルテキスト関連
//テキスト開始
void StartTextG(void);
//テキスト終了
void EndTextG(void);
//
bool GetTextFlg(void);

#endif // !_GAME_H_


