//=======================================
// �e�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/07/07
// �쐬�ҁF��������
//=======================================

#ifndef _BULLET_H_
#define _BULLET_H_

#include "GameObject.h"
#include "DrawObject.h"

class Bullet:public GameObject
{
private:
	D3DXVECTOR2 m_mov = D3DXVECTOR2(0.0f, 0.0f);

public:
	Bullet(){}	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	Bullet(DrawObject& pDrawObject, const D3DXVECTOR2& pos, const D3DXVECTOR2& size, const D3DXVECTOR2& mov, float rot)
		:GameObject(pDrawObject, pos, size, rot), m_mov(mov){}

	virtual ~Bullet() {}	//�f�X�g���N�^

	//�X�V����(�e���ړ�)
	void Update(void){ GameObject::MovePos(m_mov); }
};

#endif // !_BULLET_H_