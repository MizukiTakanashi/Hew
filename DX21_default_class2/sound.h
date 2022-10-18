
#pragma once

#include <windows.h>
#include "xaudio2.h"


bool InitSound(HWND hWnd);
void UninitSound(void);

int LoadSound(char* pFilename);				//サウンドのロード(ファイル名を指定)
void PlaySound(int index, int loopCount);	//loopCountでループを指定 0:一回再生 0未満:ループ再生 1以上:ループ回数
void StopSound(int index);
void StopSoundAll(void);					//
void SetVolume(int index, float vol);
