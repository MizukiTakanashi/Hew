//=======================================
// 爆発管理関係(cppファイル)
// 作成日：2022/09/18
// 作成者：高梨水希
//=======================================
#include "management_item.h"
#include "sound.h"

//============================
// デフォルトコンストラクタ
//============================
ItemManagement::ItemManagement()
{
	m_pItem = new Item[ENEMY_NUM];

	m_SE = LoadSound((char*)"data\\SE\\bomb000.wav");	//サウンドのロード
}

//======================
// 更新処理
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
// アイテムをセット
//==========================
void ItemManagement::SetItem(const D3DXVECTOR2& pos,int typeitem, bool ice)
{

    Item Temp(m_DOMissile, pos, typeitem);
	m_pItem[m_ItemNum] = Temp;

	//アイテムの見た目変更
	switch (typeitem)
	{
	case (int)Item::Item_NUM::ENEMYITEM_TYPE_HOMING:
		m_pItem[m_ItemNum].SetDrawob(m_DOMissile);
		break;
	case (int)Item::Item_NUM::ENEMYITEM_TYPE_LASER:
		m_pItem[m_ItemNum].SetDrawob(m_DOLaser);
		break;
	case (int)Item::Item_NUM::ENEMYITEM_TYPE_GATORING:
		m_pItem[m_ItemNum].SetDrawob(m_DOGatoring);
		break;
	case (int)Item::Item_NUM::ENEMYITEM_TYPE_BARRIAR:
		m_pItem[m_ItemNum].SetDrawob(m_DOBarrier);
		break;
	case (int)Item::Item_NUM::ENEMYITEM_TYPE_STOP:
		m_pItem[m_ItemNum].SetDrawob(m_DOStop);
		break;
	case (int)Item::Item_NUM::ENEMYITEM_TYPE_ICERAIN:
		m_pItem[m_ItemNum].SetDrawob(m_DOIcerain);
		break;
	case (int)Item::Item_NUM::ENEMYITEM_GRENADE:
		m_pItem[m_ItemNum].SetDrawob(m_DOGrenade);
		break;
	case (int)Item::Item_NUM::ENEMYITEM_FIRE:
		m_pItem[m_ItemNum].SetDrawob(m_DOFire);
		break;
	case (int)Item::Item_NUM::ENEMYITEM_ACID:
		m_pItem[m_ItemNum].SetDrawob(m_DOAcid);
		break;
	case (int)Item::Item_NUM::ENEMYITEM_FIREBALL:
		m_pItem[m_ItemNum].SetDrawob(m_DOFireball);
		break;

	default:
		m_pItem[m_ItemNum].SetDrawob(m_DOPoisonlaser);
		break;
	}

	if (ice) {
		m_pItem[m_ItemNum].SetDrawob(m_DOIce);
	}

	m_ItemNum++;
}
