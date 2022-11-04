//=============================================================================
//
// 入力処理 [input.h]
// Author : 
//
//=============================================================================
#pragma once

#include <XInput.h>

//*****************************************************************************
// マクロ定義
//*****************************************************************************

//ボタン一覧  DWORD型変数値に対して下記のビットのON/OFFで表される
//例　　　　　button & XINPUT_GAMEPAD_A が 0でなければAが押されている
//            button & (XINPUT_GAMEPAD_A | XINPUT_GAMEPAD_B) が　(XINPUT_GAMEPAD_A | XINPUT_GAMEPAD_B)なら
//	      XINPUT_GAMEPAD_AとXINPUT_GAMEPAD_Bが同時におされている

// XINPUT_GAMEPAD_DPAD_UP			十字キー上
// XINPUT_GAMEPAD_DPAD_DOWN			十字キー下
// XINPUT_GAMEPAD_DPAD_LEFT			十字キー左
// XINPUT_GAMEPAD_DPAD_RIGHT		十字キー右
// XINPUT_GAMEPAD_START
// XINPUT_GAMEPAD_BACK
// XINPUT_GAMEPAD_LEFT_THUMB		Lスティック押し込み
// XINPUT_GAMEPAD_RIGHT_THUMB		Rスティック押し込み
// XINPUT_GAMEPAD_LEFT_SHOULDER		Lボタン
// XINPUT_GAMEPAD_RIGHT_SHOULDER	Rボタン
// XINPUT_GAMEPAD_A
// XINPUT_GAMEPAD_B
 //XINPUT_GAMEPAD_X
// XINPUT_GAMEPAD_Y

//スティックの範囲
// X軸 左-1.0　右 1.0
// Y軸 上 1.0　下-1.0

//トリガーの範囲
// 0 ～ 255

// バイブレーションの範囲
// 0 ～ 255

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************

HRESULT InitInput(HINSTANCE hInst, HWND hWnd);	//初期化で一回呼ぶ
void UninitInput(void);	//終了処理で一回呼ぶ
void UpdateInput(void);	//アップデート処理で一回呼ぶ


//取得したい情報ごとに呼び分ける
//何回でも呼び出し可能

//================
// 左スティック

// 左右
// 0以上：右  0以下：左
float GetThumbLeftX(int padNo);

//上下
// 0以上：上  0以下：下
float GetThumbLeftY(int padNo);

//================
// 右スティック

// 左右
// 1.0：右  -1.0：左
float GetThumbRightX(int padNo);

//上下
// 1.0：上  -1.0：下
float GetThumbRightY(int padNo);

// バイブレーション
void SetLeftVibration(int padNo, int speed);	//左
void SetRightVibration(int padNo, int speed);	//右
void SetVibration(int padNo, int speed);		//全体
void StopVibration(int padNo);					//止める

//押している瞬間
int GetLeftTrigger(int padNo);
int GetRightTrigger(int padNo);
//押した瞬間
int GetLeftTriggerTriggered(int padNo);
int GetRightTriggerTriggered(int padNo);
//離した瞬間
// true：離した  false：離してない
bool GetLeftTriggerRelease(int padNo);
bool GetRightTriggerRelease(int padNo);

BOOL IsButtonPressed(int padNo,DWORD button);	//押している瞬間
BOOL IsButtonTriggered(int padNo,DWORD button);	//押した瞬間
BOOL IsButtonRelease(int padNo,DWORD button);	//離した瞬間


