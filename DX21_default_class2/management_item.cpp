//=======================================
// �����Ǘ��֌W(cpp�t�@�C��)
// �쐬���F2022/09/18
// �쐬�ҁF��������
//=======================================
#include "management_item.h"
#include "sound.h"

//============================
// �f�t�H���g�R���X�g���N�^
//============================
ItemManagement::ItemManagement()
{
	m_pItem = new Item[ENEMY_NUM];

	m_SE = LoadSound((char*)"data\\SE\\bomb000.wav");	//�T�E���h�̃��[�h
}

//======================
// �X�V����
//======================
void ItemManagement::Update(void)
{
	for (int i = 0; i < m_ItemNum; i++) {
		/*for (int j = i; j < m_ItemNum - 1; j++) {
			m_pItem[j] = m_pItem[j + 1];
			m_ItemNum--;
		}*/
		m_pItem[i].Update();
	}

}

void ItemManagement::DeleteItem(int index_num)
{
	for (int i = index_num; i < m_ItemNum - 1; i++) {
		m_pItem[i] = m_pItem[i + 1];
	}
	m_ItemNum--;
}

//==========================
// �A�C�e�����Z�b�g
//==========================
void ItemManagement::SetItem(const D3DXVECTOR2& pos,int typeitem)
{
    Item Temp(*m_DOMissile, pos, typeitem);

	switch (typeitem)
	{
	case 0:
		m_pItem[m_ItemNum].SetDrawob(*m_DOMissile);
		break;
	case 1:
		m_pItem[m_ItemNum].SetDrawob(*m_DOLaser);
		break;
	case 2:
		m_pItem[m_ItemNum].SetDrawob(*m_DOGatoring);
		break;
	case 3:
		m_pItem[m_ItemNum].SetDrawob(*m_DOMissile);
		break;
	case 4:
		m_pItem[m_ItemNum].SetDrawob(*m_DOLaser);
		break;
	case 5:
		m_pItem[m_ItemNum].SetDrawob(*m_DOGatoring);
		break;
	case 6:
		m_pItem[m_ItemNum].SetDrawob(*m_DOMissile);
		break;
	case 7:
		m_pItem[m_ItemNum].SetDrawob(*m_DOLaser);
		break;
	case 8:
		m_pItem[m_ItemNum].SetDrawob(*m_DOGatoring);
		break;
	default:
		m_pItem[m_ItemNum].SetDrawob(*m_DOMissile);
		break;
	}

	m_pItem[m_ItemNum] = Temp;
	m_ItemNum++;

}
