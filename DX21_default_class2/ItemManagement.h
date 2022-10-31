//=======================================
// 爆発管理関係(ヘッダファイル)
// 作成日：2022/09/18
// 作成者：高梨水希
//=======================================
#pragma once

#include "main.h"
#include "itemP.h"


class ItemManagement
{
	//定数
private:
	static const int MAX_NUM = 50;	//爆発の最大数


	//メンバ変数
private:
	int m_SE = 0;

	DrawObject m_DrawObject;
	Item* m_pItem = nullptr;
	int m_ItemNum = 0;	//アイテムの数

public:
	//デフォルトコンストラクタ
	ItemManagement();

	//引数付きコンストラクタ
	ItemManagement(DrawObject& DrawObject);

	~ItemManagement() { delete[] m_pItem; }	//デストラクタ

	//更新処理
	void Update(void);

	//描画処理
	void Draw(void)const {
		for (int i = 0; i < m_ItemNum; i++) {
			m_pItem[i].Draw();
		}
	}
	//現在のアイテム位置を返す
	const D3DXVECTOR2& GetItemPos(int index_num)const { return m_pItem[index_num].GetPos(); }

	//アイテムのサイズを返す
	const D3DXVECTOR2& GetItemSize(void)const { return m_pItem[0].GetSize(); }

	//指定したアイテムを消す
	void DeleteItem(int index_num);

	//現在のアイテムの数を返す
	int GetItemNum(void)const { return m_ItemNum; }

	//アイテムをセット
	void SetItem(const D3DXVECTOR2& pos,int typeitem);
};

