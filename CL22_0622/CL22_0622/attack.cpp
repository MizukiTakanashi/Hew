#include "attack.h"



void Attack::AttackPrint()
{
	std::string type[] =
	{
		"��","��"
	};
	std::cout << "������" << type[(int)m_TypeAttack] << "\n";
	std::cout << "�U����:" << m_attack << "\n";
}
void Attack::ItemPrint()
{
	Item::ItemPrint();
	AttackPrint();
}