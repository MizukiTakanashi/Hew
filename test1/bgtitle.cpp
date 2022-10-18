//==============================================
//
//	[.cpp]
//	Author	:
//	Date	:
//==============================================

//==============================================
//インクルード
//==============================================
#include	"main.h"
#include	"renderer.h"
#include	"texture.h"
#include	"sprite.h"

//==============================================
//マクロ定義
//==============================================

//==============================================
//グローバル変数
//==============================================
static	ID3D11ShaderResourceView	*g_TitleTexture = NULL;//テクスチャ情報
static	char	*g_TitleTextureName = (char*)"data\\texture\\bg.png";

typedef	struct
{
	D3DXVECTOR3		Position;	//表示座標
	D3DXVECTOR2		Size;		//サイズ
	D3DXCOLOR		Color;		//色
	float			Rotate;		//角度
}TITLE;

TITLE	TitleObject;//タイトル画面オブジェクト

int		TitleTextureNo;//テクスチャ番号

//==============================================
//初期化
//==============================================
void	InitBGTitle()
{
	//	テクスチャのロード
	TitleTextureNo = LoadTexture(g_TitleTextureName);
	if (TitleTextureNo == -1)
	{//読み込みエラー
		exit(999);	//強制終了
	}

	TitleObject.Position = D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);
	TitleObject.Size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	TitleObject.Color = D3DXCOLOR(1.0, 1.0, 1.0, 1.0);
	TitleObject.Rotate = 0.0;


}
//==============================================
//終了処理
//==============================================
void	UninitBGTitle()
{
}

//==============================================
//更新処理
//==============================================
void	UpdateBGTitle()
{



}
//==============================================
//描画処理
//==============================================
void	DrawBGTitle()
{
	//２Ｄ表示をするためのマトリクスを設定
	SetWorldViewProjection2D();
	//テクスチャのセット
	GetDeviceContext()->PSSetShaderResources(0, 1,
		GetTexture(TitleTextureNo));
	//スプライトの描画
	DrawSpriteColorRotation
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



