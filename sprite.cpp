
//==============================
//
//スプライト描画
//==============================
#include	"renderer.h"
#include	"sprite.h"

//==================================
//マクロ定義
//==================================
#define		NUM_VERTEX	(4)	//スプライト頂点数

//==================================
//プロトタイプ宣言
//sprite.cpp内で使う関数に対するもの
//==================================


//==================================
//グローバル変数
//==================================
static	ID3D11Buffer		*g_VertexBufferTriangle = NULL;	//頂点バッファ

//===========================================================================================
//三角形用頂点格納処理
//in 表示座標X, 表示座標Y, 横サイズ, 縦サイズ, 回転角度, 色,
//   アニメーション番号, UVマップ横サイズ, UVマップ縦サイズ, 横に並ぶアニメーション数
//===========================================================================================
void Sprite::DrawSpriteAnimationRotation(float PosX, float PosY, float Size_W, float Size_H,
	float Kakudo, const D3DXCOLOR& col,
	float PaternNo, float uv_w, float uv_h, int NumPatern)
{
	D3D11_MAPPED_SUBRESOURCE msr;
	//頂点バッファへの書き込み許可をもらう
	GetDeviceContext()->Map(g_VertexBufferTriangle, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);
	//頂点構造体の型にポインター型を変換をする
	VERTEX_3D *vertex = (VERTEX_3D*)msr.pData;

	//頂点 V0をセット
	vertex[0].Position = D3DXVECTOR3(-Size_W / 2, -Size_H / 2, 0.0f);
	vertex[0].Diffuse = col;
	//頂点 V1をセット
	vertex[1].Position = D3DXVECTOR3(+Size_W / 2, -Size_H / 2, 0.0f);
	vertex[1].Diffuse = col;
	//頂点 V2をセット
	vertex[2].Position = D3DXVECTOR3(-Size_W / 2, +Size_H / 2, 0.0f);
	vertex[2].Diffuse = col;
	//頂点 V3をセット
	vertex[3].Position = D3DXVECTOR3(+Size_W / 2, +Size_H / 2, 0.0f);
	vertex[3].Diffuse = col;

	//UV座標の計算
	int no = PaternNo;	//パターン番号を整数値にする 小数点以下を捨てる
	float	u = (no % NumPatern) * uv_w;
	float	v = (no / NumPatern) * uv_h;

	//UV座標の書き換え
	vertex[0].TexCoord = D3DXVECTOR2(u, v);				//LEFT-TOP
	vertex[1].TexCoord = D3DXVECTOR2(u + uv_w, v);		//RIGHT-TOP
	vertex[2].TexCoord = D3DXVECTOR2(u, v + uv_h);		//LEFT-BOTTOM
	vertex[3].TexCoord = D3DXVECTOR2(u + uv_w, v + uv_h);	//RIGHT-BOTTOM

	//度をラジアンへ変換する
	float	rad = D3DXToRadian(Kakudo);
	float	x, y;

	for (int i = 0; i < 4; i++)
	{
		//加法定理		
		x = vertex[i].Position.x * cosf(rad) - vertex[i].Position.y * sinf(rad);
		y = vertex[i].Position.y * cosf(rad) + vertex[i].Position.x * sinf(rad);

		vertex[i].Position.x = x + PosX;	//平行移動（中心をずらす）
		vertex[i].Position.y = y + PosY;
	}

	GetDeviceContext()->Unmap(g_VertexBufferTriangle, 0);//書き込み終了

	//描画設定
	{
		UINT stride = sizeof(VERTEX_3D);
		UINT offset = 0;
		GetDeviceContext()->IASetVertexBuffers(0, 1, &g_VertexBufferTriangle, &stride, &offset);
		// プリミティブトポロジ設定
		GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
	}
	//テクスチャの設定

	// ポリゴン描画
	GetDeviceContext()->Draw(NUM_VERTEX, 0);
}

//===========================================================================================
//三角形用頂点格納処理
//in 表示座標X, 表示座標Y, 横サイズ, 縦サイズ, 回転角度, 色,
//   UV開始座標X, UV開始座標Y, UVマップ横サイズ, UVマップ縦サイズ
//===========================================================================================
void Sprite::DrawSpriteUVStart(float PosX, float PosY, float Size_W, float Size_H, float Kakudo, const D3DXCOLOR& col,
	float start_x, float start_y, float uv_w, float uv_h)
{
	D3D11_MAPPED_SUBRESOURCE msr;
	//頂点バッファへの書き込み許可をもらう
	GetDeviceContext()->Map(g_VertexBufferTriangle, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);
	//頂点構造体の型にポインター型を変換をする
	VERTEX_3D *vertex = (VERTEX_3D*)msr.pData;

	//頂点 V0をセット
	vertex[0].Position = D3DXVECTOR3(-Size_W / 2, -Size_H / 2, 0.0f);
	vertex[0].Diffuse = col;
	//頂点 V1をセット
	vertex[1].Position = D3DXVECTOR3(+Size_W / 2, -Size_H / 2, 0.0f);
	vertex[1].Diffuse = col;
	//頂点 V2をセット
	vertex[2].Position = D3DXVECTOR3(-Size_W / 2, +Size_H / 2, 0.0f);
	vertex[2].Diffuse = col;
	//頂点 V3をセット
	vertex[3].Position = D3DXVECTOR3(+Size_W / 2, +Size_H / 2, 0.0f);
	vertex[3].Diffuse = col;

	//UV座標の書き換え
	vertex[0].TexCoord = D3DXVECTOR2(start_x, start_y);				//LEFT-TOP
	vertex[1].TexCoord = D3DXVECTOR2(start_x + uv_w, start_y);		//RIGHT-TOP
	vertex[2].TexCoord = D3DXVECTOR2(start_x, start_y + uv_h);		//LEFT-BOTTOM
	vertex[3].TexCoord = D3DXVECTOR2(start_x + uv_w, start_y + uv_h);	//RIGHT-BOTTOM

	//度をラジアンへ変換する
	float	rad = D3DXToRadian(Kakudo);
	float	x, y;

	for (int i = 0; i < 4; i++)
	{
		//加法定理		
		x = vertex[i].Position.x * cosf(rad) - vertex[i].Position.y * sinf(rad);
		y = vertex[i].Position.y * cosf(rad) + vertex[i].Position.x * sinf(rad);

		vertex[i].Position.x = x + PosX;	//平行移動（中心をずらす）
		vertex[i].Position.y = y + PosY;
	}

	GetDeviceContext()->Unmap(g_VertexBufferTriangle, 0);//書き込み終了

	//描画設定
	{
		UINT stride = sizeof(VERTEX_3D);
		UINT offset = 0;
		GetDeviceContext()->IASetVertexBuffers(0, 1, &g_VertexBufferTriangle, &stride, &offset);
		// プリミティブトポロジ設定
		GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
	}
	//テクスチャの設定

	// ポリゴン描画
	GetDeviceContext()->Draw(NUM_VERTEX, 0);
}

//====================================
// コンストラクタ
//====================================
Sprite::Sprite()
{
	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DYNAMIC;
	bd.ByteWidth = sizeof(VERTEX_3D) * NUM_VERTEX;//頂点1個＊頂点数のサイズで作る
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	GetDevice()->CreateBuffer(&bd, NULL, &g_VertexBufferTriangle);
}

//====================================
// デストラクタ
//====================================
Sprite::~Sprite()
{
	if (g_VertexBufferTriangle)
	{
		g_VertexBufferTriangle->Release();//使い終わったので解放する
		g_VertexBufferTriangle = NULL;
	}
}
