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
	enum class STAGE_NUM : int
	{
		STAGE1,
		STAGE2,
		STAGE3,
		STAGE4,
		STAGE5,
		STAGE6,
		STAGE7,
		STAGE_NUM,
	};
//定数
private:
	//ここで初期化
	static const int NUMBER_DIGIT = 10 ;

	//cppで初期化
	static const D3DXVECTOR2 NUMBER_POS;
	static const D3DXVECTOR2 NUMBER_SIZE;


//メンバ変数
private:
	int m_BGM = 0;

	TextureUseful* m_pTexUse[4] = { nullptr, nullptr , nullptr , nullptr };
	DrawObject* m_pDrawOb[4] = { nullptr, nullptr , nullptr , nullptr };
	UI* m_pBG = nullptr;
	UI* m_pTitle = nullptr;
	UI* m_pContinue = nullptr;
	UI* m_pRetry = nullptr;
	Score* m_pScore = nullptr;

public:
	Result();	//デフォルトコンストラクタ

	Result(Score* pNumber);
	Result(Score* pNumber, STAGE_NUM stagenum);

	~Result();	//デストラクタ

	//更新処理
	void Update(void);

	//描画処理
	void Draw(void)const;
};

#endif // !_RESULT_H_