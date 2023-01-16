//=======================================
// �����̃X�e�[�W�֌W(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#pragma once

#include "inh_stage.h"

#include "collision_all.h"

#include "management_enemy_fireball.h"

class StageVenus : public InhStage
{
//�����o�ϐ�
private:
	CollisionAll* m_pColAll = nullptr;		//�S�Ă̓����蔻��
	EnemyFireballManagement* m_pEnemyFireballManagement = nullptr;

	//�����o�֐�
public:
	StageVenus(Score* pNumber);

	~StageVenus();	//�f�X�g���N�^

	//�X�V
	void Update(void) override;

	//�`��
	void Draw(void)const override;

	//�X�R�A��Ԃ�
	int GetScore(void)const { return m_pScore->GetNumber(); }
};

void VenusHitStop(int flame);
void VenusBossDown();
