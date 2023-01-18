//=======================================
// �Q�[����ʊ֌W(�w�b�_�t�@�C��)
// �쐬���F2022/07/14
// �쐬�ҁF��������
//=======================================
#pragma once
#ifndef _GAME_H_
#define _GAME_H_

#include "inh_stage.h"

#include "collision_all.h"
#include "text_management.h"
#include "management_enemy_missile.h"
#include "management_enemy_laser.h"
#include "management_enemy_gatoring.h"
#include "all_enemy_management.h"


class Game : public InhStage
{
	//�����o�ϐ�
private:
	EnemyMissileManagement* m_pEnemyMissileManagement = nullptr;
	EnemyLaserManagement* m_pEnemyLaserManagement = nullptr;
	EnemyGatoringManagement* m_pEnemyGatoringManagement = nullptr;
	AllEnemyManagement* m_pAllEnemyManagement = nullptr;
	CollisionAll* m_pColAll = nullptr;		//�S�Ă̓����蔻��
	TextManagement* m_pTextManagement = nullptr; //�`���[�g���A���e�L�X�g

	//�����o�֐�
public:
	Game(Score* pNumber);

	~Game();	//�f�X�g���N�^

	//�X�V
	void Update(void);

	//�`��
	void Draw(void)const;

	//�X�R�A��Ԃ�
	int GetScore(void)const { return m_pScore->GetNumber(); }
};

//�`���[�g���A���e�L�X�g�֘A
//�e�L�X�g�J�n
void StartTextG(void);
//�e�L�X�g�I��
void EndTextG(void);
//
bool GetTextFlg(void);

#endif // !_GAME_H_


