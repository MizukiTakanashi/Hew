//=======================================
// 爆発管理関係(cppファイル)
// 作成日：2022/09/18
// 作成者：高梨水希
//=======================================
#include "ItemManagement.h"
#include "sound.h"

//============================
// デフォルトコンストラクタ
//============================
ItemManagement::ItemManagement()
{
	m_pItem = new Item[MAX_NUM];

	m_SE = LoadSound((char*)"data\\SE\\bomb000.wav");	//サウンドのロード
}

//=========================
// 引数付きコンストラクタ
//=========================
ItemManagement::ItemManagement(DrawObject& DrawObject) :m_DrawObject(DrawObject)
{
	m_pItem = new Item[MAX_NUM];

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

//==========================
// 爆発をセット
//==========================
void ItemManagement::SetItem(const D3DXVECTOR2& pos)
{
	Item Temp(m_DrawObject, pos);
	m_pItem[m_ItemNum] = Temp;
	m_ItemNum++;

	PlaySound(m_SE, 0);
	SetVolume(m_SE, 0.1f);
}
