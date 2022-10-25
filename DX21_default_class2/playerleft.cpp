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
	//  Rキーを押すと腕に装着している敵の弾を発射する
	if (GetKeyboardTrigger(DIK_E))	// 弾を発射させる
	{
		m_shot = true;	// 弾が発射した
	}
	// 発射する
	if (m_shot)
	{
		MovePos(D3DXVECTOR2(0.0f, -SHOT_SPEED));	// 動く際に必要

		if (GetScreenOut());
	}
	else
	{
		// 移動
		SetPos(pos - D3DXVECTOR2(30.0f, 0.0f));
	}
}
