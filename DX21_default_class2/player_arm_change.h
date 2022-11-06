#pragma once
#include "player_left.h"
#include "player_right.h"

class PlayerArmChange
{
private:
	PlayerLeft* m_PlayerLeft = nullptr;	//�v���C���[�̍��r
	PlayerRight* m_PlayerRight = nullptr;	//�v���C���[�̉E�r
public:
	PlayerArmChange(){}	//�f�t�H���g�R���X�g���N�^
	
	//�����t���R���X�g���N�^
	PlayerArmChange(PlayerLeft* m_rPlayerLeft, PlayerRight* m_rPlayerRight)
	:m_PlayerLeft(m_rPlayerLeft),m_PlayerRight(m_rPlayerRight) {}	

	~PlayerArmChange(){}	//�f�X�g���N�^

	//�r�̒��g����
	void Change();
};