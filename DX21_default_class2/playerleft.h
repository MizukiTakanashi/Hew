#pragma once
//=======================================
// ���@�̍�(�w�b�_)
// �쐬���F2022/10/23
// �쐬�ҁF���c�m�s
//=======================================
#ifndef PLAYER_LEFT
#define PLAYER_LEFT



#include "GameObject.h"
#include "DrawObject.h"

class PlayerLeft :public GameObject
{
private:

public:
	PlayerLeft() {}	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	PlayerLeft(DrawObject& pDrawObject, const D3DXVECTOR2& pos, float rot)
		:GameObject(pDrawObject, pos, D3DXVECTOR2(50.0f, 100.0f), rot) {}

	virtual ~PlayerLeft() {}	//�f�X�g���N�^


	//�X�V����
	void Update(D3DXVECTOR2& pos) {  }

};

#endif // !PLAYER_LEFT