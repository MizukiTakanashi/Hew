//====================================================
// テキストの管理関係(cppファイル)
// 作成日：
// 作成者：恩田洋行
//====================================================
#include "text_management.h"
#include "inputx.h"
#include "keyboard.h"
#include "game.h"


//==========================
// 定数初期化
//==========================
//public
const float TextManagement::FLAME_SIZE_X = 900.0f;
const float TextManagement::FLAME_SIZE_Y = 200.0f;
const float TextManagement::FLAME_POS_X = SCREEN_WIDTH / 2;
const float TextManagement::FLAME_POS_Y = 600.0f;

const float TextManagement::TEXT_POS_X = 230.0f;
const float TextManagement::TEXT_POS_Y = 570.0f;
const float TextManagement::TEXT_BET_X = 20.0f;
const float TextManagement::TEXT_BET_Y = 20.0f;
const float TextManagement::TEXT_SIZE_X = 20.0f;
const float TextManagement::TEXT_SIZE_Y = 20.0f;
//private

TextManagement::TextManagement()
{
	TextureUseful temp((char*)"data\\texture\\text_flame.png");
	m_TextFrame = DrawObject(temp);
	temp.SetTextureName((char*)"data\\texture\\triangle.png");
	m_Triangle = DrawObject(temp);
}

void TextManagement::Update(void)
{
	m_FlameCount++;

	if (m_FlameCount == m_TexTime[m_TextCount])
	{
		SetText();
	}


	if (m_RunText)
	{
		if (m_FlameCount % 3 == 0)
		{
			m_PaternNum++;
		}
		if (InputGetKeyDown(KK_ENTER) || m_PaternNum == m_PaternMax)
		{
			m_PaternNum = m_PaternMax;
			m_RunText = false;
		}

	}
	else
	{
		if (InputGetKeyDown(KK_ENTER) && GetTextFlg())
		{
			EndText();
		}

	}
}

void TextManagement::Draw(void)
{
	m_TextFrame.Draw(D3DXVECTOR2(FLAME_POS_X, FLAME_POS_Y), D3DXVECTOR2(FLAME_SIZE_X, FLAME_SIZE_Y));
	if(!m_RunText)
	m_Triangle.Draw(D3DXVECTOR2(SCREEN_WIDTH - 220, SCREEN_HEIGHT - 45), D3DXVECTOR2(30, 30));

	int x, y;
	for (int i = 0; i < m_PaternNum; i++)
	{
		x = i % TEXT_NUM_X;
		y = i / TEXT_NUM_X;

		m_Text.SetPaterNo(i);
		m_Text.Draw(D3DXVECTOR2(TEXT_POS_X + TEXT_BET_X * x, TEXT_POS_Y + TEXT_BET_Y * y), D3DXVECTOR2(TEXT_SIZE_X, TEXT_SIZE_Y));
	}
}

void TextManagement::SetText(void)
{
	TextureUseful temp;
	switch (m_TextCount)
	{
	case 0:
		temp.SetTextureName((char*)"data\\texture\\tuto1.png");
		m_Text = DrawObject(temp, 0, 0.025f, 0.25f, 40);
		m_PaternMax = 160;

		break;
	case 1:	
		temp.SetTextureName((char*)"data\\texture\\tuto2.png");
		m_Text = DrawObject(temp, 0, 0.025f, 0.5f, 40);
		m_PaternMax = 80;

		break;
	case 2:
		temp.SetTextureName((char*)"data\\texture\\tuto3.png");
		m_Text = DrawObject(temp, 0, 0.025f, 0.2f, 40);
		m_PaternMax = 200;

		break;
	case 3:
		temp.SetTextureName((char*)"data\\texture\\tuto4.png");
		m_Text = DrawObject(temp, 0, 0.025f, 1.0f / 7, 40);
		m_PaternMax = 280;

		break;
	case 4:
		temp.SetTextureName((char*)"data\\texture\\tuto5.png");
		m_Text = DrawObject(temp, 0, 0.025f, 0.2f, 40);
		m_PaternMax = 200;

		break;
	default:
		break;
	}

	m_RunText = true;
	m_PaternNum = 0;
	StartTextG();
}

void TextManagement::EndText(void)
{
	EndTextG();
	m_FlameCount = 0;
	m_TextCount++;
	Keyboard_Reset();
}

