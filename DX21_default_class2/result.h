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
	static const int NUMBER_DIGIT = 10 ;

	//cppで初期化
	static const D3DXVECTOR2 NUMBER_POS;
	static const D3DXVECTOR2 NUMBER_SIZE;


//メンバ変数
private:
	int m_BGM = 0;		//BGM
	int m_SE_01 = 0;	//決定音
	int m_SE_03 = 0;	//カーソル移動音

	TextureUseful* m_pTexUse[6] = { nullptr, nullptr , nullptr , nullptr, nullptr, nullptr };
	DrawObject* m_pDrawOb[6] = { nullptr, nullptr , nullptr , nullptr, nullptr, nullptr };
	UI* m_pBG = nullptr;
	UI* m_pText_Clear = nullptr;
	UI* m_pStageTitle = nullptr;
	UI* m_pText_title = nullptr;
	UI* m_pText_Retry = nullptr;
	UI* m_pCursor = nullptr;
	Score* m_pScore = nullptr;

	bool m_isClear = false;		//CLEARしたかどうか
	bool m_select_retry = true; //どっちを選択しているか

public:
	Result();	//デフォルトコンストラクタ

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