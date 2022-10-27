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

	//爆発をセット
	void SetItem(const D3DXVECTOR2& pos);
};

