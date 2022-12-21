//=======================================
// ���[�U�[�֌W(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================

#ifndef _LASER_H_
#define _LASER_H_

#include "game_object.h"
#include "draw_object.h"

class Laser:public GameObject
{
//�萔
public:
	//����(�㉺�͏������ōs�����ߏ���)
	enum class DIRECTION :int {
		NONE,
		RIGHT,
		LEFT,
		NUM
	};

	//cpp�ŏ�����
	static const float SPEED_X;			//���[�U�[�̃X�s�[�hX
	static const float SPEED_Y;			//���[�U�[�̃X�s�[�hY

	//�����ŏ�����
	static const int LASER_TIME = 180;	//���[�U�[�̍ő�ˏo����

//�����o�ϐ�
private:
	int m_lasertime = LASER_TIME;				//���[�U�[�̌��݂̎ˏo����
	DIRECTION m_direction = DIRECTION::NONE;	//���[�U�[�̌���

//�����o�֐�
public:
	Laser(){}	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	Laser(DrawObject& pDrawObject, const D3DXVECTOR2& pos, const D3DXVECTOR2& size)
		:GameObject(pDrawObject, pos, size, 0.0f) {}

	~Laser()override {}	//�f�X�g���N�^

	//���[�U�[�̌����ύX
	void SetLaserDirectioon(DIRECTION direction) { m_direction = direction; }

	//���[�U�[�̍폜
	void DeleteLaser() { m_lasertime = -1; }

	//���[�U�[�̎c�莞�Ԃ�Ԃ�
	int GetLaserTime() { return m_lasertime; }

	//�X�V����(�e���ړ�)
	void Update(const D3DXVECTOR2& pos, bool down = true); 
};

#endif // !_LASER_H_