//=======================================
// 自機の真ん中(ヘッダ)
// 作成日：
// 作成者：恩田洋行
//=======================================
#include "player_center.h"
#include "inputx.h"
#include "keyboard.h"

//==========================
// 定数の初期化
//==========================
const D3DXVECTOR2 PlayerCenter::FROM_PLAYER_POS = D3DXVECTOR2(0.0f, 30.0f);

void PlayerCenter::ArmDraw(void) const
{
	//腕になにかついていれば描画
	if (m_type != TYPE::TYPE_NONE)
	{
		if (m_type != TYPE::TYPE_OLD) {
			//腕についているアイテム自身の描画
			//DrawReverse();
			//残弾数横の敵アイコン表示
			Draw(m_Remaining_Icon_Pos, ICON_SIZE);
		}

		if (m_pEnemyItem != nullptr) {
			//腕についているアイテムの弾等描画
			m_pEnemyItem->PlayerArmDraw();
			if (m_type != TYPE::TYPE_OLD)
			{
				m_pRemaining_Num->DrawNumber();
			}
		}

	}
}

//==========================
// ボタン判定
//==========================
void PlayerCenter::ButtonPress(void)
{

}
