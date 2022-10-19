#include "manager.h"
#include<iostream>
#include"item.h"



void Manager::Add(Item * pItem)
{
	m_items[m_count++] = pItem;
}

void Manager::DeleteItem(int index)
{
	delete m_items[index];
	m_items[index] = m_items[--m_count];
}

void Manager::DeleteItem(Item * pItem)
{
	for (int i = 0; i < m_count; i++)
	{
		if (m_items[i] == pItem) {
			DeleteItem(i);
			break;
		}
	}
}

Item * Manager::GetItem(int index)
{
	return m_items[index];
}

int Manager::GetCount()
{
	return m_count;
}

void Manager::printItemData(void)
{
	for (int i = 0; i < m_count; i++) 
	{
		std::cout << "[" << i << "]\n";
		m_items[i]->ItemPrint();
		std::cout << std::endl;
	}
}


void Manager::swap(int x, int y)
{
	Item* ptemp = m_items[x];
	m_items[x] = m_items[y];
	m_items[y] = ptemp;
}
