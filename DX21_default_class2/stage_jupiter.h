#pragma once
//=======================================
// �ؐ��̃X�e�[�W�֌W(�w�b�_�t�@�C��)
// �쐬���F2023/01/26
// �쐬�ҁF��������
//=======================================

#ifndef _STAGE_JUPITER_H_
#define _STAGE_JUPITER_H_

#include "inh_stage.h"
#include "collision_all.h"
#include "all_enemy_management.h"
#include "management_enemy_laser.h"
#include "management_enemy_missile.h"
#include "management_enemy_barrier.h"
#include "management_enemy_public.h"

class StageJupiter : public InhStage
{
//�����o�ϐ�
private:
	//�G
	Management_EnemyPublic* m_pEnemyPublic = nullptr;
	EnemyMissileManagement* m_pEnemyMissile = nullptr;
	EnemyLaserManagement* m_pEnemyLaser = nullptr;
	EnemyBarrierManagement* m_pEnemyBarrier = nullptr;
	AllEnemyManagement* m_pAllEnemyManagement = nullptr;
	CollisionAll* m_pColAll = nullptr;


//�����o�֐�
public:
	StageJupiter(Score* pNumber);

	~StageJupiter()override;	//�f�X�g���N�^

	//�X�V
	void Update(void);

	//�`��
	void Draw(void)const;

	//�X�R�A��Ԃ�
	int GetScore(void)const { return m_pScore->GetNumber(); }
};

#endif // !_STAGE_JUPITER_H_