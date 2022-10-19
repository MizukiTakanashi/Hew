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
	ma.Add(new Item("基本アイテム", 100, 10.0f, "アイテムです"));
	ma.Add(new SUB_ITEM("おくちゅり", 20, 1.0f, "おくちゅりでちゅよ～"));
	ma.Add(new Attack("剣", 1000, 10.0f, "剣です",10,Attack::ATTACK_NUM::ATTACK_SWORD));
	ma.Add(new Defense("盾", 500, 10.0f, "盾です", 10, Defense::DEFENSE_NUM::TIPE_SHILD));
	sort.GoldSort();
	ma.printItemData();
	ma.swap(1, 2);
	
	return 0;
}