#pragma once
//=======================================
// マネジメント関係(ヘッダファイル)
// 作成日：2022/10/28
// 作成者：高梨水希
//=======================================

#ifndef _MANAGEMENT_H_
#define _MANAGEMENT_H_

#include "GameObject.h"

class Management
{
private:
	GameObject* m_pObj = nullptr;	//オブジェクト
	int m_obj_max_num = 0;			//オブジェクトの最大数
	int m_obj_num = 0;				//現在のオブジェクト数

public:
	//デフォルトコンストラクタ
	Management(){}

	//引数付きコンストラクタ
	Management(GameObject* pObj, int max_num):m_pObj(pObj), m_obj_max_num(max_num) {}
	
	//デストラクタ
	virtual ~Management(){}

	//現在のオブジェクトの数を返す
	int GetObjNum(void)const { return m_obj_num; }

	//現在のオブジェクト数を増やす
	void IncreaseObjNum(int num = 1) { m_obj_num += num; }

	//オブジェクトを描画する
	void DrawObj(void)const {
		for (int i = 0; i < m_obj_num; i++) {
			(m_pObj + i)->Draw();
		}
	}

	//指定した番号の物を消す
	void Delete(int index_num);

	//指定した番号の座標を返す
	const D3DXVECTOR2& GetObjPos(int index_num)const { return (m_pObj + index_num)->GetPos(); }

	//指定した番号のサイズを返す
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const { return (m_pObj + index_num)->GetSize(); }
};

#endif // !_MANAGEMENT_H_