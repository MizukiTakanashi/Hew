//=======================================
// ボスクラス(cppファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#include "boss.h"
#include "inh_stage.h"

//==========================
// 定数初期化
//==========================
//public
const float Boss::SIZE_X = 200.0f;
const float Boss::SIZE_Y = 200.0f;
const float Boss::STOP_POS_Y = 100.0f;
const float Boss::RANGE = 200.0f;
//private
const float Boss::SPEED_X = 1.5f;
const float Boss::SPEED_Y = 2.5f;

int m_boss_count = 0;
int m_boss_count1 = 0;
int m_boss_count2 = 0;
int m_boss_count3 = 0;
int m_boss_count4 = 0;


Boss::~Boss()
{
	
}

//======================
// 更新処理
//======================
void Boss::Update(void)
{

	//無敵時間減少
	m_invincible_flame--;

	if (m_stop_time > 0)
	{
		m_stop_time--;
		return;
	}


	//止まる場所まで移動する
	if (GameObject::GetPos().y < STOP_POS_Y) {
		GameObject::MovePos(D3DXVECTOR2(0.0f, SPEED_Y));
	}

	//左右に動く
	float rad = D3DXToRadian(m_move_width);
	SetPos(D3DXVECTOR2(m_init_posx + cosf(rad) * RANGE, GetPos().y));
	m_move_width += SPEED_X;

	m_boss_count++;
	m_boss_count1++;
	m_boss_count2++;
	m_boss_count3++;
	m_boss_count4++;

	//時間が来たら弾を作る
	if (m_boss_count > BULLET_TIME) {
		m_bullet_make = true;
		m_boss_count = 0;
	}
	if (m_boss_count1 > BULLET_TIME) {
		m_bullet_make1 = true;
		m_boss_count1 = 0;
	}
	if (m_boss_count2 > BULLET_TIME) {
		m_bullet_make2 = true;
		m_boss_count2 = 0;
	}
	if (m_boss_count3 > BULLET_TIME) {
		m_bullet_make3 = true;
		m_boss_count3 = 0;
	}
	if (m_boss_count4 > BULLET_TIME) {
		m_bullet_make4 = true;
		m_boss_count4 = 0;
	}

}
