//=======================================
// 火星のステージ関係(cppファイル)
// 作成日：2022/12/15
// 作成者：高梨水希
//=======================================
#include "stage_mercury.h"
#include "sound.h"

//==========================
// 定数初期化
//==========================

//==========================
// グローバル変数
//==========================
int MercuryStopFlame = 0;	//ヒットストップ用
bool isDownMercury = false; //ボスが死んだか

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

	//========================================================
	// 全ての当たり判定
	//m_pColAll = new CollisionAll(m_pPlayer, m_pPlayerLeft, m_pPlayerRight, m_pExplosionManagement,
	//	m_pItemManagement, m_pScore, m_pBom, );

	//敵のポインタをセット（順番変えるのNG）
	//m_pColAll->AddEnemyPointer(m_pEnemyBarrierManagement);
}

//==========================
// デストラクタ
//==========================
StageMercury::~StageMercury()
{
	//delete m_pColAll;

	delete m_pEnemyLaser;
	delete m_pEnemyIce;
	delete m_pEnemyFire;
}

//==========================
// 更新処理
//==========================
void StageMercury::Update(void)
{
	//ヒットストップ
	if (MercuryStopFlame > 0)
	{
		MercuryStopFlame--;
		return;
	}

	//ボスが死んだら
	if (isDownMercury)
		Fade(SCENE::SCENE_RESULT);

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
		Fade(SCENE::SCENE_RESULT);
	}
}

//==========================
// 描画処理
//==========================
void StageMercury::Draw(void) const
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
	m_pEnemyLaser->Draw();
	m_pEnemyIce->Draw();
	m_pEnemyFire->Draw();

	//プレイヤーの弾の表示
	m_pPlayer->DrawBullet();

	m_pExplosionManagement->Draw();

	m_pItemManagement->Draw();

	//ボムの描画
	m_pBom->BomDraw();

	//UIの描画
	m_pFrame->Draw();
	m_pPlayerHP->DrawHP();
	m_pScore->DrawNumber();
	m_pComboNum->SetNumber(m_pScore->GetComboNum());
	m_pComboNum->DrawNumber();
	m_pMultiply->Draw();
}

//==========================
// ヒットストップ
//==========================
void MercuryHitStop(int flame)
{
	MercuryStopFlame = flame;
}

void MercuryBossDown()
{
	isDownMercury = true;
}