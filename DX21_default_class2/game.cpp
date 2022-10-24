//=======================================
// ゲーム画面関係(cppファイル)
// 作成日：2022/07/14
// 作成者：高梨水希
//=======================================
#include "game.h"
#include "input.h"
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
	m_BGM = LoadSound((char*)"data\\BGM\\opportunity (online-audio-converter.com).wav");	//サウンドのロード
	PlaySound(m_BGM, -1);	//BGM再生
	SetVolume(m_BGM, 0.1f);

	m_pTexUseful = new TextureUseful[10];
	m_pDrawObject = new DrawObject[10];

	//背景の初期化処理
	m_pBG = new BG((char*)"data\\texture\\bg_uchu_space.jpg");	

	//弾
	m_pTexUseful[2].SetTextureName((char*)"data\\texture\\bullet00.png");
	m_pDrawObject[2].SetDrawObject(m_pTexUseful[2]);

	//プレイヤー
	m_pTexUseful[0].SetTextureName((char*)"data\\texture\\player2.png");
	m_pDrawObject[0].SetDrawObject(m_pTexUseful[0]);
	m_pPlayer = new Player(m_pDrawObject[0], m_pDrawObject[2]);

	//プレイヤーの左右
	m_pTexUseful[5].SetTextureName((char*)"data\\texture\\player2.png");
	m_pDrawObject[6].SetDrawObject(m_pTexUseful[5]);
	m_pPlayerLeft = new PlayerLeft();

	m_pTexUseful[6].SetTextureName((char*)"data\\texture\\player2.png");
	m_pDrawObject[7].SetDrawObject(m_pTexUseful[6]);
	m_pPlayerRight = new PlayerRight();

	//敵の配置場所
	m_pEnemySetPos = new EnemySetPos;

	//普通の敵
	m_pTexUseful[1].SetTextureName((char*)"data\\texture\\eilian.png");
	m_pDrawObject[1].SetDrawObject(m_pTexUseful[1]);

	m_pEnemyNormalManagement = new EnemyNormalManagement(m_pDrawObject[1], m_pDrawObject[2],
		*m_pEnemySetPos);

	//プレイヤーのHP
	m_pTexUseful[3].SetTextureName((char*)"data\\texture\\playerHP.png");
	m_pDrawObject[3].SetDrawObject(m_pTexUseful[3], 0.0f, 1.0f, 0.5f, 1);

	m_pDrawObject[4].SetDrawObject(m_pTexUseful[3], 1.0f, 1.0f, 0.5f, 1);
	m_pPlayerHP = new PlayerHP(m_pDrawObject[3], m_pDrawObject[4]);

	//爆発
	m_pTexUseful[4].SetTextureName((char*)"data\\texture\\explosion000.png");
	m_pDrawObject[5].SetDrawObject(m_pTexUseful[4], 0.0f, 0.125f, 1.0f, 7);
	m_pExplosionManagement = new ExplosionManagement(m_pDrawObject[5]);

	//数字の初期化
	m_pNumber->SetInitPos(NUMBER_POS);
	m_pNumber->SetPos(NUMBER_POS);
	m_pNumber->SetSize(NUMBER_SIZE);
	m_pNumber->SetDigit(NUMBER_DIGIT);

	//プレイヤーと普通の敵の当たり判定
	m_pPlayerEnemyNormalCol = new PlayerEnemyNormalCollision(m_pPlayer, m_pEnemyNormalManagement, 
		m_pExplosionManagement, m_pNumber);
}

//=========================
// 引数付きコンストラクタ
//=========================
Game::Game(Number * pNumber):m_pNumber(pNumber)
{
	m_BGM = LoadSound((char*)"data\\BGM\\opportunity (online-audio-converter.com).wav");	//サウンドのロード
	PlaySound(m_BGM, -1);	//BGM再生
	SetVolume(m_BGM, 0.1f);

	m_pTexUseful = new TextureUseful[10];
	m_pDrawObject = new DrawObject[10];

	//背景の初期化処理
	m_pBG = new BG((char*)"data\\texture\\bg_uchu_space.jpg");

	//弾
	m_pTexUseful[2].SetTextureName((char*)"data\\texture\\bullet00.png");
	m_pDrawObject[2].SetDrawObject(m_pTexUseful[2]);

	//プレイヤー
	m_pTexUseful[0].SetTextureName((char*)"data\\texture\\player2.png");
	m_pDrawObject[0].SetDrawObject(m_pTexUseful[0]);
	m_pPlayer = new Player(m_pDrawObject[0], m_pDrawObject[2]);

	//プレイヤーの左右
	m_pTexUseful[5].SetTextureName((char*)"data\\texture\\player2.png");
	m_pDrawObject[6].SetDrawObject(m_pTexUseful[5]);
	m_pPlayerLeft = new PlayerLeft(m_pDrawObject[6], m_pPlayer->GetPos(), 0.0f);

	m_pTexUseful[6].SetTextureName((char*)"data\\texture\\player2.png");
	m_pDrawObject[7].SetDrawObject(m_pTexUseful[6]);
	m_pPlayerRight = new PlayerRight(m_pDrawObject[7], m_pPlayer->GetPos(), 0.0f);


	//敵の配置場所
	m_pEnemySetPos = new EnemySetPos;

	//普通の敵
	m_pTexUseful[1].SetTextureName((char*)"data\\texture\\eilian.png");
	m_pDrawObject[1].SetDrawObject(m_pTexUseful[1]);

	m_pEnemyNormalManagement = new EnemyNormalManagement(m_pDrawObject[1], m_pDrawObject[2],
		*m_pEnemySetPos);

	//プレイヤーのHP
	m_pTexUseful[3].SetTextureName((char*)"data\\texture\\playerHP.png");
	m_pDrawObject[3].SetDrawObject(m_pTexUseful[3], 0.0f, 1.0f, 0.5f, 1);

	m_pDrawObject[4].SetDrawObject(m_pTexUseful[3], 1.0f, 1.0f, 0.5f, 1);
	m_pPlayerHP = new PlayerHP(m_pDrawObject[3], m_pDrawObject[4]);

	//爆発
	m_pTexUseful[4].SetTextureName((char*)"data\\texture\\explosion000.png");
	m_pDrawObject[5].SetDrawObject(m_pTexUseful[4], 0.0f, 0.125f, 1.0f, 7);
	m_pExplosionManagement = new ExplosionManagement(m_pDrawObject[5]);

	//数字の初期化
	m_pNumber->SetInitPos(NUMBER_POS);
	m_pNumber->SetPos(NUMBER_POS);
	m_pNumber->SetSize(NUMBER_SIZE);
	m_pNumber->SetDigit(NUMBER_DIGIT);

	//プレイヤーと普通の敵の当たり判定
	m_pPlayerEnemyNormalCol = new PlayerEnemyNormalCollision(m_pPlayer, m_pEnemyNormalManagement, 
		m_pExplosionManagement, m_pNumber);
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
	delete m_pPlayerHP;
	delete m_pPlayer;
	delete m_pPlayerLeft;
	delete m_pPlayerRight;
	delete m_pBG;

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
	m_pBG->Update();

	m_pPlayer->Update();
	m_pPlayerLeft->Update(m_pPlayer->GetPos());
	m_pPlayerRight->Update(m_pPlayer->GetPos());

	m_pExplosionManagement->Update();

	//普通の敵の更新処理
	m_pEnemyNormalManagement->Update(m_pPlayer->GetPos());


	//====================================
	//プレイヤーのHPに対する攻撃の処理
	int attack_num = 0;

	//普通の敵
	attack_num += m_pPlayerEnemyNormalCol->Update();
	
	//プレイヤーのHPを攻撃数によって減らす
	if (attack_num != 0) {
		m_pPlayerHP->ReduceHP((float)attack_num);
		m_pExplosionManagement->SetExplosion(m_pPlayer->GetPos());
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
	m_pPlayerLeft->Draw();
	m_pPlayerRight->Draw();
	m_pEnemyNormalManagement->Draw();

	m_pPlayer->DrawBullet();
	m_pExplosionManagement->Draw();

	//UIの描画
	m_pPlayerHP->DrawHP();
	m_pNumber->DrawNumber();
}
