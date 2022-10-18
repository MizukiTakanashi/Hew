
#include "main.h"
#include "titletext.h"

static	ID3D11ShaderResourceView	*g_TitleTextTexture = NULL;//テクスチャ情報
static	char	*g_ResultTextureName = (char*)"data\\texture\\titletext.png";
int		TitleTextTextureNo;//テクスチャ番号


void InitTitletext()
{
	//	テクスチャのロード
	TitleTextTextureNo = LoadTexture(g_ResultTextureName);
	if (TitleTextTextureNo == -1)
	{//読み込みエラー
		exit(999);	//強制終了
	}
}


void UninitTitletext()
{

}


void UpdateTitletext()
{

}


void DrawTitletext()
{
	////２Ｄ表示をするためのマトリクスを設定
	SetWorldViewProjection2D();
	//テクスチャのセット
	GetDeviceContext()->PSSetShaderResources(0, 1,
		GetTexture(TitleTextTextureNo));
	//スプライトの描画
	DrawSpriteColorRotation
	(
		SCREEN_WIDTH / 2,
		SCREEN_HEIGHT / 2,
		400,
		100,
		0,
		D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f),
		0,
		1.0f,
		1.0f,
		1
	);


}
