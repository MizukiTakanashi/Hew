//=======================================
// 数字関係(cppファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#include "number.h"

//==========================
// 定数初期化
//==========================
const float Number::SPACE_RATIO = 0.2f;


//=========================
// 引数付きコンストラクタ
//=========================
Number::Number(DrawObject& pDrawObject, const D3DXVECTOR2& pos, const D3DXVECTOR2& size, int digit)
	:UI(pDrawObject, pos, size), m_digit(digit), m_init_pos(pos)
{
	m_space = size.x * SPACE_RATIO;
}


//==========================
// 描画処理
//==========================
void Number::DrawNumber(void)
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