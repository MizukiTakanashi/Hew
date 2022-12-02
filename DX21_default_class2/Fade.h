#pragma once
#include"main.h"
#include "scene.h"
enum FADE_STATE
{
	FADE_STATE_NONE,
	FADE_STATE_IN,
	FADE_STATE_OUT
};

void InitFade();
void UpdateFade();
void DrawFade();

void Fade(SCENE NextScene);
FADE_STATE GetFadeState();
