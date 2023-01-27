//=======================================
// 土星のステージ関係(cppファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#include "stage_saturn.h"
#include "sound.h"

//==========================
// 引数付きコンストラクタ
//==========================
StageSaturn::StageSaturn(Score* pNumber):InhStage(pNumber)
{
	m_pBG_Moon = new BGPlanet((char*)"data\\texture\\saturn.png");

	//=======================
	// 敵
	//レーザーの敵
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_LASER].SetTextureName((char*)"data\\texture\\bullet_gass.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_LASER]);
	m_pEnemyLaserManagement = new EnemyLaserManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_LASER], 
		m_pDrawObject[(int)DRAW_TYPE::BULLET_LASER], 3);

	//めぐみん
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_MEGUMIN].SetTextureName((char*)"data\\texture\\megumin.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_MEGUMIN].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_MEGUMIN]);
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_MEGUMIN].SetTextureName((char*)"data\\texture\\bullet_megumin.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_MEGUMIN].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_MEGUMIN]);
	m_pEnemyMeguminManagement = new EnemyMeguminManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_MEGUMIN], 
		m_pDrawObject[(int)DRAW_TYPE::BULLET_MEGUMIN]);

	//ガトリング
	m_pEnemyGatoring = new EnemyGatoringManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_GATORING], 
		m_pDrawObject[(int)DRAW_TYPE::BULLET_ENEMY], 3);

	//ミサイル
	m_pEnemyMissile = new EnemyMissileManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_NORMAL],
		m_pDrawObject[(int)DRAW_TYPE::BULLET_ENEMY], 3);

	//毒沼
	m_pTexUseful[(int)TEXTURE_TYPE::POISON].SetTextureName((char*)"data\\texture\\poison.png");
	m_pDrawObject[(int)DRAW_TYPE::POISON].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::POISON], 2.0f, 1.0, 1.0f, 3);
	m_pPoisonField = new Management_PoisonField(m_pDrawObject[(int)DRAW_TYPE::POISON]);

	m_pBossManagement = new BossManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_MEGUMIN], m_pDrawObject[(int)DRAW_TYPE::BULLET_MEGUMIN], 1);

	//敵の管理
	m_pAllEnemyManagement = new AllEnemyManagement;
	m_pAllEnemyManagement->AddPointer(m_pEnemyLaserManagement);
	m_pAllEnemyManagement->AddPointer(m_pEnemyMeguminManagement);
	m_pAllEnemyManagement->AddPointer(m_pEnemyGatoring);
	m_pAllEnemyManagement->AddPointer(m_pEnemyMissile);
	m_pAllEnemyManagement->AddPointer(m_pBossManagement);
	
	//========================================================
	// 全ての当たり判定
	m_pColAll = new CollisionAll(CollisionAll::STAGE::SATURN, m_pPlayer, m_pPlayerLeft, m_pPlayerRight, m_pExplosionManagement,
		m_pItemManagement, m_pScore, m_pBom);
	m_pColAll->SetPoison(m_pPoisonField);

	//敵のポインタをセット
	m_pColAll->AddEnemyPointer(m_pEnemyMeguminManagement);
	m_pColAll->AddEnemyPointer(m_pEnemyLaserManagement);
	m_pColAll->AddEnemyPointer(m_pEnemyGatoring);
	m_pColAll->AddEnemyPointer(m_pEnemyMissile);
	m_pColAll->AddEnemyPointer(m_pBossManagement);
}

//==========================
// デストラクタ
//==========================
StageSaturn::~StageSaturn()
{
	delete m_pAllEnemyManagement;
	delete m_pColAll;
	delete m_pEnemyLaserManagement;
	delete m_pEnemyMeguminManagement;
	delete m_pEnemyMissile;
	delete m_pEnemyGatoring;
	delete m_pPoisonField;
	delete m_pBossManagement;
}

//==========================
// 更新処理
//==========================
void StageSaturn::Update(void)
{
	//ヒットストップ
	if (m_StopFlame > 0)
	{
		m_StopFlame--;

		//ゆっくりになるのであれば...
		if (m_HitStopSlow != -1) {
			//時間が来たら処理をかける
			if (++m_HitStopSlow >= HIT_STOP_SLOW_INTERVAL) {
				m_HitStopSlow = 0;
			}
			else {
				return;
			}
		}
		//ゆっくりにならないのであれば...
		else {
			//処理を飛ばす
			return;
		}
	}

	//プレイヤーのHPが0になったら...
	if (m_pPlayerHP->GetHP0Flag()) {
		if (m_GameoverHitstop) {
			m_StopFlame = HIT_STOP_TIME;
			m_GameoverHitstop = false;
			m_HitStopSlow = 0;
		}
		else {
			if (m_StopFlame <= 0) {
				SetStageClear(false);
				Fade(SCENE::SCENE_RESULT, STAGE::STAGE_SATURN);
				return;
			}
		}
	}

	//最後の列の敵を全て倒したら

	if (m_pEnemyLaserManagement->IsClear() && m_pEnemyMeguminManagement->IsClear()
		&& m_pBossManagement->IsClear()&&
		m_pEnemyMissile->IsClear() && m_pEnemyGatoring->IsClear()) {

		if (m_GameclearHitstop) {
			m_StopFlame = HIT_STOP_TIME;
			m_GameclearHitstop = false;
			m_HitStopSlow = 0;
		}
		else {
			if (m_StopFlame <= 0) {
				//リザルト画面に行く
				SetStageClear(true);
				Fade(SCENE::SCENE_RESULT, STAGE::STAGE_SATURN);
				return;
			}
		}
	}

	//ボスが死んだら
	if (m_isBossDown)
	{
		SetStageClear(true);
		Fade(SCENE::SCENE_RESULT, STAGE::STAGE_SATURN);
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

	//=======================
	// 敵
	m_pEnemyLaserManagement->Update();
	m_pEnemyMeguminManagement->Update();
	m_pEnemyGatoring->Update();
	m_pBossManagement->Update();
	m_pEnemyMissile->Update(m_pPlayer->GetPos());

	m_pPoisonField->Update();
	//ボム
	m_pBom->Update();

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
	//合体した時のヒットストップ
	if (m_pPlayerLeft->IsHitStop()) {
		m_StopFlame = HIT_STOP_UNION;
		m_pPlayerLeft->SetHitStop(false);
	}
	if (m_pPlayerRight->IsHitStop()) {
		m_StopFlame = HIT_STOP_UNION;
		m_pPlayerRight->SetHitStop(false);
	}

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
		SetStageClear(false);
		Fade(SCENE::SCENE_RESULT, STAGE::STAGE_SATURN);
	}

	//最後の列の敵を全て倒したら
	if (m_pEnemyGatoring->IsClear() && m_pEnemyMeguminManagement->IsClear()&& m_pEnemyMissile->IsClear()) {
		//リザルト画面に行く
		SetStageClear(true);
		Fade(SCENE::SCENE_RESULT, STAGE::STAGE_SATURN);
	}
}

//==========================
// 描画処理
//==========================
void StageSaturn::Draw(void) const
{
	m_pBG->DrawBG();
	m_pBG_Moon->DrawSaturn();

	//UIの描画
	m_pFrame->Draw();
	m_pPlayerHP->DrawHP();
	m_pScore->DrawNumber();
	m_pComboNum->SetNumber(m_pScore->GetComboNum());
	m_pComboNum->DrawNumber();
	m_pMultiply->Draw();
	m_pStageSataurn->Draw();

	//プレイヤーの描画処理
	if (m_pPlayerHP->IsDrawPlayer()) {
		m_pPlayer->Draw();
	}
	m_pPlayer->DrawBullet();
	if (m_pPlayerHP->IsDrawPlayer()) {
		m_pPlayerLeft->ArmDraw();
		m_pPlayerRight->ArmDraw();
		m_pPlayerCenter->ArmDraw();
	}

	//敵の描画
	m_pEnemyLaserManagement->Draw();
	m_pEnemyMeguminManagement->Draw();
	m_pEnemyGatoring->Draw();
	m_pEnemyMissile->Draw();
	m_pBossManagement->Draw();

	m_pPoisonField->Draw();

	m_pExplosionManagement->Draw();

	m_pItemManagement->Draw();

	//ボムの描画
	m_pBom->BomDraw();


}
