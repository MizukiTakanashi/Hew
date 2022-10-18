
#include "main.h"
#include "resulttext.h"

static	ID3D11ShaderResourceView	*g_ResultTextTexture = NULL;//テクスチャ情報
static	char	*g_ResultTextureName = (char*)"data\\texture\\resulttext.png";
int		ResultTextTextureNo;//テクスチャ番号


void InitResulttext()
{
	//	テクスチャのロード
	ResultTextTextureNo = LoadTexture(g_ResultTextureName);
	if (ResultTextTextureNo == -1)
	{//読み込みエラー
		exit(999);	//強制終了
	}
}


void UninitResulttext()
{

}


void UpdateResulttext()
{

}


void DrawResulttext()
{
	////２Ｄ表示をするためのマトリクスを設定
	SetWorldViewProjection2D();
	//テクスチャのセット
	GetDeviceContext()->PSSetShaderResources(0, 1,
		GetTexture(ResultTextTextureNo));
	//スプライトの描画
	DrawSpriteColorRotation
	(
		SCREEN_WIDTH / 2,
		SCREEN_HEIGHT / 2 - 100,
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
