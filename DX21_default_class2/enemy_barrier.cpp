//=======================================
// バリアの敵関係(cppファイル)
// 作成日：2022/12/08
// 作成者：高梨水希
//=======================================
#include "enemy_barrier.h"

//==========================
// 定数初期化
//==========================
//public
const float EnemyBarrier::SIZE_X = 50.0f;
const float EnemyBarrier::SIZE_Y = 60.0f;
const float EnemyBarrier::STOP_POS_Y = 100.0f;
const float EnemyBarrier::RANGE = 20.0f;
//private
const float EnemyBarrier::SPEED_X = 1.5f;
const float EnemyBarrier::SPEED_Y = 2.5f;
const D3DXVECTOR2 EnemyBarrier::BARRIER_SIZE = D3DXVECTOR2(50.0f, 50.0f);
const D3DXVECTOR2 EnemyBarrier::INTERVAL_POS = D3DXVECTOR2(0.0f, 10.0f);

//======================
// 更新処理
//======================
void EnemyBarrier::Update(void)
{
	m_invincible_flame--;
	//止まる場所まで移動する
	if (GameObject::GetPos().y < STOP_POS_Y) {
		GameObject::MovePos(D3DXVECTOR2(0.0f, SPEED_Y));
	}

	//左右に動く
	float rad = D3DXToRadian(m_move_width);
	SetPos(D3DXVECTOR2(m_init_posx + cosf(rad) * RANGE, GetPos().y));
	m_move_width += SPEED_X;

	//============================
	// バリア

	//バリアが出現していたら...
	if (m_barrier_time >= 0) {
		//バリアの座標を敵の隣にセット
		m_pBarrier->SetPos(GameObject::GetPos() + INTERVAL_POS);

		//バリアの時間が制限時間を過ぎていたら...
		if (m_barrier_time++ > BARRIER_TIME_LIMIT) {
			//バリアを消す
			m_barrier_time = -1;
			m_barrier_interval_time = 0;
		}
	}
	//バリアが出現していなかったら...
	else {
		//次のバリアの出現時間が制限時間を過ぎていたら...
		if (m_barrier_interval_time++ > BARRIER_INTERVAL) {
			//バリアを出す
			m_barrier_interval_time = -1;
			m_barrier_time = 0;
		}
	}
}
