//=======================================
// �Q�[���I�u�W�F�N�g�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/09/15
// �쐬�ҁF��������
//=======================================
#pragma once

#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include "main.h"
#include "DrawObject.h"
#include "ScreenOut.h"

class GameObject
{
private:
	DrawObject m_pDrawObject;
	D3DXVECTOR2 m_pos = D3DXVECTOR2(0.0f, 0.0f);
	D3DXVECTOR2 m_size = D3DXVECTOR2(0.0f, 0.0f);
	D3DXCOLOR m_color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	float m_rot = 0.0f;

public:
	GameObject() {}	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	GameObject(DrawObject& pDrawObject, const D3DXVECTOR2& pos, const D3DXVECTOR2& size, float rot = 0.0f)
		:m_pDrawObject(pDrawObject), m_pos(pos), m_size(size), m_rot(rot) {}

	~GameObject(){}	//�f�X�g���N�^

	//�`�揈��
	void Draw()const { m_pDrawObject.Draw(m_pos, m_size, m_color, m_rot); }

	//���W�𓮂���
	void MovePos(const D3DXVECTOR2& mov) { m_pos += mov; }

	//�p�x���Z�b�g
	void SetRot(float rot) { m_rot = rot; }

	//�A�j���[�V�����ԍ����Z�b�g
	void SetAnimationNum(float index_num) { m_pDrawObject.SetPaterNo(index_num); }

	//��ʊO�ɏo�����ۂ�
	bool GetScreenOut(void)const { return ScreenOut::GetScreenOut(m_pos, m_size); }

	//���W��Ԃ�
	const D3DXVECTOR2& GetPos(void)const { return m_pos; }

	//�T�C�Y��Ԃ�
	const D3DXVECTOR2& GetSize(void)const { return m_size; }
};

#endif // !_GAME_OBJECT_H_