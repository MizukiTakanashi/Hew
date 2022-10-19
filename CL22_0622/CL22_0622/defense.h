#pragma once
#ifndef DEFENSE_H_
#define DEFENSE_H_
#include<string>
#include <iostream>
#include"item.h"

class Defense :public Item
{
public:
	enum class DEFENSE_NUM :int
	{
		TIPE_SHILD = 0,
		TYPE_TYESUTO,
		TYPE_BUUTU
	};
private:
	int m_Defense = 0;
	enum DEFENSE_NUM m_typedefense = DEFENSE_NUM::TIPE_SHILD;
public:
	Defense(std::string name, int price, int weight, std::string text, int defense, DEFENSE_NUM type)
		:Item(name, price, weight, text), m_Defense(defense), m_typedefense(type) {}
	void ItemPrint()override;
	void DefensePrint();	//�f�B�t�F���X�̕\��
	
	virtual~Defense() {}
};



#endif // !DEFENSE_H_







/*virtual void Selfintroduction(void) {
			Item::Selfintroduction();
			std::cout << "�h��́F" << m_Defense << "\n";
			std::cout << "�����ʒu:" << m_type << " \n";
		}*/