//=======================================
// �����Ǘ��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/09/18
// �쐬�ҁF��������
//=======================================
#pragma once

#include "main.h"
#include "item_p.h"


class ItemManagement
{
	//�萔
private:
	static const int ENEMY_NUM = 50;	//�����̍ő吔


	//�����o�ϐ�
private:
	int m_SE = 0;
	DrawObject m_DOMissile;
	DrawObject m_DOLaser;
	DrawObject m_DOGatoring;
	Item* m_pItem = nullptr;
	int m_ItemNum = 0;	//�A�C�e���̐�

public:
	//�f�t�H���g�R���X�g���N�^
	ItemManagement();

	~ItemManagement() { delete[] m_pItem; }	//�f�X�g���N�^

	//�X�V����
	void Update(void);

	//�`�揈��
	void Draw(void)const {
		for (int i = 0; i < m_ItemNum; i++) {
			m_pItem[i].Draw();
		}
	}

	//���݂̃A�C�e���ʒu��Ԃ�
	const D3DXVECTOR2& GetItemPos(int index_num)const { return m_pItem[index_num].GetPos(); }

	//�A�C�e���̃T�C�Y��Ԃ�
	const D3DXVECTOR2& GetItemSize(void)const { return m_pItem[0].GetSize(); }

	//�w�肵���A�C�e��������
	void DeleteItem(int index_num);

	//���݂̃A�C�e���̐���Ԃ�
	int GetItemNum(void)const { return m_ItemNum; }

	//�A�C�e�����Z�b�g
	void SetItem(const D3DXVECTOR2& pos, int typeitem);

	//�A�C�e���̃^�C�v��Ԃ�
	int GetItemType(int i) const { return m_pItem[i].GerItemType(); }

	void SetDrawMissile(DrawObject& pd) { m_DOMissile = pd; }
	void SetDrawLaser(DrawObject& pd) { m_DOLaser = pd; }
	void SetDrawGatoring(DrawObject& pd) { m_DOGatoring = pd; }
};

