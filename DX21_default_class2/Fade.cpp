
#include "main.h"
#include "texture.h"
#include "sprite.h"
#include "Fade.h"



FADE_STATE	g_FadeState;
SCENE		g_FadeNextScene;
float		g_FadeAlpha;


void InitFade()
{
	g_FadeState = FADE_STATE_NONE;
	g_FadeNextScene = SCENE_NONE;
	g_FadeAlpha = 0.0f;
}



void UninitFade()
{

}


void UpdateFade()
{

	if (g_FadeState == FADE_STATE_OUT)
	{
		if (g_FadeAlpha >= 1.0f)
		{
			g_FadeAlpha = 1.0f;
			g_FadeState = FADE_STATE_IN;
			SetScene(g_FadeNextScene);
		}

		g_FadeAlpha += 1.0f / 20.0f;

	}
	else if (g_FadeState == FADE_STATE_IN)
	{

		if (g_FadeAlpha <= 0.0f)
		{
			g_FadeAlpha = 0.0f;
			g_FadeState = FADE_STATE_NONE;
		}

		g_FadeAlpha -= 1.0f / 20.0f;

	}

}

void DrawFade()
{
	if (g_FadeState == FADE_STATE_NONE)
		return;


	m_pTexUseful1[0];

	Sprite::DrawSpriteUVStart(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, g_FadeAlpha), 0.0f, m_start_uv_y, 1.0f, 1.0f);
}



void Fade(SCENE NextScene)
{

	g_FadeNextScene = NextScene;

	g_FadeState = FADE_STATE_OUT;

}



FADE_STATE GetFadeState()
{
	return g_FadeState;
}
