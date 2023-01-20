#pragma once
//=======================================
// �ΐ��̃X�e�[�W�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/12/15
// �쐬�ҁF��������
//=======================================

#ifndef _STAGE_MARS_H_
#define _STAGE_MARS_H_

#include "inh_stage.h"

#include "management_enemy_barrier.h"
#include "management_enemy_missile.h"
#include "management_enemy_icerain.h"
#include "management_enemy_stop.h"
#include "management_enemy_grenade.h"
#include "all_enemy_management.h"
#include "collision_all.h"
#include "boss.h"

class StageMars : public InhStage
{
	//�����o�ϐ�
private:
	EnemyBarrierManagement* m_pEnemyBarrierManagement = nullptr;
	EnemyIceRainManagement* m_pEnemyIceRainManagement = nullptr;
	EnemyStopManagement* m_pEnemyStopManagement = nullptr;
	EnemyMissileManagement* m_pEnemyMissileManagement = nullptr;
	EnemyGrenadeManagement* m_pEnemyGrenadeManagement = nullptr;

	AllEnemyManagement* m_pAllEnemyManagement = nullptr;
	CollisionAll* m_pColAll1 = nullptr;
	Boss* m_pBoss = nullptr;

	//�����o�֐�
public:
	StageMars(Score* pNumber);

	~StageMars()override;	//�f�X�g���N�^

	//�X�V
	void Update(void);

	//�`��
	void Draw(void)const;

	//�X�R�A��Ԃ�
	int GetScore(void)const { return m_pScore->GetNumber(); }
};

#endif // !_STAGE_MARS_H_