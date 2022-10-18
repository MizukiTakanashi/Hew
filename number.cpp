//=======================================
// �����֌W(cpp�t�@�C��)
// �쐬���F2022/09/29
// �쐬�ҁF��������
//=======================================
#include "number.h"

//==========================
// �萔������
//==========================
const float Number::SPACE_RATIO = 0.2f;

//=========================
// �����t���R���X�g���N�^
//=========================
Number::Number(DrawObject & pDrawObject, const D3DXVECTOR2 & pos, const D3DXVECTOR2 & size, int digit)
	:UI(pDrawObject, pos, size), m_digit(digit) 
{
	m_space = size.x * SPACE_RATIO;
}

//==========================
// �`�揈��
//==========================
void Number::DrawNumber(void)
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