//=======================================
// 普通の敵の管理関係(ヘッダファイル)
// 作成日：2022/09/13
// 作成者：高梨水希
//=======================================
#pragma once

#ifndef _ENEMY_NORMAL_MANAGEMENT_H_
#define _ENEMY_NORMAL_MANAGEMENT_H_

#include "main.h"
#include "EnemyManagement.h"
#include "EnemyNormal.h"
#include "bullet.h"
#include "DrawObject.h"
#include "EnemySetPos.h"

class EnemyNormalManagement:public EnemyManagement
{
//定数
private:
	//ここで初期化
	//敵自身
	static const int MAX_NUM = 10;				//敵の最大数
	static const int APPEARANCE_TIME = 200;		//敵の出現スピード
	static const int BULLET_BREAK_TIME = 200;	//ホーミング弾が壊れる時間

	//cppで初期化
	//弾
	static const float BULLET_SIZE_X;		//サイズX
	static const float BULLET_SIZE_Y;		//サイズY
	static const float BULLET_SPEED;		//スピード

public:
	//ここで初期化
	//敵自身
	static const int ATTACK = 1;			//攻撃値
	//弾
	static const int BULLET_ATTACK = 1;		//攻撃値


private:
	//メンバ変数
	EnemyNormal* m_pEnemyNormal = nullptr;
	Bullet* m_pBullet = nullptr;
	DrawObject m_pDrawObjectEnemy;
	DrawObject m_pDrawObjectBullet;
	EnemySetPos m_pEnemySetPos;

	int m_EnemyItem_num = 0;	//敵のアイテムの数

	int m_count = 0;		//敵の出現速度

public:
	//デフォルトコンストラクタ
	EnemyNormalManagement(){
		m_pEnemyNormal = new EnemyNormal[MAX_NUM];
		m_pBullet = new Bullet[MAX_NUM];
	}	

	//引数付きコンストラクタ
	EnemyNormalManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2,
		EnemySetPos& pEnemySetPos );

	//デストラクタ
	~EnemyNormalManagement()override { delete[] m_pEnemyNormal; delete[] m_pBullet; }

	//更新処理
	void Update(const D3DXVECTOR2& PlayerPos);

	//描画処理
	void Draw(void)const;			

	//指定した敵を消す
	void DeleteObj(int index_num)override;

	//指定した弾を消す
	void DeleteBullet(int index_num)override;

	//指定した番号の座標を返す(オーバーライド)
	const D3DXVECTOR2& GetObjPos(int index_num)const override { return m_pEnemyNormal[index_num].GetPos(); }

	//指定した番号のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override { return m_pEnemyNormal[index_num].GetSize(); }

	//指定した弾の座標を返す
	const D3DXVECTOR2& GetBulletPos(int index_num)const override{ return m_pBullet[index_num].GetPos(); }

	//弾のサイズを返す
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override{ return m_pBullet[index_num].GetSize(); }
};

#endif // !_ENEMY_NORMAL_MANAGEMENT_H_