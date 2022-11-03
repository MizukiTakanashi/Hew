//=======================================
// ゲームオブジェクト関係(ヘッダファイル)
// 作成日：2022/09/15
// 作成者：高梨水希
//=======================================
#pragma once

#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include "main.h"
#include "draw_object.h"
#include "screen_out.h"

class GameObject
{
private:
	DrawObject m_pDrawObject;
	D3DXVECTOR2 m_pos = D3DXVECTOR2(0.0f, 0.0f);
	D3DXVECTOR2 m_size = D3DXVECTOR2(0.0f, 0.0f);
	D3DXCOLOR m_color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	float m_rot = 0.0f;

public:
	GameObject() {}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	GameObject(DrawObject& pDrawObject, const D3DXVECTOR2& pos, const D3DXVECTOR2& size, float rot = 0.0f)
		:m_pDrawObject(pDrawObject), m_pos(pos), m_size(size), m_rot(rot) {}

	virtual ~GameObject(){}	//デストラクタ

	//描画処理
	void Draw()const { m_pDrawObject.Draw(m_pos, m_size, m_color, m_rot); }

	//座標を動かす
	void MovePos(const D3DXVECTOR2& mov) { m_pos += mov; }

	//座標をセット
	void SetPos(const D3DXVECTOR2& pos) { m_pos = pos; }

	//サイズをセット
	void SetSize(const D3DXVECTOR2& size) { m_size = size; }

	//角度をセット
	void SetRot(float rot) { m_rot = rot; }

	//アニメーション番号をセット
	void SetAnimationNum(float index_num) { m_pDrawObject.SetPaterNo(index_num); }

	//画面外に出たか否か
	bool GetScreenOut(void)const { return ScreenOut::GetScreenOut(m_pos, m_size); }

	//座標を返す
	const D3DXVECTOR2& GetPos(void)const { return m_pos; }

	//サイズを返す
	const D3DXVECTOR2& GetSize(void)const { return m_size; }

	//色をセット
	void SetColor(D3DXCOLOR color) { m_color = color; }
};

#endif // !_GAME_OBJECT_H_