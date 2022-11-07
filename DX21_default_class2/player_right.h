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
#include "player_arm_1.h"

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
		TYPE_SHOOT,	// �O�̃^�C�v�̒e�̏��� & ���g���˒�
		TYPE_OLD,	// �O�̃^�C�v�̒e�̏�����
		TYPE_NUM,
	};

private:
	//�����ŏ�����
	static const int TRIGGER = 100;				//�g���K�[�̏d��(0�`255)

	//cpp�ŏ�����
	static const D3DXVECTOR2 SIZE;				//�T�C�Y
	static const float SHOT_SPEED;				//�؂藣�����˃X�s�[�h
	static const D3DXVECTOR2 FROM_PLAYER_POS;	//�v���C���[����ǂꂭ�炢����Ă��邩

//�����o�ϐ�
private:
	bool m_shot = false;					//���˂������ۂ�
	TYPE m_type = TYPE::TYPE_NONE;			//�����G�̃^�C�v

	inhPlayerArm* m_pEnemyItem = nullptr;	//�r�ɂ��Ă���G�̃N���X
	DrawObject m_bullet_draw;				//�e�̕`��I�u�W�F�N�g
	DrawObject m_laser_draw;				//���[�U�[�̕`��I�u�W�F�N�g

//�����o�֐�
public:
	PlayerRight() {}			//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	PlayerRight(DrawObject& pDrawObject, DrawObject& pBullet, DrawObject& pLaser, const D3DXVECTOR2& pos)
		:GameObject(pDrawObject, pos, SIZE), 
		m_bullet_draw(pBullet), m_laser_draw(pLaser) {}

	~PlayerRight()override { delete m_pEnemyItem; }	//�f�X�g���N�^

	//�X�V����
	// player_pos�F�v���C���[�̍��W�@enemy_pos�F��ԋ߂��G�̍��W
	void Update(const D3DXVECTOR2& player_pos, const D3DXVECTOR2& enemy_pos);

	//�`�揈��
	void RightDraw(void)const;

	//�r�̃^�C�v��ݒ�
	void SetType(int type, bool newtype = true);

	//�^�C�v��Ԃ�
	TYPE GetType(void)const { return m_type; }

	// �r�̃N���X�̃|�C���^��Ԃ�
	inhPlayerArm* GetArmPointer(void)const { return m_pEnemyItem; }

	//�r�̃N���X�̃|�C���^�̃Z�b�g
	void SetArmPointer(inhPlayerArm* ArmPointer) { m_pEnemyItem = ArmPointer; }
};

#endif // !PLAYER_RIGHT_H_