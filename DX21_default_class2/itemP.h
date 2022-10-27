//=======================================
// 爆発関係(ヘッダファイル)
// 作成日：2022/07/14
// 作成者：高梨水希
//=======================================



#include "GameObject.h"
#include "DrawObject.h"
#include "main.h"

class Item :public GameObject
{
public:
	enum class Item_NUM :int
	{
		ENEMYITEM_NUM = 0,
		ENEMYITEM_TYPE1,
		ENEMYITEM_TYPE2,
		ENEMYITEM_TYPE3,
		ENEMYITEM_TYPE4,
		ENEMYITEM_TYPE5,
		ENEMYITEM_TYPE6,
		ENEMYITEM_TYPE7,
		ENEMYITEM_TYPE8,
	};

private:
	//cppで初期化
	static const float SIZE_X;		//サイズX
	static const float SIZE_Y;		//サイズY
	static const D3DXVECTOR2 ITEM_MOOB;		//サイズY

	enum Item_NUM m_TypeItem = Item_NUM::ENEMYITEM_NUM;
public:
	Item() {}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	Item(DrawObject& DrawObject, const D3DXVECTOR2& pos/*Item_NUM typeitem*/)
		:GameObject(DrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y)) {}
	//更新処理
	void Update(void) { GameObject::MovePos(ITEM_MOOB); }

	~Item() {}
};

