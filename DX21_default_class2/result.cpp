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
const D3DXVECTOR2 Result::NUMBER_POS = D3DXVECTOR2(1170, 97);
const D3DXVECTOR2 Result::NUMBER_SIZE = D3DXVECTOR2(30.0f, 30.0f);

//=========================
// �����t���R���X�g���N�^
//=========================
Result::Result(bool isClear,  Score* pNumber, STAGE stagenum) :m_pScore(pNumber), m_stage(stagenum)
{
	m_isClear = isClear;

	//=================
	// ��

	//BGM
	m_BGM = LoadSound((char*)"data\\BGM\\silky_sky_away (online-audio-converter.com).wav");	//�T�E���h�̃��[�h
	PlaySound(m_BGM, -1);
	SetVolume(m_BGM, 0.05f);

	//���艹
	m_SE_01 = LoadSound((char*)"data\\SE\\2_01.wav");
	//SetVolume(g_SE, 0.1f);

	//�J�[�\���ړ���
	m_SE_03 = LoadSound((char*)"data\\SE\\2_03.wav");
	//SetVolume(g_SE, 0.1f);

	switch (m_stage)
	{
	case STAGE::STAGE_MOON:
		m_pTexUse[1] = new TextureUseful((char*)"data\\texture\\moon_name.png");
		break;
	case STAGE::STAGE_MARS:
		m_pTexUse[1] = new TextureUseful((char*)"data\\texture\\mars_name.png");
		break;
	case STAGE::STAGE_MERCURY:
		m_pTexUse[1] = new TextureUseful((char*)"data\\texture\\mercury_name.png");
		break;
	case STAGE::STAGE_JUPITER:
		m_pTexUse[1] = new TextureUseful((char*)"data\\texture\\jupiter_name.png");
		break;
	case STAGE::STAGE_VENUS:
		m_pTexUse[1] = new TextureUseful((char*)"data\\texture\\venus_name.png");
		break;
	case STAGE::STAGE_SATURN:
		m_pTexUse[1] = new TextureUseful((char*)"data\\texture\\saturn_name.png");
		break;
	case STAGE::STAGE_SUN:
		m_pTexUse[1] = new TextureUseful((char*)"data\\texture\\sun_name.png");
		break;
	case STAGE::STAGE_NUM:
		break;
	default:
		break;
	}

	if (isClear)
	{
		m_pTexUse[0] = new TextureUseful((char*)"data\\texture\\bg_clear.png");
	}
	else
	{
		m_pTexUse[0] = new TextureUseful((char*)"data\\texture\\bg_gameover.jpg");
	}

	m_pTexUse[2] = new TextureUseful((char*)"data\\texture\\cursor.png");

	m_pDrawOb[0] = new DrawObject(*m_pTexUse[0]);
	m_pDrawOb[1] = new DrawObject(*m_pTexUse[1]);
	m_pDrawOb[2] = new DrawObject(*m_pTexUse[2]);

	m_pBG = new UI(*m_pDrawOb[0], D3DXVECTOR2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT));
	m_pStageTitle = new UI(*m_pDrawOb[1], D3DXVECTOR2(510, 97), D3DXVECTOR2(220, 27));
	m_pCursor = new UI(*m_pDrawOb[2], D3DXVECTOR2(480, 490), D3DXVECTOR2(30, 30));

	m_pScore->SetDigit(NUMBER_DIGIT);
	m_pScore->SetInitPos(NUMBER_POS);
	m_pScore->SetPos(NUMBER_POS);
	m_pScore->SetSize(NUMBER_SIZE);
}

Result::~Result()
{
	m_pScore->SetNumber(0);

	StopSound(m_BGM);

	//delete m_pTexUse;
	//delete m_pDrawOb;
	delete m_pBG;
	delete m_pStageTitle;
	delete m_pCursor;

}

//======================
// �X�V����
//======================
void Result::Update(void)
{
	//�㉺�̃{�^���������ꂽ��I����ύX
	if (InputGetKeyDown(KK_DOWN) && !m_isClear || InputGetKeyDown(KK_UP) && !m_isClear ||
		IsButtonTriggered(0, XINPUT_GAMEPAD_DPAD_UP) && !m_isClear || 
		IsButtonTriggered(0, XINPUT_GAMEPAD_DPAD_DOWN) && !m_isClear){
		Select();
		PlaySound(m_SE_03, 0);
	}

	//���X�e�B�b�N�ō��ɓ|���ꂽ��...
	if (GetThumbLeftY(0) < -0.5f) {
		//�O�t���[���̃X�e�B�b�N���E�ɓ|����Ă���...(�A������������)
		if (m_thumb_before >= -0.5f) {
			//���ɂ��炷
			Select();
			PlaySound(m_SE_03, 0);
		}
	}
	//���X�e�B�b�N�ŉE�ɓ|���ꂽ��...
	if (GetThumbLeftY(0) > 0) {
		//�O�t���[���̃X�e�B�b�N�����ɓ|����Ă���...(�A������������)
		if (m_thumb_before <= 0.0f) {
			//�E�ɂ��炷
			Select();
			PlaySound(m_SE_03, 0);
		}
	}
	//�X�e�B�b�N�̒l��ۑ�
	m_thumb_before = GetThumbLeftY(0);

	//�I���ɂ���ăJ�[�\���ʒu��ύX
	if (m_select_retry)
	{
		m_pCursor->SetPos(D3DXVECTOR2(m_pCursor->GetPos().x, 420));
	}
	else
	{
		m_pCursor->SetPos(D3DXVECTOR2(m_pCursor->GetPos().x, 490));
	}

	//�V�[����ύX
	if (InputGetKeyDown(KK_ENTER))
	{
		PlaySound(m_SE_01, 0);

		if (m_select_retry)
		{
			switch (m_stage)
			{
			case STAGE::STAGE_MOON:
				Fade(SCENE::SCENE_GAME, m_stage);
				break;
			case STAGE::STAGE_MARS:
				Fade(SCENE::SCENE_MARS, m_stage);
				break;
			case STAGE::STAGE_MERCURY:
				Fade(SCENE::SCENE_MERCURY, m_stage);
				break;
			case STAGE::STAGE_JUPITER:
				Fade(SCENE::SCENE_JUPITER, m_stage);
				break;
			case STAGE::STAGE_VENUS:
				Fade(SCENE::SCENE_VENUS, m_stage);
				break;
			case STAGE::STAGE_SATURN:
				Fade(SCENE::SCENE_SATURN, m_stage);
				break;
			case STAGE::STAGE_SUN:
				Fade(SCENE::SCENE_SUN, m_stage);
				break;
			case STAGE::STAGE_NUM:
				Fade(SCENE::SCENE_GAME, m_stage);
				break;
			default:
				break;
			}
		}
		else
		{
			Fade(SCENE::SCENE_TITLE, STAGE::STAGE_MOON);

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
	m_pCursor->Draw();
	m_pScore->DrawNumber();
}
