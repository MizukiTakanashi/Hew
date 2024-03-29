//=======================================
// 自機の右(ヘッダ)
// 作成日：2022/10/25
// 作成者：山本亮太
//=======================================
#include "player_right.h"

//#include "input.h"
#include "inputx.h"
#include "keyboard.h"

//==========================
// 定数の初期化
//==========================
const D3DXVECTOR2 PlayerRight::FROM_PLAYER_POS = D3DXVECTOR2(40.0f, 0.0f);

//==========================
// ボタン判定
//==========================
void PlayerRight::ButtonPress(void)
{
	//切り離しボタン
	inhPlayerArmBoth::SetSeparationButton(InputGetKeyDown(KK_C) || IsButtonTriggered(0, XINPUT_GAMEPAD_RIGHT_SHOULDER));

	//弾発射ボタン(押している間)
	inhPlayerArmBoth::SetBulletShotButton(InputGetKey(KK_SPACE) || (GetRightTrigger(0) > TRIGGER) || (GetLeftTrigger(0) > TRIGGER));

	//弾発射ボタン(押した時)
	inhPlayerArmBoth::SetBulletShotButtonTrigger(InputGetKeyDown(KK_SPACE) || GetRightTriggerTriggered(0, TRIGGER) || GetLeftTriggerTriggered(0, TRIGGER));
}
