#pragma once
#include"main.h"
#include "scene.h"
#include "texture_useful.h"
enum FADE_STATE
{
	FADE_STATE_NONE,
	FADE_STATE_IN,
	FADE_STATE_OUT
};
TextureUseful* m_pTexUseful1 = nullptr;
float m_start_uv_y = 0.0f;		//UVç¿ïWY
void InitFade();
void UninitFade();
void UpdateFade();
void DrawFade();

void Fade(SCENE NextScene);
FADE_STATE GetFadeState();
