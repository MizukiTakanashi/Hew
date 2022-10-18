
#pragma once

#include <windows.h>
#include "xaudio2.h"


bool InitSound(HWND hWnd);	//�T�E���h�̏�����
void UninitSound(void);		//�T�E���h�̏I������

int LoadSound(char* pFilename);				//�T�E���h�̃��[�h
void PlaySound(int index, int loopCount);	//�T�E���h�̍Đ� loopCount:0,���Đ�:0����,���[�v:1�ȏ�,���[�v��
void StopSound(int index);					//�T�E���h�̒�~

void StopSoundAll(void);					//�T�E���h�̑S��~
void SetVolume(int index, float vol);		//�T�E���h�̉��ʐݒ�
