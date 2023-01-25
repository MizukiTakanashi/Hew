//=======================================
// 火星のステージ関係(cppファイル)
// 作成日：2022/12/15
// 作成者：高梨水希
//=======================================
#include "stage_mercury.h"
#include "sound.h"

//==========================
// 引数付きコンストラクタ
//==========================
StageMercury::StageMercury(Score* pNumber):InhStage(pNumber)
{
	m_pBG_Moon = new BGPlanet((char*)"data\\texture\\mercury.png");

	//======================
	// 敵
	//レーザー
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_LASER].SetTextureName((char*)"data\\texture\\laser00.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_LASER]);
	m_pEnemyLaser = new EnemyLaserManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_LASER], 
		m_pDrawObject[(int)DRAW_TYPE::BULLET_LASER], 2);

	//氷
	m_pEnemyIce = new EnemyIceRainManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_ICE], 
		m_pDrawObject[(int)DRAW_TYPE::BULLET_ICE], 2);

	//炎
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_FIRE].SetTextureName((char*)"data\\texture\\enemy_fire.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_FIRE].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_FIRE]);
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_FIRE].SetTextureName((char*)"data\\texture\\bullet_fire.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_FIRE].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_FIRE]);
	m_pEnemyFire = new EnemyFireManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_FIRE], 
		m_pDrawObject[(int)DRAW_TYPE::BULLET_FIRE], 2);

	//ミサイル
	m_pEnemyMissile = new EnemyMissileManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_NORMAL],
		m_pDrawObject[(int)DRAW_TYPE::BULLET_ENEMY], 2);

	//腕
	m_pPlayerLeft->DrawSetFireE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_FIRE]);
	m_pPlayerLeft->DrawSetFire(&m_pDrawObject[(int)DRAW_TYPE::BULLET_FIRE]);
	m_pPlayerRight->DrawSetFireE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_FIRE]);
	m_pPlayerRight->DrawSetFire(&m_pDrawObject[(int)DRAW_TYPE::BULLET_FIRE]);
	m_pPlayerCenter->DrawSetFireE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_FIRE]);
	m_pPlayerCenter->DrawSetFire(&m_pDrawObject[(int)DRAW_TYPE::BULLET_FIRE]);

	//炎ギミック
	m_pTexUseful[(int)TEXTURE_TYPE::FIREFIELD].SetTextureName((char*)"data\\texture\\gimmick_Mercury2.png");
	m_pDrawObject[(int)DRAW_TYPE::FIREFIELD].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::FIREFIELD], 2.0f, 1.0, 1.0f, 3);
	m_pManagement_FireField = new Management_FireField(m_pDrawObject[(int)DRAW_TYPE::FIREFIELD]);

	//氷ギミック
	m_pTexUseful[(int)TEXTURE_TYPE::ICEFIELD].SetTextureName((char*)"data\\texture\\gimmick_Mercury .png");
	m_pDrawObject[(int)DRAW_TYPE::ICEFIELD].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ICEFIELD], 2.0f, 1.0, 1.0f, 3);
	m_pManagement_IceField = new Management_IceField(m_pDrawObject[(int)DRAW_TYPE::ICEFIELD]);
	
	//敵の管理
	m_pAllEnemyManagement = new AllEnemyManagement;
	m_pAllEnemyManagement->AddPointer(m_pEnemyLaser);
	m_pAllEnemyManagement->AddPointer(m_pEnemyIce);
	m_pAllEnemyManagement->AddPointer(m_pEnemyFire);
	m_pAllEnemyManagement->AddPointer(m_pEnemyMissile);

	//========================================================
	// 全ての当たり判定
	m_pColAll = new CollisionAll(CollisionAll::STAGE::MERCURY, m_pPlayer, m_pPlayerLeft, m_pPlayerRight, m_pExplosionManagement,
		m_pItemManagement, m_pScore, m_pBom);
	m_pColAll->SetHP(m_pPlayerHP);
	m_pColAll->SetIceField(m_pManagement_IceField);
	m_pColAll->SetFireField(m_pManagement_FireField);

	//敵のポインタをセット
	m_pColAll->AddEnemyPointer(m_pEnemyLaser);
	m_pColAll->AddEnemyPointer(m_pEnemyIce);
	m_pColAll->AddEnemyPointer(m_pEnemyFire);
	m_pColAll->AddEnemyPointer(m_pEnemyMissile);
}

//==========================
// デストラクタ
//==========================
StageMercury::~StageMercury()
{
	delete m_pColAll;
	delete m_pAllEnemyManagement;

	delete m_pEnemyLaser;
	delete m_pEnemyIce;
	delete m_pEnemyFire;
	delete m_pEnemyMissile;
	delete m_pManagement_IceField;
	delete m_pManagement_FireField;
}

//==========================
// 更新処理
//==========================
void StageMercury::Update(void)
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
		Fade(SCENE::SCENE_RESULT, STAGE::STAGE_MERCURY);
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
	m_pEnemyLaser->Update();
	m_pEnemyIce->Update();
	m_pEnemyFire->Update();
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
	m_pManagement_FireField->Update();
	m_pManagement_IceField->Update();

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
		Fade(SCENE::SCENE_RESULT, STAGE::STAGE_MERCURY);
	}

	//最後の列の敵を全て倒したら
	if (m_pEnemyLaser->IsClear() && m_pEnemyIce->IsClear() &&
		m_pEnemyFire->IsClear() && m_pEnemyMissile->IsClear()) {
		//リザルト画面に行く
		SetStageClear(true);
		Fade(SCENE::SCENE_RESULT, STAGE::STAGE_MERCURY);
	}
}

//==========================
// 描画処理
//==========================
void StageMercury::Draw(void) const
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
	m_pStageMarcury->Draw();

	//プレイヤーの描画処理
	m_pPlayer->Draw();
	m_pPlayer->DrawBullet();
	m_pPlayerLeft->ArmDraw();
	m_pPlayerRight->ArmDraw();
	m_pPlayerCenter->ArmDraw();

	//敵の描画
	m_pEnemyLaser->Draw();
	m_pEnemyIce->Draw();
	m_pEnemyFire->Draw();
	m_pEnemyMissile->Draw();

	m_pExplosionManagement->Draw();

	m_pItemManagement->Draw();

	m_pManagement_IceField->Draw();
	m_pManagement_FireField->Draw();


	//ボムの描画
	m_pBom->BomDraw();

}
