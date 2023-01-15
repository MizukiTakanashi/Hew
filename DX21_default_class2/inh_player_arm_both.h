#pragma once
//===================================================
// �v���C���[�̘r�̉E���֌W(�p���p)(�w�b�_�t�@�C��)
// �쐬���F2022/11/08
// �쐬�ҁF��������
//===================================================

#ifndef _INH_PLAYER_ARM_BOTH_H_
#define _INH_PLAYER_ARM_BOTH_H_

#include "game_object.h"
#include "inh_player_arm.h"
#include "number.h"

class inhPlayerArmBoth :public GameObject
{
//�萔
public:
	//�r�ɂ��G�̃^�C�v
	enum class TYPE :int
	{
		TYPE_NONE,	//	�������Ă��Ȃ�
		TYPE1,		//�z�[�~���O
		TYPE2,		//���[�U�[
		TYPE3,		//�K�g�����O
		TYPE4,		//�o���A
		TYPE5,		//�������~�߂�
		TYPE6,		//�X�̓G
		TYPE7,
		TYPE8,
		TYPE_SHOOT,	// �O�̃^�C�v�̒e�̏��� & ���g���˒�
		TYPE_OLD,	// �O�̃^�C�v�̒e�̏�����
		TYPE_NUM,
	};

//�萔
private:
	//cpp�ŏ�����
	static const D3DXVECTOR2 SIZE;				//�T�C�Y
	static const float SHOT_SPEED;				//�؂藣�����˃X�s�[�h
	static const D3DXVECTOR2 ICON_SIZE;			//�G�A�C�R���̕\���ꏊ

//�����o�ϐ�
private: 
	D3DXVECTOR2 m_from_player = D3DXVECTOR2(0.0f, 0.0f);	//�v���C���[����ǂꂭ�炢����Ă��邩

	bool m_shot = false;					//�������g�����˂���Ă邩�ۂ�
	TYPE m_type = TYPE::TYPE_NONE;			//�����G�̃^�C�v

	inhPlayerArm* m_pEnemyItem = nullptr;	//�r�ɂ��Ă���G�̃N���X
	DrawObject m_bullet_draw;				//�e�̕`��I�u�W�F�N�g
	DrawObject m_laser_draw;				//���[�U�[�̕`��I�u�W�F�N�g
	DrawObject* m_barrier_draw = nullptr;	//�o���A�̕`��I�u�W�F�N�g
	DrawObject* m_bullet_stop_draw = nullptr;	//�������~�߂�G�̒e�̕`��I�u�W�F�N�g
	DrawObject* m_bullet_icerain_draw = nullptr;	//�X�̓G�̕`��

	bool m_separation_button = false;		//�؂藣���{�^���������ꂽ��
	bool m_bullet_shot = false;				//�e���˂̃{�^���������ꂽ��(�����Ă����)
	bool m_bullet_shot_trigger = false;		//�e���˂̃{�^���������ꂽ��(��������)

	Number* m_pRemaining_Num = nullptr;	//�c�e���\���I�u�W�F�N�g
	D3DXVECTOR2 m_Remaining_Icon_Pos = D3DXVECTOR2(0.0f, 0.0f);	//�G�A�C�R���\���ꏊ

//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	inhPlayerArmBoth(){}

	//�����t���R���X�g���N�^
	inhPlayerArmBoth(DrawObject& pDrawObject, DrawObject& pBullet, DrawObject& pLaser, const D3DXVECTOR2& pos,
		const D3DXVECTOR2& from_player, DrawObject& pDrawobNumber, D3DXVECTOR2 num_pos, D3DXVECTOR2 icon_pos)
		:GameObject(pDrawObject, pos, SIZE), m_bullet_draw(pBullet), m_laser_draw(pLaser),
		m_from_player(from_player), m_Remaining_Icon_Pos(icon_pos) 
	{
		m_pRemaining_Num = new Number(pDrawobNumber, num_pos, D3DXVECTOR2(40.0f, 60.0f), 2);
	}

	//�f�X�g���N�^
	virtual ~inhPlayerArmBoth()override 
	{
		delete m_pEnemyItem; 
		delete m_pRemaining_Num;
	}

	//�X�V����
	// player_pos�F�v���C���[�̍��W�@enemy_pos�F��ԋ߂��G�̍��W
	void Update(const D3DXVECTOR2& player_pos, const D3DXVECTOR2& enemy_pos);

	//�`�揈��
	void ArmDraw(void)const;

	//�r�̃^�C�v��ݒ�
	void SetType(TYPE type, bool newtype = true);

	//�^�C�v��Ԃ�
	TYPE GetType(void)const { return m_type; }

	// �r�̃N���X�̃|�C���^��Ԃ�
	inhPlayerArm* GetArmPointer(void)const { return m_pEnemyItem; }

	//�r�̃N���X�̃|�C���^�̃Z�b�g
	void SetArmPointer(inhPlayerArm* ArmPointer) { m_pEnemyItem = ArmPointer; }


	//�؂藣���{�^���������ꂽ���t���O���Z�b�g
	void SetSeparationButton(bool flag) { m_separation_button = flag; }

	//�e���˂̃{�^���������ꂽ���t���O(�����Ă����)���Z�b�g
	void SetBulletShotButton(bool flag) { m_bullet_shot = flag; }

	//�e���˂̃{�^���������ꂽ���t���O(��������)���Z�b�g
	void SetBulletShotButtonTrigger(bool flag) { m_bullet_shot_trigger = flag; }

	//�c�e����
	void HeelBullet(void) { if (m_pEnemyItem)m_pEnemyItem->HeelBullet(); }

	//覐΂Ɠ����������ɘr������
	void BreakShootingArm();

	//�o���A�̕`��I�u�W�F�N�g���Z�b�g
	void DrawSetBarrier(DrawObject* pDraw) { m_barrier_draw = pDraw; }

	//�������~�߂�G�̒e�`��I�u�W�F�N�g���Z�b�g
	void DrawSetBulleStop(DrawObject* pDraw) { m_bullet_stop_draw = pDraw; }

	//�X�̓G�̘r�̕`��
	void DrawSetIceRain(DrawObject* pDraw) { m_bullet_icerain_draw = pDraw; }
};

#endif // !_INH_PLAYER_ARM_BOTH_H_