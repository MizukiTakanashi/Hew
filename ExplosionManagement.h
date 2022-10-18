//=======================================
// 爆発管理関係(ヘッダファイル)
// 作成日：2022/09/18
// 作成者：高梨水希
//=======================================
#pragma once

#include "explosion.h"
#include "main.h"

#ifndef _EXPLOSION_MANAGEMENT_H_
#define _EXPLOSION_MANAGEMENT_H_

class ExplosionManagement
{
//定数
private:
	static const int MAX_NUM = 50;	//爆発の最大数


//メンバ変数
private:
	int m_SE = 0;

	DrawObject m_DrawObject;
	Explosion* m_pExplosion = nullptr;
	int m_ExplosionNum = 0;

public:
	//デフォルトコンストラクタ
	ExplosionManagement();

	//引数付きコンストラクタ
	ExplosionManagement(DrawObject& DrawObject);

	~ExplosionManagement() { delete[] m_pExplosion; }	//デストラクタ

	//更新処理
	void Update(void);

	//描画処理
	void Draw(void)const{
		for (int i = 0; i < m_ExplosionNum; i++) {
			m_pExplosion[i].Draw();
		}
	}

	//爆発をセット
	void SetExplosion(const D3DXVECTOR2& pos);
};

#endif // !_EXPLOSION_MANAGEMENT_H_