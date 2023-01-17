#pragma once
//=======================================
// �y���̃X�e�[�W�֌W(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================

#ifndef _STAGE_SATURN_H_
#define _STAGE_SATURN_H_

#include "inh_stage.h"

#include "all_enemy_management.h"
#include "saturn_collision_all.h"
#include "management_enemy_laser.h"
#include "management_enemy_megumin.h"
#include "management_poisonfield.h"
class StageSaturn : public InhStage
{
//�萔
private:



//�����o�ϐ�
private:
	EnemyLaserManagement* m_pEnemyLaserManagement = nullptr;
	EnemyMeguminManagement* m_pEnemyMeguminManagement = nullptr;
	AllEnemyManagement* m_pAllEnemyManagement = nullptr;
	SaturnCollisionAll* m_pColAll = nullptr;		//�S�Ă̓����蔻��
	Management_PoisonField* m_pPoisonField = nullptr;
//�����o�֐�
public:
	StageSaturn(Score* pNumber);

	~StageSaturn();	//�f�X�g���N�^

	//�X�V
	void Update(void);

	//�`��
	void Draw(void)const;

	//�X�R�A��Ԃ�
	int GetScore(void)const { return m_pScore->GetNumber(); }
};

void SaturnHitStop(int flame);
void SaturnBossDown();


#endif // !_STAGE_SATURN_H_