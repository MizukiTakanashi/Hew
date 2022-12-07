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

int StopFlame = 0; //ヒットストップ用


//==========================
// 初期化処理
//==========================
Game::Game()
{
	//m_BGM = LoadSound((char*)"data\\BGM\\opportunity (online-audio-converter.com).wav");	//サウンドのロード
	//PlaySound(m_BGM, -1);	//BGM再生
	//SetVolume(m_BGM, 0.1f);
	//
	//m_pTexUseful = new TextureUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_NUM];
	//m_pDrawObject = new DrawObject[(int)DRAW_TYPE::DRAW_TYPE_NUM];
	//
	////背景の初期化処理
	//m_pBG = new BG((char*)"data\\texture\\bg_uchu_space.jpg");	
	//
	////弾
	//m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_BULLET].SetTextureName((char*)"data\\texture\\bullet00.png");
	////m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_BULLET].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_BULLET]);
	//
	////レーザー
	//m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_LASER].SetTextureName((char*)"data\\texture\\laser00.png");
	////m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_LASER]);
	//
	////プレイヤー
	//m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_PLAYER].SetTextureName((char*)"data\\texture\\player.png");
	//m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_PLAYER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_PLAYER]);
	//m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_PLAYER_BULLET].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_BULLET]);
	//m_pPlayer = new Player(m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_PLAYER], m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_PLAYER_BULLET]);
	//
	////プレイヤーの左右
	//m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_PLAYER_ARM].SetTextureName((char*)"data\\texture\\arm.png");
	//m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_PLAYER_ARM_LEFT].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_PLAYER_ARM]);
	//m_pPlayerLeft = new PlayerLeft();
	//
	//m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_PLAYER_ARM_RIGHT].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_PLAYER_ARM]);
	//m_pPlayerRight = new PlayerRight();
	//
	////敵の配置場所
	//m_pEnemySetPos = new EnemySetPos;
	//
	////普通の敵
	//m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_ENEMY1].SetTextureName((char*)"data\\texture\\eilian.png");
	//m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_ENEMY1].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_ENEMY1]);
	//m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_ENEMY1_BULLET].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_BULLET]);
	//
	//m_pEnemyNormalManagement = 
	//	new EnemyNormalManagement(m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_ENEMY1], 
	//		m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_ENEMY1_BULLET], *m_pEnemySetPos);
	//
	////レーザーの敵
	//m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_ENEMY2_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_LASER]);
	//m_pEnemyLaserManagement = new EnemyLaserManagement(m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_ENEMY2],
	//	m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_ENEMY2_LASER], *m_pEnemySetPos);
	//
	////爆発
	//m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_EXPLOSION].SetTextureName((char*)"data\\texture\\explosion000.png");
	//m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_EXPLOSION].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_EXPLOSION], 0.0f, 0.125f, 1.0f, 7);
	//m_pExplosionManagement = new ExplosionManagement(m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_EXPLOSION]);
	//
	////プレイヤーのHP
	//m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_PLAYER_HP].SetTextureName((char*)"data\\texture\\playerHP.png");
	//m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_PLAYER_HP].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_PLAYER_HP], 0.0f, 1.0f, 0.5f, 1);
	//m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_PLAYER_HP_FRAME].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_PLAYER_HP], 1.0f, 1.0f, 0.5f, 1);
	//
	//m_pPlayerHP = new PlayerHP(m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_PLAYER_HP], 
	//	m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_PLAYER_HP_FRAME], m_pExplosionManagement);
	//
	////敵のアイテム
	//m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_ENEMY_ITEM_EXPLOSION].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_EXPLOSION], 0.0f, 0.125f, 1.0f, 7);
	//m_pItemManagement = new ItemManagement(m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_ENEMY_ITEM_EXPLOSION]);
	//
	////数字の初期化
	//m_pScore->SetInitPos(NUMBER_POS);
	//m_pScore->SetPos(NUMBER_POS);
	//m_pScore->SetSize(NUMBER_SIZE);
	//m_pScore->SetDigit(NUMBER_DIGIT);
	//
	////プレイヤーと普通の敵の当たり判定
	//m_pPlayerEnemyNormalCol = new PlayerEnemyNormalCollision(m_pPlayer, m_pEnemyNormalManagement,
	//	m_pExplosionManagement, m_pScore, m_pItemManagement);
	//
	////プレイヤーとレーザーの敵の当たり判定
	//m_pPlayerEnemyLaserCol = new PlayerEnemyLaserCollision(m_pPlayer, m_pEnemyLaserManagement,
	//	m_pExplosionManagement, m_pScore, m_pItemManagement);
	//
	////プレイヤーの腕と敵のアイテムの当たり判定
	//m_ArmEnemyCollision = new ArmEnemyCollision(m_pPlayerLeft, m_pPlayerRight, m_pItemManagement);
	//
	//m_pArmEnemyCol = new PlayerArmEnemyCol();
	//
	////敵の管理
	//m_pAllEnemyManagement = new AllEnemyManagement(m_pEnemyNormalManagement, m_pEnemyLaserManagement, 2);
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
	m_pBG = new BG((char*)"data\\texture\\moon_bg.png");

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

	//プレイヤー
	m_pTexUseful[(int)TEXTURE_TYPE::PLAYER].SetTextureName((char*)"data\\texture\\player_00.png");
	m_pDrawObject[(int)DRAW_TYPE::PLAYER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::PLAYER]);
	m_pPlayer = new Player(m_pDrawObject[(int)DRAW_TYPE::PLAYER], m_pDrawObject[(int)DRAW_TYPE::PLAYER_BULLET], m_pDrawObject[(int)DRAW_TYPE::PLAYER_BULLET]);

	//敵の配置場所
	//m_pEnemySetPos = new EnemySetPos;

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
	//隕石
	m_pTexUseful[(int)TEXTURE_TYPE::METEO].SetTextureName((char*)"data\\texture\\Meteo.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_METEO].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::METEO], 2.0f, 1.0, 1.0f, 3);

	m_pEnemyNormalManagement = new EnemyNormalManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_NOREMAL], m_pDrawObject[(int)DRAW_TYPE::BULLET_ENEMY]);
	m_pEnemyMissileManagement = new EnemyMissileManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_NOREMAL], m_pDrawObject[(int)DRAW_TYPE::BULLET_ENEMY]);
	m_pEnemyLaserManagement = new EnemyLaserManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_LASER], m_pDrawObject[(int)DRAW_TYPE::ENEMY_LASER_LASER]);
	m_pEnemyGatoringManagement = new EnemyGatoringManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_GATORING], m_pDrawObject[(int)DRAW_TYPE::BULLET_ENEMY]);
	m_pEnemyPublicManagement = new Management_EnemyPublic(m_pDrawObject[(int)DRAW_TYPE::ENEMY_PUBLIC]);
	m_pEnemyAttackManagement = new EnemyAttackManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_ATTCK]);
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

	m_pPlayerHP = new PlayerHP(m_pDrawObject[(int)DRAW_TYPE::PLAYER_HP_BAR]);

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
		m_pItemManagement, m_pScore, m_pBom);

	//敵のポインタをセット
	m_pColAll->AddEnemyPointer(m_pEnemyNormalManagement);
	m_pColAll->AddEnemyPointer(m_pEnemyLaserManagement);
	m_pColAll->AddEnemyPointer(m_pEnemyGatoringManagement);
	m_pColAll->AddEnemyPointer(m_pEnemyPublicManagement);
	m_pColAll->AddEnemyPointer(m_pEnemyMissileManagement);
	m_pColAll->AddEnemyPointer(m_pEnemyAttackManagement);
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
	delete m_pExplosionManagement;
	delete m_pEnemyNormalManagement;
	delete m_pEnemyLaserManagement;
	delete m_pEnemyGatoringManagement;
	delete m_pEnemyPublicManagement;
	delete m_pEnemyMissileManagement;
	delete m_pEnemyAttackManagement;
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
	//背景
	m_pBG->Update();

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
	m_pEnemyNormalManagement->Update(m_pPlayer->GetPos());
	m_pEnemyMissileManagement->Update(m_pPlayer->GetPos());
	m_pEnemyLaserManagement->Update();
	m_pEnemyGatoringManagement->Update(m_pPlayer->GetPos());
	m_pEnemyAttackManagement->Update(m_pPlayer->GetPos());
	m_pEnemyPublicManagement->Update();
	m_pMeteoManagement->Update();

	//ボム
	m_pBom->Update();

	//====================================
	//プレイヤーのHPに対する処理
	int attack_num = 0;
	int heel_num = 0;

	//プレイヤーの腕

	//ホーミング弾用
	D3DXVECTOR2 temp_pos = m_pAllEnemyManagement->GetCloltestEnemyPos(m_pPlayerLeft->GetPos());

	m_pPlayerLeft->ButtonPress();
	//切り離されたらHPを減らす
	attack_num += m_pPlayerLeft->Update(m_pPlayer->GetPos(), temp_pos);
	m_pPlayerRight->ButtonPress();
	//切り離されたらHPを減らす
	attack_num += m_pPlayerRight->Update(m_pPlayer->GetPos(), temp_pos);
	m_pPlayerCenter->ButtonPress();
	//切り離されたらHPを減らす
	attack_num += m_pPlayerCenter->Update(m_pPlayer->GetPos(), temp_pos);

	//敵とプレイヤーの当たり判定
	attack_num += m_pColAll->Collision();

	//回復
	heel_num = m_pColAll->HeelCollision();

	//プレイヤーのHPを攻撃数によって減らす
	if (attack_num != 0) {
		m_pPlayerHP->ReduceHP((float)attack_num);
	}
	if (heel_num != 0) {
		m_pPlayerHP->HeelHP((float)heel_num);
	}

	//プレイヤーのHPが0になったら...
	if (m_pPlayerHP->GetHP0Flag()) {
		Fade(SCENE::SCENE_RESULT);
	}
}

//==========================
// 描画処理
//==========================
void Game::Draw(void)const
{
	m_pBG->DrawBG();
	m_pPlayer->Draw();

	//プレイヤーの腕の描画処理
	m_pPlayerLeft->ArmDraw();
	m_pPlayerRight->ArmDraw();
	m_pPlayerCenter->ArmDraw();

	//敵の描画
	m_pEnemyNormalManagement->Draw();
	m_pEnemyLaserManagement->Draw();
	m_pEnemyGatoringManagement->Draw();
	m_pEnemyPublicManagement->Draw();
	m_pEnemyAttackManagement->Draw();
	m_pMeteoManagement->Draw();
	m_pEnemyMissileManagement->Draw();

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

}


void HitStop(int flame)
{
	StopFlame = flame;
}
