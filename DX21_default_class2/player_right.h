#pragma once
//=======================================
// ���@�̉E(�w�b�_)
// �쐬���F2022/10/23
// �쐬�ҁF���c�m�s
//=======================================
#ifndef PLAYER_RIGHT_H_
#define PLAYER_RIGHT_H_

#include "game_object.h"
#include "draw_object.h"
#include "inh_player_arm.h"
#include "player_arm1.h"

class PlayerRight :public GameObject
{
//�萔
public:
	//�r�ɂ��G�̃^�C�v
	enum class TYPE :int
	{
		TYPE_NONE,	//	�������Ă��Ȃ�
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
	//cpp�ŏ�����
	static const float SHOT_SPEED;	//���˃X�s�[�h


//�����o�ϐ�
private:
	bool m_shot = false;					//���˂������ۂ�
	TYPE m_type = TYPE::TYPE_NONE;			//�����G�̃^�C�v
	inhPlayerArm* m_pEnemyItem = nullptr;	//�r�ɂ��Ă���G�̃N���X

//�����o�֐�
public:
	PlayerRight() {}			//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	PlayerRight(DrawObject& pDrawObject, const D3DXVECTOR2& pos, float rot)
		:GameObject(pDrawObject, pos, D3DXVECTOR2(30.0f, 50.0f), rot) {}

	virtual ~PlayerRight() {}	//�f�X�g���N�^

	//�X�V����
	void Update(const D3DXVECTOR2& player_pos, const D3DXVECTOR2& enemy_pos);

	//�`�揈��
	void RightDraw(void)const;

	//�r�̃^�C�v��ݒ�
	void SetType(int type){ m_type = (TYPE)type; }
};

#endif // !PLAYER_RIGHT_H_