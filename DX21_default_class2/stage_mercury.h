#pragma once
//=======================================
// �����̃X�e�[�W�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/12/15
// �쐬�ҁF��������
//=======================================

#ifndef _STAGE_MERCURY_H_
#define _STAGE_MERCURY_H_

#include "inh_stage.h"

#include "management_enemy_barrier.h"
#include "collision_all.h"

class StageMercury : public InhStage
{
	//�萔
private:
	////�����ŏ�����
	//static const int NUMBER_DIGIT = 10;		//�����̌�

	////cpp�ŏ�����
	//static const D3DXVECTOR2 NUMBER_SIZE;	//�����̃T�C�Y
	//static const D3DXVECTOR2 NUMBER_POS;	//�����̈ʒu

	//enum class TEXTURE_TYPE :int
	//{
	//	PLAYER,
	//	PLAYER_HP,
	//	ENEMY,
	//	ENEMY_ITEM,
	//	ENEMY_BARRIER,
	//	BULLET_CIRCLE_RED,
	//	BULLET_CIRCLE_GREEN,
	//	BULLET_SQUARE_GREEN,
	//	BULLET_LASER,
	//	BULLET_BARRIER,
	//	EXPLOSION,
	//	NUMBER,
	//	MULTIPLY,
	//	FRAME,
	//	NUM
	//};

	//enum class DRAW_TYPE :int
	//{
	//	PLAYER,
	//	PLAYER_HP_BAR,
	//	ENEMY_BARRIER,
	//	ENEMY_BARRIER_BARRIER,
	//	ENEMY_ITEM,
	//	PLAYER_BULLET,
	//	BULLET_ENEMY,
	//	EXPLOSION,
	//	PLAYER_ARM_ENEMY,
	//	PLAYER_ARM_BULLET,
	//	PLAYER_ARM_LASER,
	//	PLAYER_ARM_RIGHT,
	//	PLAYER_ARM_RIGHT_BULLET,
	//	PLAYER_ARM_RIGHT_LASER,
	//	PLAYER_ARM_CENTER,
	//	PLAYER_ARM_CENTTER_BULLET,
	//	PLAYER_ARM_CENTER_LASER,
	//	NUMBER,
	//	MULTIPLY,
	//	BOMB,						//���e
	//	FRAME,
	//	NUM
	//};


	//�����o�ϐ�
private:
	//int m_BGM = 0;

	//Score* m_pScore = nullptr;

	//TextureUseful* m_pTexUseful = nullptr;
	//DrawObject* m_pDrawObject = nullptr;

	//BG* m_pBG = nullptr;
	//BGPlanet* m_pBG_Moon = nullptr;
	//Player* m_pPlayer = nullptr;
	EnemyBarrierManagement* m_pEnemyBarrierManagement = nullptr;

	//PlayerHP* m_pPlayerHP = nullptr;
	//ExplosionManagement* m_pExplosionManagement = nullptr;
	//ItemManagement* m_pItemManagement = nullptr;

	//PlayerLeft* m_pPlayerLeft = nullptr;
	//PlayerRight* m_pPlayerRight = nullptr;
	//PlayerCenter* m_pPlayerCenter = nullptr;

	//UI* m_pMultiply = nullptr;
	//UI* m_pFrame = nullptr;
	//Number* m_pComboNum = nullptr;

	//AllEnemyManagement* m_pAllEnemyManagement = nullptr;

	//PlayerArmChange* m_pPlayerArmChange = nullptr;	//�r�̌���

	CollisionAll* m_pColAll = nullptr;		//�S�Ă̓����蔻��

	//Bom* m_pBom = nullptr;					//�{��

	//�����o�֐�
public:
	StageMercury(Score* pNumber);

	~StageMercury();	//�f�X�g���N�^

	//�X�V
	void Update(void);

	//�`��
	void Draw(void)const;

	//�X�R�A��Ԃ�
	int GetScore(void)const { return m_pScore->GetNumber(); }
};

void MercuryHitStop(int flame);
void MercuryBossDown();


#endif // !_STAGE_MERCURY_H_