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
		ENEMYITEM_TYPE_HOMING = 0,	//ホーミング	
		ENEMYITEM_TYPE_LASER,		//レーザー
		ENEMYITEM_TYPE_GATORING,	//ガトリング
		ENEMYITEM_TYPE_BARRIAR,		//バリア
		ENEMYITEM_TYPE_STOP,		//STOP
		ENEMYITEM_TYPE_ICERAIN,		//氷柱
		ENEMYITEM_GRENADE,			//グレネード敵
		ENEMYITEM_FIRE,			//炎の敵
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

