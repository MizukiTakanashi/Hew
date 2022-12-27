//=======================================
// �X�R�A�֌W(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#include "score.h"

//==========================
// �萔������
//==========================
const float Score::COMBO_MAGNIFICATION = 1.1f; //�R���{�p�����̔{��


//=========================
// �����t���R���X�g���N�^
//=========================
Score::Score(DrawObject& pDrawObject, const D3DXVECTOR2& pos, const D3DXVECTOR2& size, int digit)
	:Number(pDrawObject, pos, size, digit)
{
	
}

void Score::AddScore(int num)
{
	AddNumber(num * (int)m_ComboMagnification);
	m_ComboMagnification *= Score::COMBO_MAGNIFICATION;
	m_ComboNum++;
}
