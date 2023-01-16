//=======================================
// 継承用のステージ関係(cppファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#include "inh_stage.h"
#include "sound.h"

//==========================
// 定数初期化
//==========================
const D3DXVECTOR2 InhStage::NUMBER_POS = D3DXVECTOR2(1230.0f, 30.0f);
const D3DXVECTOR2 InhStage::NUMBER_SIZE = D3DXVECTOR2(30.0f, 30.0f);

//==========================
// グローバル変数
//==========================

//==========================
// 引数付きコンストラクタ
//==========================
InhStage::InhStage(Score* pNumber):m_pScore(pNumber)
{
	m_BGM = LoadSound((char*)"data\\BGM\\opportunity (online-audio-converter.com).wav");	//サウンドのロード
	PlaySound(m_BGM, -1);	//BGM再生
	SetVolume(m_BGM, 0.1f);

	//背景の初期化処理
	m_pBG = new BG((char*)"data\\texture\\game_bg_scroll.jpg");

	//画像読み込み
	m_pTexUseful = new TextureUseful[(int)TEXTURE_TYPE::NUM];
	m_pDrawObject = new DrawObject[(int)DRAW_TYPE::NUM];



	//各オブジェクトインスタンス化



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

	//バリア
	m_pTexUseful[(int)TEXTURE_TYPE::BARRIER].SetTextureName((char*)"data\\texture\\Barrier.png");

	//プレイヤー
	m_pTexUseful[(int)TEXTURE_TYPE::PLAYER].SetTextureName((char*)"data\\texture\\player_anime.png");
	m_pDrawObject[(int)DRAW_TYPE::PLAYER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::PLAYER], 1.0f, 0.25f, 1.0f, 4);
	m_pPlayer = new Player(m_pDrawObject[(int)DRAW_TYPE::PLAYER], m_pDrawObject[(int)DRAW_TYPE::PLAYER_BULLET], m_pDrawObject[(int)DRAW_TYPE::PLAYER_BULLET]);

	//=======================
	// 敵
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY].SetTextureName((char*)"data\\texture\\teki2.png");


	//=======================
	// 残弾表示
	m_pTexUseful[(int)TEXTURE_TYPE::NUMBER].SetTextureName((char*)"data\\texture\\number.png");
	m_pDrawObject[(int)DRAW_TYPE::NUMBER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::NUMBER], 0.0f, 0.0909f, 1.0f, 11);

	//=======================
	// コンボ数の横の×
	m_pTexUseful[(int)TEXTURE_TYPE::MULTIPLY].SetTextureName((char*)"data\\texture\\multiply.png");
	m_pDrawObject[(int)DRAW_TYPE::MULTIPLY].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::MULTIPLY], 0.0f, 1.0f, 1.0f, 1);
	m_pMultiply = new UI(m_pDrawObject[(int)DRAW_TYPE::MULTIPLY], D3DXVECTOR2(SCREEN_WIDTH - 130, SCREEN_HEIGHT - 40), D3DXVECTOR2(40.0f, 40.0f), D3DXCOLOR());

	//=======================
	// コンボ継続数表示
	m_pComboNum = new Number(m_pDrawObject[(int)DRAW_TYPE::NUMBER], D3DXVECTOR2(0.0f, 0.0f), D3DXVECTOR2(40.0f, 60.0f), 2);
	m_pComboNum->SetInitPos(D3DXVECTOR2(SCREEN_WIDTH - 30, SCREEN_HEIGHT - 40));

	//フレーム
	m_pTexUseful[(int)TEXTURE_TYPE::FRAME].SetTextureName((char*)"data\\texture\\ui.png");
	m_pDrawObject[(int)DRAW_TYPE::FRAME].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::FRAME]);
	m_pFrame = new UI(m_pDrawObject[(int)DRAW_TYPE::FRAME], D3DXVECTOR2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2),
		D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT));

	//=======================
	// プレイヤーの腕の左
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY], 0.0f, 0.33f, 1.0f, 3);
	//弾
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT_BULLET].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_GREEN], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(0.2f, 1.0f, 0.2f, 1.0f));
	//レーザー
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_LASER], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f));
	m_pPlayerLeft = new PlayerLeft(m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT], m_pPlayer->GetPos(), m_pDrawObject[(int)DRAW_TYPE::NUMBER], D3DXVECTOR2(130.0f, 600.0f), D3DXVECTOR2(30.0f, 600.0f));

	m_pPlayerLeft->DrawSetSurcleBullet(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT_BULLET]);
	m_pPlayerLeft->DrawSetLaser(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT_LASER]);
	//=======================
	// プレイヤーの腕の右
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_RIGHT].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY], 0.0f, 0.33f, 1.0f, 3);
	//弾
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_RIGHT_BULLET].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_GREEN], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(0.2f, 1.0f, 0.2f, 1.0f));
	//レーザー
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_RIGHT_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_LASER], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f));
	m_pPlayerRight = new PlayerRight(m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_RIGHT], m_pPlayer->GetPos(), m_pDrawObject[(int)DRAW_TYPE::NUMBER], D3DXVECTOR2(130.0f, 680.0f), D3DXVECTOR2(30.0f, 680.0f));

	//=======================
	// プレイヤーの腕の真ん中
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_CENTER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY], 0.0f, 0.33f, 1.0f, 3);
	//弾
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_CENTTER_BULLET].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_GREEN], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(0.2f, 1.0f, 0.2f, 1.0f));
	//レーザー
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_CENTER_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_LASER], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f));
	m_pPlayerCenter = new PlayerCenter(m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_CENTER], m_pPlayer->GetPos(), m_pDrawObject[(int)DRAW_TYPE::NUMBER], D3DXVECTOR2(130.0f, 520.0f), D3DXVECTOR2(30.0f, 520.0f));

	m_pPlayerLeft->DrawSetSurcleBullet(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT_BULLET]);
	m_pPlayerLeft->DrawSetLaser(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT_LASER]);
	m_pPlayerRight->DrawSetSurcleBullet(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT_BULLET]);
	m_pPlayerRight->DrawSetLaser(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT_LASER]);
	m_pPlayerCenter->DrawSetSurcleBullet(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT_BULLET]);
	m_pPlayerCenter->DrawSetLaser(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT_LASER]);


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
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_HP_BAR].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::PLAYER_HP], 0.0f, 0.5f, 1.0f, 2);

	m_pPlayerHP = new PlayerHP(m_pDrawObject[(int)DRAW_TYPE::PLAYER_HP_BAR], m_pExplosionManagement, m_pPlayer);

	//ボム
	m_pDrawObject[(int)DRAW_TYPE::BOMB].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_GREEN]);
	m_pBom = new Bom(m_pDrawObject[(int)DRAW_TYPE::BOMB], 3);

	//m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_METEO].SetTextureName((char*)"data\\texture\\Meteo.png");
	//m_pDrawObject[(int)DRAW_TYPE::ENEMY_METEO].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_METEO]);
	//m_pMeteoManagement = new Management_Meteo();

	//敵の管理
	m_pAllEnemyManagement = new AllEnemyManagement;

	//========================================================
	 //全ての当たり判定
	//m_pColAll = new CollisionAll(m_pPlayer, m_pPlayerLeft, m_pPlayerRight, m_pExplosionManagement,
	//	m_pItemManagement, m_pScore, m_pBom, m_pMeteoManagement);

}

//==========================
// デストラクタ
//==========================
InhStage::~InhStage()
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
	delete m_pMeteoManagement;
	delete m_pItemManagement;
	delete m_pPlayer;
	delete m_pPlayerHP;
	delete m_pPlayerLeft;
	delete m_pPlayerRight;
	delete m_pPlayerCenter;
	delete m_pComboNum;
	delete m_pMultiply;

	//そのほか
	delete[] m_pDrawObject;
	delete[] m_pTexUseful;

	//BGMをストップ
	StopSound(m_BGM);
}