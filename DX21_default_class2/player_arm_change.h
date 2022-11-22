#pragma once
#include "player_left.h"
#include "player_right.h"
#include "player_center.h"

class PlayerArmChange
{
private:
	PlayerLeft* m_PlayerLeft = nullptr;	//プレイヤーの左腕
	PlayerRight* m_PlayerRight = nullptr;	//プレイヤーの右腕
	PlayerCenter* m_PlayerCenter = nullptr;	//プレイヤーの真ん中
public:
	PlayerArmChange(){}	//デフォルトコンストラクタ
	
	//引数付きコンストラクタ
	PlayerArmChange(PlayerLeft* m_rPlayerLeft, PlayerRight* m_rPlayerRight, PlayerCenter* m_rPlayerCenter)
	:m_PlayerLeft(m_rPlayerLeft),m_PlayerRight(m_rPlayerRight), m_PlayerCenter(m_rPlayerCenter) {}

	~PlayerArmChange(){}	//デストラクタ

	//腕の中身交換
	void Change();
};