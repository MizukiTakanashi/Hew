#pragma once
//============================================================
// �y���̑S�ẴQ�[���I�u�W�F�N�g�̓����蔻��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/1/17
// �쐬�ҁF��������
//============================================================

#ifndef _SATURN_COLLISION_ALL_H_
#define _SATURN_COLLISION_ALL_H_

#include "player.h"
#include "management_enemy.h"
#include "inh_player_arm_both.h"
#include "management_explosion.h"
#include "management_item.h"
#include "score.h"
#include "Bom.h"

class SaturnCollisionAll
{
	//�萔
private:
	enum class TYPE :int
	{
		//�V�����G�͏ォ��ǉ�
		NORMAL,
		GATORING,
		NUM
	};


	//�����ŏ�����
	static const int ENEMY_NUM = 10;		//�S�G�̎�ސ��̐�����
	static const int SE_INTERVAL = 30;		//�����̉��̊Ԋu

	//�����o�ϐ�
private:
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

	Bom* m_pBom = nullptr;							//�{��

	int m_SE = 0;									//�����̉�
	int m_SE_interval_count = 0;					//�����̉��̊Ԋu�J�E���g
	int m_SE_08 = 0;								//�o���A���e�𒵂˕Ԃ���
	int m_SE_09 = 0;								//�o���A�����鉹
	int m_SE_10 = 0;								//��C�𗁂т���

	//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	SaturnCollisionAll();

	//�����t���R���X�g���N�^
	SaturnCollisionAll(Player* pPlayer, inhPlayerArmBoth* pL, inhPlayerArmBoth* pR,
		ExplosionManagement* pExplosion, ItemManagement* pItem, Score* pNumber,
		Bom* pBom);

	//�f�X�g���N�^
	~SaturnCollisionAll() {}

	//�G�̃N���X�̃|�C���^��������
	void AddEnemyPointer(EnemyManagement* pEnemy) {
		m_pEnemy[m_enemy_num] = pEnemy;
		m_enemy_num++;
	}

	//�����蔻��(�v���C���[��HP�����铖���蔻��)
	int Collision(void);

	//�v���C���[��HP���񕜂��铖���蔻��
	void HeelCollision(void);
};

#endif // !_MARS_COLLISION_ALL_H_