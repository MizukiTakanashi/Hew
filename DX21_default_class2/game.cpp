//=======================================
// ゲーム画面関係(cppファイル)
// 作成日：2022/07/14
// 作成者：高梨水希
//=======================================
#include "game.h"
#include "scene.h"
#include "sound.h"

//==========================
// グローバル変数
//==========================
bool isText = false; //チュートリアルテキスト用

//=========================
// 引数付きコンストラクタ
//=========================
Game::Game(Score* pNumber) :InhStage(pNumber)
{
	m_pBG_Moon = new BGPlanet((char*)"data\\texture\\moon.png");
	m_pTextManagement = new TextManagement();

	//=======================
	// レーザー
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_LASER].SetTextureName((char*)"data\\texture\\laser00.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_LASER]);

	
	//隕石
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_METEO].SetTextureName((char*)"data\\texture\\Meteo.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_METEO].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_METEO], 2.0f, 1.0, 1.0f, 3);

	m_pEnemyMissileManagement = new EnemyMissileManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_NORMAL], m_pDrawObject[(int)DRAW_TYPE::BULLET_ENEMY], 0);
	m_pEnemyLaserManagement = new EnemyLaserManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_LASER], m_pDrawObject[(int)DRAW_TYPE::BULLET_LASER], 0);
	m_pEnemyGatoringManagement = new EnemyGatoringManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_GATORING], m_pDrawObject[(int)DRAW_TYPE::BULLET_ENEMY]);
	m_pMeteoManagement = new Management_Meteo(m_pDrawObject[(int)DRAW_TYPE::ENEMY_METEO]);



	//敵の管理
	m_pAllEnemyManagement = new AllEnemyManagement;
	m_pAllEnemyManagement->AddPointer(m_pEnemyMissileManagement);
	m_pAllEnemyManagement->AddPointer(m_pEnemyLaserManagement);
	m_pAllEnemyManagement->AddPointer(m_pEnemyGatoringManagement);

	//========================================================
	// 全ての当たり判定
	m_pColAll = new CollisionAll(CollisionAll::STAGE::MOON, m_pPlayer, m_pPlayerLeft, m_pPlayerRight, m_pExplosionManagement,
		m_pItemManagement, m_pScore, m_pBom);
	m_pColAll->SetMeteo(m_pMeteoManagement);

	//敵のポインタをセット（順番変えるのNG）
	m_pColAll->AddEnemyPointer(m_pEnemyMissileManagement);
	m_pColAll->AddEnemyPointer(m_pEnemyLaserManagement);
	m_pColAll->AddEnemyPointer(m_pEnemyGatoringManagement);
	//m_pColAll->AddEnemyPointer(m_pMeteoManagement);
}

//==========================
// 終了処理
//==========================
Game::~Game()
{
	delete m_pAllEnemyManagement;
	delete m_pColAll;
	delete m_pEnemyMissileManagement;
	delete m_pEnemyLaserManagement;
	delete m_pEnemyGatoringManagement;
	delete m_pTextManagement;
}

//======================
// 更新処理
//======================
void Game::Update(void)
{
	//ヒットストップ
	if (m_StopFlame > 0)
	{
		m_StopFlame--;
		return;
	}

	//チュートリアルテキスト
	m_pTextManagement->Update();
	if (isText)
	{
		return;
	}

	//背景
	m_pBG->Update();
	m_pBG_Moon->Update();

	//腕の切り替え
	m_pPlayerArmChange->Change();

	//プレイヤー
	m_pPlayer->Update(m_pPlayerHP->IsPlayerInvincible());

	m_pPlayerHP->Update();

	//爆発
	m_pExplosionManagement->Update();

	//敵から落ちるアイテム
	m_pItemManagement->Update();

	//ボム
	m_pBom->Update();

	//=======================
	// 敵
	m_pEnemyMissileManagement->Update(m_pPlayer->GetPos());
	m_pEnemyLaserManagement->Update();
	m_pEnemyGatoringManagement->Update(m_pPlayer->GetPos());
	m_pMeteoManagement->Update();


	//====================================
	//プレイヤーのHPに対する処理
	int attack_num = 0;

	//プレイヤーの腕

	//ホーミング弾用
	D3DXVECTOR2 temp_pos = m_pAllEnemyManagement->GetCloltestEnemyPos(m_pPlayerLeft->GetPos());

	//腕のアップデート
	m_pPlayerLeft->ButtonPress();
	m_pPlayerLeft->Update(m_pPlayer->GetPos(), temp_pos);
	m_pPlayerRight->ButtonPress();
	m_pPlayerRight->Update(m_pPlayer->GetPos(), temp_pos);
	m_pPlayerCenter->ButtonPress();
	m_pPlayerCenter->Update(m_pPlayer->GetPos(), temp_pos);

	//敵とプレイヤーの当たり判定
	attack_num += m_pColAll->Collision();

	//回復
	m_pColAll->HeelCollision();

	//プレイヤーのHPを攻撃数によって減らす
	if (attack_num != 0) {
		m_pPlayerHP->ReduceHP((float)attack_num);
	}

	//プレイヤーのHPが0になったら...
	if (m_pPlayerHP->GetHP0Flag()) {
		//リザルト画面に行く
		SetStageClear(false);
		Fade(SCENE::SCENE_RESULT, STAGE::STAGE_MOON);
	}

	//最後の列の敵を全て倒したら
	if (m_pEnemyMissileManagement->IsClear() && m_pEnemyLaserManagement->IsClear() &&
		m_pEnemyGatoringManagement->IsClear()) {
		//リザルト画面に行く
		SetStageClear(true);
		Fade(SCENE::SCENE_RESULT, STAGE::STAGE_MOON);
	}
}

//==========================
// 描画処理
//==========================
void Game::Draw(void)const
{
	m_pBG->DrawBG();
	m_pBG_Moon->DrawBG();
	m_pFrame->Draw();
	m_pPlayer->Draw();

	//プレイヤーの腕の描画処理
	m_pPlayerLeft->ArmDraw();
	m_pPlayerRight->ArmDraw();
	m_pPlayerCenter->ArmDraw();

	//敵の描画
	m_pEnemyMissileManagement->Draw();
	m_pEnemyLaserManagement->Draw();
	m_pEnemyGatoringManagement->Draw();
	m_pMeteoManagement->Draw();

	//プレイヤーの弾の表示
	m_pPlayer->DrawBullet();

	m_pExplosionManagement->Draw();

	m_pItemManagement->Draw();

	//ボムの描画
	m_pBom->BomDraw();

	//UIの描画
	m_pPlayerHP->DrawHP();
	m_pScore->DrawNumber();
	m_pComboNum->SetNumber(m_pScore->GetComboNum());
	m_pComboNum->DrawNumber();
	m_pMultiply->Draw();

	if (isText)
	{
		m_pTextManagement->Draw();
	}
}


void StartTextG(void)
{
	isText = true;
}

void EndTextG(void)
{
	isText = false;
}

bool GetTextFlg(void)
{
	return isText;
}
