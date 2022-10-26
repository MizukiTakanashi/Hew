//=======================================
// 自機の右(ヘッダ)
// 作成日：2022/10/25
// 作成者：山本亮太
//=======================================
#include "playerright.h"
#include "input.h"

const float PlayerRight::SHOT_SPEED = 0.1f;

void PlayerRight::Update(D3DXVECTOR2 pos)
{


	//Rを押したら発射
	if (GetKeyboardTrigger(DIK_R))
	{
		m_shot = true;
	}

	//発射
	if (m_shot)
	{
		MovePos(D3DXVECTOR2(0.0f, -SHOT_SPEED));

		//画面外に出たらTYPEを元に戻す
		if (GetScreenOut())
		{
			m_type = TYPE::TYPE_NONE;
		}
	}
	else
	{
		//移動
		SetPos(pos + D3DXVECTOR2(30.0f, 0.0f));
	}

}

void PlayerRight::RightDraw(void)
{
	if (m_type != TYPE::TYPE_NONE)
	{
		Draw();
	}
}
