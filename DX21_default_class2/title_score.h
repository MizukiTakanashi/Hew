#pragma once
//=======================================
// スコア表示関係(ヘッダファイル)
// 作成日：2022/12/16
// 作成者：高梨水希
//=======================================

#ifndef _TITLE_SCORE_H_
#define _TITLE_SCORE_H_

#include "score.h"
#include "scene.h"
#include "UI.h"

class TitleScore
{
//定数
private:


//メンバ変数
private:
	TextureUseful* m_pTexUse[5];
	DrawObject* m_pDrawOb[5];

	UI* m_pBG = nullptr;
	Score* m_pScore = nullptr;
	int m_score[STAGE_NUM];

//メンバ関数
public:
	//デフォルトコンストラクタ
	TitleScore(){
		for (int i = 0; i < STAGE_NUM; i++) {
			m_score[i] = 0;
		}
	}

	//引数付きコンストラクタ
	TitleScore(Score* pNumber, int score[]);

	//更新処理
	void Update(void);

	//描画処理
	void Draw(void);
};

#endif // !_TITLE_SCORE_H_