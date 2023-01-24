#pragma once
//=======================================
// �w�i�֌W(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================

#include "main.h"
#include "sprite.h"
#include "texture.h"

class PoorVision
{
//�萔
public:
	//cpp�ŏ�����

//�����o�ϐ�
private:
	int m_tex_num = 0;				//�e�N�X�`���ԍ�
	D3DXVECTOR2 m_pos;

	bool m_fadein = false;
	float m_alp = 0.0f;

//�����o�֐�
public:
	//�����t���R���X�g���N�^
	PoorVision(char * tex_name){ m_tex_num = LoadTexture(tex_name); }

	~PoorVision() {}	//�f�X�g���N�^

	//�X�V����
	void Update(D3DXVECTOR2 pos);

	//�`�揈��
	void Draw()const;

	void SetPV();
};
