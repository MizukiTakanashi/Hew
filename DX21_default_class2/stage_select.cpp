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

	//�`��֌W�̂���
	m_pTexUseful = new TextureUseful[(int)TEXTURE_TYPE::NUM];
	m_pDrawObject = new DrawObject[(int)DRAW_TYPE::NUM];

	//�ΐ�
	m_pTexUseful[(int)TEXTURE_TYPE::MARS].SetTextureName((char*)"data\\texture\\mars.png");
	m_pDrawObject[(int)DRAW_TYPE::MARS].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::MARS]);

	//����
	m_pTexUseful[(int)TEXTURE_TYPE::MERCURY].SetTextureName((char*)"data\\texture\\mercury.png");
	m_pDrawObject[(int)DRAW_TYPE::MERCURY].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::MERCURY]);


	//�f��
	m_pPlanet = new StageSelectPlanet(m_pDrawObject[(int)DRAW_TYPE::MARS], m_pDrawObject[(int)DRAW_TYPE::MERCURY]);
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
	//�f��
	m_pPlanet->Draw();
}