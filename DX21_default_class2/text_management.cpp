//====================================================
// テキストの管理関係(cppファイル)
// 作成日：
// 作成者：恩田洋行
//====================================================
#include "text_management.h"
#include "inputx.h"
#include "keyboard.h"
#include "game.h"
#include "sound.h"

//==========================
// 定数初期化
//==========================
//private
const float TextManagement::FLAME_SIZE_X = 900.0f;
const float TextManagement::FLAME_SIZE_Y = 200.0f;
const float TextManagement::FLAME_POS_X = SCREEN_WIDTH / 2;
const float TextManagement::FLAME_POS_Y = 600.0f;

const float TextManagement::TEXT_POS_X = 330.0f;
const float TextManagement::TEXT_POS_Y = 570.0f;
const float TextManagement::TEXT_BET_X = 20.0f;
const float TextManagement::TEXT_BET_Y = 20.0f;
const float TextManagement::TEXT_SIZE_X = 20.0f;
const float TextManagement::TEXT_SIZE_Y = 20.0f;

//==========================
// デフォルトコンストラクタ
//==========================
TextManagement::TextManagement()
{
	TextureUseful temp((char*)"data\\texture\\text_flame.png");
	m_TextFrame = DrawObject(temp);
	temp.SetTextureName((char*)"data\\texture\\cursor.png");
	m_Triangle = DrawObject(temp);

	//================
	// 音

	//テキスト送る際の音(カーソル移動音)
	m_SE_01 = LoadSound((char*)"data\\SE\\1_03.wav");
	//SetVolume(m_BGM, 0.1f);
}

//==========================
// 更新処理
//==========================
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

		//キーボードのEnterキーを押されたら...
		//パッドのBボタンを押されたら...
		if ((IsButtonTriggered(0, XINPUT_GAMEPAD_B) || InputGetKeyDown(KK_ENTER)) 
			|| m_PaternNum == m_PaternMax)
		{
			m_PaternNum = m_PaternMax;
			m_RunText = false;
		}

	}
	else
	{
		//キーボードのEnterキーを押されたら...
		//パッドのBボタンを押されたら...
		if ((IsButtonTriggered(0, XINPUT_GAMEPAD_B) || InputGetKeyDown(KK_ENTER)) 
			&& GetTextFlg())
		{
			EndText();
			PlaySound(m_SE_01, 0);
		}

	}
}

//==========================
// 描画処理
//==========================
void TextManagement::Draw(void)
{
	m_TextFrame.Draw(D3DXVECTOR2(FLAME_POS_X, FLAME_POS_Y), D3DXVECTOR2(FLAME_SIZE_X, FLAME_SIZE_Y));
	if(!m_RunText)
	m_Triangle.Draw(D3DXVECTOR2(SCREEN_WIDTH - 250, SCREEN_HEIGHT - 90), D3DXVECTOR2(20, 20), 90);

	int x, y;
	for (int i = 0; i < m_PaternNum; i++)
	{
		x = i % TEXT_NUM_X;
		y = i / TEXT_NUM_X;

		m_Text.SetPaterNo((float)i);
		m_Text.Draw(D3DXVECTOR2(TEXT_POS_X + TEXT_BET_X * x, TEXT_POS_Y + TEXT_BET_Y * y), D3DXVECTOR2(TEXT_SIZE_X, TEXT_SIZE_Y));
	}
}

void TextManagement::SetText(void)
{
	TextureUseful temp;
	switch (m_TextCount)
	{
	case 0:
		temp.SetTextureName((char*)"data\\texture\\01story.png");
		m_Text = DrawObject(temp, 0, 1.0f / 30, 1.0f / 3, 30);
		m_PaternMax = 90;

		break;
	case 1:	
		temp.SetTextureName((char*)"data\\texture\\02story2.png");
		m_Text = DrawObject(temp, 0, 1.0f / 30, 1.0f / 2, 30);
		m_PaternMax = 60;

		break;
	case 2:
		temp.SetTextureName((char*)"data\\texture\\player operation.png");
		m_Text = DrawObject(temp, 0, 1.0f / 30, 1.0f / 2, 30);
		m_PaternMax = 60;

		break;
	case 3:
		temp.SetTextureName((char*)"data\\texture\\player operation2.png");
		m_Text = DrawObject(temp, 0, 1.0f / 30, 1.0f / 4, 30);
		m_PaternMax = 120;

		break;
	case 4:
		temp.SetTextureName((char*)"data\\texture\\gatling description.png");
		m_Text = DrawObject(temp, 0, 1.0f / 30, 1.0f / 4, 30);
		m_PaternMax = 120;

		break;
	case 5:
		temp.SetTextureName((char*)"data\\texture\\Combined explanation.png");
		m_Text = DrawObject(temp, 0, 1.0f / 30, 1.0f / 3, 30);
		m_PaternMax = 90;

		break;
	case 6:
		temp.SetTextureName((char*)"data\\texture\\Combined explanation2.png");
		m_Text = DrawObject(temp, 0, 1.0f / 30, 1.0f / 4, 30);
		m_PaternMax = 120;

		break;
	case 7:
		temp.SetTextureName((char*)"data\\texture\\missile description.png");
		m_Text = DrawObject(temp, 0, 1.0f / 30, 1.0f / 4, 30);
		m_PaternMax = 90;

		break;
	case 8:
		temp.SetTextureName((char*)"data\\texture\\Weapon switch.png");
		m_Text = DrawObject(temp, 0, 1.0f / 30, 1.0f / 4, 30);
		m_PaternMax = 120;

		break;
	case 9:
		temp.SetTextureName((char*)"data\\texture\\Weapon switch2.png");
		m_Text = DrawObject(temp, 0, 1.0f / 30, 1.0f / 2, 30);
		m_PaternMax = 60;

		break;
	case 10:
		temp.SetTextureName((char*)"data\\texture\\laser description.png");
		m_Text = DrawObject(temp, 0, 1.0f / 30, 1.0f / 3, 30);
		m_PaternMax = 90;

		break;
	case 11:
		temp.SetTextureName((char*)"data\\texture\\laser description2.png");
		m_Text = DrawObject(temp, 0, 1.0f / 30, 1.0f / 4, 30);
		m_PaternMax = 120;

		break;
	case 12:
		temp.SetTextureName((char*)"data\\texture\\Bomb description.png");
		m_Text = DrawObject(temp, 0, 1.0f / 30, 1.0f / 3, 30);
		m_PaternMax = 90;

		break;
	case 13:
		temp.SetTextureName((char*)"data\\texture\\Bomb description2.png");
		m_Text = DrawObject(temp, 0, 1.0f / 30, 1.0f / 4, 30);
		m_PaternMax = 120;

		break;
	case 14:
		temp.SetTextureName((char*)"data\\texture\\Bomb description3.png");
		m_Text = DrawObject(temp, 0, 1.0f / 30, 1.0f / 3, 30);
		m_PaternMax = 90;

		break;
	case 15:
		temp.SetTextureName((char*)"data\\texture\\end.png");
		m_Text = DrawObject(temp, 0, 1.0f / 30, 1.0f / 2, 30);
		m_PaternMax = 60;

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

