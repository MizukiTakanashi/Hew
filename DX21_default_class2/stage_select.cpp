//=======================================
// Xe[WIðæÊÖW(cppt@C)
// ì¬úF2022/11/29
// ì¬ÒFó
//=======================================

#include "stage_select.h"

//==========================
// ftHgRXgN^
//==========================
StageSelect::StageSelect()
{
	//XRAðú»
	for (int i = 0; i < STAGE_NUM; i++) {
		m_stage_score[i] = 0;
	}
}

//==========================
// øt«RXgN^
//==========================
StageSelect::StageSelect(int stage_score[])
{
	//XRAðú»
	for (int i = 0; i < STAGE_NUM; i++) {
		m_stage_score[i] = stage_score[i];
	}

	//`æÖWÌàÌ
	m_pTexUseful = new TextureUseful[(int)TEXTURE_TYPE::NUM];
	m_pDrawObject = new DrawObject[(int)DRAW_TYPE::NUM];

	//wi
	m_pBG = new BG((char*)"data\\texture\\stage_select_bg.jpg");

	//Î¯
	m_pTexUseful[(int)TEXTURE_TYPE::MARS].SetTextureName((char*)"data\\texture\\mars.png");
	m_pDrawObject[(int)DRAW_TYPE::MARS].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::MARS]);

	//¯
	m_pTexUseful[(int)TEXTURE_TYPE::MERCURY].SetTextureName((char*)"data\\texture\\mercury.png");
	m_pDrawObject[(int)DRAW_TYPE::MERCURY].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::MERCURY]);

	//Ø¯
	m_pTexUseful[(int)TEXTURE_TYPE::JUPITER].SetTextureName((char*)"data\\texture\\jupiter.png");
	m_pDrawObject[(int)DRAW_TYPE::JUPITER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::JUPITER]);

	//à¯
	m_pTexUseful[(int)TEXTURE_TYPE::VENUS].SetTextureName((char*)"data\\texture\\venus.png");
	m_pDrawObject[(int)DRAW_TYPE::VENUS].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::VENUS]);

	//y¯
	m_pTexUseful[(int)TEXTURE_TYPE::SATURN].SetTextureName((char*)"data\\texture\\saturn.png");
	m_pDrawObject[(int)DRAW_TYPE::SATURN].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::SATURN]);

	//¾z
	m_pTexUseful[(int)TEXTURE_TYPE::SUN].SetTextureName((char*)"data\\texture\\sun.png");
	m_pDrawObject[(int)DRAW_TYPE::SUN].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::SUN]);

	//f¯
	m_pPlanet = new StageSelectPlanet(m_pDrawObject[(int)DRAW_TYPE::MARS], m_pDrawObject[(int)DRAW_TYPE::MERCURY],
		m_pDrawObject[(int)DRAW_TYPE::JUPITER], m_pDrawObject[(int)DRAW_TYPE::VENUS], m_pDrawObject[(int)DRAW_TYPE::SATURN],
		m_pDrawObject[(int)DRAW_TYPE::SUN]);
}

//==========================
// XV
//==========================
void StageSelect::Update(void)
{
	//f¯
	m_pPlanet->Update();
}

//==========================
// `æ
//==========================
void StageSelect::Draw(void) const
{
	//wi
	m_pBG->DrawBG();

	//f¯
	m_pPlanet->Draw();
}