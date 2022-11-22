#pragma once
#include "player_left.h"
#include "player_right.h"
#include "player_center.h"

class PlayerArmChange
{
private:
	PlayerLeft* m_PlayerLeft = nullptr;	//�v���C���[�̍��r
	PlayerRight* m_PlayerRight = nullptr;	//�v���C���[�̉E�r
	PlayerCenter* m_PlayerCenter = nullptr;	//�v���C���[�̐^��
public:
	PlayerArmChange(){}	//�f�t�H���g�R���X�g���N�^
	
	//�����t���R���X�g���N�^
	PlayerArmChange(PlayerLeft* m_rPlayerLeft, PlayerRight* m_rPlayerRight, PlayerCenter* m_rPlayerCenter)
	:m_PlayerLeft(m_rPlayerLeft),m_PlayerRight(m_rPlayerRight), m_PlayerCenter(m_rPlayerCenter) {}

	~PlayerArmChange(){}	//�f�X�g���N�^

	//�r�̒��g����
	void Change();
};