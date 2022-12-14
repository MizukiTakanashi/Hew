//=======================================
// ステージ選択画面関係(cppファイル)
// 作成日：2022/11/29
// 作成者：高梨水希
//=======================================

#include "stage_select.h"

//==========================
// デフォルトコンストラクタ
//==========================
StageSelect::StageSelect()
{
	//スコアを初期化
	for (int i = 0; i < STAGE_NUM; i++) {
		m_stage_score[i] = 0;
	}
}

//==========================
// 引数付きコンストラクタ
//==========================
StageSelect::StageSelect(int stage_score[])
{
	//スコアを初期化
	for (int i = 0; i < STAGE_NUM; i++) {
		m_stage_score[i] = stage_score[i];
	}

	bool stage_clear = true;
	//スコアから全ステージクリアしているか確認
	for (int i = 0; i < STAGE::STAGE_SUN; i++) {
		//スコアが一つでも0の物があれば...
		if (m_stage_score[i] == 0) {
			//ステージクリアしていないをセット
			stage_clear = false;
			break;
		}
	}

	//描画関係のもの
	m_pTexUseful = new TextureUseful[(int)TEXTURE_TYPE::NUM];
	m_pDrawObject = new DrawObject[(int)DRAW_TYPE::NUM];

	//背景
	m_pBG = new BG((char*)"data\\texture\\stage_select_bg.jpg");

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

	//太陽
	m_pTexUseful[(int)TEXTURE_TYPE::SUN].SetTextureName((char*)"data\\texture\\sun.png");
	m_pDrawObject[(int)DRAW_TYPE::SUN].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::SUN]);

	//白い軌道の線
	m_pTexUseful[(int)TEXTURE_TYPE::WHITE_CIRCLE].SetTextureName((char*)"data\\texture\\stage_select_circle.png");
	m_pDrawObject[(int)DRAW_TYPE::WHITE_CIRCLE].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::WHITE_CIRCLE]);

	//惑星
	m_pPlanet = new StageSelectPlanet(m_pDrawObject[(int)DRAW_TYPE::MARS], m_pDrawObject[(int)DRAW_TYPE::MERCURY],
		m_pDrawObject[(int)DRAW_TYPE::JUPITER], m_pDrawObject[(int)DRAW_TYPE::VENUS], m_pDrawObject[(int)DRAW_TYPE::SATURN],
		m_pDrawObject[(int)DRAW_TYPE::SUN], m_pDrawObject[(int)DRAW_TYPE::WHITE_CIRCLE], true/*stage_clear*/);
}

//==========================
// 更新処理
//==========================
void StageSelect::Update(void)
{
	//惑星
	m_pPlanet->Update();
}

//==========================
// 描画処理
//==========================
void StageSelect::Draw(void) const
{
	//背景
	m_pBG->DrawBG();

	//惑星
	m_pPlanet->Draw();
}