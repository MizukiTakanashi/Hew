//=======================================
// ���U���g��ʊ֌W(cpp�t�@�C��)
// �쐬���F2022/09/22
// �쐬�ҁF��������
//=======================================
#include "result.h"

//#include "input.h"
#include "inputx.h"
#include "keyboard.h"

#include "scene.h"
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
	m_BGM = LoadSound((char*)"data\\BGM\\silky_sky_away (online-audio-converter.com).wav");	//�T�E���h�̃��[�h
	PlaySound(m_BGM, -1);
	SetVolume(m_BGM, 0.05f);

	m_pTexUse = new TextureUseful((char*)"data\\texture\\result.png");
	m_pDrawOb = new DrawObject(*m_pTexUse);
	m_pBG = new UI(*m_pDrawOb, D3DXVECTOR2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT));
}

//=========================
// �����t���R���X�g���N�^
//=========================
Result::Result(Score * pNumber):m_pScore(pNumber)
{
	m_BGM = LoadSound((char*)"data\\BGM\\silky_sky_away (online-audio-converter.com).wav");	//�T�E���h�̃��[�h
	PlaySound(m_BGM, -1);
	SetVolume(m_BGM, 0.05f);


	m_pTexUse = new TextureUseful((char*)"data\\texture\\result.png");
	m_pDrawOb = new DrawObject(*m_pTexUse);
	m_pBG = new UI(*m_pDrawOb, D3DXVECTOR2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT));

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
	//SPACE�L�[�����͂��ꂽ��^�C�g����ʂɖ߂�
	if (InputGetKeyDown(KK_SPACE)){
		Fade(SCENE::SCENE_TITLE);
	}
}

//==========================
// �`�揈��
//==========================
void Result::Draw(void)const
{
	m_pBG->Draw();

	m_pScore->DrawNumber();
}
