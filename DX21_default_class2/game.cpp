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
const D3DXVECTOR2 Game::NUMBER_POS = D3DXVECTOR2(350.0f, 30.0f);
const D3DXVECTOR2 Game::NUMBER_SIZE = D3DXVECTOR2(40.0f, 40.0f);

//==========================
// 初期化処理
//==========================
Game::Game()
{
	//m_BGM = LoadSound((char*)"data\\BGM\\opportunity (online-audio-converter.com).wav");	//サウンドのロード
	//PlaySound(m_BGM, -1);	//BGM再生
	//SetVolume(m_BGM, 0.1f);

	//m_pTexUseful = new TextureUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_NUM];
	//m_pDrawObject = new DrawObject[(int)DRAW_TYPE::DRAW_TYPE_NUM];

	////背景の初期化処理
	//m_pBG = new BG((char*)"data\\texture\\bg_uchu_space.jpg");	

	////弾
	//m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_BULLET].SetTextureName((char*)"data\\texture\\bullet00.png");
	////m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_BULLET].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_BULLET]);

	////レーザー
	//m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_LASER].SetTextureName((char*)"data\\texture\\laser00.png");
	////m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_LASER]);

	////プレイヤー
	//m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_PLAYER].SetTextureName((char*)"data\\texture\\player.png");
	//m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_PLAYER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_PLAYER]);
	//m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_PLAYER_BULLET].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_BULLET]);
	//m_pPlayer = new Player(m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_PLAYER], m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_PLAYER_BULLET]);

	////プレイヤーの左右
	//m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_PLAYER_ARM].SetTextureName((char*)"data\\texture\\arm.png");
	//m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_PLAYER_ARM_LEFT].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_PLAYER_ARM]);
	//m_pPlayerLeft = new PlayerLeft();

	//m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_PLAYER_ARM_RIGHT].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_PLAYER_ARM]);
	//m_pPlayerRight = new PlayerRight();

	////敵の配置場所
	//m_pEnemySetPos = new EnemySetPos;

	////普通の敵
	//m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_ENEMY1].SetTextureName((char*)"data\\texture\\eilian.png");
	//m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_ENEMY1].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_ENEMY1]);
	//m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_ENEMY1_BULLET].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_BULLET]);

	//m_pEnemyNormalManagement = 
	//	new EnemyNormalManagement(m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_ENEMY1], 
	//		m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_ENEMY1_BULLET], *m_pEnemySetPos);

	////レーザーの敵
	//m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_ENEMY2_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_LASER]);
	//m_pEnemyLaserManagement = new EnemyLaserManagement(m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_ENEMY2],
	//	m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_ENEMY2_LASER], *m_pEnemySetPos);

	////爆発
	//m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_EXPLOSION].SetTextureName((char*)"data\\texture\\explosion000.png");
	//m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_EXPLOSION].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_EXPLOSION], 0.0f, 0.125f, 1.0f, 7);
	//m_pExplosionManagement = new ExplosionManagement(m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_EXPLOSION]);

	////プレイヤーのHP
	//m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_PLAYER_HP].SetTextureName((char*)"data\\texture\\playerHP.png");
	//m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_PLAYER_HP].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_PLAYER_HP], 0.0f, 1.0f, 0.5f, 1);
	//m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_PLAYER_HP_FRAME].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_PLAYER_HP], 1.0f, 1.0f, 0.5f, 1);

	//m_pPlayerHP = new PlayerHP(m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_PLAYER_HP], 
	//	m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_PLAYER_HP_FRAME], m_pExplosionManagement);

	////敵のアイテム
	//m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_ENEMY_ITEM_EXPLOSION].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::TEXTURE_TYPE_EXPLOSION], 0.0f, 0.125f, 1.0f, 7);
	//m_pItemManagement = new ItemManagement(m_pDrawObject[(int)DRAW_TYPE::DRAW_TYPE_ENEMY_ITEM_EXPLOSION]);

	////数字の初期化
	//m_pNumber->SetInitPos(NUMBER_POS);
	//m_pNumber->SetPos(NUMBER_POS);
	//m_pNumber->SetSize(NUMBER_SIZE);
	//m_pNumber->SetDigit(NUMBER_DIGIT);

	////プレイヤーと普通の敵の当たり判定
	//m_pPlayerEnemyNormalCol = new PlayerEnemyNormalCollision(m_pPlayer, m_pEnemyNormalManagement,
	//	m_pExplosionManagement, m_pNumber, m_pItemManagement);

	////プレイヤーとレーザーの敵の当たり判定
	//m_pPlayerEnemyLaserCol = new PlayerEnemyLaserCollision(m_pPlayer, m_pEnemyLaserManagement,
	//	m_pExplosionManagement, m_pNumber, m_pItemManagement);

	////プレイヤーの腕と敵のアイテムの当たり判定
	//m_ArmEnemyCollision = new ArmEnemyCollision(m_pPlayerLeft, m_pPlayerRight, m_pItemManagement);

	//m_pArmEnemyCol = new PlayerArmEnemyCol();

	////敵の管理
	//m_pAllEnemyManagement = new AllEnemyManagement(m_pEnemyNormalManagement, m_pEnemyLaserManagement, 2);
}

//=========================
// 引数付きコンストラクタ
//=========================
Game::Game(Number * pNumber):m_pNumber(pNumber)
{
	m_BGM = LoadSound((char*)"data\\BGM\\opportunity (online-audio-converter.com).wav");	//サウンドのロード
	PlaySound(m_BGM, -1);	//BGM再生
	SetVolume(m_BGM, 0.1f);

	m_pTexUseful = new TextureUseful[(int)TEXTURE_TYPE::NUM];
	m_pDrawObject = new DrawObject[(int)DRAW_TYPE::NUM];

	//背景の初期化処理
	m_pBG = new BG((char*)"data\\texture\\bg_uchu_space.jpg");

	//=======================
	// 弾
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET].SetTextureName((char*)"data\\texture\\bullet_red.png");
	//プレイヤー側の弾
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_BULLET].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f));
	//敵側の弾
	m_pDrawObject[(int)DRAW_TYPE::BULLET_ENEMY].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET]);
	
	//=======================
	// レーザー
	m_pTexUseful[(int)TEXTURE_TYPE::LASER].SetTextureName((char*)"data\\texture\\laser00.png");

	//敵側のレーザー
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_LASER_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::LASER]);
	
	//プレイヤー
	m_pTexUseful[(int)TEXTURE_TYPE::PLAYER].SetTextureName((char*)"data\\texture\\player.png");
	m_pDrawObject[(int)DRAW_TYPE::PLAYER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::PLAYER]);
	m_pPlayer = new Player(m_pDrawObject[(int)DRAW_TYPE::PLAYER], m_pDrawObject[(int)DRAW_TYPE::PLAYER_BULLET]);

	//敵の配置場所
	m_pEnemySetPos = new EnemySetPos;

	//=======================
	// 敵
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY].SetTextureName((char*)"data\\texture\\teki2.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_NOREMAL].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY], 0.0f, 0.33f, 1.0f, 3);
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY], 1.0f, 0.33f, 1.0f, 3);
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_GATORING].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY], 2.0f, 0.33f, 1.0f, 3);

	m_pEnemyNormalManagement = new EnemyNormalManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_NOREMAL], m_pDrawObject[(int)DRAW_TYPE::BULLET_ENEMY],
		*m_pEnemySetPos);
	m_pEnemyLaserManagement = new EnemyLaserManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_LASER], m_pDrawObject[(int)DRAW_TYPE::ENEMY_LASER_LASER],
		*m_pEnemySetPos);
	m_pEnemyGatoringManagement = new EnemyGatoringManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_GATORING], m_pDrawObject[(int)DRAW_TYPE::BULLET_ENEMY],
		*m_pEnemySetPos);

	//=======================
	// プレイヤーの腕の左
	//m_pTexUseful[5].SetTextureName((char*)"data\\texture\\arm.png");
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY], 0.0f, 0.33f, 1.0f, 3);
	//弾
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT_BULLET].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f));
	//レーザー
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::LASER], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f));
	m_pPlayerLeft = new PlayerLeft(m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT], m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT_BULLET],
		m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT_LASER], m_pPlayer->GetPos());

	//=======================
	// プレイヤーの腕の右
	//m_pTexUseful[6].SetTextureName((char*)"data\\texture\\arm.png");
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_RIGHT].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY], 0.0f, 0.33f, 1.0f, 3);
	//弾
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_RIGHT_BULLET].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f));
	//レーザー
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_RIGHT_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::LASER], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f));
	m_pPlayerRight = new PlayerRight(m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_RIGHT], m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_RIGHT_BULLET],
		m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_RIGHT_LASER], m_pPlayer->GetPos());

	//腕の交換
	m_pPlayerArmChange=new PlayerArmChange(m_pPlayerLeft, m_pPlayerRight);
	//爆発
	m_pTexUseful[(int)TEXTURE_TYPE::EXPLOSION].SetTextureName((char*)"data\\texture\\explosion000.png");
	m_pDrawObject[(int)DRAW_TYPE::EXPLOSION].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::EXPLOSION], 0.0f, 0.125f, 1.0f, 7);
	m_pExplosionManagement = new ExplosionManagement(m_pDrawObject[(int)DRAW_TYPE::EXPLOSION]);

	//プレイヤーのHP
	m_pTexUseful[(int)TEXTURE_TYPE::PLAYER_HP].SetTextureName((char*)"data\\texture\\playerHP.png");
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_HP_BAR].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::PLAYER_HP], 0.0f, 1.0f, 0.5f, 1);

	m_pDrawObject[(int)DRAW_TYPE::PLAYER_HP_FRAME].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::PLAYER_HP], 1.0f, 1.0f, 0.5f, 1);
	m_pPlayerHP = new PlayerHP(m_pDrawObject[(int)DRAW_TYPE::PLAYER_HP_BAR], m_pDrawObject[(int)DRAW_TYPE::PLAYER_HP_FRAME], m_pExplosionManagement);

	//敵のアイテム
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_ITEM].SetTextureName((char*)"data\\texture\\EnemyItem.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_ITEM].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_ITEM], 0.0f, 1.0f, 1.0f,1 );
	m_pItemManagement = new ItemManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_ITEM]);

	//数字の初期化
	m_pNumber->SetInitPos(NUMBER_POS);
	m_pNumber->SetPos(NUMBER_POS);
	m_pNumber->SetSize(NUMBER_SIZE);
	m_pNumber->SetDigit(NUMBER_DIGIT);

	//プレイヤーと普通の敵の当たり判定
	m_pPlayerEnemyNormalCol = new PlayerEnemyNormalCollision(m_pPlayer, m_pEnemyNormalManagement,
		m_pExplosionManagement, m_pNumber, m_pItemManagement);

	//プレイヤーとレーザーの敵の当たり判定
	m_pPlayerEnemyLaserCol = new PlayerEnemyLaserCollision(m_pPlayer, m_pEnemyLaserManagement,
		m_pExplosionManagement, m_pNumber, m_pItemManagement);

	//プレイヤーとガトリングの敵の当たり判定
	m_pPlayerEnemyGatoringCol = new PlayerEnemyGatoringCollision(m_pPlayer, m_pEnemyGatoringManagement,
		m_pExplosionManagement, m_pNumber, m_pItemManagement);

	//プレイヤーの腕と敵のアイテムの当たり判定
	m_ArmEnemyCollision = new ArmEnemyCollision(m_pPlayerLeft, m_pPlayerRight, m_pItemManagement);

	//敵の管理
	m_pAllEnemyManagement = new AllEnemyManagement;
	m_pAllEnemyManagement->AddPointer(m_pEnemyNormalManagement);
	m_pAllEnemyManagement->AddPointer(m_pEnemyLaserManagement);
	m_pAllEnemyManagement->AddPointer(m_pEnemyGatoringManagement);

	//発射した腕と敵の当たり判定
	m_pArmAllEnemyCollision = new ArmAllEnemyCollision(m_pPlayerLeft, m_pPlayerRight, m_pEnemyLaserManagement,
												m_pEnemyGatoringManagement, m_pEnemyNormalManagement, m_pExplosionManagement);

	//プレイヤーの腕のアイテムの弾と敵の当たり判定
	m_pArmEnemyCol = new PlayerArmEnemyCol(m_pEnemyNormalManagement, m_pEnemyLaserManagement,
		m_pEnemyGatoringManagement, m_pExplosionManagement, m_pItemManagement, m_pNumber);
}

//==========================
// 終了処理
//==========================
Game::~Game()
{
	//描画がない物から消していく
	delete m_pEnemySetPos;

	//ゲームオブジェクトを消す
	delete m_pExplosionManagement;
	delete m_pEnemyNormalManagement;
	delete m_pEnemyLaserManagement;
	delete m_pEnemyGatoringManagement;
	delete m_pPlayerHP;
	delete m_pPlayer;
	delete m_pPlayerLeft;
	delete m_pPlayerRight;
	delete m_pBG;

	delete m_pItemManagement;
	delete m_pPlayerEnemyNormalCol;
	delete m_pPlayerEnemyLaserCol;
	delete m_pPlayerEnemyGatoringCol;
	delete m_pArmEnemyCol;
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
	//背景
	m_pBG->Update();

	//腕の切り替え
	m_pPlayerArmChange->Change();

	//プレイヤー
	m_pPlayer->Update(m_pPlayerHP->IsPlayerInvincible());
	m_pPlayerLeft->Update(m_pPlayer->GetPos(), m_pAllEnemyManagement->GetCloltestEnemyPos(m_pPlayerLeft->GetPos()));
	m_pPlayerRight->Update(m_pPlayer->GetPos(), m_pAllEnemyManagement->GetCloltestEnemyPos(m_pPlayerRight->GetPos()));

	m_pPlayerHP->Update();

	//爆発
	m_pExplosionManagement->Update();

	//敵から落ちるアイテム
	m_pItemManagement->Update();

	//=======================
	// 敵の更新処理
	m_pEnemyNormalManagement->Update(m_pPlayer->GetPos());
	m_pEnemyLaserManagement->Update();
	m_pEnemyGatoringManagement->Update(m_pPlayer->GetPos());
	m_ArmEnemyCollision->Update();
	m_pArmAllEnemyCollision->Update();

	//==========================
	// プレイヤーの腕と敵
	//左腕
	m_pArmEnemyCol->SetPlayerArm(m_pPlayerLeft->GetArmPointer());
	m_pArmEnemyCol->Collision();
	//右腕
	m_pArmEnemyCol->SetPlayerArm(m_pPlayerRight->GetArmPointer());
	m_pArmEnemyCol->Collision();

	//====================================
	//====================================
	//プレイヤーのHPに対する敵の攻撃の処理
	int attack_num = 0;
	int heel_num = 0;
	//普通の敵
	attack_num += m_pPlayerEnemyNormalCol->Update();
	//レーザーの敵
	attack_num += m_pPlayerEnemyLaserCol->Update();
	//レーザーの敵
	attack_num += m_pPlayerEnemyGatoringCol->Update();
	//回復
	heel_num += m_ArmEnemyCollision->Update();

	//プレイヤーのHPを攻撃数によって減らす
	if (attack_num != 0) {
		m_pPlayerHP->ReduceHP((float)attack_num, m_pPlayer->GetPos());
	}
	if (heel_num != 0) {
		m_pPlayerHP->HeelHP((float)heel_num, m_pPlayer->GetPos());
	}
	
	//プレイヤーのHPが0になったら...
	if (m_pPlayerHP->GetHP0Flag()) {
		SetScene(SCENE::SCENE_RESULT);
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
	m_pPlayerLeft->LeftDraw();
	m_pPlayerRight->RightDraw();

	m_pEnemyNormalManagement->Draw();
	m_pEnemyLaserManagement->Draw();
	m_pEnemyGatoringManagement->Draw();

	m_pPlayer->DrawBullet();
	m_pExplosionManagement->Draw();

	m_pItemManagement->Draw();

	//UIの描画
	m_pPlayerHP->DrawHP();
	m_pNumber->DrawNumber();
}
