//=======================================
// 全ての敵の管理関係(cppファイル)
// 作成日：2022/10/30
// 作成者：高梨水希
//=======================================

#include "all_enemy_management.h"

const D3DXVECTOR2& AllEnemyManagement::GetCloltestEnemyPos(const D3DXVECTOR2& pos)
{
	//もしも既にターゲットにしている敵がいたら...
	if (m_enemy_index[0] != -1) {
		//もしもターゲットにしている敵が死んでいたら...
		for (int i = 0; i < m_enemy_num; i++) {
			if (m_enemy_index[0] == i) {
				if (m_enemy_index[1] == m_pEnemy[i]->GetDeleteObjIndex()) {
					//ターゲットの敵をリセット
					m_enemy_index[0] = -1;
					m_enemy_index[1] = -1;
				}
				//ターゲットよりも配列的に前の敵が消されたら...
				else if(m_pEnemy[i]->GetDeleteObjIndex() != m_enemy_delete_before) {
					//一つ配列をずらす
					m_enemy_index[1] -= 1;
				}
			}

			//現在、消したオブジェクトの番号を記録
			m_enemy_delete_before = m_pEnemy[i]->GetDeleteObjIndex();
		}

		if (m_enemy_index[0] != -1) {
			//ターゲットにしている敵の座標を返す
			return m_pEnemy[m_enemy_index[0]]->GetObjPos(m_enemy_index[1]);
		}
	}

	D3DXVECTOR2 min_pos = D3DXVECTOR2(0.0f, 0.0f);
	D3DXVECTOR2 min_vec_pos = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	float min_vec = 0.0f;

	//全部の敵の位置を検索
	for (int i = 0; i < m_enemy_num; i++) {
		for (int j = 0; j < m_pEnemy[i]->GetObjNum(); j++) {
			//ベクトルを取得
			D3DXVECTOR2 vec_pos = m_pEnemy[i]->GetObjPos(j) - pos;

			//ベクトルを比べて小さい方を記憶しておく
			if (min_vec_pos.x * min_vec_pos.x + min_vec_pos.y * min_vec_pos.y 
				> vec_pos.x * vec_pos.x + vec_pos.y * vec_pos.y) {
				min_vec_pos = vec_pos;
				min_pos = m_pEnemy[i]->GetObjPos(j);
				m_enemy_index[0] = i;
				m_enemy_index[1] = j;
			}
		}
	}

	//引数の座標から一番近い敵の座標を返す
	return min_pos;
}
