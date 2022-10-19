#pragma once
#include<string>
#include <iostream>
#include "item.h"

class SUB_ITEM :public Item
{
	public:
		SUB_ITEM(){}
		SUB_ITEM(std::string name, int price, int weight, std::string text)
			:Item(name,price,weight,text) {}
};