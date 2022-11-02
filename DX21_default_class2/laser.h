//=======================================
// ���[�U�[�֌W(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================

#ifndef _LASER_H_
#define _LASER_H_

#include "GameObject.h"
#include "DrawObject.h"
#include "enemylaser.h"

class Laser:public GameObject
{
private:
	int m_lasertime = LASER_TIME;

public:
	static const float SPEED_Y;			//���[�U�[�̃X�s�[�hY
	static const int LASER_TIME;			//���[�U�[�̎ˏo����


	Laser(){}	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	Laser(DrawObject& pDrawObject, const D3DXVECTOR2& pos, const D3DXVECTOR2& size)
		:GameObject(pDrawObject, pos, size, 0.0f) {}

	virtual ~Laser() {}	//�f�X�g���N�^

	//���[�U�[�̍폜
	void DeleteLaser() { m_lasertime = -1; }

	//�X�V����(�e���ړ�)
	void Update(const D3DXVECTOR2& pos); 
};

#endif // !_LASER_H_