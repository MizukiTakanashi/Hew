
#pragma once

#include <windows.h>
#include "xaudio2.h"


bool InitSound(HWND hWnd);	//サウンドの初期化
void UninitSound(void);		//サウンドの終了処理

int LoadSound(char* pFilename);				//サウンドのロード
void PlaySound(int index, int loopCount);	//サウンドの再生 loopCount:0,一回再生:0未満,ループ:1以上,ループ回数
void StopSound(int index);					//サウンドの停止

void StopSoundAll(void);					//サウンドの全停止
void SetVolume(int index, float vol);		//サウンドの音量設定
