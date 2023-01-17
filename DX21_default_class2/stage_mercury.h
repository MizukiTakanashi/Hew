#pragma once
//=======================================
// �����̃X�e�[�W�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/12/15
// �쐬�ҁF��������
//=======================================

#ifndef _STAGE_MERCURY_H_
#define _STAGE_MERCURY_H_

#include "inh_stage.h"

class StageMercury : public InhStage
{
//�萔
private:

	
//�����o�ϐ�
private:
	//Bom* m_pBom = nullptr;					//�{��

	//�����o�֐�
public:
	StageMercury(Score* pNumber);

	~StageMercury();	//�f�X�g���N�^

	//�X�V
	void Update(void);

	//�`��
	void Draw(void)const;

	//�X�R�A��Ԃ�
	int GetScore(void)const { return m_pScore->GetNumber(); }
};

void MercuryHitStop(int flame);
void MercuryBossDown();


#endif // !_STAGE_MERCURY_H_