#include "management.h"

//==========================
// �I�u�W�F�N�g������
//==========================
void Management::Delete(int index_num)
{
	//��O�ɋl�߂Ă���
	for (int i = index_num; i < m_obj_num - 1; i++) {
		m_pObj[i] = m_pObj[i + 1];
	}
	m_obj_num--;
}