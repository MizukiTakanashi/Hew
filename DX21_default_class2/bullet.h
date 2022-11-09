//=======================================
// �e�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/07/07
// �쐬�ҁF��������
//=======================================

#ifndef _BULLET_H_
#define _BULLET_H_

#include <time.h>
#include "game_object.h"
#include "draw_object.h"

class Bullet:public GameObject
{
private:
	D3DXVECTOR2 m_mov = D3DXVECTOR2(0.0f, 0.0f);	//�ړ���
	int m_time = 0;									//�e���o���Ă���̌o�ߎ���

public:
	Bullet(){}	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	Bullet(DrawObject& pDrawObject, const D3DXVECTOR2& pos, const D3DXVECTOR2& size, const D3DXVECTOR2& mov, float rot)
		:GameObject(pDrawObject, pos, size, rot), m_mov(mov){}

	~Bullet()override {}	//�f�X�g���N�^

	//�X�V����(�e���ړ�)(�o�ߎ��Ԃ��v��)
	void Update(void) { GameObject::MovePos(m_mov); m_time++; }

	//�e�̈ړ����ăZ�b�g(�z�[�~���O�e�p���ȁH)
	void SetMove(const D3DXVECTOR2& mov) { m_mov = mov; }

	//�e���o���Ă���̌o�ߎ��Ԃ�Ԃ�
	int GetTime(void)const { return m_time; }
};

#endif // !_BULLET_H_