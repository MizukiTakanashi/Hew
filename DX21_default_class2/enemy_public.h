//==============================
//�������Ȃ��G
//11/22
//����đ�
//=============================
#pragma once
#include "game_object.h"
class EnemyPublic :public GameObject
{
	//�萔
public:
	//cpp�ŏ�����
	static const float SIZE_X;			//�T�C�YX
	static const float SIZE_Y;			//�T�C�YY

	//�����o�ϐ�
private:
	float m_move_width = 0.0f;			//�G����������cos�J�[�u
	float m_init_posx = 0.0f;			//�G�̏����ʒuX
	//cpp�ŏ�����
	static const float SPEED_X;			//�G�̃X�s�[�hY
	static const float SPEED_Y;			//�G�̃X�s�[�hY
	static const int HP_MAX;			//�G��HP�ő�l

	int m_hp = HP_MAX;					//�G�̌��݂�HP

public:
	EnemyPublic() {}	//�f�t�H���g�R���X�g���N�^
	EnemyPublic(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:GameObject(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y)) {}
	~EnemyPublic() {}
	void Update(void);	//�X�V����

	//HP�����炷
	void ReduceHP(int amount) { m_hp -= amount; }

	//HP��Ԃ�
	int GetHP(void) { return m_hp; }

};

