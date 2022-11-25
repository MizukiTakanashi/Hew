//=======================================
// プレイヤー関係(ヘッダファイル)
// 作成日：2022/06/27
// 作成者：高梨水希
//=======================================

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "main.h"
#include "draw_object.h"
#include "game_object.h"
#include "bullet.h"
#include "Bom.h"
//======================
// マクロ定義
//======================

class Player:public GameObject
{
private:
	//定数

	//プレイヤー本体
	static const float BOX_W;		//四角形の横のサイズ
	static const float BOX_H;		//四角形の縦のサイズ
	static const float START_POS_X;	//初期位置X
	static const float START_POS_Y;	//初期位置Y
	static const float SPEED_X;		//スピードX
	static const float SPEED_Y;		//スピードY
	static const float SPEED;		//スピード

	//弾
	//ここで初期化
	static const int BULLET_MAX_NUM = 100;		//プレイヤーの弾の総数
	static const int BULLET_INTERVAL_TIME = 20;	//弾の発射間隔
	
	static const float BULLET_SIZE_X;			//弾のサイズX
	static const float BULLET_SIZE_Y;			//弾のサイズY
	static const float BULLET_SPEED_X;			//弾のスピードX
	static const float BULLET_SPEED_Y;			//弾のスピードY

	static const D3DXCOLOR INVINCIBLE__COLOR;	//プレイヤー無敵時間の色
	//爆弾
	static const int BOM_MAX_NUM = 100;		//プレイヤーの弾の総数
	static const int BOM_INTERVAL_TIME = 20;	//弾の発射間隔

	static const float BOM_SIZE_X;			//弾のサイズX
	static const float BOM_SIZE_Y;			//弾のサイズY
private:
	Bullet* m_pBullet = nullptr;
	int m_BulletNum = 0;			//弾の現在の数
	DrawObject m_BulletDrawObject;
	int m_BulletInterval = 0;		//弾の発射間隔
	//爆弾
	Bom* m_pBom = nullptr;
	int m_BomNum = 0;			//爆弾の現在の数
	DrawObject m_BomDrawObject;
	int m_BomInterval = 0;		//爆弾の発射間隔
public:
	//デフォルトコンストラクタ
	Player() {
		m_pBullet = new Bullet[BULLET_MAX_NUM];
		m_pBom = new Bom[BOM_MAX_NUM];
	}

	//引数付きコンストラクタ
	Player(DrawObject& pDrawObject, DrawObject& BulletDrawObject,DrawObject& BomDrawObject)
		:GameObject(pDrawObject, D3DXVECTOR2(START_POS_X, START_POS_Y), D3DXVECTOR2(BOX_W, BOX_H)),
		m_BulletDrawObject(BulletDrawObject),m_BomDrawObject(BomDrawObject)
	{
		m_pBullet = new Bullet[BULLET_MAX_NUM];
		m_pBom = new Bom[BOM_MAX_NUM];
		
	}

	~Player()override {
		delete[] m_pBullet;
		delete[]m_pBom;
	}		//デストラクタ

	//更新処理
	void Update(bool);

	//弾の描画処理
	void DrawBullet(void)const;


	//現在弾の数を返す
	int GetBulletNum(void)const { return m_BulletNum; }

	//指定した弾を消す
	void DeleteBullet(int index_num);

	//指定した弾の座標を返す
	const D3DXVECTOR2& GetBulletPos(int index_num)const { return m_pBullet[index_num].GetPos(); }

	//弾のサイズを返す
	const D3DXVECTOR2& GetBulletSize(void)const { return m_pBullet[0].GetSize(); }


	//爆弾の描画処理
	void DrawBom(void)const;

	//現在爆弾の数を返す
	int GetBomNum(void)const { return m_BomNum; }

	//指定した爆弾を消す
	void DeleteBom(int index_num);

	//指定した爆弾の座標を返す
	const D3DXVECTOR2& GetBomPos(int index_num)const { return m_pBom[index_num].GetPos(); }

	//爆弾のサイズを返す
	const D3DXVECTOR2& GetBomSize(void)const { return m_pBom[0].GetSize(); }
};

#endif // !_PLAYER_H_
