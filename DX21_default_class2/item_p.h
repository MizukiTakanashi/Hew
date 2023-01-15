//=======================================
// �����֌W(�w�b�_�t�@�C��)
// �쐬���F2022/07/14
// �쐬�ҁF��������
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
		ENEMYITEM_TYPE1 = 0,	//�z�[�~���O	
		ENEMYITEM_TYPE2,		//���[�U�[
		ENEMYITEM_TYPE3,		//�K�g�����O
		ENEMYITEM_TYPE4,		//�o���A
		ENEMYITEM_TYPE5,		//STOP
		ENEMYITEM_TYPE6,		//�X��
		ENEMYITEM_TYPE7,		//�O���l�[�h�G
		ENEMYITEM_TYPE8,
		ENEMYITEM_NUM,
	};

private:
	//cpp�ŏ�����
	static const float SIZE_X;		//�T�C�YX
	static const float SIZE_Y;		//�T�C�YY
	static const D3DXVECTOR2 ITEM_MOOB;		//�T�C�YY

	Item_NUM m_TypeItem = Item_NUM::ENEMYITEM_NUM;
public:
	Item() {}	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	Item(DrawObject& DrawObject, const D3DXVECTOR2& pos,int typeitem)
		:GameObject(DrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y)), m_TypeItem((Item_NUM)typeitem) {}
	
	//�f�X�g���N�^
	~Item()override{}
	
	//�X�V����
	void Update(void) { GameObject::MovePos(ITEM_MOOB); }

	//�A�C�e���̃^�C�v��Ԃ�
	int GerItemType() const { return (int)m_TypeItem; }
};

