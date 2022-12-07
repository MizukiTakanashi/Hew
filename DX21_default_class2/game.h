//=======================================
// �Q�[����ʊ֌W(�w�b�_�t�@�C��)
// �쐬���F2022/07/14
// �쐬�ҁF��������
//=======================================
#pragma once
#ifndef _GAME_H_
#define _GAME_H_

#include "main.h"
#include "sprite.h"
#include "BG.h"
#include "player.h"
#include "draw_object.h"
//#include "enemy_set_pos.h"
#include "management_enemy_normal.h"
#include "management_enemy_laser.h"
#include "management_enemy_gatoring.h"
#include "management_enemy_missile.h"
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
#include "collision_all.h"
#include "management_meteo.h"
#include "management_enemy_public.h"
#include "player_center.h"
#include "management_enemy_attack.h"
#include "Bom.h"

class Game
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
		ENEMY_PUBLIC,
		ENEMY_ITEM,
		BULLET_CIRCLE_RED,
		BULLET_CIRCLE_GREEN,
		BULLET_SQUARE_GREEN,
		LASER,
		EXPLOSION,
		NUMBER,
		MULTIPLY,
		METEO,
		NUM
	};

	enum class DRAW_TYPE :int
	{
		PLAYER,
		PLAYER_HP_BAR,
		ENEMY_NOREMAL,
		ENEMY_LASER,
		ENEMY_GATORING,
		ENEMY_PUBLIC,
		ENEMY_METEO,
		ENEMY_ATTCK,
		ENEMY_ITEM,
		PLAYER_BULLET,
		BULLET_ENEMY,
		ENEMY_LASER_LASER,
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
	Player* m_pPlayer = nullptr;
	EnemyNormalManagement* m_pEnemyNormalManagement = nullptr;
	EnemyLaserManagement* m_pEnemyLaserManagement = nullptr;
	EnemyGatoringManagement* m_pEnemyGatoringManagement = nullptr;
	EnemyMissileManagement* m_pEnemyMissileManagement = nullptr;
	EnemyAttackManagement* m_pEnemyAttackManagement = nullptr;
	Management_EnemyPublic* m_pEnemyPublicManagement = nullptr;
	Management_Meteo* m_pMeteoManagement = nullptr;
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

	CollisionAll* m_pColAll = nullptr;		//�S�Ă̓����蔻��

	Bom* m_pBom = nullptr;					//�{��

	//�����o�֐�
public:
	Game();	//�f�t�H���g�R���X�g���N�^

	Game(Score* pNumber);

	~Game();	//�f�X�g���N�^

	//�X�V
	void Update(void);

	//�`��
	void Draw(void)const;

	//�X�R�A��Ԃ�
	int GetScore(void)const { return m_pScore->GetNumber(); }
};

void HitStop(int flame);

#endif // !_GAME_H_


