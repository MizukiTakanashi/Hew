//=======================================
// プレイヤーのHP関係(ヘッダファイル)
// 作成日：2022/09/17
// 作成者：高梨水希
//=======================================
#pragma once

#ifndef _PLAYER_HP_H_
#define _PLAYER_HP_H_

#include "DrawObject.h"
#include "UI.h"

//======================
// マクロ定義
//======================
#define PLAYER_HP_POS_Y (PLAYER_HP_SIZE_Y / 2 + PLAYER_HP_POS_SPACE_X)

class PlayerHP:public UI
{
private:
	//定数
	//cppで初期化
	static const float HP_MAX;			//最大HP
	static const float SIZE_X;			//サイズX
	static const float SIZE_Y;			//サイズY
	static const float FLAME_SIZE_X;	//フレームサイズX
	static const float FLAME_SIZE_Y;	//フレームサイズY
	static const float POS_SPACE_X;		//端からどれくらい離れているかX
	static const float POS_SPACE_Y;		//端からどれくらい離れているかY
	static const float POS_X;			//表示位置
	static const float POS_Y;			//表示位置

private:
	bool m_HP0 = false;
	DrawObject m_frame_DrawObject;
	float m_hp = HP_MAX;

public:
	PlayerHP() { m_hp = HP_MAX; }	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	PlayerHP(DrawObject& DrawObject1, DrawObject& DrawObject2) 
		:UI(DrawObject1, D3DXVECTOR2(POS_X, POS_Y),
		D3DXVECTOR2(SIZE_X, SIZE_Y)), m_frame_DrawObject(DrawObject2){}

	~PlayerHP(){}							//デストラクタ

	//HPを減らす
	void ReduceHP(float reduce_num);

	//描画
	void DrawHP(void)const;

	//HPが0になったかどうかのフラグを返す
	bool GetHP0Flag(void)const { return m_HP0; }
};

#endif // !_PLAYER_HP_H_