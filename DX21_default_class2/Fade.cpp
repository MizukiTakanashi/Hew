
#include "main.h"
#include "texture.h"
#include "sprite.h"
#include "Fade.h"
#include "scene.h"

FADE_STATE	g_FadeState;
SCENE		g_FadeNextScene;
float		g_FadeAlpha;
float m_start_uv_y = 0.0f;		//UVÀ•WY

void InitFade()
{
	g_FadeState = FADE_STATE_NONE;
	g_FadeNextScene = SCENE_NONE;
	g_FadeAlpha = 0.0f;
	SetScene(SCENE::SCENE_TITLE);
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

	//SetTexture(0);

	//DrawSprite(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT,
	//	0.0f, 0.0f, 1.0f, 1.0f,
	//	MakeFloat4(0.0f, 0.0f, 0.0f, g_FadeAlpha));
	//GetDeviceContext()->PSGetShaderResources(0, 1, NULL);

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
