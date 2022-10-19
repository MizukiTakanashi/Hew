#include "attack.h"



void Attack::AttackPrint()
{
	std::string type[] =
	{
		"Œ•","•€"
	};
	std::cout << "•ŠíŽí—Þ" << type[(int)m_TypeAttack] << "\n";
	std::cout << "UŒ‚—Í:" << m_attack << "\n";
}
void Attack::ItemPrint()
{
	Item::ItemPrint();
	AttackPrint();
}