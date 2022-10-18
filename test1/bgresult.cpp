//==============================================
//
//	[.cpp]
//	Author	:
//	Date	:
//==============================================

//==============================================
//インクルード
//==============================================
#include "main.h"
#include "bgresult.h"

//==============================================
//マクロ定義
//==============================================

//==============================================
//グローバル変数
//==============================================
static	ID3D11ShaderResourceView	*g_ResultTexture = NULL;//テクスチャ情報
static	char	*g_ResultTextureName = (char*)"data\\texture\\bg.png";

typedef	struct
{
	D3DXVECTOR3		Position;	//表示座標
	D3DXVECTOR2		Size;		//サイズ
	D3DXCOLOR		Color;		//色
	float			Rotate;		//角度
}RESULT;

RESULT	ResultObject;//タイトル画面オブジェクト

int		ResultTextureNo;//テクスチャ番号

//==============================================
//初期化
//==============================================
void	InitBGResult()
{
	//	テクスチャのロード
	ResultTextureNo = LoadTexture(g_ResultTextureName);
	if (ResultTextureNo == -1)
	{//読み込みエラー
		exit(999);	//強制終了
	}

	ResultObject.Position = D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);
	ResultObject.Size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	ResultObject.Color = D3DXCOLOR(1.0, 1.0, 1.0, 1.0);
	ResultObject.Rotate = 0.0;


}
//==============================================
//終了処理
//==============================================
void	UninitBGResult()
{
}

//==============================================
//更新処理
//==============================================
void	UpdateBGResult()
{
	//キー入力のチェック
	if (GetKeyboardTrigger(DIK_SPACE))
	{
		SetScene(SCENE::SCENE_GAME);
	}


}
//==============================================
//描画処理
//==============================================
void	DrawBGResult()
{
	//２Ｄ表示をするためのマトリクスを設定
	SetWorldViewProjection2D();
	//テクスチャのセット
	GetDeviceContext()->PSSetShaderResources(0, 1,
		GetTexture(ResultTextureNo));
	//スプライトの描画
	DrawSpriteColorRotation
	(
		ResultObject.Position.x,
		ResultObject.Position.y,
		ResultObject.Size.x,
		ResultObject.Size.y,
		ResultObject.Rotate,
		ResultObject.Color,
		0,
		1.0f,
		1.0f,
		1
	);


}



