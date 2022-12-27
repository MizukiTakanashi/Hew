//=======================================
// スコア関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#include "score.h"

//==========================
// 定数初期化
//==========================
const float Score::COMBO_MAGNIFICATION = 1.1f; //コンボ継続時の倍率


//=========================
// 引数付きコンストラクタ
//=========================
Score::Score(DrawObject& pDrawObject, const D3DXVECTOR2& pos, const D3DXVECTOR2& size, int digit)
	:Number(pDrawObject, pos, size, digit)
{
	
}

void Score::AddScore(int num)
{
	AddNumber(num * (int)m_ComboMagnification);
	m_ComboMagnification *= Score::COMBO_MAGNIFICATION;
	m_ComboNum++;
}
