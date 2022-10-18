//=======================================
// �G�̔z�u�ꏊ�֌W(cpp�t�@�C��)
// �쐬���F2022/09/14
// �쐬�ҁF��������
//=======================================
#include "EnemySetPos.h"
#include "collision.h"

//==========================
// �G��z�u
//==========================
bool EnemySetPos::SetEnemy(const D3DXVECTOR2& pos, const D3DXVECTOR2& size)
{
	for (int i = 0; i < m_index_num; i++) {
		//���̓G�Ɠ������Ă�����z�u�ł��Ȃ�
		if (Collision::ColBox(pos, m_pos[i], size, m_size[i])) {
			return false;
		}
	}
	m_pos[m_index_num] = pos;
	m_size[m_index_num] = size;
	m_index_num++;
	return true;
}

//==========================
// �G���폜
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
