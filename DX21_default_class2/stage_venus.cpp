//=======================================
// 金星のステージ関係(cppファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#include "stage_venus.h"
#include "sound.h"

//==========================
// 引数付きコンストラクタ
//==========================
StageVenus::StageVenus(Score* pNumber):InhStage(pNumber)
{
	//画像読み込み
	m_pBG_Moon = new BGPlanet((char*)"data\\texture\\venus.png");

	//=======================
	// 敵
	//火球の敵
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_FIREBALL].SetTextureName((char*)"data\\texture\\enemy_fireball.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_FIREBALL].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_FIREBALL]);
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_FIREBALL].SetTextureName((char*)"data\\texture\\sun.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_FIREBALL].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_FIREBALL]);

	m_pEnemyFireballManagement = new EnemyFireballManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_FIREBALL], m_pDrawObject[(int)DRAW_TYPE::BULLET_FIREBALL]);

	//酸性雨の敵
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_ACID].SetTextureName((char*)"data\\texture\\enemy_acid.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_ACID].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_ACID]);
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_ACID].SetTextureName((char*)"data\\texture\\bullet_acid.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_ACID].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_ACID]);

	m_pEnemyAcidManagement = new EnemyAcidManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_ACID], m_pDrawObject[(int)DRAW_TYPE::BULLET_ACID]);

	//視界を悪くする敵
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_POOR].SetTextureName((char*)"data\\texture\\enemy_poorvision.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_POOR].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_POOR]);
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_MIST].SetTextureName((char*)"data\\texture\\bullet_mist.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_MIST].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_MIST]);

	m_pEnemuPoorvisionManagement = new EnemyPoorvisionManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_POOR], m_pDrawObject[(int)DRAW_TYPE::BULLET_MIST]);

	//プレイヤーのスピードを遅くする敵
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_SPEEDDOWN].SetTextureName((char*)"data\\texture\\enemy_speeddown.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_SPEEDDOWN].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_SPEEDDOWN]);
	m_pDrawObject[(int)DRAW_TYPE::BULLET_SPEEDDOWN].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_MIST], 1.0f, 1.0f, 1.0f, 1, D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));

	m_pEnemySpeeddownManagement = new EnemySpeeddownManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_SPEEDDOWN], m_pDrawObject[(int)DRAW_TYPE::BULLET_SPEEDDOWN]);


	//敵の管理
	//m_pAllEnemyManagement->AddPointer(m_pEnemyFireballManagement);
	

	//敵のポインタをセット（順番変えるのNG）
	//m_pColAll->AddEnemyPointer(m_pEnemyFireballManagement);
}

//==========================
// デストラクタ
//==========================
StageVenus::~StageVenus()
{
	delete m_pEnemyFireballManagement;
	delete m_pEnemuPoorvisionManagement;
	delete m_pEnemySpeeddownManagement;
	delete m_pEnemyAcidManagement;
	delete m_pColAll;
}

//==========================
// 更新処理
//==========================
void StageVenus::Update(void)
{
	//ヒットストップ
	if (m_StopFlame > 0)
	{
		m_StopFlame--;
		return;
	}

	//ボスが死んだら
	if (m_isBossDown)
	{
		SetStageClear(true);
		Fade(SCENE::SCENE_RESULT, STAGE::STAGE_VENUS);
	}

	//背景
	m_pBG->Update();
	m_pBG_Moon->Update();

	//腕の切り替え
	m_pPlayerArmChange->Change();

	//プレイヤー
	m_pPlayer->Update(m_pPlayerHP->IsPlayerInvincible());
	m_pPoorvision->Update(m_pPlayer->GetPos());

	m_pPlayerHP->Update();

	//爆発
	m_pExplosionManagement->Update();

	//敵から落ちるアイテム
	m_pItemManagement->Update();

	//=======================
	// 敵
	m_pEnemyFireballManagement->Update(m_pPlayer->GetPos());
	m_pEnemyAcidManagement->Update();
	m_pEnemuPoorvisionManagement->Update();
	m_pEnemySpeeddownManagement->Update();

	//ボム
	m_pBom->Update();

	//====================================
	//プレイヤーのHPに対する処理
	int attack_num = 0;

	//プレイヤーの腕

	//腕のアップデート
	m_pPlayerLeft->ButtonPress();
	m_pPlayerLeft->Update(m_pPlayer->GetPos(), D3DXVECTOR2(0.0f, 0.0f));
	m_pPlayerRight->ButtonPress();
	m_pPlayerRight->Update(m_pPlayer->GetPos(), D3DXVECTOR2(0.0f, 0.0f));
	m_pPlayerCenter->ButtonPress();
	m_pPlayerCenter->Update(m_pPlayer->GetPos(), D3DXVECTOR2(0.0f, 0.0f));

	//敵とプレイヤーの当たり判定
	//attack_num += m_pColAll->Collision();

	//回復
	//m_pColAll->HeelCollision();

	//プレイヤーのHPを攻撃数によって減らす
	if (attack_num != 0) {
		m_pPlayerHP->ReduceHP((float)attack_num);
	}

	//プレイヤーのHPが0になったら...
	if (m_pPlayerHP->GetHP0Flag()) {
		SetStageClear(false);
		Fade(SCENE::SCENE_RESULT, STAGE::STAGE_VENUS);
	}
}

//==========================
// 描画処理
//==========================
void StageVenus::Draw(void) const
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
	m_pEnemyFireballManagement->Draw();
	m_pEnemyAcidManagement->Draw();
	m_pEnemuPoorvisionManagement->Draw();
	m_pEnemySpeeddownManagement->Draw();

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

	m_pPoorvision->Draw();
}
