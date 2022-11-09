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
	m_BGM = LoadSound((char*)"data\\BGM\\silky_sky_away (online-audio-converter.com).wav");	//サウンドのロード
	PlaySound(m_BGM, -1);
	SetVolume(m_BGM, 0.05f);

	m_pTexUse = new TextureUseful((char*)"data\\texture\\result.png");
	m_pDrawOb = new DrawObject(*m_pTexUse);
	m_pBG = new UI(*m_pDrawOb, D3DXVECTOR2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT));
}

//=========================
// 引数付きコンストラクタ
//=========================
Result::Result(Number * pNumber):m_pNumber(pNumber)
{
	m_BGM = LoadSound((char*)"data\\BGM\\silky_sky_away (online-audio-converter.com).wav");	//サウンドのロード
	PlaySound(m_BGM, -1);
	SetVolume(m_BGM, 0.05f);


	m_pTexUse = new TextureUseful((char*)"data\\texture\\result.png");
	m_pDrawOb = new DrawObject(*m_pTexUse);
	m_pBG = new UI(*m_pDrawOb, D3DXVECTOR2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT));

	m_pNumber->SetDigit(NUMBER_DIGIT);
	m_pNumber->SetInitPos(NUMBER_POS);
	m_pNumber->SetPos(NUMBER_POS);
	m_pNumber->SetSize(NUMBER_SIZE);
}

Result::~Result()
{
	m_pNumber->SetNumber(0);

	StopSound(m_BGM);
}

//======================
// 更新処理
//======================
void Result::Update(void)
{
	//SPACEキーが入力されたらタイトル画面に戻る
	if (InputGetKeyDown(KK_SPACE)){
		SetScene(SCENE::SCENE_TITLE);
	}
}

//==========================
// 描画処理
//==========================
void Result::Draw(void)const
{
	m_pBG->Draw();

	m_pNumber->DrawNumber();
}
