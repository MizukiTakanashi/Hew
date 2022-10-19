#pragma once
#ifndef ATTACK_H_
#define ATTACK_H_
#include<string>
#include <iostream>
#include "item.h"

class Attack:public Item
{
public:
	enum class ATTACK_NUM :int
	{
		ATTACK_SWORD = 0,
		ATTACK_AXE
	};
private:
	
	int m_attack;	//攻撃力
	enum ATTACK_NUM m_TypeAttack = ATTACK_NUM::ATTACK_SWORD;
public:
	Attack(std::string name, int price, int weight, std::string text,int attack,ATTACK_NUM typeattack)
		:Item(name,price,weight,text), m_attack(attack),m_TypeAttack(typeattack) {}

	void ItemPrint()override;
	void AttackPrint();	//アタックの表示
	

	virtual~Attack(){}
};


#endif // !ATTACK_H_
