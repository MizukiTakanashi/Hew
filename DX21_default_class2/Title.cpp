//=======================================
// タイトル画面関係(cppファイル)
// 作成日：2022/07/14
// 作成者：高梨水希
//=======================================
#include	"main.h"
#include	"texture.h"

//#include	"input.h"
#include "inputx.h"
#include "keyboard.h"

#include	"scene.h"
#include	"sound.h"
#include	"BG.h"

//======================
// グローバル変数
//======================
static	ID3D11ShaderResourceView	*g_TitleTexture = NULL;//テクスチャ情報
static	char	*g_TitleTextureName = (char*)"data\\texture\\Title.png";
int		g_TitleSoundNo;
int		g_SE = 0;
BG* p_title_bg;
Sprite* g_p1Sprite;
bool g_title_tutorial = true;

//タイトル構造体
typedef	struct
{
	D3DXVECTOR3		Position;	//表示座標
	D3DXVECTOR2		Size;		//サイズ
	D3DXCOLOR		Color;		//色
	float			Rotate;		//角度
}TITLE;

TITLE	TitleObject;	//タイトル画面オブジェクト

int		TitleTextureNo;	//テクスチャ番号

//==========================
// 初期化処理
//==========================
void	InitTitle(bool tutorial)
{
	TitleTextureNo = LoadTexture(g_TitleTextureName);				//テクスチャのロード
	g_TitleSoundNo = LoadSound((char*)"data\\BGM\\Title.wav");	//サウンドのロード
	
	//決定音
	g_SE = LoadSound((char*)"data\\SE\\2_01.wav");
	//SetVolume(g_SE, 0.1f);

	if (TitleTextureNo == -1)
	{//読み込みエラー
		exit(999);	//強制終了
	}

	TitleObject.Position = D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);
	TitleObject.Size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	TitleObject.Color = D3DXCOLOR(1.0, 1.0, 1.0, 1.0);
	TitleObject.Rotate = 0.0;

	PlaySound(g_TitleSoundNo, -1);	//BGM再生
	SetVolume(g_TitleSoundNo, 0.1f);

	g_p1Sprite = new Sprite;

	//チュートリアルプレイ済みか
	g_title_tutorial = tutorial;
}

//==========================
// 終了処理
//==========================
void	UninitTitle()
{
	StopSound(g_TitleSoundNo);

	delete p_title_bg;
}

//======================
// 更新処理
//======================
void	UpdateTitle()
{
	//キー入力のチェック
	if (InputGetKeyDown(KK_SPACE) || IsButtonTriggered(0, XINPUT_GAMEPAD_B))
	{
		PlaySound(g_SE, 0);
		if (g_title_tutorial) {
			Fade(SCENE::SCENE_STAGE_SELECT, STAGE::STAGE_MOON);
		}
		else {
			Fade(SCENE::SCENE_STAGE_SELECT, STAGE::STAGE_MOON);
		}
	}

	//Aボタンを押したらステージ選択画面に行く
	/*if (InputGetKeyDown(KK_A))
	{
		Fade(SCENE::SCENE_STAGE_SELECT, STAGE::STAGE_MERCURY);
		PlaySound(g_SE, 0);
	}*/

	//Dボタンを押したらステージ選択画面に行く
	if (InputGetKeyDown(KK_D) || GetLeftTriggerTriggered(0, 120))
	{
		Fade(SCENE::SCENE_TITLE_SCORE, STAGE::STAGE_MERCURY);
		PlaySound(g_SE, 0);
	}

	//Wボタンを押したらリザルト画面に行く
	/*if (InputGetKeyDown(KK_S))
	{
		Fade(SCENE::SCENE_RESULT, STAGE::STAGE_MERCURY);
		PlaySound(g_SE, 0);
	}*/
}

//==========================
// 描画処理
//==========================
void	DrawTitle()
{
	//テクスチャのセット
	GetDeviceContext()->PSSetShaderResources(0, 1,
		GetTexture(TitleTextureNo));

	//スプライトの描画
	g_p1Sprite->DrawSpriteAnimationRotation
	(
		TitleObject.Position.x,
		TitleObject.Position.y,
		TitleObject.Size.x,
		TitleObject.Size.y,
		TitleObject.Rotate,
		TitleObject.Color,
		0,
		1.0f,
		1.0f,
		1
	);
}



