//==============================================
//
//	[.cpp]
//	Author	:
//	Date	:
//==============================================

//==============================================
//インクルード
//==============================================
#include "polygon.h"


//==============================================
// マクロ定義
//==============================================
#define NUM_VERTEX_LINESTRIP (64)	//ラインストリップ頂点最大数

//==============================================
// プロトタイプ宣言
//==============================================
void	SetVertexLineStrip(int);							//ラインストリップ頂点格納処理
void	SetVertexLine(float, float, float, float);			//直線用頂点格納処理
void	SetVertexCircle(float, float, float, int, D3DXCOLOR);	//多角形の表示


//==============================================
// グローバル変数
//==============================================
static	ID3D11Buffer		*g_VertexBufferLineStrip = NULL;//ラインストリップ用
//static	ID3D11Buffer		*g_VertexBufferTriangle = NULL;	//四角形用
static	ID3D11Buffer		*g_VertexBufferLine = NULL;		//直線用

static	ID3D11Buffer		*g_VertexBufferCircle = NULL;	//多角形用

float	PositionX = SCREEN_WIDTH / 2;//画面中央座標
float	PositionY = SCREEN_HEIGHT / 2;

//float	Kakudo = 0; //四角形の回転角度

float	StartPositionX = 0;				//直線のスタート座標z
float	StartPositionY = 0;
float	EndPositionX = SCREEN_WIDTH;	//直線の終了座標
float	EndPositionY = SCREEN_HEIGHT;


D3DXVECTOR3		Goal = D3DXVECTOR3(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 0);//画面中央
D3DXVECTOR3		Speed;
D3DXVECTOR3		Start;




//==============================================
// 初期化処理
//==============================================
HRESULT InitPolygon(void)
{
	//乱数の初期化
	srand(timeGetTime());
	//ポリゴンの表示座標をランダムに決定
	//PositionX = rand() % SCREEN_WIDTH;
	//PositionY = rand() % SCREEN_HEIGHT;

	Start.x = PositionX;
	Start.y = PositionY;
	Start.z = 0.0f;

	//目的地までのベクトルを作る
	Speed = Goal - Start;
	//正規化して長さを1にする
	D3DXVec3Normalize(&Speed, &Speed);
	//ベクトルを任意の長さにする
	Speed *= 1.5f;



	// 頂点バッファ生成
	{
		D3D11_BUFFER_DESC bd;
		ZeroMemory(&bd, sizeof(bd));
		bd.Usage = D3D11_USAGE_DYNAMIC;
		bd.ByteWidth = sizeof(VERTEX_3D) * NUM_VERTEX_LINESTRIP;//頂点1個＊頂点数のサイズで作る
		bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		GetDevice()->CreateBuffer(&bd, NULL, &g_VertexBufferLineStrip);
		// 頂点バッファ更新
		SetVertexLineStrip(4);
	}

	//直線用
	{
		// 頂点バッファ生成
		D3D11_BUFFER_DESC bd;
		ZeroMemory(&bd, sizeof(bd));
		bd.Usage = D3D11_USAGE_DYNAMIC;
		bd.ByteWidth = sizeof(VERTEX_3D) * 2;			//頂点1個＊頂点数のサイズで作る
		bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		GetDevice()->CreateBuffer(&bd, NULL, &g_VertexBufferLine);
		//直線用頂点格納処理
		SetVertexLine(StartPositionX, StartPositionY, EndPositionX, EndPositionY );
	}

	//多角形用
	{
		// 頂点バッファ生成
		D3D11_BUFFER_DESC bd;
		ZeroMemory(&bd, sizeof(bd));
		bd.Usage = D3D11_USAGE_DYNAMIC;
		bd.ByteWidth = sizeof(VERTEX_3D) * 64;	//頂点1個＊頂点数のサイズで作る
		bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		GetDevice()->CreateBuffer(&bd, NULL, &g_VertexBufferCircle);

		//多角形用頂点格納処理
		D3DXCOLOR	col = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		SetVertexCircle(300.0f, 500.0f, 100.0f, 32, col);

	}



	return S_OK;
}

//==============================================
// 終了処理
//==============================================
void UninitPolygon(void)
{
	// 頂点バッファの解放
	if (g_VertexBufferLineStrip)
	{
		g_VertexBufferLineStrip->Release();//使い終わったので解放する
		g_VertexBufferLineStrip = NULL;
	}

	if (g_VertexBufferLine)
	{
		g_VertexBufferLine->Release();//使い終わったので解放する
		g_VertexBufferLine = NULL;
	}

	if (g_VertexBufferCircle)
	{
		g_VertexBufferCircle->Release();//使い終わったので解放する
		g_VertexBufferCircle = NULL;
	}


}

//==============================================
// 更新処理
//==============================================
void UpdatePolygon(void)
{

	Start += Speed;	//移動する
	//PositionX = Start.x;
	//PositionY = Start.y;


}

//==============================================
// 描画処理
//==============================================
void DrawPolygon(void)
{

	// ２Ｄ表示をするためのマトリクスを設定
	SetWorldViewProjection2D();


}


//==============================================
// 頂点データ設定
//in
//  頂点の数
//==============================================
void SetVertexLineStrip(int	NumVertex)
{
	D3D11_MAPPED_SUBRESOURCE msr;
	//頂点バッファへの書き込み許可をもらう
	GetDeviceContext()->Map(g_VertexBufferLineStrip, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);

	VERTEX_3D *vertex = (VERTEX_3D*)msr.pData;

	//一本目の直線の頂点をセット
	vertex[0].Position = D3DXVECTOR3(100.0f, 100.0f, 0.0f);
	vertex[0].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

	vertex[1].Position = D3DXVECTOR3(SCREEN_WIDTH-100.0f, SCREEN_HEIGHT-100.0f, 0.0f);
	vertex[1].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

	//二本目の直線の頂点をセット
	vertex[2].Position = D3DXVECTOR3(SCREEN_WIDTH / 2, 0.0f + 50.0f, 0.0f);
	vertex[2].Diffuse = D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f);
	vertex[2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

	vertex[3].Position = D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 50.0f, 0.0f);
	vertex[3].Diffuse = D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f);
	vertex[3].TexCoord = D3DXVECTOR2(1.0f, 1.0f);


	GetDeviceContext()->Unmap(g_VertexBufferLineStrip, 0);
}


//==============================================
//直線の頂点を格納
//in
//  開始座標X, 開始座標Y, 終了座標X, 終了座標Y
//==============================================
void	SetVertexLine(float StartX, float StartY, float EndX, float EndY)
{
	D3D11_MAPPED_SUBRESOURCE msr;
	//頂点バッファへの書き込み許可をもらう
	GetDeviceContext()->Map(g_VertexBufferLine, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);
	//頂点構造体の型にポインター型を変換をする
	VERTEX_3D *vertex = (VERTEX_3D*)msr.pData;

	//頂点 V0をセット
	vertex[0].Position = D3DXVECTOR3(StartX, StartY, 0.0f);
	vertex[0].Diffuse = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
	vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);
	//頂点 V1をセット
	vertex[1].Position = D3DXVECTOR3(EndX, EndY, 0.0f);
	vertex[1].Diffuse = D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f);
	vertex[1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

	GetDeviceContext()->Unmap(g_VertexBufferLine, 0);//書き込み終了

}

//==============================================
//ラインで多角形の表示
//in
//　表示座標X, 表示座標Y, 半径, 頂点数, 角度, 色
//==============================================
void	SetVertexCircle(float PosX, float PosY, float Rad, int NumVertex, D3DXCOLOR col)
{

	D3D11_MAPPED_SUBRESOURCE msr;
	//頂点バッファへの書き込み許可をもらう
	GetDeviceContext()->Map(g_VertexBufferCircle, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);
	//頂点構造体の型にポインター型を変換をする
	VERTEX_3D *vertex = (VERTEX_3D*)msr.pData;

	float	kakudo = 0;
	for (int i = 0; i < NumVertex; i++)
	{
		vertex[i].Position.x = cosf(D3DXToRadian(kakudo)) * Rad + PosX;
		vertex[i].Position.y = sinf(D3DXToRadian(kakudo)) * Rad + PosY;
		vertex[i].Position.z = 0.0f;
		vertex[i].Diffuse = col;
		vertex[i].TexCoord = D3DXVECTOR2(0.0f, 0.0f);
		kakudo += (360.0f / NumVertex);
	}
	//最後の頂点に最初の頂点をコピーして図形を閉じる
	vertex[NumVertex].Position = vertex[0].Position;
	vertex[NumVertex].Diffuse = vertex[0].Diffuse;
	vertex[NumVertex].TexCoord = vertex[0].TexCoord;

	GetDeviceContext()->Unmap(g_VertexBufferCircle, 0);//書き込み終了



}

