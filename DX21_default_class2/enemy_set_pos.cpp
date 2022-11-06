//=======================================
// 敵の配置場所関係(cppファイル)
// 作成日：2022/09/14
// 作成者：高梨水希
//=======================================
#include "enemy_set_pos.h"
#include "collision.h"
#include "screen_out.h"

//==========================
// 敵を配置
//==========================
bool EnemySetPos::SetEnemy(const D3DXVECTOR2& pos, const D3DXVECTOR2& size)
{
	//敵が画面外に出そうになったら配置できない
	if (ScreenOut::GetScreenOut(pos, size)) {
		return false;
	}

	//for (int i = 0; i < m_index_num; i++) {
	//	//他の敵と当たっていたら配置できない
	//	if (Collision::ColBox(pos, m_pos[i], size, m_size[i])) {
	//		return false;
	//	}
	//}
	m_pos[m_index_num] = pos;
	m_size[m_index_num] = size;
	m_index_num++;
	return true;
}

//==========================
// 敵を削除
//==========================
void EnemySetPos::DeleteEnemy(const D3DXVECTOR2 & pos)
{
	for (int i = 0; i < m_index_num; i++) {
		if (m_pos[i].y == pos.y) {
			for (int j = i; j < m_index_num - 1; j++) {
				m_pos[j] = m_pos[j + 1];
				m_size[j] = m_size[j + 1];
			}
			m_index_num--;
			break;
		}
	}
}
