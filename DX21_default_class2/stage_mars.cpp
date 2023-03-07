//=======================================
// 火星のステージ関係(cppファイル)
// 作成日：2022/12/15
// 作成者：高梨水希
//=======================================
#include "stage_mars.h"
#include "sound.h"

//==========================
// 引数付きコンストラクタ
//==========================
StageMars::StageMars(Score* pNumber):InhStage(pNumber)
{
	m_pBG_Moon = new BGPlanet((char*)"data\\texture\\mars.png");

	//バリアの敵
	m_pEnemyBarrierManagement = new EnemyBarrierManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_BARRIER], m_pDrawObject[(int)DRAW_TYPE::BULLET_BARRIER], 1);

	//ステージ表示読み込み
	//火星
	m_pTexUseful[(int)TEXTURE_TYPE::MARS].SetTextureName((char*)"data\\texture\\mars_name.png");
	m_pDrawObject[(int)DRAW_TYPE::MARS].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::MARS], 0.0f, 1.0f, 1.0f, 1);
	m_pStageMars = new UI(m_pDrawObject[(int)DRAW_TYPE::MARS], D3DXVECTOR2(160.0f, 40.0f), D3DXVECTOR2(80.0f, 25.0f), D3DXCOLOR());

	//氷の敵
	m_pEnemyIceRainManagement = new EnemyIceRainManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_ICE], m_pDrawObject[(int)DRAW_TYPE::BULLET_ICE], 1);

	//動きを止める敵
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_STOP].SetTextureName((char*)"data\\texture\\enemy_stop.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_STOP].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_STOP]);
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_STOP].SetTextureName((char*)"data\\texture\\bullet_stop.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_STOP].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_STOP]);
	m_pEnemyStopManagement = new EnemyStopManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_STOP], m_pDrawObject[(int)DRAW_TYPE::BULLET_STOP]);
	
	//ホーミングの敵
	m_pEnemyMissileManagement = new EnemyMissileManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_NORMAL], m_pDrawObject[(int)DRAW_TYPE::BULLET_MISSILE], 1);

	m_pBossManagement = new BossManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_ICE], m_pDrawObject[(int)DRAW_TYPE::BULLET_ICE], 1);
	//グレネード敵
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_GREANADE].SetTextureName((char*)"data\\texture\\grenade.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_GRENADE].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_GREANADE]);
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_GRENADE_EXPLOSION].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::EXPLOSION], 0.0f, 0.125f, 1.0f, 7);
	m_pEnemyGrenadeManagement = new EnemyGrenadeManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_GRENADE],
		m_pDrawObject[(int)DRAW_TYPE::BULLET_ENEMY], m_pDrawObject[(int)DRAW_TYPE::ENEMY_GRENADE_EXPLOSION], 1);

	//STOP_ITEM
	m_pTexUseful[(int)TEXTURE_TYPE::ITEM_STOP].SetTextureName((char*)"data\\texture\\item_stop.png");
	m_pDrawObject[(int)DRAW_TYPE::ITEM_STOP].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ITEM_STOP]);
	m_pItemManagement->SetDrawStop(m_pDrawObject[(int)DRAW_TYPE::ITEM_STOP]);

	m_pPlayerLeft->DrawSetBulleStop(&m_pDrawObject[(int)DRAW_TYPE::BULLET_STOP]);
	m_pPlayerRight->DrawSetBulleStop(&m_pDrawObject[(int)DRAW_TYPE::BULLET_STOP]);
	m_pPlayerCenter->DrawSetBulleStop(&m_pDrawObject[(int)DRAW_TYPE::BULLET_STOP]);
	m_pPlayerLeft->DrawSetStopE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_STOP]);
	m_pPlayerRight->DrawSetStopE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_STOP]);
	m_pPlayerCenter->DrawSetStopE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_STOP]);

	//敵の管理
	m_pAllEnemyManagement = new AllEnemyManagement;
	m_pAllEnemyManagement->AddPointer(m_pEnemyBarrierManagement);
	m_pAllEnemyManagement->AddPointer(m_pEnemyStopManagement);
	m_pAllEnemyManagement->AddPointer(m_pEnemyIceRainManagement);
	m_pAllEnemyManagement->AddPointer(m_pEnemyGrenadeManagement);
	m_pAllEnemyManagement->AddPointer(m_pEnemyMissileManagement);
	m_pAllEnemyManagement->AddPointer(m_pBossManagement);

	//腕
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_GRENADE_EXPLOSION].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::EXPLOSION], 0.0f, 0.125f, 1.0f, 7);
	m_pPlayerLeft->DrawSetExplosion(m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_GRENADE_EXPLOSION]);
	m_pPlayerRight->DrawSetExplosion(m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_GRENADE_EXPLOSION]);
	m_pPlayerCenter->DrawSetExplosion(m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_GRENADE_EXPLOSION]);

	//========================================================
	// 全ての当たり判定
	m_pColAll1 = new CollisionAll(CollisionAll::STAGE::MARS, m_pPlayer, m_pPlayerLeft, m_pPlayerRight, m_pExplosionManagement,
		m_pItemManagement, m_pScore, m_pBom);
	m_pColAll1->SetGrenade(m_pEnemyGrenadeManagement);

	//敵のポインタをセット（順番変えるのNG）
	m_pColAll1->AddEnemyPointer(m_pEnemyBarrierManagement);
	m_pColAll1->AddEnemyPointer(m_pEnemyStopManagement);
	m_pColAll1->AddEnemyPointer(m_pEnemyIceRainManagement);
	m_pColAll1->AddEnemyPointer(m_pEnemyGrenadeManagement);
	m_pColAll1->AddEnemyPointer(m_pEnemyMissileManagement);
	m_pColAll1->AddEnemyPointer(m_pBossManagement);

	//ギミック
	m_pTexUseful[(int)TEXTURE_TYPE::GIMMICK_MARS].SetTextureName((char*)"data\\texture\\mars_gimmick.PNG");
	m_pDrawObject[(int)DRAW_TYPE::GIMMICK_MARS].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::GIMMICK_MARS]);
	m_pDrawObject[(int)DRAW_TYPE::GIMMICK_MARS].SetDrawColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f));
	m_pGimmick = new MarsGimmick(m_pDrawObject[(int)DRAW_TYPE::GIMMICK_MARS]);
}

//==========================
// デストラクタ
//==========================
StageMars::~StageMars()
{
	//描画がない物から消していく
	delete m_pAllEnemyManagement;
	delete m_pColAll1;

	//ゲームオブジェクトを消す
	delete m_pGimmick;
	//if (m_pBoss) {
	//	delete m_pBoss;
	//}
	delete m_pEnemyBarrierManagement;
	delete m_pEnemyMissileManagement;
	delete m_pEnemyGrenadeManagement;
	delete m_pEnemyIceRainManagement;
	delete m_pEnemyStopManagement;
	delete m_pBossManagement;
}

//==========================
// 更新処理
//==========================
void StageMars::Update(void)
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
				Fade(SCENE::SCENE_RESULT, STAGE::STAGE_MARS);
				return;
			}
		}
	}

	//最後の列の敵を全て倒したら
	if ( m_pBossManagement->IsClear()) {
		if (m_GameclearHitstop) {
			m_StopFlame = HIT_STOP_TIME;
			m_GameclearHitstop = false;
			m_HitStopSlow = 0;
		}
		else {
			if (m_StopFlame <= 0) {
				//リザルト画面に行く
				SetStageClear(true);
				Fade(SCENE::SCENE_RESULT, STAGE::STAGE_MARS);
				return;
			}
		}
	}

	//ボスが死んだら
	if (m_isBossDown) 
	{
		SetStageClear(true);
		Fade(SCENE::SCENE_RESULT, STAGE::STAGE_MARS);
	}

	//背景
	m_pBG->Update();
	m_pBG_Moon->Update();

	//腕の切り替え
	m_pPlayerArmChange->Change();

	//ギミック
	m_pGimmick->Update();

	//プレイヤー
	m_pPlayer->SetSlow(m_pGimmick->GetMoveDown());
	m_pPlayer->Update(m_pPlayerHP->IsPlayerInvincible());

	m_pPlayerHP->Update();

	//爆発
	m_pExplosionManagement->Update();

	//敵から落ちるアイテム
	m_pItemManagement->Update();

	//=======================
	// 敵
	m_pEnemyMissileManagement->Update(m_pPlayer->GetPos());
	m_pEnemyBarrierManagement->Update();
	m_pEnemyIceRainManagement->Update(m_pPlayer->GetPos());
	m_pEnemyStopManagement->Update();
	m_pEnemyGrenadeManagement->Update(m_pPlayer->GetPos());
	m_pBossManagement->Update();

	//ボム
	m_pBom->Update();

	//====================================
	//プレイヤーのHPに対する処理
	int attack_num = 0;

	//プレイヤーの腕

	//ホーミング弾用
	D3DXVECTOR2 temp_pos = m_pAllEnemyManagement->GetCloltestEnemyPos(m_pPlayer->GetPos());

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

	////ボス処理
	//if (m_pBoss)
	//{
	//	m_pBoss->Update();
	//}
	//else if(m_pEnemyBarrierManagement->IsClear() && m_pEnemyStopManagement->IsClear())
	//{
	//	m_pBoss = new Boss(m_pDrawObject[(int)DRAW_TYPE::ENEMY_STOP], this);
	//}

	
	//敵とプレイヤーの当たり判定
	attack_num += m_pColAll1->Collision();

	//回復
	m_pColAll1->HeelCollision();

	//プレイヤーのHPを攻撃数によって減らす
	if (attack_num != 0) {
		m_pPlayerHP->ReduceHP((float)attack_num);
	}

}

//==========================
// 描画処理
//==========================
void StageMars::Draw(void) const
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
	m_pStageMars->Draw();

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
	m_pEnemyMissileManagement->Draw();
	m_pEnemyBarrierManagement->Draw();
	m_pEnemyIceRainManagement->Draw();
	m_pEnemyStopManagement->Draw();
	m_pEnemyGrenadeManagement->Draw();
	m_pBossManagement->Draw();
	//if (m_pBoss) {
	//	m_pBoss->Draw();
	//}

	m_pItemManagement->Draw();

	m_pExplosionManagement->Draw();

	m_pGimmick->Draw();

	//ボムの描画
	m_pBom->BomDraw();
}
