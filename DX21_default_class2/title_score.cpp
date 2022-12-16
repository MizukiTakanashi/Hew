//=======================================
// スコア表示関係(cppファイル)
// 作成日：2022/12/16
// 作成者：高梨水希
//=======================================
#include "title_score.h"

//==========================
// 引数付きコンストラクタ
//==========================
TitleScore::TitleScore(Score* pNumber, int score[]):m_pScore(pNumber)
{
	bool sun_appearance = true;

	//スコアの初期化
	for (int i = 0; i < STAGE_NUM; i++) {
		m_score[i] = score[i];
	}

	for (int i = 0; i < STAGE_SUN; i++) {
		if (m_score[i] == 0) {
			sun_appearance = false;
		}
	}

	m_pTexUse = new TextureUseful[(int)TEXTURE_TYPE::NUM];
	m_pDrawOb = new DrawObject[(int)DRAW_TYPE::NUM];

	m_pTexUse[(int)TEXTURE_TYPE::BG].SetTextureName((char*)"data\\texture\\stage_select_bg.jpg");
	m_pDrawOb[(int)DRAW_TYPE::BG].SetDrawObject(m_pTexUse[(int)TEXTURE_TYPE::BG]);

	m_pBG = new UI(m_pDrawOb[(int)DRAW_TYPE::BG], D3DXVECTOR2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2),
		D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT));
}

//==========================
// 更新処理
//==========================
void TitleScore::Update(void)
{
}

//==========================
// 描画処理
//==========================
void TitleScore::Draw(void)
{
	m_pBG->Draw();
}
