/*==============================================================================

   ���_�Ǘ�[polygon.h]
														 Author :
														 Date   :
--------------------------------------------------------------------------------

==============================================================================*/
#pragma once


#include "main.h"
#include "sprite.h"
#include "texture.h"

class BG
{
public:
	//�萔
	static const float UV_SPEED;	//�w�i�̓����X�s�[�h

private:
	int m_tex_num = 0;
	float m_start_uv_x = 0.0f;

public:
	BG() {}		//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	BG(char * tex_name){ m_tex_num = LoadTexture(tex_name); }

	~BG() {}	//�f�X�g���N�^

	//�X�V����
	void Update() { m_start_uv_x += UV_SPEED; }

	//�`�揈��
	void DrawBG()const;
};
