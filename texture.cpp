
//====================
//テクスチャ管理
//====================

#include	"texture.h"

//=====================
//マクロ定義
//=====================
#define		MAX_TEXTURE_NUM		(100)	//テクスチャをロードできる枚数

//=====================
//グローバル変数
//=====================
//ロードしたテクスチャの情報配列
static	ID3D11ShaderResourceView*	g_pTexture[MAX_TEXTURE_NUM];

//ロードしたテクスチャの枚数を表す
static	UINT	g_TextureIndex = 0;

//ロードしたテクスチャファイル名のバッファ
static	char	g_TextureName[MAX_TEXTURE_NUM][256];

//=====================
//プロトタイプ宣言
//=====================


//======================================
//テクスチャのロード
//in	ファイル名
//out	テクスチャインデックス
//======================================
int		LoadTexture(char* filename)
{
	//すでに読み込まれたテクスチャ名を調べて同名の
	//テクスチャ名がある場合は、その番号を返す。
	for (int i = 0; i < g_TextureIndex; i++)
	{
		//テクスチャ名の比較
		if (strcmp(g_TextureName[i], filename) == 0 )
		//if (strcmp(&g_TextureName[i][0], filename))
		{
			return	i;
		}
	}
	//読み込み最大数を超えていたらエラー
	if (g_TextureIndex == MAX_TEXTURE_NUM)
	{
		return	-1;	//エラー値としてマイナス値を返す
	}

	//テクスチャのロード
	HRESULT		hr = D3DX11CreateShaderResourceViewFromFile(
					GetDevice(),
					filename,
					NULL,
					NULL,
					&g_pTexture[g_TextureIndex],
					NULL);
	if (hr != S_OK)
	{
		return	-1;	//エラー値としてマイナス値を返す
	}

	//テクスチャ名の登録
	strcpy_s(g_TextureName[g_TextureIndex], 256, filename);
//	strcpy_s(&g_TextureName[g_TextureIndex][0], 256, filename);

	int		retIndex = g_TextureIndex;	//現在の数を保存

	g_TextureIndex++;					//読み込み数をインクリメント

	return	retIndex;					//読み込んだテクスチャの番号を返す
}
//=====================================
//テクスチャの解放
//=====================================
void	UninitTexture()
{
	//読み込んだ全てのテクスチャを解放する
	for (int i = 0; i < g_TextureIndex; i++)
	{
		if (g_pTexture[i] != NULL)//ポインタが入っているか？
		{
			g_pTexture[i]->Release();	//テクスチャを解放する
			g_pTexture[i] = NULL;		//ポインタを初期化する
		}
	}

}
//=====================================
//テクスチャの取得
//in	テクスチャインデックス
//out	テクスチャ情報のあるポインタ
//=====================================
ID3D11ShaderResourceView**	GetTexture(int index)
{
	//不正値のチェック
	if (index < 0)				//0未満の時
	{
		return	NULL;
	}
	if(index >= g_TextureIndex)	//読み込み数オーバー
	{ 
		return	NULL;
	}

	return	&g_pTexture[index];//indexが表す配列のポインタ

}