//=======================================
// �S�Ă̓G�̊Ǘ��֌W(cpp�t�@�C��)
// �쐬���F2022/10/30
// �쐬�ҁF��������
//=======================================

#include "all_enemy_management.h"

const D3DXVECTOR2& AllEnemyManagement::GetCloltestEnemyPos(const D3DXVECTOR2& pos)
{
	//���������Ƀ^�[�Q�b�g�ɂ��Ă���G��������...
	if (m_enemy_index[0] != -1) {
		//�������^�[�Q�b�g�ɂ��Ă���G������ł�����...
		for (int i = 0; i < m_enemy_num; i++) {
			if (m_enemy_index[0] == i) {
				if (m_enemy_index[1] == m_pEnemy[i]->GetDeleteObjIndex()) {
					//�^�[�Q�b�g�̓G�����Z�b�g
					m_enemy_index[0] = -1;
					m_enemy_index[1] = -1;
				}
				//�^�[�Q�b�g�����z��I�ɑO�̓G�������ꂽ��...
				else if(m_pEnemy[i]->GetDeleteObjIndex() != m_enemy_delete_before) {
					//��z������炷
					m_enemy_index[1] -= 1;
				}
			}

			//���݁A�������I�u�W�F�N�g�̔ԍ����L�^
			m_enemy_delete_before = m_pEnemy[i]->GetDeleteObjIndex();
		}

		if (m_enemy_index[0] != -1) {
			//�^�[�Q�b�g�ɂ��Ă���G�̍��W��Ԃ�
			return m_pEnemy[m_enemy_index[0]]->GetObjPos(m_enemy_index[1]);
		}
	}

	D3DXVECTOR2 min_pos = D3DXVECTOR2(0.0f, 0.0f);
	D3DXVECTOR2 min_vec_pos = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	float min_vec = 0.0f;

	//�S���̓G�̈ʒu������
	for (int i = 0; i < m_enemy_num; i++) {
		for (int j = 0; j < m_pEnemy[i]->GetObjNum(); j++) {
			//�x�N�g�����擾
			D3DXVECTOR2 vec_pos = m_pEnemy[i]->GetObjPos(j) - pos;

			//�x�N�g�����ׂď����������L�����Ă���
			if (min_vec_pos.x * min_vec_pos.x + min_vec_pos.y * min_vec_pos.y 
				> vec_pos.x * vec_pos.x + vec_pos.y * vec_pos.y) {
				min_vec_pos = vec_pos;
				min_pos = m_pEnemy[i]->GetObjPos(j);
				m_enemy_index[0] = i;
				m_enemy_index[1] = j;
			}
		}
	}

	//�����̍��W�����ԋ߂��G�̍��W��Ԃ�
	return min_pos;
}
