#pragma once
//============================================================
// �S�ẴQ�[���I�u�W�F�N�g�̓����蔻��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/11/10
// �쐬�ҁF��������
//============================================================

#ifndef _COLLISION_ALL_H_
#define _COLLISION_ALL_H_

#include "player.h"
#include "management_enemy.h"
#include "inh_player_arm_both.h"
#include "management_explosion.h"
#include "management_item.h"
#include "score.h"
#include "Bom.h"

//�e�X�e�[�W
#include "management_meteo.h"
#include "management_enemy_grenade.h"
#include "player_hp.h"
#include "management_poisonfield.h"

class CollisionAll
{
//�萔
public:
	enum class STAGE :int
	{
		MOON,
		MARS,
		MERCURY,
		SATURN,
		NUM
	};

private:
	//�����ŏ�����
	static const int ENEMY_NUM = 10;		//�S�G�̎�ސ��̐�����
	static const int SE_INTERVAL = 30;		//�����̉��̊Ԋu


//�����o�ϐ�
private:
	STAGE m_stage = STAGE::MOON;					//���݂̃X�e�[�W

	Player* m_pPlayer = nullptr;					//�v���C���[

	int m_enemy_num = 0;							//�G�̎�ނ̐�
	EnemyManagement* m_pEnemy[ENEMY_NUM];			//�G�S�N���X

	inhPlayerArmBoth* m_pPlayerLeft = nullptr;		//�v���C���[�̍��r
	inhPlayerArmBoth* m_pPlayerRight = nullptr;		//�v���C���[�̉E�r
	
	ExplosionManagement* m_pExplosion = nullptr;	//����
	ItemManagement* m_pItem = nullptr;				//�A�C�e��
	Score* m_pScore = nullptr;						//�|�����G�̐��\��
	Number* m_pCombo = nullptr;						//�R���{�̃|�C���^

	bool m_player_enemy_col = false;				//�v���C���[�ƓG����������������

	int m_SE = 0;									//�����̉�
	int m_SE_interval_count = 0;					//�����̉��̊Ԋu�J�E���g

	Bom* m_pBom = nullptr;							//�{��

	//==========================
	// �e�X�e�[�W
	//��
	Management_Meteo* m_pMeteo = nullptr;			//覐�

	//�ΐ�
	EnemyGrenadeManagement* m_pGrenade = nullptr;	//�O���l�[�h�G
	int m_SE_08 = 0;								//�o���A���e�𒵂˕Ԃ���
	int m_SE_09 = 0;								//�o���A�����鉹
	int m_SE_10 = 0;								//��C�𗁂т���

	//����
	PlayerHP* m_pHP = nullptr;						//�v���C���[��HP

	//�y��
	Management_PoisonField* m_pPoison = nullptr;	//�ŏ�

//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	CollisionAll();

	//�����t���R���X�g���N�^
	CollisionAll(STAGE stage, Player* pPlayer, inhPlayerArmBoth* pL, inhPlayerArmBoth* pR, 
		ExplosionManagement* pExplosion, ItemManagement* pItem, Score* pNumber, 
		Bom* pBom);

	//�f�X�g���N�^
	~CollisionAll(){}

	//�G�̃N���X�̃|�C���^��������
	void AddEnemyPointer(EnemyManagement* pEnemy) { 
		m_pEnemy[m_enemy_num] = pEnemy; 
		m_enemy_num++;
	}
	 
	//�����蔻��(�v���C���[��HP�����铖���蔻��)
	int Collision(void);

	//�v���C���[��HP���񕜂��铖���蔻��
	void HeelCollision(void);


	//==========================
	// �e�X�e�[�W
	
	//��
	//覐΂��Z�b�g
	void SetMeteo(Management_Meteo* pMeteo) { m_pMeteo = pMeteo; }

	//�ΐ�
	//�O���l�[�h�G���Z�b�g
	void SetGrenade(EnemyGrenadeManagement* pGrenade) { m_pGrenade = pGrenade; }

	//����
	//�v���C���[��HP���Z�b�g
	void SetHP(PlayerHP* pHP) { m_pHP = pHP; }

	//�y��
	//�ŏ����Z�b�g
	void SetPoison(Management_PoisonField* pPoison) { m_pPoison = pPoison; }
};

#endif // !_COLLISION_ALL_H_