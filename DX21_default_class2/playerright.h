#pragma once
//=======================================
// ���@�̉E(�w�b�_)
// �쐬���F2022/10/23
// �쐬�ҁF���c�m�s
//=======================================
#ifndef PLAYER_RIGHT
#define PLAYER_RIGHT



#include "GameObject.h"
#include "DrawObject.h"

class PlayerRight :public GameObject
{
private:
	
public:
	PlayerRight() {}	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	PlayerRight(DrawObject& pDrawObject, const D3DXVECTOR2& pos, float rot)
		:GameObject(pDrawObject, pos, D3DXVECTOR2(50.0f, 100.0f), rot) {}

	virtual ~PlayerRight() {}	//�f�X�g���N�^


	//�X�V����
	void Update(D3DXVECTOR2 pos) {  }

};

#endif // !PLAYER_RIGHT
