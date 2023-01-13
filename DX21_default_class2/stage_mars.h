#pragma once
//=======================================
// �ΐ��̃X�e�[�W�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/12/15
// �쐬�ҁF��������
//=======================================

#ifndef _STAGE_MARS_H_
#define _STAGE_MARS_H_

#include "main.h"
#include "sprite.h"
#include "BG.h"
#include "bg_planet.h"
#include "player.h"
#include "draw_object.h"
#include "management_enemy_barrier.h"
#include "management_enemy_normal.h"
#include "management_enemy_icerain.h"
#include "management_enemy_stop.h"
#include "management_enemy_grenade.h"
#include "texture_useful.h"
#include "player_hp.h"
#include "management_explosion.h"
#include "score.h"
#include "number.h"
#include "player_left.h"
#include "player_right.h"
#include "management_item.h"
#include "all_enemy_management.h"
#include "player_arm_change.h"
#include "mars_collision_all.h"
#include "player_center.h"
#include "Bom.h"
#include "boss.h"
#include "management_enemy_laser.h"//�ڐA�\��

class StageMars
{
	//�萔
private:
	//�����ŏ�����
	static const int NUMBER_DIGIT = 10;		//�����̌�

	//cpp�ŏ�����
	static const D3DXVECTOR2 NUMBER_SIZE;	//�����̃T�C�Y
	static const D3DXVECTOR2 NUMBER_POS;	//�����̈ʒu

	enum class TEXTURE_TYPE :int
	{
		PLAYER,
		PLAYER_HP,
		ENEMY,
		ENEMY_ITEM,
		ENEMY_BARRIER,
		ENEMY_GREANADE,
		BULLET_CIRCLE_RED,
		BULLET_CIRCLE_GREEN,
		BULLET_SQUARE_GREEN,
		LASER,
		BARRIER,
		EXPLOSION,
		NUMBER,
		MULTIPLY,
		ENEMY_ICE,	//�X�̓G�̃e�N�X�`���Z�b�g
		BULLET_ICE,	//�X�̒e�̃e�N�X�`���Z�b�g
		ENEMY_STOP,
		BULLET_STOP,
		NUM
	};

	enum class DRAW_TYPE :int
	{
		PLAYER,
		PLAYER_HP_BAR,
		ENEMY_BARRIER,
		ENEMY_BARRIER_BARRIER,
		ENEMY_ICE,
		ENEMY_STOP,
		ENEMY_NOREMAL,
		ENEMY_GRENADE,
		ENEMY_GRENADE_EXPLOSION,
		BULLET_STOP,
		ENEMY_ITEM,
		PLAYER_BULLET,
		BULLET_ENEMY,
		BULLET_ENEMY_ICE,
		EXPLOSION,
		PLAYER_ARM_LEFT,
		PLAYER_ARM_LEFT_BULLET,
		PLAYER_ARM_LEFT_LASER,
		PLAYER_ARM_RIGHT,
		PLAYER_ARM_RIGHT_BULLET,
		PLAYER_ARM_RIGHT_LASER,
		PLAYER_ARM_CENTER,
		PLAYER_ARM_CENTTER_BULLET,
		PLAYER_ARM_CENTER_LASER,
		NUMBER,
		MULTIPLY,
		BOMB,						//���e
		NUM
	};


	//�����o�ϐ�
private:
	int m_BGM = 0;

	Score* m_pScore = nullptr;

	TextureUseful* m_pTexUseful = nullptr;
	DrawObject* m_pDrawObject = nullptr;

	BG* m_pBG = nullptr;
	BGPlanet* m_pBG_Moon = nullptr;
	Player* m_pPlayer = nullptr;

	EnemyBarrierManagement* m_pEnemyBarrierManagement = nullptr;
	EnemyIceRainManagement* m_pEnemyIceRainManagement = nullptr;
	EnemyStopManagement* m_pEnemyStopManagement = nullptr;
	EnemyNormalManagement* m_pEnemyNormalManagement = nullptr;
	EnemyGrenadeManagement* m_pEnemyGrenadeManagement = nullptr;

	PlayerHP* m_pPlayerHP = nullptr;
	ExplosionManagement* m_pExplosionManagement = nullptr;
	ItemManagement* m_pItemManagement = nullptr;

	PlayerLeft* m_pPlayerLeft = nullptr;
	PlayerRight* m_pPlayerRight = nullptr;
	PlayerCenter* m_pPlayerCenter = nullptr;

	Number* m_pRemaining_Left = nullptr;
	Number* m_pRemaining_Right = nullptr;
	Number* m_pRemaining_Center = nullptr;

	UI* m_pMultiply = nullptr;
	Number* m_pComboNum = nullptr;

	AllEnemyManagement* m_pAllEnemyManagement = nullptr;

	PlayerArmChange* m_pPlayerArmChange = nullptr;	//�r�̌���

	MarsCollisionAll* m_pColAll = nullptr;		//�S�Ă̓����蔻��

	Bom* m_pBom = nullptr;					//�{��

	Boss* m_pBoss = nullptr;

	//�����o�֐�
public:
	StageMars() {}	//�f�t�H���g�R���X�g���N�^

	StageMars(Score* pNumber);

	~StageMars();	//�f�X�g���N�^

	//�X�V
	void Update(void);

	//�`��
	void Draw(void)const;

	//�X�R�A��Ԃ�
	int GetScore(void)const { return m_pScore->GetNumber(); }
};

void MarsHitStop(int flame);
void MarsBossDown();

#endif // !_STAGE_MARS_H_