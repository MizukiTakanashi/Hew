//=======================================
// スコア表示関係(cppファイル)
// 作成日：2022/12/16
// 作成者：高梨水希
//=======================================
#include "title_score.h"
#include "sound.h"
#include "inputx.h"
#include "keyboard.h"

//==========================
// 定数の初期化
//==========================
const D3DXVECTOR2 TitleScore::NUMBER_SIZE = D3DXVECTOR2(40.0f, 60.0f);
const float TitleScore::NUMBER_INIT_POS_X = SCREEN_WIDTH / 2 + 200.0f;

const D3DXVECTOR2 TitleScore::FLAME_SIZE = D3DXVECTOR2(1000.0f, 70.0f);
const float TitleScore::FLAME_POS_X = SCREEN_WIDTH / 2 + 100.0f;

const D3DXVECTOR2 TitleScore::PLANET_SIZE = D3DXVECTOR2(70.0f, 70.0f);
const D3DXVECTOR2 TitleScore::PLANET_SATURN_SIZE = D3DXVECTOR2(70.0f, 50.0f);
const float TitleScore::PLANET_POS_X = 100.0f;

const D3DXVECTOR2 TitleScore::WORD_SIZE = D3DXVECTOR2(600.0f, 100.0f);
const float TitleScore::WORD_POS_Y = 60.0f;

//==========================
// デフォルトコンストラクタ
//==========================
TitleScore::TitleScore()
{
	for (int i = 0; i < STAGE_NUM; i++) {
		m_score[i] = 0;
	}

	for (int i = 0; i < (int)UI_TYPE::NUM; i++) {
		m_pUI[i] = nullptr;
	}

	for (int i = 0; i < (int)UI_TYPE::SUN - (int)UI_TYPE::MERCURY + 1; i++) {
		m_pScore[i] = nullptr;
	}
}

//==========================
// 引数付きコンストラクタ
//==========================
TitleScore::TitleScore(int score[])
{
	//スコアの初期化
	for (int i = 0; i < STAGE_NUM; i++) {
		m_score[i] = score[i];
	}

	for (int i = 0; i < STAGE_SUN; i++) {
		if (m_score[i] == 0) {
			m_sun_appearance = false;
		}
	}

	m_pTexUseful = new TextureUseful[(int)TEXTURE_TYPE::NUM];
	m_pDrawObject = new DrawObject[(int)DRAW_TYPE::NUM];

	//背景
	m_pTexUseful[(int)TEXTURE_TYPE::BG].SetTextureName((char*)"data\\texture\\stage_select_bg.jpg");
	m_pDrawObject[(int)DRAW_TYPE::BG].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BG]);
	m_pUI[(int)UI_TYPE::BG] = new UI(m_pDrawObject[(int)DRAW_TYPE::BG], D3DXVECTOR2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2),
		D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT));

	//最高スコアという表示
	m_pTexUseful[(int)TEXTURE_TYPE::WORD].SetTextureName((char*)"data\\texture\\stage_select_bg.jpg");
	m_pDrawObject[(int)DRAW_TYPE::WORD].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::WORD]);
	m_pUI[(int)UI_TYPE::WORD] = new UI(m_pDrawObject[(int)DRAW_TYPE::WORD], D3DXVECTOR2(SCREEN_WIDTH / 2, WORD_POS_Y),
		WORD_SIZE);

	//フレーム
	m_pTexUseful[(int)TEXTURE_TYPE::FLAME].SetTextureName((char*)"data\\texture\\stage_select_bg.jpg");

	//数字
	m_pTexUseful[(int)TEXTURE_TYPE::NUMBER].SetTextureName((char*)"data\\texture\\number.png");
	m_pDrawObject[(int)DRAW_TYPE::NUMBER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::NUMBER], 0.0f, 0.1f, 1.0f, 10);

	//火星
	m_pTexUseful[(int)TEXTURE_TYPE::MARS].SetTextureName((char*)"data\\texture\\mars.png");
	m_pDrawObject[(int)DRAW_TYPE::MARS].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::MARS]);

	//水星
	m_pTexUseful[(int)TEXTURE_TYPE::MERCURY].SetTextureName((char*)"data\\texture\\mercury.png");
	m_pDrawObject[(int)DRAW_TYPE::MERCURY].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::MERCURY]);

	//木星
	m_pTexUseful[(int)TEXTURE_TYPE::JUPITER].SetTextureName((char*)"data\\texture\\jupiter.png");
	m_pDrawObject[(int)DRAW_TYPE::JUPITER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::JUPITER]);

	//金星
	m_pTexUseful[(int)TEXTURE_TYPE::VENUS].SetTextureName((char*)"data\\texture\\venus.png");
	m_pDrawObject[(int)DRAW_TYPE::VENUS].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::VENUS]);

	//土星
	m_pTexUseful[(int)TEXTURE_TYPE::SATURN].SetTextureName((char*)"data\\texture\\saturn.png");
	m_pDrawObject[(int)DRAW_TYPE::SATURN].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::SATURN]);

	int num = 0;
	//太陽がいなければ
	if (!m_sun_appearance) {
		num = (int)UI_TYPE::SUN;
	}
	//太陽がいれば
	else {
		//太陽
		m_pTexUseful[(int)TEXTURE_TYPE::SUN].SetTextureName((char*)"data\\texture\\sun.png");
		m_pDrawObject[(int)DRAW_TYPE::SUN].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::SUN]);

		num = (int)UI_TYPE::FLAME_MERCURY;
	}

	for (int i = (int)UI_TYPE::MERCURY; i < num; i++) {
		float temp_y = (SCREEN_HEIGHT - (WORD_POS_Y + WORD_SIZE.y / 2)) / 7.0f * (i - 1) + (WORD_POS_Y + WORD_SIZE.y / 2);
		
		//惑星
		m_pUI[i] = new UI(m_pDrawObject[i + 1], D3DXVECTOR2(PLANET_POS_X, temp_y),
			PLANET_SIZE);

		//フレーム
		m_pDrawObject[i + 6].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::FLAME]);
		m_pUI[i + 6] = new UI(m_pDrawObject[i + 6], D3DXVECTOR2(FLAME_POS_X, temp_y),
			FLAME_SIZE);

		//数字
		m_pScore[i - 2] = new Number(m_pDrawObject[(int)DRAW_TYPE::NUMBER], D3DXVECTOR2(FLAME_POS_X, temp_y),
			NUMBER_SIZE, NUMBER_DIGIT);
		m_pScore[i - 2]->SetNumber(m_score[i - 2]);
		m_pScore[i - 2]->SetInitPos(D3DXVECTOR2(NUMBER_INIT_POS_X, temp_y));
	}

	m_pUI[(int)UI_TYPE::SATURN]->SetSize(PLANET_SATURN_SIZE);

	//=================
	// 音

	//キャンセル音
	m_SE_02 = LoadSound((char*)"data\\SE\\2_02.wav");
	//SetVolume(g_SE, 0.1f);
}

//==========================
// 更新処理
//==========================
void TitleScore::Update(void)
{
	//キーボードのSpaceを押したら...
	//パッドのAボタンを押したら...
	if (InputGetKeyDown(KK_SPACE) ||
		IsButtonTriggered(0, XINPUT_GAMEPAD_A))
	{
		//タイトル画面に行く
		PlaySound(m_SE_02, 0);
		Fade(SCENE::SCENE_TITLE, STAGE::STAGE_MERCURY);
	}
}

//==========================
// 描画処理
//==========================
void TitleScore::Draw(void)
{
	int num = 0;
	int num_1 = 0;

	//太陽がなければ
	if (!m_sun_appearance) {
		num = (int)UI_TYPE::SUN;
		num_1 = (int)UI_TYPE::SUN - (int)UI_TYPE::MERCURY;
	}
	//太陽がいれば
	else {
		num = (int)UI_TYPE::FLAME_MERCURY;
		num_1 = (int)UI_TYPE::SUN - (int)UI_TYPE::MERCURY + 1;
	}

	//惑星とフレーム
	for (int i = 0; i < num; i++) {
		//惑星
		m_pUI[i]->Draw();
		if (i > (int)UI_TYPE::WORD) {
			//フレーム
			m_pUI[i + 6]->Draw();
		}
	}

	//数字
	for (int i = 0; i < num_1; i++) {
		m_pScore[i]->DrawNumber();
	}
}