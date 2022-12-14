//==============================
//�������Ȃ��G
//11/22
//����đ�
//=============================
#pragma once
#include "inh_enemy.h"

class EnemyPublic :public Inh_Enemy
{
	//�萔
public:
	//cpp�ŏ�����
	static const float SIZE_X;			//�T�C�YX
	static const float SIZE_Y;			//�T�C�YY

private:
	static const float SPEED_X;			//�G�̃X�s�[�hY
	static const float SPEED_Y;			//�G�̃X�s�[�hY
	static const int HP_MAX = 1;		//�G��HP�ő�l

//�����o�ϐ�
private:


//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	EnemyPublic() {}	
	//�����t���R���X�g���N�^
	EnemyPublic(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:Inh_Enemy(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y), HP_MAX) {}
	//�f�X�g���N�^
	~EnemyPublic() {}

	//�X�V����
	void Update(void);	

};

