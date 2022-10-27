//=======================================
// �����֌W(�w�b�_�t�@�C��)
// �쐬���F2022/07/14
// �쐬�ҁF��������
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
	//cpp�ŏ�����
	static const float SIZE_X;		//�T�C�YX
	static const float SIZE_Y;		//�T�C�YY
	static const D3DXVECTOR2 ITEM_MOOB;		//�T�C�YY

	enum Item_NUM m_TypeItem = Item_NUM::ENEMYITEM_NUM;
public:
	Item() {}	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	Item(DrawObject& DrawObject, const D3DXVECTOR2& pos/*Item_NUM typeitem*/)
		:GameObject(DrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y)) {}
	//�X�V����
	void Update(void) { GameObject::MovePos(ITEM_MOOB); }

	~Item() {}
};

