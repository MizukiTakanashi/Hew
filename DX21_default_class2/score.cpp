//=======================================
// �X�R�A�֌W(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#include "score.h"

//==========================
// �萔������
//==========================
const float Score::SPACE_RATIO = 0.2f;
const float Score::COMBO_MAGNIFICATION = 1.1f; //�R���{�p�����̔{��


//=========================
// �����t���R���X�g���N�^
//=========================
Score::Score(DrawObject& pDrawObject, const D3DXVECTOR2& pos, const D3DXVECTOR2& size, int digit)
	:UI(pDrawObject, pos, size), m_digit(digit)
{
	m_space = size.x * SPACE_RATIO;
}

void Score::AddScore(int num)
{
	m_num += num * m_ComboMagnification;
	m_ComboMagnification *= Score::COMBO_MAGNIFICATION;
	m_ComboNum++;
}
//==========================
// �`�揈��
//==========================
void Score::DrawNumber(void)
{
	//�`��ʒu�������ʒu��
	UI::SetPos(m_init_pos);

	int num = m_num;

	//��̌�����`��
	for (int i = 0; i < m_digit; i++) {
		int n = num % 10;

		num /= 10;

		UI::SetAnimationNum((float)n);

		UI::Draw();

		//���̐�����`�悷�邽�߁A�ׂɍ��W���ڂ�
		UI::SetPos(D3DXVECTOR2(UI::GetPos().x - UI::GetSize().x - m_space, UI::GetPos().y));
	}
}