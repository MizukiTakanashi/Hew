#pragma once
#ifndef ITEM_H_
#define ITEM_H_
#include<string>
#include <iostream>
class Item
{
private:
	std::string m_name;	//���O
	int m_price = 0;		//���i
	float m_weight = 0.0f;		//�d��
	std::string m_text;		//�t���[�o�[�e�L�X�g
public:
	Item() :m_name("�s��"), m_price(0), m_weight(0), m_text("����"){}

	Item(std::string name,int price ,int weight ,std::string text)
		:m_name(name),m_price(price) ,m_weight(weight), m_text(text) {}

	virtual void ItemPrint() {
		std::cout << "�A�C�e�����F" << m_name << "\n";
		std::cout << "���i:" << m_price << "�� \n";
		std::cout << "�d��:" << m_weight << "G \n";
		std::cout << m_text << " \n";
	}
	int GetGold() { return m_price; }
	virtual~Item() {}
};

#endif // !ITEM_H_

