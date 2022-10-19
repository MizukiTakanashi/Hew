#include "defense.h"



void Defense::DefensePrint()
{
	std::string type[] =
	{
		"盾","チェストプレート","ブーツ"
	};
	std::cout << "防具位置" << type[(int)m_typedefense] << "\n";
	std::cout << "防御力:" << m_Defense << "\n";
}

void Defense::ItemPrint()
{
	Item::ItemPrint();
	DefensePrint();
}
