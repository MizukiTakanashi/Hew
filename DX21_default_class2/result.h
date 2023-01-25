//=======================================
// リザルト画面関係(ヘッダファイル)
// 作成日：2022/09/22
// 作成者：高梨水希
//=======================================
#pragma once

#ifndef _RESULT_H_
#define _RESULT_H_

#include "texture_useful.h"
#include "draw_object.h"
#include "UI.h"
#include "score.h"
#include "main.h"

class Result
{
//定数
private:
	//ここで初期化
	static const int NUMBER_DIGIT = 5 ;

	//cppで初期化
	static const D3DXVECTOR2 NUMBER_POS;
	static const D3DXVECTOR2 NUMBER_SIZE;


//メンバ変数
private:
	int m_BGM = 0;		//BGM
	int m_SE_01 = 0;	//決定音
	int m_SE_03 = 0;	//カーソル移動音
	STAGE m_stage;

	TextureUseful* m_pTexUse[3] = { nullptr, nullptr , nullptr};
	DrawObject* m_pDrawOb[3] = { nullptr, nullptr , nullptr};
	UI* m_pBG = nullptr;
	UI* m_pStageTitle = nullptr;
	UI* m_pCursor = nullptr;
	Score* m_pScore = nullptr;

	bool m_isClear = false;		//CLEARしたかどうか
	bool m_select_retry = false; //どっちを選択しているか

	float m_thumb_before = 0.0f;	//スティックの値

public:
	Result(bool isClear, Score* pNumber, STAGE stagenum);

	~Result();	//デストラクタ

	//更新処理
	void Update(void);

	//描画処理
	void Draw(void)const;

	//選択を変える
	void Select(void)
	{
		if (m_select_retry)
		{
			m_select_retry = false;
		}
		else
		{
			m_select_retry = true;
		}
	}
};

#endif // !_RESULT_H_