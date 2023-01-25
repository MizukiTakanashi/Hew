//=======================================
// ボム関係(cppファイル)
// 作成日：2022/12/07
// 作成者：高梨水希
//=======================================

#include "Bom.h"
#include "inputx.h"
#include "keyboard.h"

//==========================
// 更新処理
//==========================
void Bom::Update(void)
{
	//ボムがなくなっていれば...
	if (m_num > m_num_max) {
		return;
	}

	//ボムがセットされていなければ...

	if (GetLeftTriggerTriggered(0, 120)) {
		m_left = SAME_TIME;
	}
	if (GetRightTriggerTriggered(0, 120)) {
		m_right = SAME_TIME;
	}
	
	//ゲームパッドのXボタンを押したら...
	//キーボードのEnterを押したら...
	if (m_time == -1 && ((m_right-- > 0 && m_left-- > 0)
		|| InputGetKeyDown(KK_R))) {
		PlaySound(m_SE_17, 0);
		m_time = 0;
		m_right = 0;
		m_left = 0;
	}

	//ボムがセットされていれば...
	if (m_time >= 0) {
		//一定時間過ぎれば...
		if (m_time++ > TIME_LIMIT) {
			//ボムの現在の数を追加
			m_num++;

			//ボムを消して、カウントをリセット
			m_time = -1;
		}
	}
}

//==========================
// 描画処理
//==========================
void Bom::BomDraw(void)
{
	//ボムがセットされていれば...
	if (m_time >= 0) {
		GameObject::Draw();
	}
}
