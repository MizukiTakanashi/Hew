//=======================================
// �w�i�f���֌W(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#pragma once

#include "main.h"
#include "sprite.h"
#include "texture.h"

class BGPlanet
{
//�萔
public:
	//cpp�ŏ�����
	static const float MOVE_SPEED;	//�w�i�̓����X�s�[�h

//�����o�ϐ�
private:
	int m_tex_num = 0;				//�e�N�X�`���ԍ�
	float posy = -400.0f;

	//�����o�֐�
public:
	BGPlanet() {}		//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	BGPlanet(char* tex_name) { m_tex_num = LoadTexture(tex_name); }

	~BGPlanet() {}	//�f�X�g���N�^

	//�X�V����
	void Update() 
	{
		if (posy <= 0.0f)
		{
			posy += MOVE_SPEED;
		}
	}

	//�`�揈��
	void DrawBG()const;
	void DrawSaturn()const;
};
