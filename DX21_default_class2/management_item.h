//=======================================
// 爆発管理関係(ヘッダファイル)
// 作成日：2022/09/18
// 作成者：高梨水希
//=======================================
#pragma once

#include "main.h"
#include "item_p.h"


class ItemManagement
{
	//定数
private:
	static const int ENEMY_NUM = 50;	//爆発の最大数


	//メンバ変数
private:
	int m_SE = 0;
	DrawObject m_DOMissile;
	DrawObject m_DOLaser;
	DrawObject m_DOGatoring;
	DrawObject m_DOStop;
	DrawObject m_DOHotairlaser;
	DrawObject m_DOIcerain;
	DrawObject m_DOIce;
	DrawObject m_DOPoisonlaser;
	DrawObject m_DOFire;
	DrawObject m_DOAcid;
	DrawObject m_DOFireball;

	Item* m_pItem = nullptr;
	int m_ItemNum = 0;	//アイテムの数

public:
	//デフォルトコンストラクタ
	ItemManagement();

	//デストラクタ
	~ItemManagement() { delete[] m_pItem; }	

	//更新処理
	void Update(void);

	//描画処理
	void Draw(void)const {
		for (int i = 0; i < m_ItemNum; i++) {
			m_pItem[i].Draw();
		}
	}

	//現在のアイテム位置を返す
	const D3DXVECTOR2& GetItemPos(int index_num)const { return m_pItem[index_num].GetPos(); }

	//アイテムのサイズを返す
	const D3DXVECTOR2& GetItemSize(void)const { return m_pItem[0].GetSize(); }

	//指定したアイテムを消す
	void DeleteItem(int index_num);

	//現在のアイテムの数を返す
	int GetItemNum(void)const { return m_ItemNum; }

	//アイテムをセット
	void SetItem(const D3DXVECTOR2& pos, int typeitem, bool ice = false);

	//アイテムのタイプを返す
	int GetItemType(int i) const { return m_pItem[i].GerItemType(); }

	void SetDrawMissile(DrawObject& pd) { m_DOMissile = pd; }
	void SetDrawLaser(DrawObject& pd) { m_DOLaser = pd; }
	void SetDrawGatoring(DrawObject& pd) { m_DOGatoring = pd; }
	void SetDrawStop(DrawObject& pd) { m_DOStop = pd; }
	void SetDrawAcid(DrawObject& pd) { m_DOAcid = pd; }
	void SetDrawHotairlaser(DrawObject& pd) { m_DOHotairlaser = pd; }
	void SetDrawIcerain(DrawObject& pd) { m_DOIcerain = pd; }
	void SetDrawIce(DrawObject& pd) { m_DOIce = pd; }
	void SetDrawPoisonlaser(DrawObject& pd) { m_DOPoisonlaser = pd; }
	void SetDrawFire(DrawObject& pd) { m_DOFire = pd; }
	void SetDrawFireball(DrawObject& pd) { m_DOFireball = pd; }
};

