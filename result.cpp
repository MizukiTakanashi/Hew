//=======================================
// ���U���g��ʊ֌W(cpp�t�@�C��)
// �쐬���F2022/09/22
// �쐬�ҁF��������
//=======================================
#include "result.h"
#include "input.h"
#include "scene.h"
#include "sound.h"

//==========================
// �萔������
//==========================
const D3DXVECTOR2 Result::NUMBER_POS = D3DXVECTOR2(SCREEN_WIDTH / 2 + 100.0f, SCREEN_HEIGHT / 2);
const D3DXVECTOR2 Result::NUMBER_SIZE = D3DXVECTOR2(100.0f, 100.0f);

//==========================
// ����������
//==========================
Result::Result()
{
	m_BGM = LoadSound((char*)"data\\BGM\\silky_sky_away (online-audio-converter.com).wav");	//�T�E���h�̃��[�h
	PlaySound(m_BGM, -1);

	m_pTexUse = new TextureUseful((char*)"data\\texture\\result.png");
	m_pDrawOb = new DrawObject(*m_pTexUse);
	m_pBG = new UI(*m_pDrawOb, D3DXVECTOR2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT));
}

//=========================
// �����t���R���X�g���N�^
//=========================
Result::Result(Number * pNumber):m_pNumber(pNumber)
{
	m_BGM = LoadSound((char*)"data\\BGM\\silky_sky_away (online-audio-converter.com).wav");	//�T�E���h�̃��[�h
	PlaySound(m_BGM, -1);

	m_pTexUse = new TextureUseful((char*)"data\\texture\\result.png");
	m_pDrawOb = new DrawObject(*m_pTexUse);
	m_pBG = new UI(*m_pDrawOb, D3DXVECTOR2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT));

	m_pNumber->SetDigit(NUMBER_DIGIT);
	m_pNumber->SetInitPos(NUMBER_POS);
	m_pNumber->SetPos(NUMBER_POS);
	m_pNumber->SetSize(NUMBER_SIZE);
}

Result::~Result()
{
	m_pNumber->SetNumber(0);

	StopSound(m_BGM);
}

//======================
// �X�V����
//======================
void Result::Update(void)
{
	//SPACE�L�[�����͂��ꂽ��^�C�g����ʂɖ߂�
	if (GetKeyboardTrigger(DIK_SPACE)){
		SetScene(SCENE::SCENE_TITLE);
	}
}

//==========================
// �`�揈��
//==========================
void Result::Draw(void)const
{
	m_pBG->Draw();

	m_pNumber->DrawNumber();
}
