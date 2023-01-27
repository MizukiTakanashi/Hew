//=======================================
// 木星のステージ関係(cppファイル)
// 作成日：2023/01/26
// 作成者：高梨水希
//=======================================
#include "stage_jupiter.h"
#include "sound.h"

//==========================
// 引数付きコンストラクタ
//==========================
StageJupiter::StageJupiter(Score* pNumber) :InhStage(pNumber)
{
	m_pBG_Moon = new BGPlanet((char*)"data\\texture\\jupiter.png");

	//木星
	m_pTexUseful[(int)TEXTURE_TYPE::JUPITOR].SetTextureName((char*)"data\\texture\\jupiter_name.png");
	m_pDrawObject[(int)DRAW_TYPE::JUPITOR].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::JUPITOR], 0.0f, 1.0f, 1.0f, 1);
	m_pStageJupitor = new UI(m_pDrawObject[(int)DRAW_TYPE::JUPITOR], D3DXVECTOR2(160.0f, 40.0f), D3DXVECTOR2(80.0f, 25.0f), D3DXCOLOR());

	//======================
	// 敵
	//レーザー
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_LASER].SetTextureName((char*)"data\\texture\\laser.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_LASER]);
	m_pEnemyLaser = new EnemyLaserManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_LASER],
		m_pDrawObject[(int)DRAW_TYPE::BULLET_LASER], 5);

	//ミサイル
	m_pEnemyMissile = new EnemyMissileManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_NORMAL],
		m_pDrawObject[(int)DRAW_TYPE::BULLET_ENEMY], 5);

	//バリア
	m_pEnemyBarrier = new EnemyBarrierManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_BARRIER],
		m_pDrawObject[(int)DRAW_TYPE::BULLET_BARRIER], 5);

	//何もしてこない敵
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_PUBLIC].SetTextureName((char*)"data\\texture\\enemy_normal.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_PUBLIC].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_PUBLIC]);
	m_pEnemyPublic = new Management_EnemyPublic(m_pDrawObject[(int)DRAW_TYPE::ENEMY_PUBLIC]);

	m_pBossManagement = new BossManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_LASER], m_pDrawObject[(int)DRAW_TYPE::BULLET_LASER], 5);

	//敵の管理
	m_pAllEnemyManagement = new AllEnemyManagement;
	m_pAllEnemyManagement->AddPointer(m_pEnemyLaser);
	m_pAllEnemyManagement->AddPointer(m_pEnemyMissile);
	m_pAllEnemyManagement->AddPointer(m_pEnemyPublic);
	m_pAllEnemyManagement->AddPointer(m_pEnemyBarrier);
	m_pAllEnemyManagement->AddPointer(m_pBossManagement);

	//========================================================
	// 全ての当たり判定
	m_pColAll = new CollisionAll(CollisionAll::STAGE::JUPITER, m_pPlayer, m_pPlayerLeft, m_pPlayerRight, m_pExplosionManagement,
		m_pItemManagement, m_pScore, m_pBom);

	//敵のポインタをセット
	m_pColAll->AddEnemyPointer(m_pEnemyLaser);
	m_pColAll->AddEnemyPointer(m_pEnemyMissile);
	m_pColAll->AddEnemyPointer(m_pEnemyBarrier);
	m_pColAll->AddEnemyPointer(m_pEnemyPublic);
	m_pColAll->AddEnemyPointer(m_pBossManagement);
}

//==========================
// デストラクタ
//==========================
StageJupiter::~StageJupiter()
{
	delete m_pColAll;
	delete m_pAllEnemyManagement;

	delete m_pEnemyLaser;
	delete m_pEnemyMissile;
	delete m_pEnemyBarrier; 
	delete m_pEnemyPublic;
	delete m_pBossManagement;
}

//==========================
// 更新処理
//==========================
void StageJupiter::Update(void)
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
				Fade(SCENE::SCENE_RESULT, STAGE::STAGE_JUPITER);
				return;
			}
		}
	}

	//最後の列の敵を全て倒したら
	if (m_pEnemyLaser->IsClear() && m_pEnemyPublic->IsClear() &&
		m_pEnemyBarrier->IsClear() && m_pEnemyMissile->IsClear() && m_pBossManagement->IsClear()) {
		if (m_GameclearHitstop) {
			m_StopFlame = HIT_STOP_TIME;
			m_GameclearHitstop = false;
			m_HitStopSlow = 0;
		}
		else {
			if (m_StopFlame <= 0) {
				//リザルト画面に行く
				SetStageClear(true);
				Fade(SCENE::SCENE_RESULT, STAGE::STAGE_JUPITER);
				return;
			}
		}
	}

	////ボスが死んだら
	//if (m_isBossDown)
	//{
	//	SetStageClear(true);
	//	Fade(SCENE::SCENE_RESULT, STAGE::STAGE_MERCURY);
	//}

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
	m_pEnemyLaser->Update();
	m_pEnemyPublic->Update();
	m_pEnemyBarrier->Update();
	m_pBossManagement->Update();
	m_pEnemyMissile->Update(m_pPlayer->GetPos());

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
}

//==========================
// 描画処理
//==========================
void StageJupiter::Draw(void) const
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
	m_pStageJupitor->Draw();

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
	m_pEnemyLaser->Draw();
	m_pEnemyPublic->Draw();
	m_pEnemyBarrier->Draw();
	m_pEnemyMissile->Draw();
	m_pBossManagement->Draw();

	m_pExplosionManagement->Draw();

	m_pItemManagement->Draw();

	//ボムの描画
	m_pBom->BomDraw();
}
