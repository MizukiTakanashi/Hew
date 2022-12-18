//====================================================
// �e�L�X�g�̊Ǘ��֌W(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//====================================================
#pragma once
#include "draw_object.h"

class TextManagement
{
//�萔
public:

private:
	const static float FLAME_SIZE_X; //�t���[���T�C�Y
	const static float FLAME_SIZE_Y; //�t���[���T�C�Y
	const static float FLAME_POS_X;
	const static float FLAME_POS_Y;

	const static float TEXT_SIZE_X; //�t���[���T�C�Y
	const static float TEXT_SIZE_Y; //�t���[���T�C�Y
	const static float TEXT_BET_X; 
	const static float TEXT_BET_Y; 
	const static float TEXT_POS_X;
	const static float TEXT_POS_Y;

	const static int TEXT_NUM_X = 40;

//�����o�ϐ�
private:
	int m_FlameCount = 0;
	int m_TextCount = 0; //����`���[�g���A���e�L�X�g��\��������
	int m_PaternNum = 0;
	int m_PaternMax = 0;
	bool m_RunText = false; //�e�L�X�g���i��ł���r����
	DrawObject m_TextFrame;
	DrawObject m_Text;
	DrawObject m_Triangle;

	int m_TexTime[5] = {
		60 * 1,
		60 * 10,
		60 * 30,
		60 * 55,
		60 * 70
	};

//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	TextManagement();

	//�����t���R���X�g���N�^

	//�f�X�g���N�^

	
	//�X�V����
	void Update(void);
	//�`�揈��
	void Draw(void);

	void SetText(void);
	void EndText(void);
};
