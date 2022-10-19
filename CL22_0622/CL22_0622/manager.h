#pragma once
#ifndef _MANAGER_H_
#define _MANAGER_H_
#include<string>
#include <iostream>
#include "item.h"
//ソート担当
#define ITEM_MAX 256
class Manager:Item
{
private:
	Item* m_items[256];
	int m_count = 0;
public:
	Manager() 
	{
		for(int i = 0; i < ITEM_MAX; i++)
		{
			m_items[i] = NULL;
		}
	}
	void Add(Item*pItem);
	void DeleteItem(int index);
	void DeleteItem(Item*pItem);
	Item* GetItem(int index);	//アイテムのインデックス
	int GetCount();				
	void printItemData(void);
	void swap(int x, int y);

};

#endif // !_MANAGER_H_

