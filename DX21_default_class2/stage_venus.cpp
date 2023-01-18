//=======================================
// 金星のステージ関係(cppファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#include "stage_venus.h"
#include "sound.h"

//==========================
// 定数初期化
//==========================

//==========================
// グローバル変数
//==========================

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
	m_pEnemyFireballManagement->Update(m_pPlayer->GetPos());

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
}
