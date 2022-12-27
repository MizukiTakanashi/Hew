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

//private
const float EnemyBarrier::SPEED_Y = 2.5f;

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
}