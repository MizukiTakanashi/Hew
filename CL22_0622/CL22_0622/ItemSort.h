#pragma once
#include "manager.h"
class ItemSort
{
private:
	Manager*m_pItemManager = nullptr;
public:
	ItemSort(Manager*pItemManager)
		:m_pItemManager(pItemManager){}
	//void Sort(bool up);

	void GoldSort(void) {
		int n = m_pItemManager->GetCount();
			//0 1 2 3 4 EEE5ŒÂ n
			for (int j = 0; j < n - 1; j++) {
				for (int i = n - 2; i >= 0; i--) {
					Item* pA = m_pItemManager->GetItem(i);
					Item* pB = m_pItemManager->GetItem(i + 1);
		
					if (pA->GetGold() < pB->GetGold()) {
						m_pItemManager->swap(i, i + 1);
					}
				}
			}
	}
};

