#pragma once
//=========================================================
// ���ł���Œ��̘r�ƓG�̓����蔻��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/11/11
// �쐬�ҁF��������
//=========================================================

#include "player_left.h"
#include "player_right.h"
#include "management_item.h"
#include "management_enemy_laser.h"
#include "management_enemy_gatoring.h"
#include "management_enemy.h"
#include "management_explosion.h"

class ArmAllEnemyCollision
{
private:
	PlayerLeft* m_rplayerleft = nullptr;
	PlayerRight* m_rplayerright = nullptr;
	EnemyLaserManagement* m_rEnemyLaserManagement = nullptr;
	EnemyGatoringManagement* m_rEnemyGatoringManagement = nullptr;
	EnemyManagement* m_rEnemyManagement = nullptr;
	ExplosionManagement* m_rExplosionManagement = nullptr;

public:
	ArmAllEnemyCollision() {}	//�f�t�H���g�R���X�g���N�^
	//�����t���R���X�g���N�^
	ArmAllEnemyCollision(PlayerLeft* rplayerleft, PlayerRight* rplayerright, EnemyLaserManagement* rEnemyLaserManagement,
		EnemyGatoringManagement* rEnemyGatoringManagements, EnemyManagement* rEnemyManagement, ExplosionManagement* rExplosionManagement)
		:m_rplayerleft(rplayerleft), m_rplayerright(rplayerright), m_rEnemyLaserManagement(rEnemyLaserManagement),
		m_rEnemyGatoringManagement(rEnemyGatoringManagements), m_rEnemyManagement(rEnemyManagement), m_rExplosionManagement(rExplosionManagement) {}

	~ArmAllEnemyCollision() {}		//�f�X�g���N�^

	//�X�V����
	void Update(void);
};