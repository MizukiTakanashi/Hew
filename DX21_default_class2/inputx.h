//=============================================================================
//
// ���͏��� [input.h]
// Author : 
//
//=============================================================================
#pragma once

#include <XInput.h>

//*****************************************************************************
// �}�N����`
//*****************************************************************************

//�{�^���ꗗ  DWORD�^�ϐ��l�ɑ΂��ĉ��L�̃r�b�g��ON/OFF�ŕ\�����
//��@�@�@�@�@button & XINPUT_GAMEPAD_A �� 0�łȂ����A��������Ă���
//            button & (XINPUT_GAMEPAD_A | XINPUT_GAMEPAD_B) ���@(XINPUT_GAMEPAD_A | XINPUT_GAMEPAD_B)�Ȃ�
//	      XINPUT_GAMEPAD_A��XINPUT_GAMEPAD_B�������ɂ�����Ă���

// XINPUT_GAMEPAD_DPAD_UP			�\���L�[��
// XINPUT_GAMEPAD_DPAD_DOWN			�\���L�[��
// XINPUT_GAMEPAD_DPAD_LEFT			�\���L�[��
// XINPUT_GAMEPAD_DPAD_RIGHT		�\���L�[�E
// XINPUT_GAMEPAD_START
// XINPUT_GAMEPAD_BACK
// XINPUT_GAMEPAD_LEFT_THUMB		L�X�e�B�b�N��������
// XINPUT_GAMEPAD_RIGHT_THUMB		R�X�e�B�b�N��������
// XINPUT_GAMEPAD_LEFT_SHOULDER		L�{�^��
// XINPUT_GAMEPAD_RIGHT_SHOULDER	R�{�^��
// XINPUT_GAMEPAD_A
// XINPUT_GAMEPAD_B
 //XINPUT_GAMEPAD_X
// XINPUT_GAMEPAD_Y

//�X�e�B�b�N�͈̔�
// X�� ��-1.0�@�E 1.0
// Y�� �� 1.0�@��-1.0

//�g���K�[�͈̔�
// 0 �` 255

// �o�C�u���[�V�����͈̔�
// 0 �` 255

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************

HRESULT InitInput(HINSTANCE hInst, HWND hWnd);	//�������ň��Ă�
void UninitInput(void);	//�I�������ň��Ă�
void UpdateInput(void);	//�A�b�v�f�[�g�����ň��Ă�


//�擾��������񂲂ƂɌĂѕ�����
//����ł��Ăяo���\

//================
// ���X�e�B�b�N

// ���E
// 0�ȏ�F�E  0�ȉ��F��
float GetThumbLeftX(int padNo);

//�㉺
// 0�ȏ�F��  0�ȉ��F��
float GetThumbLeftY(int padNo);

//================
// �E�X�e�B�b�N

// ���E
// 1.0�F�E  -1.0�F��
float GetThumbRightX(int padNo);

//�㉺
// 1.0�F��  -1.0�F��
float GetThumbRightY(int padNo);

// �o�C�u���[�V����
void SetLeftVibration(int padNo, int speed);	//��
void SetRightVibration(int padNo, int speed);	//�E
void SetVibration(int padNo, int speed);		//�S��
void StopVibration(int padNo);					//�~�߂�

//�����Ă���u��
int GetLeftTrigger(int padNo);
int GetRightTrigger(int padNo);
//�������u��
int GetLeftTriggerTriggered(int padNo);
int GetRightTriggerTriggered(int padNo);
//�������u��
// true�F������  false�F�����ĂȂ�
bool GetLeftTriggerRelease(int padNo);
bool GetRightTriggerRelease(int padNo);

BOOL IsButtonPressed(int padNo,DWORD button);	//�����Ă���u��
BOOL IsButtonTriggered(int padNo,DWORD button);	//�������u��
BOOL IsButtonRelease(int padNo,DWORD button);	//�������u��


