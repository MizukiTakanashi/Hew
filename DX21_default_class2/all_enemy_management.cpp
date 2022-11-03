//=======================================
// 全ての敵の管理関係(cppファイル)
// 作成日：2022/10/30
// 作成者：高梨水希
//=======================================

#include "all_enemy_management.h"

const D3DXVECTOR2& AllEnemyManagement::GetCloltestEnemyPos(const D3DXVECTOR2& pos)
{
	D3DXVECTOR2 min_pos = D3DXVECTOR2(0.0f, 0.0f);
	D3DXVECTOR2 min_vec_pos = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	float min_vec = 0.0f;

	//全部の敵の位置を検索
	for (int i = 0; i < ENEMY_NUM; i++) {
		for (int j = 0; j < m_pEnemy[i]->GetObjNum(); j++) {
			//ベクトルを取得
			D3DXVECTOR2 vec_pos = m_pEnemy[i]->GetObjPos(j) - pos;

			//ベクトルを比べて小さい方を記憶しておく
			if (min_vec_pos.x * min_vec_pos.x + min_vec_pos.y * min_vec_pos.y 
				> vec_pos.x * vec_pos.x + vec_pos.y * vec_pos.y) {
				min_vec_pos = vec_pos;
				min_pos = m_pEnemy[i]->GetObjPos(j);
			}
		}
	}

	return min_pos;
}
