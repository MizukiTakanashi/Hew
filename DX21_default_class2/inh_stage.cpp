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
const D3DXVECTOR2 InhStage::NUMBER_POS = D3DXVECTOR2(1260.0f, 15.0f);
const D3DXVECTOR2 InhStage::NUMBER_SIZE = D3DXVECTOR2(25.0f, 25.0f);

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
	//PlaySound(m_BGM, -1);	//BGM再生
	SetVolume(m_BGM, 0.1f);

	//背景の初期化処理
	m_pBG = new BG((char*)"data\\texture\\game_bg_scroll.jpg");

	m_pPoorvision = new PoorVision((char*)"data\\texture\\poorvision.png");

	m_pTexUseful = new TextureUseful[(int)TEXTURE_TYPE::NUM];
	m_pDrawObject = new DrawObject[(int)DRAW_TYPE::NUM];


	//=======================
	// 弾
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_RED].SetTextureName((char*)"data\\texture\\bullet_red.png");
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_PLAYER].SetTextureName((char*)"data\\texture\\bullet_player.png");
	m_pTexUseful[(int)TEXTURE_TYPE::BOM].SetTextureName((char*)"data\\texture\\bakuhatu-illust21.png");
	//緑の弾
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_BULLET].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_PLAYER], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
	//敵側の弾
	m_pDrawObject[(int)DRAW_TYPE::BULLET_ENEMY].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_RED]);
	//ボム
	m_pDrawObject[(int)DRAW_TYPE::BOMB].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BOM]);
	m_pBom = new Bom(m_pDrawObject[(int)DRAW_TYPE::BOMB], 3);


	//=======================
	//数字関連
	m_pTexUseful[(int)TEXTURE_TYPE::NUMBER].SetTextureName((char*)"data\\texture\\number.png");
	// 残弾表示
	m_pDrawObject[(int)DRAW_TYPE::NUMBER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::NUMBER], 0.0f, 0.1f, 1.0f, 10);
	// コンボ継続数表示
	m_pComboNum = new Number(m_pDrawObject[(int)DRAW_TYPE::NUMBER], D3DXVECTOR2(SCREEN_WIDTH - 30, 50), D3DXVECTOR2(25.0f, 25.0f), 2);

	//=======================
	// コンボ数の横の×
	m_pTexUseful[(int)TEXTURE_TYPE::MULTIPLY].SetTextureName((char*)"data\\texture\\multiply.png");
	m_pDrawObject[(int)DRAW_TYPE::MULTIPLY].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::MULTIPLY], 0.0f, 1.0f, 1.0f, 1);
	m_pMultiply = new UI(m_pDrawObject[(int)DRAW_TYPE::MULTIPLY], D3DXVECTOR2(SCREEN_WIDTH - 110, 50), D3DXVECTOR2(25.0f, 25.0f), D3DXCOLOR());

	//プレイヤー
	m_pTexUseful[(int)TEXTURE_TYPE::PLAYER].SetTextureName((char*)"data\\texture\\player_anime.png");
	m_pDrawObject[(int)DRAW_TYPE::PLAYER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::PLAYER], 1.0f, 0.25f, 1.0f, 4);
	m_pPlayer = new Player(m_pDrawObject[(int)DRAW_TYPE::PLAYER], m_pDrawObject[(int)DRAW_TYPE::PLAYER_BULLET], m_pDrawObject[(int)DRAW_TYPE::PLAYER_BULLET]);

	//フレーム
	m_pTexUseful[(int)TEXTURE_TYPE::FRAME].SetTextureName((char*)"data\\texture\\ui.png");
	m_pDrawObject[(int)DRAW_TYPE::FRAME].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::FRAME]);
	m_pFrame = new UI(m_pDrawObject[(int)DRAW_TYPE::FRAME], D3DXVECTOR2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2),
		D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT));

	//爆発
	m_pTexUseful[(int)TEXTURE_TYPE::EXPLOSION].SetTextureName((char*)"data\\texture\\explosion000.png");
	m_pDrawObject[(int)DRAW_TYPE::EXPLOSION].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::EXPLOSION], 0.0f, 0.125f, 1.0f, 7);
	m_pExplosionManagement = new ExplosionManagement(m_pDrawObject[(int)DRAW_TYPE::EXPLOSION]);

	//プレイヤーのHP
	m_pTexUseful[(int)TEXTURE_TYPE::PLAYER_HP].SetTextureName((char*)"data\\texture\\hp.png");
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_HP_BAR].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::PLAYER_HP], 0.0f, 0.5f, 1.0f, 2);
	m_pPlayerHP = new PlayerHP(m_pDrawObject[(int)DRAW_TYPE::PLAYER_HP_BAR], m_pExplosionManagement, m_pPlayer, this);

	//太陽
	//m_pTexUseful[(int)TEXTURE_TYPE::SUN].SetTextureName((char*)"data\\texture\\sun_name.png");
	//m_pDrawObject[(int)DRAW_TYPE::SUN].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::SUN], 0.0f, 1.0f, 1.0f, 1);
	//m_pStageSun = new UI(m_pDrawObject[(int)DRAW_TYPE::SUN], D3DXVECTOR2(160.0f, 40.0f), D3DXVECTOR2(80.0f, 25.0f), D3DXCOLOR());

	//=======================
	//敵のアイテム
	m_pItemManagement = new ItemManagement();
	//画像読み込み
	m_pTexUseful[(int)TEXTURE_TYPE::ITEM_MISSILE].SetTextureName((char*)"data\\texture\\item_missile.png");
	m_pDrawObject[(int)DRAW_TYPE::ITEM_MISSILE].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ITEM_MISSILE]);
	m_pTexUseful[(int)TEXTURE_TYPE::ITEM_LASER].SetTextureName((char*)"data\\texture\\item_laser.png");
	m_pDrawObject[(int)DRAW_TYPE::ITEM_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ITEM_LASER]);
	m_pTexUseful[(int)TEXTURE_TYPE::ITEM_GATORING].SetTextureName((char*)"data\\texture\\item_gatoring.png");
	m_pDrawObject[(int)DRAW_TYPE::ITEM_GATORING].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ITEM_GATORING]);
	m_pTexUseful[(int)TEXTURE_TYPE::ITEM_BARRIER].SetTextureName((char*)"data\\texture\\item_barrier.png");
	m_pDrawObject[(int)DRAW_TYPE::ITEM_BARRIER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ITEM_BARRIER]);
	m_pTexUseful[(int)TEXTURE_TYPE::ITEM_HOTAIRLASER].SetTextureName((char*)"data\\texture\\item_hotairlaserlaser.png");
	m_pDrawObject[(int)DRAW_TYPE::ITEM_HOTAIRLASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ITEM_HOTAIRLASER]);
	m_pTexUseful[(int)TEXTURE_TYPE::ITEM_ICERAIN].SetTextureName((char*)"data\\texture\\item_icerain.png");
	m_pDrawObject[(int)DRAW_TYPE::ITEM_ICERAIN].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ITEM_ICERAIN]);
	m_pTexUseful[(int)TEXTURE_TYPE::ITEM_ICE].SetTextureName((char*)"data\\texture\\item_ice.png");
	m_pDrawObject[(int)DRAW_TYPE::ITEM_ICE].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ITEM_ICE]);
	m_pTexUseful[(int)TEXTURE_TYPE::ITEM_POISONLASER].SetTextureName((char*)"data\\texture\\item_Poisonlaserlaser.png");
	m_pDrawObject[(int)DRAW_TYPE::ITEM_POISONLASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ITEM_POISONLASER]);
	m_pTexUseful[(int)TEXTURE_TYPE::ITEM_FIRE].SetTextureName((char*)"data\\texture\\item_fire.png");
	m_pDrawObject[(int)DRAW_TYPE::ITEM_FIRE].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ITEM_FIRE]);
	m_pTexUseful[(int)TEXTURE_TYPE::ITEM_GRENADE].SetTextureName((char*)"data\\texture\\item_grenade.png");
	m_pDrawObject[(int)DRAW_TYPE::ITEM_GRENADE].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ITEM_GRENADE]);
	//画像セット
	m_pItemManagement->SetDrawMissile(m_pDrawObject[(int)DRAW_TYPE::ITEM_MISSILE]);
	m_pItemManagement->SetDrawLaser(m_pDrawObject[(int)DRAW_TYPE::ITEM_LASER]);
	m_pItemManagement->SetDrawGatoring(m_pDrawObject[(int)DRAW_TYPE::ITEM_GATORING]);
	m_pItemManagement->SetDrawBarrier(m_pDrawObject[(int)DRAW_TYPE::ITEM_BARRIER]);
	m_pItemManagement->SetDrawHotairlaser(m_pDrawObject[(int)DRAW_TYPE::ITEM_HOTAIRLASER]);
	m_pItemManagement->SetDrawIcerain(m_pDrawObject[(int)DRAW_TYPE::ITEM_ICERAIN]);
	m_pItemManagement->SetDrawIce(m_pDrawObject[(int)DRAW_TYPE::ITEM_ICE]);
	m_pItemManagement->SetDrawPoisonlaser(m_pDrawObject[(int)DRAW_TYPE::ITEM_POISONLASER]);
	m_pItemManagement->SetDrawFire(m_pDrawObject[(int)DRAW_TYPE::ITEM_FIRE]);
	m_pItemManagement->SetDrawGrenade(m_pDrawObject[(int)DRAW_TYPE::ITEM_GRENADE]);


	//=======================
	// プレイヤーの腕
	m_pPlayerCenter = new PlayerCenter(m_pPlayer->GetPos(), m_pDrawObject[(int)DRAW_TYPE::NUMBER], D3DXVECTOR2(120.0f, 590.0f), D3DXVECTOR2(230.0f, 590.0f));
	m_pPlayerLeft = new PlayerLeft(m_pPlayer->GetPos(), m_pDrawObject[(int)DRAW_TYPE::NUMBER], D3DXVECTOR2(120.0f, 640.0f), D3DXVECTOR2(230.0f, 640.0f));
	m_pPlayerRight = new PlayerRight(m_pPlayer->GetPos(), m_pDrawObject[(int)DRAW_TYPE::NUMBER], D3DXVECTOR2(120.0f, 690.0f), D3DXVECTOR2(230.0f, 690.0f));

	//合体できる敵の画像読み込み(敵の弾)
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_MISSILE].SetTextureName((char*)"data\\texture\\bullet_missile.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_MISSILE].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_MISSILE]);
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_GATORING].SetTextureName((char*)"data\\texture\\bullet_gatoring.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_GATORING].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_GATORING]);
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_BARRIER].SetTextureName((char*)"data\\texture\\bullet_barrier.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_BARRIER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_BARRIER]);
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_ICE].SetTextureName((char*)"data\\texture\\bullet_ice.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_ICE].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_ICE]);

	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_GATORING].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_GATORING], 0.0f, 1.0f, 1.0f, 1, D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_LASER], 0.0f, 1.0f, 1.0f, 1, D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));



	//腕の画像セット（弾）
	m_pPlayerLeft->DrawSetSurcleBullet(&m_pDrawObject[(int)DRAW_TYPE::BULLET_MISSILE]);
	m_pPlayerLeft->DrawSetGatoring(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_GATORING]);
	m_pPlayerLeft->DrawSetLaser(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LASER]);
	m_pPlayerLeft->DrawSetBarrier(&m_pDrawObject[(int)DRAW_TYPE::BULLET_BARRIER]);
	m_pPlayerLeft->DrawSetIceRain(&m_pDrawObject[(int)DRAW_TYPE::BULLET_ICE]);

	
	m_pPlayerRight->DrawSetSurcleBullet(&m_pDrawObject[(int)DRAW_TYPE::BULLET_MISSILE]);
	m_pPlayerRight->DrawSetGatoring(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_GATORING]);
	m_pPlayerRight->DrawSetLaser(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LASER]);
	m_pPlayerRight->DrawSetBarrier(&m_pDrawObject[(int)DRAW_TYPE::BULLET_BARRIER]);
	m_pPlayerRight->DrawSetIceRain(&m_pDrawObject[(int)DRAW_TYPE::BULLET_ICE]);
	
	m_pPlayerCenter->DrawSetSurcleBullet(&m_pDrawObject[(int)DRAW_TYPE::BULLET_MISSILE]);
	m_pPlayerCenter->DrawSetGatoring(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_GATORING]);
	m_pPlayerCenter->DrawSetLaser(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LASER]);
	m_pPlayerCenter->DrawSetBarrier(&m_pDrawObject[(int)DRAW_TYPE::BULLET_BARRIER]);
	m_pPlayerCenter->DrawSetIceRain(&m_pDrawObject[(int)DRAW_TYPE::BULLET_ICE]);
	

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


	//腕の画像セット（本体）
	m_pPlayerLeft->DrawSetHomingE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_MISSILE]);
	m_pPlayerLeft->DrawSetLaserE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_LASER]);
	m_pPlayerLeft->DrawSetGatoringE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_GATORING]);
	m_pPlayerLeft->DrawSetBarriarE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_BARRIER]);
	m_pPlayerLeft->DrawSetIceRainE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_ICERAIN]);
	m_pPlayerLeft->DrawSetGrenadeE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_GRENADE]);


	m_pPlayerRight->DrawSetHomingE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_MISSILE]);
	m_pPlayerRight->DrawSetLaserE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_LASER]);
	m_pPlayerRight->DrawSetGatoringE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_GATORING]);
	m_pPlayerRight->DrawSetBarriarE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_BARRIER]);
	m_pPlayerRight->DrawSetIceRainE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_ICERAIN]);
	m_pPlayerRight->DrawSetGrenadeE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_GRENADE]);



	m_pPlayerCenter->DrawSetHomingE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_MISSILE]);
	m_pPlayerCenter->DrawSetLaserE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_LASER]);
	m_pPlayerCenter->DrawSetGatoringE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_GATORING]);
	m_pPlayerCenter->DrawSetBarriarE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_BARRIER]);
	m_pPlayerCenter->DrawSetIceRainE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_ICERAIN]);
	m_pPlayerCenter->DrawSetGrenadeE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_GRENADE]);



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
	delete m_pPoorvision;
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