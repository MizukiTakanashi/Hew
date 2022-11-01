#pragma once
//=======================================
// マネジメント関係(ヘッダファイル)
// 作成日：2022/10/28
// 作成者：高梨水希
//=======================================

#ifndef _MANAGEMENT_H_
#define _MANAGEMENT_H_

#include "game_object.h"

class Management
{
private:
	int m_obj_max_num = 0;			//オブジェクトの最大数
	int m_obj_num = 0;				//現在のオブジェクト数

public:
	//デフォルトコンストラクタ
	Management(){}

	//引数付きコンストラクタ
	Management(int max_num) :m_obj_max_num(max_num) {}
	
	//デストラクタ
	virtual ~Management(){}

	//指定した番号のオブジェクトを消す
	virtual void DeleteObj(int index_num) = 0;

	//現在のオブジェクト数を増やす
	void IncreaseObjNum(int num = 1) { m_obj_num += num; }

	//現在のオブジェクトの数を返す
	int GetObjNum(void)const { return m_obj_num; }

	//指定した番号の座標を返す(オーバーライド用)
	virtual const D3DXVECTOR2& GetObjPos(int index_num)const = 0;

	//指定した番号のサイズを返す(オーバーライド用)
	virtual const D3DXVECTOR2& GetObjSize(int index_num = 0)const = 0;
};

#endif // !_MANAGEMENT_H_