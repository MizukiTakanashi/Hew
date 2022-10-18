//=======================================
// �e�N�X�`��(�֗�)�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/09/11
// �쐬�ҁF��������
//=======================================
#pragma once

#ifndef _TEXTURE_USEFUL_H_
#define _TEXTURE_USEFUL_H_

#include "texture.h"

class TextureUseful
{
private:
	char* m_tex_name = nullptr;
	int m_tex_index_num = 0;

public:
	TextureUseful(){}	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	TextureUseful(char* tex_name) :m_tex_name(tex_name) { m_tex_index_num = LoadTexture(m_tex_name); }

	~TextureUseful(){}	//�f�X�g���N�^

	//�e�N�X�`�����Z�b�g
	void SetTextureName(char* tex_name) { 
		m_tex_name = tex_name; 
		m_tex_index_num = LoadTexture(m_tex_name);
	}

	//�e�N�X�`���̔ԍ���Ԃ�
	int GetTexIndexNum(void)const { return m_tex_index_num; }
};

#endif // !_TEXTURE_USEFUL_H_
