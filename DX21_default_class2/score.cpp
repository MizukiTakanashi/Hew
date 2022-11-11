//=======================================
// スコア関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#include "score.h"

//==========================
// 定数初期化
//==========================
const float Score::SPACE_RATIO = 0.2f;
const float Score::COMBO_MAGNIFICATION = 1.1f; //コンボ継続時の倍率


//=========================
// 引数付きコンストラクタ
//=========================
Score::Score(DrawObject& pDrawObject, const D3DXVECTOR2& pos, const D3DXVECTOR2& size, int digit)
	:UI(pDrawObject, pos, size), m_digit(digit)
{
	m_space = size.x * SPACE_RATIO;
}

void Score::AddScore(int num)
{
	m_num += num * m_ComboMagnification;
	m_ComboMagnification *= Score::COMBO_MAGNIFICATION;
	m_ComboNum++;
}
//==========================
// 描画処理
//==========================
void Score::DrawNumber(void)
{
	//描画位置を初期位置に
	UI::SetPos(m_init_pos);

	int num = m_num;

	//上の桁から描画
	for (int i = 0; i < m_digit; i++) {
		int n = num % 10;

		num /= 10;

		UI::SetAnimationNum((float)n);

		UI::Draw();

		//次の数字を描画するため、隣に座標を移す
		UI::SetPos(D3DXVECTOR2(UI::GetPos().x - UI::GetSize().x - m_space, UI::GetPos().y));
	}
}