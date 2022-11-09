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
const D3DXVECTOR2 PlayerRight::FROM_PLAYER_POS = D3DXVECTOR2(30.0f, 0.0f);

//==========================
// ボタン判定
//==========================
void PlayerRight::ButtonPress(void)
{
	//切り離しボタン
	inhPlayerArmBoth::SetSeparationButton(InputGetKeyDown(KK_R) || IsButtonTriggered(0, XINPUT_GAMEPAD_RIGHT_SHOULDER));

	//弾発射ボタン(押している間)
	inhPlayerArmBoth::SetBulletShotButton((InputGetKey(KK_SPACE) || IsButtonPressed(0, XINPUT_GAMEPAD_A)) ||
		GetRightTrigger(0) > TRIGGER);

	//弾発射ボタン(押した時)
	inhPlayerArmBoth::SetBulletShotButtonTrigger((InputGetKey(KK_SPACE) || IsButtonPressed(0, XINPUT_GAMEPAD_A)) ||
		GetRightTriggerTriggered(0, TRIGGER));
}
