#include "defense.h"



void Defense::DefensePrint()
{
	std::string type[] =
	{
		"��","�`�F�X�g�v���[�g","�u�[�c"
	};
	std::cout << "�h��ʒu" << type[(int)m_typedefense] << "\n";
	std::cout << "�h���:" << m_Defense << "\n";
}

void Defense::ItemPrint()
{
	Item::ItemPrint();
	DefensePrint();
}
