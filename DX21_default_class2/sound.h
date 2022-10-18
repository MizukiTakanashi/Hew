
#pragma once

#include <windows.h>
#include "xaudio2.h"


bool InitSound(HWND hWnd);
void UninitSound(void);

int LoadSound(char* pFilename);				//�T�E���h�̃��[�h(�t�@�C�������w��)
void PlaySound(int index, int loopCount);	//loopCount�Ń��[�v���w�� 0:���Đ� 0����:���[�v�Đ� 1�ȏ�:���[�v��
void StopSound(int index);
void StopSoundAll(void);					//
void SetVolume(int index, float vol);
