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
}

//==========================
// �X�V����
//==========================
void StageSelect::Update(void)
{
}

//==========================
// �`�揈��
//==========================
void StageSelect::Draw(void) const
{
}