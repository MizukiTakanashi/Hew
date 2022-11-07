#pragma once
//=======================================
// �w�i�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/11/07
// �쐬�ҁF��������
//=======================================

#include "main.h"
#include "sprite.h"
#include "texture.h"

class BG
{
//�萔
public:
	//cpp�ŏ�����
	static const float UV_SPEED;	//�w�i�̓����X�s�[�h

//�����o�ϐ�
private:
	int m_tex_num = 0;				//�e�N�X�`���ԍ�
	float m_start_uv_y = 0.0f;		//UV���WY

//�����o�֐�
public:
	BG() {}		//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	BG(char * tex_name){ m_tex_num = LoadTexture(tex_name); }

	~BG() {}	//�f�X�g���N�^

	//�X�V����
	void Update() { m_start_uv_y -= UV_SPEED; }

	//�`�揈��
	void DrawBG()const;
};
