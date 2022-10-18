//=======================================
// �����蔻��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/06/27
// �쐬�ҁF��������
//=======================================

#ifndef _COLLISION_H_
#define _COLLISION_H_

#include "main.h"

class Collision
{
private:						//���a2(��)

public:
	Collision(){}	//�f�t�H���g�R���X�g���N�^

	~Collision(){}	//�f�X�g���N�^

	//�l�p�`���m�̓����蔻�� true:�������� false:�������ĂȂ�
	static bool ColBox(const D3DXVECTOR2& pos1, const D3DXVECTOR2& pos2, 
		const D3DXVECTOR2& size1, const D3DXVECTOR2& size2);

	//�ۓ��m�̓����蔻�� true:�������� false:�������ĂȂ�
	static bool ColCircle(const D3DXVECTOR2& pos1, const D3DXVECTOR2& pos2, float rot1, float rot2);
};

#endif // !_COLLISION_H_
