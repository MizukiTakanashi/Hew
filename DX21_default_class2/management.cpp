#include "management.h"

//==========================
// オブジェクトを消す
//==========================
void Management::Delete(int index_num)
{
	//手前に詰めていく
	for (int i = index_num; i < m_obj_num - 1; i++) {
		m_pObj[i] = m_pObj[i + 1];
	}
	m_obj_num--;
}