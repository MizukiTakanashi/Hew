//=======================================
// ゲーム画面関係(cppファイル)
// 作成日：2022/07/14
// 作成者：高梨水希
//=======================================
#include "game.h"
#include "scene.h"
#include "sound.h"

//==========================
// 定数初期化
//==========================
const D3DXVECTOR2 Game::NUMBER_POS = D3DXVECTOR2(1230.0f, 30.0f);
const D3DXVECTOR2 Game::NUMBER_SIZE = D3DXVECTOR2(30.0f, 30.0f);

//==========================
// グローバル変数
//==========================
int StopFlame = 0; //ヒットストップ用
bool isText = false; //チュートリアルテキスト用


//==========================
// 初期化処理
//==========================
Game::Game()
{
	
}

//=========================
// 引数付きコンストラクタ
//=========================
Game::Game(Score* pNumber) :m_pScore(pNumber)
{
	m_BGM = LoadSound((char*)"data\\BGM\\opportunity (online-audio-converter.com).wav");	//サウンドのロード
	PlaySound(m_BGM, -1);	//BGM再生
	SetVolume(m_BGM, 0.1f);

	m_pTexUseful = new TextureUseful[(int)TEXTURE_TYPE::NUM];
	m_pDrawObject = new DrawObject[(int)DRAW_TYPE::NUM];

	//背景の初期化処理
	m_pBG = new BG((char*)"data\\texture\\game_bg_scroll.jpg");
	m_pBG_Moon = new BGPlanet((char*)"data\\texture\\moon.png");

	m_pTextManagement = new TextManagement();

	//=======================
	// 弾
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_RED].SetTextureName((char*)"data\\texture\\bullet_red.png");
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_GREEN].SetTextureName((char*)"data\\texture\\bullet_green.png");
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_SQUARE_GREEN].SetTextureName((char*)"data\\texture\\bullet02.png");
	//プレイヤー側の弾
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_BULLET].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_SQUARE_GREEN], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	//爆弾
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_BULLET].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_GREEN], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	//敵側の弾
	m_pDrawObject[(int)DRAW_TYPE::BULLET_ENEMY].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_RED]);

	//=======================
	// レーザー
	m_pTexUseful[(int)TEXTURE_TYPE::LASER].SetTextureName((char*)"data\\texture\\laser00.png");

	//敵側のレーザー
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_LASER_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::LASER]);


	//バリア
	m_pTexUseful[(int)TEXTURE_TYPE::BARRIER].SetTextureName((char*)"data\\texture\\Barrier.png");

	//プレイヤー
	m_pTexUseful[(int)TEXTURE_TYPE::PLAYER].SetTextureName((char*)"data\\texture\\player_anime.png");
	m_pDrawObject[(int)DRAW_TYPE::PLAYER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::PLAYER], 1.0f, 0.25f, 1.0f, 4);
	m_pPlayer = new Player(m_pDrawObject[(int)DRAW_TYPE::PLAYER], m_pDrawObject[(int)DRAW_TYPE::PLAYER_BULLET], m_pDrawObject[(int)DRAW_TYPE::PLAYER_BULLET]);

	//=======================
	// 敵
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY].SetTextureName((char*)"data\\texture\\teki2.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_NOREMAL].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY], 0.0f, 0.33f, 1.0f, 3);
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY], 1.0f, 0.33f, 1.0f, 3);
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_GATORING].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY], 2.0f, 0.33f, 1.0f, 3);
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_ATTCK].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY], 2.0f, 0.33f, 1.0f, 3);
	//雑魚
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_PUBLIC].SetTextureName((char*)"data\\texture\\UFO.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_PUBLIC].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_PUBLIC], 1.0f, 1.0f, 1.0f, 3);
	
	//バリアの敵
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_BARRIER].SetTextureName((char*)"data\\texture\\monster11.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_BARRIER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_BARRIER]);
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_BARRIER_BARRIER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BARRIER]);

	//隕石
	m_pTexUseful[(int)TEXTURE_TYPE::METEO].SetTextureName((char*)"data\\texture\\Meteo.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_METEO].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::METEO], 2.0f, 1.0, 1.0f, 3);

	m_pEnemyNormalManagement = new EnemyNormalManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_NOREMAL], m_pDrawObject[(int)DRAW_TYPE::BULLET_ENEMY], 0);
	m_pEnemyLaserManagement = new EnemyLaserManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_LASER], m_pDrawObject[(int)DRAW_TYPE::ENEMY_LASER_LASER], 
		m_pDrawObject[(int)DRAW_TYPE::ENEMY_LASER_LASER], 1);
	m_pEnemyGatoringManagement = new EnemyGatoringManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_GATORING], m_pDrawObject[(int)DRAW_TYPE::BULLET_ENEMY]);
	m_pMeteoManagement = new Management_Meteo(m_pDrawObject[(int)DRAW_TYPE::ENEMY_METEO]);

	//=======================
	// 残弾表示
	m_pTexUseful[(int)TEXTURE_TYPE::NUMBER].SetTextureName((char*)"data\\texture\\number.png");
	m_pDrawObject[(int)DRAW_TYPE::NUMBER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::NUMBER], 0.0f, 0.0909f, 1.0f, 11);
	m_pRemaining_Left = new Number(m_pDrawObject[(int)DRAW_TYPE::NUMBER], D3DXVECTOR2(0.0f, 0.0f), D3DXVECTOR2(40.0f, 60.0f), 2);
	m_pRemaining_Right = new Number(m_pDrawObject[(int)DRAW_TYPE::NUMBER], D3DXVECTOR2(0.0f, 0.0f), D3DXVECTOR2(40.0f, 60.0f), 2);
	m_pRemaining_Center = new Number(m_pDrawObject[(int)DRAW_TYPE::NUMBER], D3DXVECTOR2(0.0f, 0.0f), D3DXVECTOR2(40.0f, 60.0f), 2);
	m_pRemaining_Left->SetInitPos(D3DXVECTOR2(130.0f, 600.0f));
	m_pRemaining_Right->SetInitPos(D3DXVECTOR2(130.0f, 680.0f));
	m_pRemaining_Center->SetInitPos(D3DXVECTOR2(130.0f, 520.0f));

	//=======================
	// コンボ数の横の×
	m_pTexUseful[(int)TEXTURE_TYPE::MULTIPLY].SetTextureName((char*)"data\\texture\\multiply.png");
	m_pDrawObject[(int)DRAW_TYPE::MULTIPLY].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::MULTIPLY], 0.0f, 1.0f, 1.0f, 1);
	m_pMultiply = new UI(m_pDrawObject[(int)DRAW_TYPE::MULTIPLY], D3DXVECTOR2(SCREEN_WIDTH - 130, SCREEN_HEIGHT - 40), D3DXVECTOR2(40.0f, 40.0f), D3DXCOLOR());

	//=======================
	// コンボ継続数表示
	m_pComboNum = new Number(m_pDrawObject[(int)DRAW_TYPE::NUMBER], D3DXVECTOR2(0.0f, 0.0f), D3DXVECTOR2(40.0f, 60.0f), 2);
	m_pComboNum->SetInitPos(D3DXVECTOR2(SCREEN_WIDTH - 30, SCREEN_HEIGHT - 40));

	//=======================
	// プレイヤーの腕の左
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY], 0.0f, 0.33f, 1.0f, 3);
	//弾
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT_BULLET].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_GREEN], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(0.2f, 1.0f, 0.2f, 1.0f));
	//レーザー
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::LASER], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f));
	m_pPlayerLeft = new PlayerLeft(m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT], m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT_BULLET],
		m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT_LASER], m_pPlayer->GetPos(), m_pRemaining_Left, D3DXVECTOR2(30.0f, 600.0f));

	//=======================
	// プレイヤーの腕の右
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_RIGHT].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY], 0.0f, 0.33f, 1.0f, 3);
	//弾
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_RIGHT_BULLET].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_GREEN], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(0.2f, 1.0f, 0.2f, 1.0f));
	//レーザー
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_RIGHT_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::LASER], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f));
	m_pPlayerRight = new PlayerRight(m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_RIGHT], m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_RIGHT_BULLET],
		m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_RIGHT_LASER], m_pPlayer->GetPos(), m_pRemaining_Right, D3DXVECTOR2(30.0f, 680.0f));

	//=======================
	// プレイヤーの腕の真ん中
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_CENTER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY], 0.0f, 0.33f, 1.0f, 3);
	//弾
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_CENTTER_BULLET].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_GREEN], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(0.2f, 1.0f, 0.2f, 1.0f));
	//レーザー
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_CENTER_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::LASER], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f));
	m_pPlayerCenter = new PlayerCenter(m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_CENTER], m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_CENTTER_BULLET],
		m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_CENTER_LASER], m_pPlayer->GetPos(), m_pRemaining_Center, D3DXVECTOR2(30.0f, 520.0f));

	//腕の交換
	m_pPlayerArmChange = new PlayerArmChange(m_pPlayerLeft, m_pPlayerRight, m_pPlayerCenter);

	//爆発
	m_pTexUseful[(int)TEXTURE_TYPE::EXPLOSION].SetTextureName((char*)"data\\texture\\explosion000.png");
	m_pDrawObject[(int)DRAW_TYPE::EXPLOSION].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::EXPLOSION], 0.0f, 0.125f, 1.0f, 7);
	m_pExplosionManagement = new ExplosionManagement(m_pDrawObject[(int)DRAW_TYPE::EXPLOSION]);

	//敵のアイテム
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_ITEM].SetTextureName((char*)"data\\texture\\EnemyItem.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_ITEM].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_ITEM], 0.0f, 1.0f, 1.0f, 1);
	m_pItemManagement = new ItemManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_ITEM]);

	//数字の初期化
	m_pScore->SetInitPos(NUMBER_POS);
	m_pScore->SetPos(NUMBER_POS);
	m_pScore->SetSize(NUMBER_SIZE);
	m_pScore->SetDigit(NUMBER_DIGIT);

	//プレイヤーのHP
	m_pTexUseful[(int)TEXTURE_TYPE::PLAYER_HP].SetTextureName((char*)"data\\texture\\hp.png");
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_HP_BAR].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::PLAYER_HP], 0.0f, 1.0f, 1.0f, 1);

	m_pPlayerHP = new PlayerHP(m_pDrawObject[(int)DRAW_TYPE::PLAYER_HP_BAR], m_pExplosionManagement, m_pPlayer);

	//ボム
	m_pDrawObject[(int)DRAW_TYPE::BOMB].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_GREEN]);
	m_pBom = new Bom(m_pDrawObject[(int)DRAW_TYPE::BOMB], 3);

	//敵の管理
	m_pAllEnemyManagement = new AllEnemyManagement;
	m_pAllEnemyManagement->AddPointer(m_pEnemyNormalManagement);
	m_pAllEnemyManagement->AddPointer(m_pEnemyLaserManagement);
	m_pAllEnemyManagement->AddPointer(m_pEnemyGatoringManagement);

	//========================================================
	// 全ての当たり判定
	m_pColAll = new CollisionAll(m_pPlayer, m_pPlayerLeft, m_pPlayerRight, m_pExplosionManagement,
		m_pItemManagement, m_pScore, m_pBom, m_pMeteoManagement);

	//敵のポインタをセット（順番変えるのNG）
	m_pColAll->AddEnemyPointer(m_pEnemyNormalManagement);
	m_pColAll->AddEnemyPointer(m_pEnemyLaserManagement);
	m_pColAll->AddEnemyPointer(m_pEnemyGatoringManagement);
	//m_pColAll->AddEnemyPointer(m_pMeteoManagement);
}

//==========================
// 終了処理
//==========================
Game::~Game()
{
	//描画がない物から消していく
	delete m_pAllEnemyManagement;
	delete m_pPlayerArmChange;
	delete m_pColAll;

	//ゲームオブジェクトを消す
	delete m_pBom;
	delete m_pBG;
	delete m_pBG_Moon;
	delete m_pExplosionManagement;
	delete m_pEnemyNormalManagement;
	delete m_pEnemyLaserManagement;
	delete m_pEnemyGatoringManagement;
	delete m_pMeteoManagement;
	delete m_pItemManagement;
	delete m_pPlayer;
	delete m_pPlayerHP;
	delete m_pPlayerLeft;
	delete m_pPlayerRight;
	delete m_pRemaining_Left;
	delete m_pRemaining_Right;
	delete m_pRemaining_Center;
	delete m_pPlayerCenter;
	delete m_pComboNum;
	delete m_pMultiply;
	delete m_pTextManagement;

	//そのほか
	delete[] m_pDrawObject;
	delete[] m_pTexUseful;

	//BGMをストップ
	StopSound(m_BGM);
}

//======================
// 更新処理
//======================
void Game::Update(void)
{
	//ヒットストップ
	if (StopFlame > 0)
	{
		StopFlame--;
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
	m_pEnemyNormalManagement->Update(m_pPlayer->GetPos());
	//m_pEnemyMissileManagement->Update(m_pPlayer->GetPos());
	m_pEnemyLaserManagement->Update();
	m_pEnemyGatoringManagement->Update(m_pPlayer->GetPos());
	//m_pEnemyAttackManagement->Update(m_pPlayer->GetPos());
	//m_pEnemyPublicManagement->Update();
	//m_pEnemyBarrierManagement->Update();
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
		Fade(SCENE::SCENE_RESULT);
	}

	//最後の列の敵を全て倒したら
	if (m_pEnemyNormalManagement->IsClear() && m_pEnemyLaserManagement->IsClear() &&
		m_pEnemyGatoringManagement->IsClear()) {
		//リザルト画面に行く
		Fade(SCENE::SCENE_RESULT);
	}
}

//==========================
// 描画処理
//==========================
void Game::Draw(void)const
{
	m_pBG->DrawBG();
	m_pBG_Moon->DrawBG();
	m_pPlayer->Draw();

	//プレイヤーの腕の描画処理
	m_pPlayerLeft->ArmDraw();
	m_pPlayerRight->ArmDraw();
	m_pPlayerCenter->ArmDraw();

	//敵の描画
	m_pEnemyNormalManagement->Draw();
	m_pEnemyLaserManagement->Draw();
	m_pEnemyGatoringManagement->Draw();
	//m_pEnemyPublicManagement->Draw();
	//m_pEnemyAttackManagement->Draw();
	m_pMeteoManagement->Draw();
	//m_pEnemyMissileManagement->Draw();
	//m_pEnemyBarrierManagement->Draw();

	//プレイヤーの弾の表示
	m_pPlayer->DrawBullet();

	m_pExplosionManagement->Draw();

	m_pItemManagement->Draw();

	//ボムの描画
	m_pBom->BomDraw();

	//UIの描画
	m_pPlayerHP->DrawHP();
	m_pScore->DrawNumber();
	m_pRemaining_Left->DrawNumber();
	m_pRemaining_Right->DrawNumber();
	m_pRemaining_Center->DrawNumber();
	m_pComboNum->SetNumber(m_pScore->GetComboNum());
	m_pComboNum->DrawNumber();
	m_pMultiply->Draw();

	if (isText)
	{
		m_pTextManagement->Draw();
	}
}


void HitStop(int flame)
{
	StopFlame = flame;
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
