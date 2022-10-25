#pragma once
//=======================================
// ���@�̍�(�w�b�_)
// �쐬���F2022/10/25
// �쐬�ҁF���� �@
//=======================================
#ifndef PLAYER_LEFT
#define PLAYER_LEFT



#include "GameObject.h"
#include "DrawObject.h"

class PlayerLeft :public GameObject
{
private:

	// �萔
	static const float SHOT_SPEED;	// �e�̔��ˑ��x

	// �����o�ϐ�
	bool m_shot = false; // ���˂������ǂ���

public:
	PlayerLeft() {}	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	PlayerLeft(DrawObject& pDrawObject, const D3DXVECTOR2& pos, float rot)
		:GameObject(pDrawObject, pos, D3DXVECTOR2(30.0f, 50.0f), rot) {}

	virtual ~PlayerLeft() {}	//�f�X�g���N�^


	//�X�V����
	void Update(D3DXVECTOR2 pos);

};

#endif // !PLAYER_LEFT