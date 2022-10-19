#include<random>
#include<iostream>
#include "attack.h"
#include "item.h"
#include "defense.h"
#include"ItemSort.h"
#include"subitem.h"

int main()
{
	Manager ma;
	ItemSort sort(&ma);
	ma.Add(new Item("��{�A�C�e��", 100, 10.0f, "�A�C�e���ł�"));
	ma.Add(new SUB_ITEM("���������", 20, 1.0f, "���������ł����`"));
	ma.Add(new Attack("��", 1000, 10.0f, "���ł�",10,Attack::ATTACK_NUM::ATTACK_SWORD));
	ma.Add(new Defense("��", 500, 10.0f, "���ł�", 10, Defense::DEFENSE_NUM::TIPE_SHILD));
	sort.GoldSort();
	ma.printItemData();
	ma.swap(1, 2);
	
	return 0;
}