//=======================================
// �����̃X�e�[�W�֌W(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#pragma once

#include "inh_stage.h"

#include "collision_all.h"

#include "management_enemy_fireball.h"
#include "management_enemy_acid.h"
#include "management_enemy_poorvision.h"
#include "management_enemy_speeddown.h"
#include "management_enemy_gatoring.h"

class StageVenus : public InhStage
{
//�����o�ϐ�
private:
	CollisionAll* m_pColAll = nullptr;		//�S�Ă̓����蔻��
	EnemyFireballManagement* m_pEnemyFireballManagement = nullptr;
	EnemyAcidManagement* m_pEnemyAcidManagement = nullptr;
	EnemyPoorvisionManagement* m_pEnemuPoorvisionManagement = nullptr;
	EnemySpeeddownManagement* m_pEnemySpeeddownManagement = nullptr;
	EnemyGatoringManagement* m_pEnemyGatoring = nullptr;

	int a = 0;

	bool m_poor_vision = false;

//�����o�֐�
public:
	StageVenus(Score* pNumber);

	~StageVenus()override;	//�f�X�g���N�^

	//�X�V
	void Update(void) override;

	//�`��
	void Draw(void)const override;

	//�X�R�A��Ԃ�
	int GetScore(void)const { return m_pScore->GetNumber(); }
};
