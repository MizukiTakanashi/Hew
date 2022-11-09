//=======================================
// UI関係(cppファイル)
// 作成日：2022/09/17
// 作成者：高梨水希
//=======================================
#pragma once

#ifndef _UI_H_
#define _UI_H_

#include "main.h"
#include "draw_object.h"

class UI
{
private:
	DrawObject m_DrawObject;
	D3DXVECTOR2 m_pos = D3DXVECTOR2(0.0f, 0.0f);
	D3DXVECTOR2 m_size = D3DXVECTOR2(0.0f, 0.0f);
	D3DXCOLOR m_color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

public:
	UI(){}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	UI(DrawObject& draw_object, const D3DXVECTOR2& pos, const D3DXVECTOR2& size, 
		const D3DXCOLOR& color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f))
		:m_DrawObject(draw_object), m_pos(pos), m_size(size), m_color(color){}

	virtual ~UI(){}	//デストラクタ

	//描画
	void Draw(void)const { m_DrawObject.Draw(m_pos, m_size); }

	//座標をセット
	void SetPos(const D3DXVECTOR2& pos) { m_pos = pos; }

	//サイズをセット
	void SetSize(const D3DXVECTOR2& size) { m_size = size; }

	//アニメーション番号をセット
	void SetAnimationNum(float num) { m_DrawObject.SetPaterNo(num); }

	//座標を返す
	const D3DXVECTOR2& GetPos(void) { return m_pos; }

	//サイズを返す
	const D3DXVECTOR2& GetSize(void) { return m_size; }
};


#endif // !_UI_H_