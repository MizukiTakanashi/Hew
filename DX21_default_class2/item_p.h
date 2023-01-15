//=======================================
// 爆発関係(ヘッダファイル)
// 作成日：2022/07/14
// 作成者：高梨水希
//=======================================
#pragma once


#include "game_object.h"
#include "draw_object.h"
#include "main.h"

class Item :public GameObject
{
public:
	enum class Item_NUM :int
	{
		ENEMYITEM_TYPE1 = 0,	//ホーミング	
		ENEMYITEM_TYPE2,		//レーザー
		ENEMYITEM_TYPE3,		//ガトリング
		ENEMYITEM_TYPE4,		//バリア
		ENEMYITEM_TYPE5,		//STOP
		ENEMYITEM_TYPE6,		//氷柱
		ENEMYITEM_TYPE7,		//グレネード敵
		ENEMYITEM_TYPE8,
		ENEMYITEM_NUM,
	};

private:
	//cppで初期化
	static const float SIZE_X;		//サイズX
	static const float SIZE_Y;		//サイズY
	static const D3DXVECTOR2 ITEM_MOOB;		//サイズY

	Item_NUM m_TypeItem = Item_NUM::ENEMYITEM_NUM;
public:
	Item() {}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	Item(DrawObject& DrawObject, const D3DXVECTOR2& pos,int typeitem)
		:GameObject(DrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y)), m_TypeItem((Item_NUM)typeitem) {}
	
	//デストラクタ
	~Item()override{}
	
	//更新処理
	void Update(void) { GameObject::MovePos(ITEM_MOOB); }

	//アイテムのタイプを返す
	int GerItemType() const { return (int)m_TypeItem; }
};

