//==============================================
//
//	[.h]
//	Author	:
//	Date	:
//==============================================
#pragma once


#pragma warning(push)
#pragma warning(disable:4005)

#define _CRT_SECURE_NO_WARNINGS			// scanf のwarning防止
#include <stdio.h>

#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <d3dx9.h>

#define DIRECTINPUT_VERSION 0x0800		// 警告対処
#include "dinput.h"
#include "mmsystem.h"

#pragma warning(pop)


//==============================================
//インクルード
//==============================================
#include "sprite.h"
#include "texture.h"
#include "input.h"
#include "renderer.h"
#include "sound.h"
#include "scene.h"
#include "collision.h"

//==============================================
// マクロ定義
//==============================================
#define SCREEN_WIDTH	(960)				// ウインドウの幅
#define SCREEN_HEIGHT	(540)				// ウインドウの高さ

#define SCREEN_LIMIT_UP 0
#define SCREEN_LIMIT_DOWN 540
#define SCREEN_LIMIT_LEFT 0
#define SCREEN_LIMIT_RIGHT 960


//==============================================
// プロトタイプ宣言
//==============================================
