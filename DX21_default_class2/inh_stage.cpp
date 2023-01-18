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
	//数字の初期化
	m_pScore->SetInitPos(NUMBER_POS);
	m_pScore->SetPos(NUMBER_POS);
	m_pScore->SetSize(NUMBER_SIZE);
	m_pScore->SetDigit(NUMBER_DIGIT);

	m_BGM = LoadSound((char*)"data\\BGM\\opportunity (online-audio-converter.com).wav");	//サウンドのロード
	PlaySound(m_BGM, -1);	//BGM再生
	SetVolume(m_BGM, 0.1f);

	//背景の初期化処理
	m_pBG = new BG((char*)"data\\texture\\game_bg_scroll.jpg");

	m_pTexUseful = new TextureUseful[(int)TEXTURE_TYPE::NUM];
	m_pDrawObject = new DrawObject[(int)DRAW_TYPE::NUM];


	//=======================
	// 弾
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_RED].SetTextureName((char*)"data\\texture\\bullet_red.png");
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_GREEN].SetTextureName((char*)"data\\texture\\bullet_green.png");
	//緑の弾
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_BULLET].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_GREEN], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	//敵側の弾
	m_pDrawObject[(int)DRAW_TYPE::BULLET_ENEMY].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_RED]);
	//ボム
	m_pDrawObject[(int)DRAW_TYPE::BOMB].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_GREEN]);
	m_pBom = new Bom(m_pDrawObject[(int)DRAW_TYPE::BOMB], 3);


	//=======================
	//数字関連
	m_pTexUseful[(int)TEXTURE_TYPE::NUMBER].SetTextureName((char*)"data\\texture\\number.png");
	// 残弾表示
	m_pDrawObject[(int)DRAW_TYPE::NUMBER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::NUMBER], 0.0f, 0.0909f, 1.0f, 11);
	// コンボ継続数表示
	m_pComboNum = new Number(m_pDrawObject[(int)DRAW_TYPE::NUMBER], D3DXVECTOR2(SCREEN_WIDTH - 30, 80), D3DXVECTOR2(30.0f, 30.0f), 2);


	//プレイヤー
	m_pTexUseful[(int)TEXTURE_TYPE::PLAYER].SetTextureName((char*)"data\\texture\\player_anime.png");
	m_pDrawObject[(int)DRAW_TYPE::PLAYER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::PLAYER], 1.0f, 0.25f, 1.0f, 4);
	m_pPlayer = new Player(m_pDrawObject[(int)DRAW_TYPE::PLAYER], m_pDrawObject[(int)DRAW_TYPE::PLAYER_BULLET], m_pDrawObject[(int)DRAW_TYPE::PLAYER_BULLET]);

	//フレーム
	m_pTexUseful[(int)TEXTURE_TYPE::FRAME].SetTextureName((char*)"data\\texture\\ui.png");
	m_pDrawObject[(int)DRAW_TYPE::FRAME].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::FRAME]);
	m_pFrame = new UI(m_pDrawObject[(int)DRAW_TYPE::FRAME], D3DXVECTOR2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2),
		D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT));

	//=======================
	// コンボ数の横の×
	m_pTexUseful[(int)TEXTURE_TYPE::MULTIPLY].SetTextureName((char*)"data\\texture\\multiply.png");
	m_pDrawObject[(int)DRAW_TYPE::MULTIPLY].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::MULTIPLY], 0.0f, 1.0f, 1.0f, 1);
	m_pMultiply = new UI(m_pDrawObject[(int)DRAW_TYPE::MULTIPLY], D3DXVECTOR2(SCREEN_WIDTH - 110, 80), D3DXVECTOR2(30.0f, 30.0f), D3DXCOLOR());

	//爆発
	m_pTexUseful[(int)TEXTURE_TYPE::EXPLOSION].SetTextureName((char*)"data\\texture\\explosion000.png");
	m_pDrawObject[(int)DRAW_TYPE::EXPLOSION].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::EXPLOSION], 0.0f, 0.125f, 1.0f, 7);
	m_pExplosionManagement = new ExplosionManagement(m_pDrawObject[(int)DRAW_TYPE::EXPLOSION]);

	//敵のアイテム
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_ITEM].SetTextureName((char*)"data\\texture\\EnemyItem.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_ITEM].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_ITEM], 0.0f, 1.0f, 1.0f, 1);
	m_pItemManagement = new ItemManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_ITEM]);

	//プレイヤーのHP
	m_pTexUseful[(int)TEXTURE_TYPE::PLAYER_HP].SetTextureName((char*)"data\\texture\\hp.png");
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_HP_BAR].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::PLAYER_HP], 0.0f, 0.5f, 1.0f, 2);
	m_pPlayerHP = new PlayerHP(m_pDrawObject[(int)DRAW_TYPE::PLAYER_HP_BAR], m_pExplosionManagement, m_pPlayer, this);



	//=======================
	// プレイヤーの腕
	m_pPlayerCenter = new PlayerCenter(m_pPlayer->GetPos(), m_pDrawObject[(int)DRAW_TYPE::NUMBER], D3DXVECTOR2(120.0f, 450.0f), D3DXVECTOR2(240.0f, 450.0f));
	m_pPlayerLeft = new PlayerLeft(m_pPlayer->GetPos(), m_pDrawObject[(int)DRAW_TYPE::NUMBER], D3DXVECTOR2(120.0f, 570.0f), D3DXVECTOR2(240.0f, 560.0f));
	m_pPlayerRight = new PlayerRight(m_pPlayer->GetPos(), m_pDrawObject[(int)DRAW_TYPE::NUMBER], D3DXVECTOR2(120.0f, 670.0f), D3DXVECTOR2(240.0f, 670.0f));

	//合体できる敵の画像読み込み(敵の弾)
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_BULLET].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_GREEN], 0.0f, 1.0f, 1.0f, 1, D3DXCOLOR(0.2f, 1.0f, 0.2f, 1.0f));
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_LASER], 0.0f, 1.0f, 1.0f, 1, D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f));

	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_BARRIER].SetTextureName((char*)"data\\texture\\bullet_barrier.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_BARRIER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_BARRIER]);
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_STOP].SetTextureName((char*)"data\\texture\\bullet_stop.jpg");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_STOP].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_STOP]);
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_ICE].SetTextureName((char*)"data\\texture\\bullet_ice.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_ICE].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_ICE]);


	//腕の画像セット（弾）
	m_pPlayerLeft->DrawSetSurcleBullet(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_BULLET]);
	m_pPlayerLeft->DrawSetLaser(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LASER]);
	m_pPlayerLeft->DrawSetBarrier(&m_pDrawObject[(int)DRAW_TYPE::BULLET_BARRIER]);
	m_pPlayerLeft->DrawSetBulleStop(&m_pDrawObject[(int)DRAW_TYPE::BULLET_STOP]);
	m_pPlayerLeft->DrawSetIceRain(&m_pDrawObject[(int)DRAW_TYPE::BULLET_ICE]);
	

	//合体できる敵の画像読み込み(敵本体)
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_NORMAL].SetTextureName((char*)"data\\texture\\enemy_missile.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_NORMAL].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_NORMAL]);
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_LASER].SetTextureName((char*)"data\\texture\\enemy_laser.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_LASER]);
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_GATORING].SetTextureName((char*)"data\\texture\\enemy_gatoring.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_GATORING].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_GATORING]);
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_BARRIER].SetTextureName((char*)"data\\texture\\enemy_barrier.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_BARRIER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_BARRIER]);
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_ICE].SetTextureName((char*)"data\\texture\\enemy_icerain.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_ICE].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_ICE]);
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_STOP].SetTextureName((char*)"data\\texture\\enemy_stop.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_STOP].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_STOP]);


	//腕の画像セット（本体）
	m_pPlayerLeft->DrawSetHomingE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_NORMAL]);
	m_pPlayerLeft->DrawSetLaserE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_LASER]);
	m_pPlayerLeft->DrawSetGatoringE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_GATORING]);
	m_pPlayerLeft->DrawSetBarriarE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_BARRIER]);
	m_pPlayerLeft->DrawSetIceRainE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_ICE]);
	m_pPlayerLeft->DrawSetStopE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_STOP]);

	m_pPlayerRight->DrawSetHomingE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_NORMAL]);
	m_pPlayerRight->DrawSetLaserE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_LASER]);
	m_pPlayerRight->DrawSetGatoringE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_GATORING]);
	m_pPlayerRight->DrawSetBarriarE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_BARRIER]);
	m_pPlayerRight->DrawSetIceRainE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_ICE]);
	m_pPlayerRight->DrawSetStopE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_STOP]);

	m_pPlayerCenter->DrawSetHomingE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_NORMAL]);
	m_pPlayerCenter->DrawSetLaserE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_LASER]);
	m_pPlayerCenter->DrawSetGatoringE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_GATORING]);
	m_pPlayerCenter->DrawSetBarriarE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_BARRIER]);
	m_pPlayerCenter->DrawSetIceRainE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_ICE]);
	m_pPlayerCenter->DrawSetStopE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_STOP]);

	//腕の交換
	m_pPlayerArmChange = new PlayerArmChange(m_pPlayerLeft, m_pPlayerRight, m_pPlayerCenter);
}

//==========================
// デストラクタ
//==========================
InhStage::~InhStage()
{
	//描画がない物から消していく
	delete m_pPlayerArmChange;

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