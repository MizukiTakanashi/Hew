//=======================================
// 自機の左(ヘッダ)
// 作成日：2022/10/25
// 作成者：小西 蓮
//=======================================
#include "playerleft.h"
#include "input.h"

const float PlayerLeft::SHOT_SPEED = 0.1f;

void PlayerLeft::Update(D3DXVECTOR2 pos) 
{
	//  Rキーを押すと腕に装着している敵を発射する
	if (GetKeyboardTrigger(DIK_E))	
	{
		m_shot = true;	// 発射した
	}

	// 発射する
	if (m_shot)
	{
		MovePos(D3DXVECTOR2(0.0f, -SHOT_SPEED));	// 動く際に必要
		
		// 画面外に出たらTYPEを元に戻す
		if (GetScreenOut())
		{
			m_type = TYPE::TYPE_NONE;
		}
	}
	else
	{
		// 移動
		SetPos(pos - D3DXVECTOR2(30.0f, 0.0f));
	}
}

void PlayerLeft::LeftDraw(void)
{
	if (m_type != TYPE::TYPE_NONE)
	{
		Draw();
	}
}
