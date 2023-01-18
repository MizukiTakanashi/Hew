//=======================================
// 自機の左(ヘッダ)
// 作成日：2022/10/25
// 作成者：小西 蓮
//=======================================
#include "player_left.h"

//#include "input.h"
#include "inputx.h"
#include "keyboard.h"

//==========================
// 定数の初期化
//==========================
const D3DXVECTOR2 PlayerLeft::FROM_PLAYER_POS = D3DXVECTOR2(-40.0f, 0.0f);

void PlayerLeft::ArmDraw(void) const
{
	//腕になにかついていれば描画
	if (m_type != TYPE::TYPE_NONE)
	{
		if (m_type != TYPE::TYPE_OLD) {
			//腕についているアイテム自身の描画
			DrawReverse();
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
void PlayerLeft::ButtonPress(void)
{
	//切り離しボタン
	inhPlayerArmBoth::SetSeparationButton(InputGetKeyDown(KK_E) || IsButtonTriggered(0, XINPUT_GAMEPAD_LEFT_SHOULDER));

	//弾発射ボタン(押している間)
	inhPlayerArmBoth::SetBulletShotButton((InputGetKey(KK_SPACE) || IsButtonPressed(0, XINPUT_GAMEPAD_A)) ||
		GetRightTrigger(0) > TRIGGER);

	//弾発射ボタン(押した時)
	inhPlayerArmBoth::SetBulletShotButtonTrigger((InputGetKeyDown(KK_SPACE) || IsButtonTriggered(0, XINPUT_GAMEPAD_A)) ||
		GetRightTriggerTriggered(0, TRIGGER));
}
