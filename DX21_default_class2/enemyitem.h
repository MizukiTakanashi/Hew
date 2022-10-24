//=======================================
// �G�̃A�C�e���֌W(�w�b�_�t�@�C��)
// �쐬���F2022/10/23
// �쐬�ҁF����đ�
//=======================================

#ifndef _ENEMYITEM_H_
#define _ENEMYITEM_H_

#include "GameObject.h"
#include "DrawObject.h"

class EnemyItem :public GameObject
{
public:
	enum class EnemyItem_NUM :int
	{
		ENEMYITEM_TYPE1,
		ENEMYITEM_TYPE2,
		ENEMYITEM_TYPE3,
		ENEMYITEM_TYPE4,
		ENEMYITEM_TYPE5,
		ENEMYITEM_TYPE6,
		ENEMYITEM_TYPE7,
		ENEMYITEM_TYPE8,
		ENEMYITEM_TYPE_NUM,
	};
private:
	enum EnemyItem_NUM m_TypeAttack = EnemyItem_NUM::ENEMYITEM_TYPE_NUM;
	D3DXVECTOR2 m_mov = D3DXVECTOR2(0.0f, 0.0f);

public:
	EnemyItem() {}	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	EnemyItem(DrawObject& pDrawObject, const D3DXVECTOR2& pos, const D3DXVECTOR2& size, const D3DXVECTOR2& mov, float rot, EnemyItem_NUM typeenemyitem)
		:GameObject(pDrawObject, pos, size, rot), m_mov(mov) {}

	virtual ~EnemyItem() {}	//�f�X�g���N�^

	//�X�V����(�G�̃A�C�e�����ړ�)
	void Update(void) { GameObject::MovePos(m_mov); }
};
#endif //!_ENEMYITEM_H_