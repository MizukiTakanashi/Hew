//=======================================
// ���[�U�[�֌W(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================

#ifndef _LASER_H_
#define _LASER_H_

#include "game_object.h"
#include "draw_object.h"
#include "enemy_laser.h"

class Laser:public GameObject
{
private:
	//D3DXVECTOR2 m_mov = D3DXVECTOR2(0.0f, 0.0f);
	EnemyLaser* m_pEnemynum = nullptr; //���[�U�[���ˏo���Ă���G�l�~�[�̃|�C���^
	int m_lasertime = LASER_TIME;

public:
	static const float SPEED_Y;			//���[�U�[�̃X�s�[�hY
	static const int LASER_TIME;			//���[�U�[�̎ˏo����


	Laser(){}	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	Laser(DrawObject& pDrawObject, const D3DXVECTOR2& pos, const D3DXVECTOR2& size, EnemyLaser* pEnemyLaser)
		:GameObject(pDrawObject, pos, size, 0.0f), m_pEnemynum(pEnemyLaser) {}

	virtual ~Laser() {}	//�f�X�g���N�^

	bool IsLaserUse() { if (m_lasertime < 0) { return false; } return true; }

	//�X�V����(�e���ړ�)
	void Update(void); 
};

#endif // !_LASER_H_