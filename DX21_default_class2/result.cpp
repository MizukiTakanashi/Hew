//=======================================
// ���U���g��ʊ֌W(cpp�t�@�C��)
// �쐬���F2022/09/22
// �쐬�ҁF��������
//=======================================
#include "result.h"

//#include "input.h"
#include "inputx.h"
#include "keyboard.h"

#include "Fade.h"
#include "sound.h"

//==========================
// �萔������
//==========================
const D3DXVECTOR2 Result::NUMBER_POS = D3DXVECTOR2(800, SCREEN_HEIGHT / 2);
const D3DXVECTOR2 Result::NUMBER_SIZE = D3DXVECTOR2(50.0f, 50.0f);

//==========================
// ����������
//==========================
Result::Result()
{
	//m_BGM = LoadSound((char*)"data\\BGM\\silky_sky_away (online-audio-converter.com).wav");	//�T�E���h�̃��[�h
	//PlaySound(m_BGM, -1);
	//SetVolume(m_BGM, 0.05f);

	//m_pTexUse = new TextureUseful((char*)"data\\texture\\result.png");
	//m_pDrawOb = new DrawObject(*m_pTexUse);
	//m_pBG = new UI(*m_pDrawOb, D3DXVECTOR2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT));
}

//=========================
// �����t���R���X�g���N�^
//=========================
Result::Result(Score * pNumber, STAGE stagenum):m_pScore(pNumber)
{
	m_BGM = LoadSound((char*)"data\\BGM\\silky_sky_away (online-audio-converter.com).wav");	//�T�E���h�̃��[�h
	PlaySound(m_BGM, -1);
	SetVolume(m_BGM, 0.05f);

	switch (stagenum)
	{
	case STAGE::STAGE_MOON:
		m_pTexUse[0] = new TextureUseful((char*)"data\\texture\\result.png");
		m_pTexUse[1] = new TextureUseful((char*)"data\\texture\\stage_title.png");
		break;
	case STAGE::STAGE_MARS:
		m_pTexUse[0] = new TextureUseful((char*)"data\\texture\\result.png");
		m_pTexUse[1] = new TextureUseful((char*)"data\\texture\\result.png");
		break;
	case STAGE::STAGE_MERCURY:
		m_pTexUse[0] = new TextureUseful((char*)"data\\texture\\result.png");
		m_pTexUse[1] = new TextureUseful((char*)"data\\texture\\result.png");
		break;
	case STAGE::STAGE_JUPITER:
		m_pTexUse[0] = new TextureUseful((char*)"data\\texture\\result.png");
		m_pTexUse[1] = new TextureUseful((char*)"data\\texture\\result.png");
		break;
	case STAGE::STAGE_VENUS:
		m_pTexUse[0] = new TextureUseful((char*)"data\\texture\\result.png");
		m_pTexUse[1] = new TextureUseful((char*)"data\\texture\\result.png");
		break;
	case STAGE::STAGE_SATURN:
		m_pTexUse[0] = new TextureUseful((char*)"data\\texture\\result.png");
		m_pTexUse[1] = new TextureUseful((char*)"data\\texture\\result.png");
		break;
	case STAGE::STAGE_SUN:
		m_pTexUse[0] = new TextureUseful((char*)"data\\texture\\result.png");
		m_pTexUse[1] = new TextureUseful((char*)"data\\texture\\result.png");
		break;
	case STAGE::STAGE_NUM:
		break;
	default:
		break;
	}

	m_pTexUse[2] = new TextureUseful((char*)"data\\texture\\retry_text.png");
	m_pTexUse[3] = new TextureUseful((char*)"data\\texture\\title_text.png");
	m_pTexUse[4] = new TextureUseful((char*)"data\\texture\\cursor.png");

	m_pDrawOb[0] = new DrawObject(*m_pTexUse[0]);
	m_pDrawOb[1] = new DrawObject(*m_pTexUse[1]);
	m_pDrawOb[2] = new DrawObject(*m_pTexUse[2]);
	m_pDrawOb[3] = new DrawObject(*m_pTexUse[3]);
	m_pDrawOb[4] = new DrawObject(*m_pTexUse[4]);

	m_pBG = new UI(*m_pDrawOb[0], D3DXVECTOR2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT));
	m_pStageTitle = new UI(*m_pDrawOb[1], D3DXVECTOR2(200, 100), D3DXVECTOR2(300, 150));
	m_pText_Retry = new UI(*m_pDrawOb[2], D3DXVECTOR2(SCREEN_WIDTH / 2 + 100, SCREEN_HEIGHT / 2 + 200), D3DXVECTOR2(300, 100));
	m_pText_title = new UI(*m_pDrawOb[3], D3DXVECTOR2(SCREEN_WIDTH / 2 + 100, SCREEN_HEIGHT / 2 + 300), D3DXVECTOR2(300, 100));
	m_pCursor = new UI(*m_pDrawOb[4], D3DXVECTOR2(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 + 300), D3DXVECTOR2(50, 50));

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
// �X�V����
//======================
void Result::Update(void)
{
	//�㉺�̃{�^���������ꂽ��I����ύX
	if (InputGetKeyDown(KK_DOWN) || InputGetKeyDown(KK_UP)){
		Select();
	}

	//�I���ɂ���ăJ�[�\���ʒu��ύX
	if (m_select_retry)
	{
		m_pCursor->SetPos(D3DXVECTOR2(m_pCursor->GetPos().x, m_pText_Retry->GetPos().y));
	}
	else
	{
		m_pCursor->SetPos(D3DXVECTOR2(m_pCursor->GetPos().x, m_pText_title->GetPos().y));
	}

	//�V�[����ύX
	if (InputGetKeyDown(KK_ENTER))
	{
		if (m_select_retry)
		{
			Fade(SCENE::SCENE_GAME);
		}
		else
		{
			Fade(SCENE::SCENE_STAGE_SELECT);

		}
	}
}

//==========================
// �`�揈��
//==========================
void Result::Draw(void)const
{
	m_pBG->Draw();
	m_pStageTitle->Draw();
	m_pText_Retry->Draw();
	m_pText_title->Draw();
	m_pCursor->Draw();

	m_pScore->DrawNumber();

}
