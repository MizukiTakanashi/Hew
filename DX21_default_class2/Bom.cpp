//=======================================
// �{���֌W(cpp�t�@�C��)
// �쐬���F2022/12/07
// �쐬�ҁF��������
//=======================================

#include "Bom.h"
#include "inputx.h"
#include "keyboard.h"

//==========================
// �X�V����
//==========================
void Bom::Update(void)
{
	//�{�����Ȃ��Ȃ��Ă����...
	if (m_num > m_num_max) {
		return;
	}

	//�{�����Z�b�g����Ă��Ȃ����...

	if (GetLeftTriggerTriggered(0, 120)) {
		m_left = SAME_TIME;
	}
	if (GetRightTriggerTriggered(0, 120)) {
		m_right = SAME_TIME;
	}
	
	//�Q�[���p�b�h��X�{�^������������...
	//�L�[�{�[�h��Enter����������...
	if (m_time == -1 && ((m_right-- > 0 && m_left-- > 0)
		|| InputGetKeyDown(KK_R))) {
		PlaySound(m_SE_17, 0);
		m_time = 0;
		m_right = 0;
		m_left = 0;
	}

	//�{�����Z�b�g����Ă����...
	if (m_time >= 0) {
		//��莞�ԉ߂����...
		if (m_time++ > TIME_LIMIT) {
			//�{���̌��݂̐���ǉ�
			m_num++;

			//�{���������āA�J�E���g�����Z�b�g
			m_time = -1;
		}
	}
}

//==========================
// �`�揈��
//==========================
void Bom::BomDraw(void)
{
	//�{�����Z�b�g����Ă����...
	if (m_time >= 0) {
		GameObject::Draw();
	}
}
