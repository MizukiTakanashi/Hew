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

	m_pEnemyFireballManagement = new EnemyFireballManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_FIREBALL], 
		m_pDrawObject[(int)DRAW_TYPE::BULLET_FIREBALL]);

	//酸性雨の敵
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_ACID].SetTextureName((char*)"data\\texture\\enemy_acid.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_ACID].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_ACID]);
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_ACID].SetTextureName((char*)"data\\texture\\bullet_acid.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_ACID].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_ACID]);

	m_pEnemyAcidManagement = new EnemyAcidManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_ACID], 
		m_pDrawObject[(int)DRAW_TYPE::BULLET_ACID]);

	//視界を悪くする敵
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_POOR].SetTextureName((char*)"data\\texture\\enemy_poorvision.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_POOR].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_POOR]);
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_MIST].SetTextureName((char*)"data\\texture\\bullet_mist.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_MIST].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_MIST]);

	m_pEnemuPoorvisionManagement = new EnemyPoorvisionManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_POOR], 
		m_pDrawObject[(int)DRAW_TYPE::BULLET_MIST]);

	//プレイヤーのスピードを遅くする敵
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_SPEEDDOWN].SetTextureName((char*)"data\\texture\\enemy_speeddown.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_SPEEDDOWN].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_SPEEDDOWN]);
	m_pDrawObject[(int)DRAW_TYPE::BULLET_SPEEDDOWN].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_MIST], 
		1.0f, 1.0f, 1.0f, 1, D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));

	m_pEnemySpeeddownManagement = new EnemySpeeddownManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_SPEEDDOWN], 
		m_pDrawObject[(int)DRAW_TYPE::BULLET_SPEEDDOWN]);

	//ガトリング敵
	m_pEnemyGatoring = new EnemyGatoringManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_GATORING],
		m_pDrawObject[(int)DRAW_TYPE::BULLET_ENEMY], 4);

	//敵の管理
	//m_pAllEnemyManagement->AddPointer(m_pEnemyFireballManagement);
	
	//当たり判定
	m_pColAll = new CollisionAll(CollisionAll::STAGE::VENUS, m_pPlayer, m_pPlayerLeft, m_pPlayerRight,
		m_pExplosionManagement, m_pItemManagement, m_pScore, m_pBom);
	//敵のポインタをセット
	m_pColAll->AddEnemyPointer(m_pEnemyFireballManagement);
	m_pColAll->AddEnemyPointer(m_pEnemyAcidManagement);
	m_pColAll->AddEnemyPointer(m_pEnemuPoorvisionManagement);
	m_pColAll->AddEnemyPointer(m_pEnemySpeeddownManagement);
	m_pColAll->AddEnemyPointer(m_pEnemyGatoring);

	m_pPlayerCenter->DrawSetAcid(&m_pDrawObject[(int)DRAW_TYPE::BULLET_ACID]);
	m_pPlayerRight->DrawSetAcid(&m_pDrawObject[(int)DRAW_TYPE::BULLET_ACID]);
	m_pPlayerLeft->DrawSetAcid(&m_pDrawObject[(int)DRAW_TYPE::BULLET_ACID]);

}

//==========================
// デストラクタ
//==========================
StageVenus::~StageVenus()
{
	delete m_pColAll;
	delete m_pEnemyFireballManagement;
	delete m_pEnemuPoorvisionManagement;
	delete m_pEnemySpeeddownManagement;
	delete m_pEnemyAcidManagement;
	delete m_pEnemyGatoring;
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
	m_pEnemyGatoring->Update();

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
	attack_num += m_pColAll->Collision();

	//回復
	m_pColAll->HeelCollision();

	//視界を悪くするか
	if (m_pColAll->IsPoorVision()) {
		InhStage::SetPoorVision();
		m_pColAll->SetPoorVision(false);
	}

	//プレイヤーのHPを攻撃数によって減らす
	if (attack_num != 0) {
		m_pPlayerHP->ReduceHP((float)attack_num);
	}

	//プレイヤーのHPが0になったら...
	if (m_pPlayerHP->GetHP0Flag()) {
		SetStageClear(false);
		Fade(SCENE::SCENE_RESULT, STAGE::STAGE_VENUS);
	}
	//最後の列の敵を全て倒したら
	if (m_pEnemuPoorvisionManagement->IsClear() && m_pEnemyAcidManagement->IsClear() && m_pEnemySpeeddownManagement->IsClear() && m_pEnemyFireballManagement->IsClear() && m_pEnemyGatoring->IsClear()) {
		//リザルト画面に行く
		SetStageClear(true);
		Fade(SCENE::SCENE_RESULT, STAGE::STAGE_SATURN);
	}
}

//==========================
// 描画処理
//==========================
void StageVenus::Draw(void) const
{
	m_pBG->DrawBG();
	m_pBG_Moon->DrawBG();

	//UIの描画
	m_pFrame->Draw();
	m_pPlayerHP->DrawHP();
	m_pScore->DrawNumber();
	m_pComboNum->SetNumber(m_pScore->GetComboNum());
	m_pComboNum->DrawNumber();
	m_pMultiply->Draw();
	m_pStageVenus->Draw();


	//プレイヤーの腕の描画処理
	m_pPlayer->Draw();
	m_pPlayer->DrawBullet();
	m_pPlayerLeft->ArmDraw();
	m_pPlayerRight->ArmDraw();
	m_pPlayerCenter->ArmDraw();

	//敵の描画
	m_pEnemyFireballManagement->Draw();
	m_pEnemyAcidManagement->Draw();
	m_pEnemuPoorvisionManagement->Draw();
	m_pEnemySpeeddownManagement->Draw();
	m_pEnemyGatoring->Draw();

	m_pExplosionManagement->Draw();

	m_pItemManagement->Draw();

	//ボムの描画
	m_pBom->BomDraw();

	m_pPoorvision->Draw();
}
