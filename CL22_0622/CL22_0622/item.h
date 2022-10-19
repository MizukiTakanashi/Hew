#pragma once
#ifndef ITEM_H_
#define ITEM_H_
#include<string>
#include <iostream>
class Item
{
private:
	std::string m_name;	//名前
	int m_price = 0;		//価格
	float m_weight = 0.0f;		//重さ
	std::string m_text;		//フレーバーテキスト
public:
	Item() :m_name("不明"), m_price(0), m_weight(0), m_text("無し"){}

	Item(std::string name,int price ,int weight ,std::string text)
		:m_name(name),m_price(price) ,m_weight(weight), m_text(text) {}

	virtual void ItemPrint() {
		std::cout << "アイテム名：" << m_name << "\n";
		std::cout << "価格:" << m_price << "＄ \n";
		std::cout << "重さ:" << m_weight << "G \n";
		std::cout << m_text << " \n";
	}
	int GetGold() { return m_price; }
	virtual~Item() {}
};

#endif // !ITEM_H_

