//=======================================
// �X�e�[�W�I����ʊ֌W(cpp�t�@�C��)
// �쐬���F2022/11/29
// �쐬�ҁF��������
//=======================================

#include "stage_select.h"

//==========================
// �f�t�H���g�R���X�g���N�^
//==========================
StageSelect::StageSelect()
{
	//�X�R�A��������
	for (int i = 0; i < STAGE_NUM; i++) {
		m_stage_score[i] = 0;
	}
}

//==========================
// �����t���R���X�g���N�^
//==========================
StageSelect::StageSelect(int stage_score[])
{
	//�X�R�A��������
	for (int i = 0; i < STAGE_NUM; i++) {
		m_stage_score[i] = stage_score[i];
	}

	bool stage_clear = true;
	//�X�R�A����S�X�e�[�W�N���A���Ă��邩�m�F
	for (int i = 0; i < STAGE::STAGE_SUN; i++) {
		//�X�R�A����ł�0�̕��������...
		if (m_stage_score[i] == 0) {
			//�X�e�[�W�N���A���Ă��Ȃ����Z�b�g
			stage_clear = false;
			break;
		}
	}

	//�`��֌W�̂���
	m_pTexUseful = new TextureUseful[(int)TEXTURE_TYPE::NUM];
	m_pDrawObject = new DrawObject[(int)DRAW_TYPE::NUM];

	//�w�i
	m_pBG = new BG((char*)"data\\texture\\stage_select_bg.jpg");

	//�ΐ�
	m_pTexUseful[(int)TEXTURE_TYPE::MARS].SetTextureName((char*)"data\\texture\\mars.png");
	m_pDrawObject[(int)DRAW_TYPE::MARS].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::MARS]);

	//����
	m_pTexUseful[(int)TEXTURE_TYPE::MERCURY].SetTextureName((char*)"data\\texture\\mercury.png");
	m_pDrawObject[(int)DRAW_TYPE::MERCURY].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::MERCURY]);

	//�ؐ�
	m_pTexUseful[(int)TEXTURE_TYPE::JUPITER].SetTextureName((char*)"data\\texture\\jupiter.png");
	m_pDrawObject[(int)DRAW_TYPE::JUPITER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::JUPITER]);

	//����
	m_pTexUseful[(int)TEXTURE_TYPE::VENUS].SetTextureName((char*)"data\\texture\\venus.png");
	m_pDrawObject[(int)DRAW_TYPE::VENUS].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::VENUS]);

	//�y��
	m_pTexUseful[(int)TEXTURE_TYPE::SATURN].SetTextureName((char*)"data\\texture\\saturn.png");
	m_pDrawObject[(int)DRAW_TYPE::SATURN].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::SATURN]);

	//���z
	m_pTexUseful[(int)TEXTURE_TYPE::SUN].SetTextureName((char*)"data\\texture\\sun.png");
	m_pDrawObject[(int)DRAW_TYPE::SUN].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::SUN]);

	//�����O���̐�
	m_pTexUseful[(int)TEXTURE_TYPE::WHITE_CIRCLE].SetTextureName((char*)"data\\texture\\stage_select_circle.png");
	m_pDrawObject[(int)DRAW_TYPE::WHITE_CIRCLE].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::WHITE_CIRCLE]);

	//�f��
	m_pPlanet = new StageSelectPlanet(m_pDrawObject[(int)DRAW_TYPE::MARS], m_pDrawObject[(int)DRAW_TYPE::MERCURY],
		m_pDrawObject[(int)DRAW_TYPE::JUPITER], m_pDrawObject[(int)DRAW_TYPE::VENUS], m_pDrawObject[(int)DRAW_TYPE::SATURN],
		m_pDrawObject[(int)DRAW_TYPE::SUN], m_pDrawObject[(int)DRAW_TYPE::WHITE_CIRCLE], true/*stage_clear*/);
}

//==========================
// �X�V����
//==========================
void StageSelect::Update(void)
{
	//�f��
	m_pPlanet->Update();
}

//==========================
// �`�揈��
//==========================
void StageSelect::Draw(void) const
{
	//�w�i
	m_pBG->DrawBG();

	//�f��
	m_pPlanet->Draw();
}