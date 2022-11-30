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

	//描画関係のもの
	m_pTexUseful = new TextureUseful[(int)TEXTURE_TYPE::NUM];
	m_pDrawObject = new DrawObject[(int)DRAW_TYPE::NUM];

	//火星
	m_pTexUseful[(int)TEXTURE_TYPE::MARS].SetTextureName((char*)"data\\texture\\mars.png");
	m_pDrawObject[(int)DRAW_TYPE::MARS].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::MARS]);

	//水星
	m_pTexUseful[(int)TEXTURE_TYPE::MERCURY].SetTextureName((char*)"data\\texture\\mercury.png");
	m_pDrawObject[(int)DRAW_TYPE::MERCURY].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::MERCURY]);


	//惑星
	m_pPlanet = new StageSelectPlanet(m_pDrawObject[(int)DRAW_TYPE::MARS], m_pDrawObject[(int)DRAW_TYPE::MERCURY]);
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
	//惑星
	m_pPlanet->Draw();
}