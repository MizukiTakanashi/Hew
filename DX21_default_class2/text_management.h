//====================================================
// �e�L�X�g�̊Ǘ��֌W(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//====================================================
#pragma once


class TextManagement
{
//�萔
public:
	const static float FLAME_SIZE_X; //�t���[���T�C�Y
	const static float FLAME_SIZE_Y; //�t���[���T�C�Y

private:

//�����o�ϐ�
private:
	int m_TextNum = 0; //����`���[�g���A���e�L�X�g��\��������

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
};
