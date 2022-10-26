#pragma once
//=======================================
// ���@�̍�(�w�b�_)
// �쐬���F2022/10/25
// �쐬�ҁF���� �@
//=======================================
#ifndef PLAYER_LEFT_H_
#define PLAYER_LEFT_H_



#include "GameObject.h"
#include "DrawObject.h"

class PlayerLeft :public GameObject
{
public:

	// �r�ɒ����G�̎��
	enum class TYPE :int
	{
		TYPE_NONE,	// �����t���Ă��Ȃ�
		TYPE1,
		TYPE2,
		TYPE3,
		TYPE4,
		TYPE5,
		TYPE6,
		TYPE7,
		TYPE8,
		TYPE_NUM,
	};


private:

	// �萔
	static const float SHOT_SPEED;	// �e�̔��ˑ��x

	// �����o�ϐ�
	bool m_shot = false; // ���˂������ǂ���
	TYPE m_type = TYPE::TYPE1; // �t�����G�̃^�C�v


public:
	PlayerLeft() {}	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	PlayerLeft(DrawObject& pDrawObject, const D3DXVECTOR2& pos, float rot)
		:GameObject(pDrawObject, pos, D3DXVECTOR2(30.0f, 50.0f), rot) {}

	virtual ~PlayerLeft() {}	//�f�X�g���N�^


	//�X�V����
	void Update(D3DXVECTOR2 pos);

	// �`�揈��
	void LeftDraw(void);
};

#endif // !PLAYER_LEFT_H_