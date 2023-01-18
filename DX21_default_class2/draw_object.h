//=======================================
// オブジェクト描画関係(ヘッダファイル)
// 作成日：2022/09/12
// 作成者：高梨水希
//=======================================
#pragma once

#ifndef _DRAW_OBJECT_H_
#define _DRAW_OBJECT_H_

#include "main.h"
#include "sprite.h"
#include "texture_useful.h"

class DrawObject
{
private:
	TextureUseful m_pTexUseful;
	float m_paternNo = 0.0f;		//現在のアニメーション番号
	float m_uv_w = 0.0f;			//横のUVサイズ
	float m_uv_h = 0.0f;			//縦のUVサイズ
	int m_tex_num = 0;				//横に並んでいるアニメーション数
	D3DXCOLOR m_color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);	//色

public:
	DrawObject(){}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	DrawObject(const TextureUseful& pTexUseful, 
		float paternNo = 0.0f, float uv_w = 1.0f, float uv_h = 1.0f, int tex_num = 1,
		const D3DXCOLOR& color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f))
		:m_pTexUseful(pTexUseful), m_paternNo(paternNo), m_uv_w(uv_w), m_uv_h(uv_h), 
		m_tex_num(tex_num), m_color(color) {}

	~DrawObject(){}	//デストラクタ

	void SetDrawObject(const TextureUseful& pTexUseful, float paternNo = 0.0f, float uv_w = 1.0f, 
		float uv_h = 1.0f, int tex_num = 1, const D3DXCOLOR& color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

	//描画
	void Draw(const D3DXVECTOR2& pos, const D3DXVECTOR2& size, float rot = 0.0f)const;
	void DrawReverse(const D3DXVECTOR2& pos, const D3DXVECTOR2& size, float rot = 0.0f)const;

	//色をセット
	void SetDrawColor(const D3DXCOLOR& col) { m_color = col; }

	//アニメーション番号指定
	void SetPaterNo(float patenNo) { m_paternNo = patenNo; }
	
	//アニメーション番号を返す
	int GetPaterNo(void) { return (int)m_paternNo; }
};

#endif // !_DRAW_OBJECT_H_