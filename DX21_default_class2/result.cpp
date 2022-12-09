//=======================================
// リザルト画面関係(cppファイル)
// 作成日：2022/09/22
// 作成者：高梨水希
//=======================================
#include "result.h"

//#include "input.h"
#include "inputx.h"
#include "keyboard.h"

#include "scene.h"
#include "sound.h"

//==========================
// 定数初期化
//==========================
const D3DXVECTOR2 Result::NUMBER_POS = D3DXVECTOR2(800, SCREEN_HEIGHT / 2);
const D3DXVECTOR2 Result::NUMBER_SIZE = D3DXVECTOR2(50.0f, 50.0f);

//==========================
// 初期化処理
//==========================
Result::Result()
{
	//m_BGM = LoadSound((char*)"data\\BGM\\silky_sky_away (online-audio-converter.com).wav");	//サウンドのロード
	//PlaySound(m_BGM, -1);
	//SetVolume(m_BGM, 0.05f);

	//m_pTexUse = new TextureUseful((char*)"data\\texture\\result.png");
	//m_pDrawOb = new DrawObject(*m_pTexUse);
	//m_pBG = new UI(*m_pDrawOb, D3DXVECTOR2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT));
}

//=========================
// 引数付きコンストラクタ
//=========================
Result::Result(Score * pNumber, STAGE_NUM stagenum):m_pScore(pNumber)
{
	m_BGM = LoadSound((char*)"data\\BGM\\silky_sky_away (online-audio-converter.com).wav");	//サウンドのロード
	PlaySound(m_BGM, -1);
	SetVolume(m_BGM, 0.05f);

	switch (stagenum)
	{
	case Result::STAGE_NUM::STAGE1:
		m_pTexUse[0] = new TextureUseful((char*)"data\\texture\\result.png");
		m_pTexUse[1] = new TextureUseful((char*)"data\\texture\\result.png");
		break;
	case Result::STAGE_NUM::STAGE2:
		m_pTexUse[0] = new TextureUseful((char*)"data\\texture\\result.png");
		m_pTexUse[1] = new TextureUseful((char*)"data\\texture\\result.png");
		break;
	case Result::STAGE_NUM::STAGE3:
		m_pTexUse[0] = new TextureUseful((char*)"data\\texture\\result.png");
		m_pTexUse[1] = new TextureUseful((char*)"data\\texture\\result.png");
		break;
	case Result::STAGE_NUM::STAGE4:
		m_pTexUse[0] = new TextureUseful((char*)"data\\texture\\result.png");
		m_pTexUse[1] = new TextureUseful((char*)"data\\texture\\result.png");
		break;
	case Result::STAGE_NUM::STAGE5:
		m_pTexUse[0] = new TextureUseful((char*)"data\\texture\\result.png");
		m_pTexUse[1] = new TextureUseful((char*)"data\\texture\\result.png");
		break;
	case Result::STAGE_NUM::STAGE6:
		m_pTexUse[0] = new TextureUseful((char*)"data\\texture\\result.png");
		m_pTexUse[1] = new TextureUseful((char*)"data\\texture\\result.png");
		break;
	case Result::STAGE_NUM::STAGE7:
		m_pTexUse[0] = new TextureUseful((char*)"data\\texture\\result.png");
		m_pTexUse[1] = new TextureUseful((char*)"data\\texture\\result.png");
		break;
	case Result::STAGE_NUM::STAGE_NUM:
		break;
	default:
		break;
	}

	m_pTexUse[2] = new TextureUseful((char*)"data\\texture\\result.png");
	m_pTexUse[3] = new TextureUseful((char*)"data\\texture\\result.png");

	m_pDrawOb[0] = new DrawObject(*m_pTexUse[0]);
	m_pDrawOb[1] = new DrawObject(*m_pTexUse[1]);
	m_pDrawOb[2] = new DrawObject(*m_pTexUse[2]);
	m_pDrawOb[3] = new DrawObject(*m_pTexUse[3]);

	m_pBG = new UI(*m_pDrawOb[0], D3DXVECTOR2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT));
	m_pTitle = new UI(*m_pDrawOb[1], D3DXVECTOR2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), D3DXVECTOR2(500, 200));
	m_pRetry = new UI(*m_pDrawOb[2], D3DXVECTOR2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 100), D3DXVECTOR2(300, 100));
	m_pContinue = new UI(*m_pDrawOb[3], D3DXVECTOR2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 200), D3DXVECTOR2(300, 100));

	m_pScore->SetDigit(NUMBER_DIGIT);
	m_pScore->SetInitPos(NUMBER_POS);
	m_pScore->SetPos(NUMBER_POS);
	m_pScore->SetSize(NUMBER_SIZE);
}

Result::~Result()
{
	m_pScore->SetNumber(0);

	StopSound(m_BGM);
}

//======================
// 更新処理
//======================
void Result::Update(void)
{
	//SPACEキーが入力されたらタイトル画面に戻る
	if (InputGetKeyDown(KK_SPACE)){
		Fade(SCENE::SCENE_TITLE);
	}
}

//==========================
// 描画処理
//==========================
void Result::Draw(void)const
{
	m_pBG->Draw();
	m_pTitle->Draw();
	m_pRetry->Draw();
	m_pContinue->Draw();

	m_pScore->DrawNumber();
}
