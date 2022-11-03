#pragma once
//=======================================
// ���@�̍�(�w�b�_)
// �쐬���F2022/10/25
// �쐬�ҁF���� �@
//=======================================
#ifndef PLAYER_LEFT_H_
#define PLAYER_LEFT_H_

#include "GameObject.h"
#include "DrawObject.h"
#include "inhPlayerArm.h"
#include "PlayerArm1.h"

class PlayerLeft :public GameObject
{
//�萔
public:
	// �r�ɒ����G�̎��
	enum class TYPE :int
	{
		TYPE_NONE,	// �����t���Ă��Ȃ�
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
	static const D3DXVECTOR2 SIZE;				//�T�C�Y
	static const float SHOT_SPEED;				// �؂藣�����˃X�s�[�h
	static const D3DXVECTOR2 FROM_PLAYER_POS;	//�v���C���[����ǂꂭ�炢����Ă��邩

// �����o�ϐ�
private:
	bool m_shot = false;					// ���˂������ǂ���
	TYPE m_type = TYPE::TYPE_NONE;			// �t�����G�̃^�C�v
	
	inhPlayerArm* m_pEnemyItem = nullptr;	//�r�ɂ��Ă���G�̃N���X
	DrawObject m_bullet_draw;				//�e�̕`��I�u�W�F�N�g
	DrawObject m_laser_draw;				//���[�U�[�̕`��I�u�W�F�N�g

//�����o�֐�
public:
	PlayerLeft() {}	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	PlayerLeft(DrawObject& pDrawObject, DrawObject& pBullet, DrawObject& pLaser, const D3DXVECTOR2& pos)
		:GameObject(pDrawObject, pos, SIZE),
		m_bullet_draw(pBullet), m_laser_draw(pLaser) {}

	~PlayerLeft()override { delete m_pEnemyItem; }	//�f�X�g���N�^

	//�X�V����
	// player_pos�F�v���C���[�̍��W�@enemy_pos�F��ԋ߂��G�̍��W
	void Update(const D3DXVECTOR2& player_pos, const D3DXVECTOR2& enemy_pos);

	// �`�揈��
	void LeftDraw(void)const;

	// �r�̃^�C�v��ݒ�
	void SetType(int type);

	// �r�̃N���X�̃|�C���^��Ԃ�
	inhPlayerArm* GetArmPointer(void)const { return m_pEnemyItem; }
};

#endif // !PLAYER_LEFT_H_