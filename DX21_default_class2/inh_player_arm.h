#pragma once
//==============================================
// (継承用)プレイヤーの腕関係(ヘッダファイル)
// 作成日：2022/10/28
// 作成者：高梨水希
//==============================================

#ifndef _INH_PLAYER_ARM_H_
#define _INH_PLAYER_ARM_H_

#include "game_object.h"

class inhPlayerArm:public GameObject
{
//定数
public:
	// 腕に着く敵の種類
	enum class TYPE :int
	{
		TYPE1,		//ホーミング
		TYPE2,		//レーザー
		TYPE3,		//ガトリング
		TYPE4,		//バリア
		TYPE5,
		TYPE6,
		TYPE7,
		TYPE8,
		TYPE_NUM,
	};

//メンバ変数
private:
	int m_BulletNum = 0;		//現在の弾の数
	int m_bullet_maked_num = 0;	//今まで作られた弾の数(アイテムの消費量)
	int m_bullet_max_num = 0;	//アイテムが出す最大弾数
	
	int m_bullet_hp = 0;		//現在の弾のHP
	
	bool m_right = false;		//右についてるか左についてるか
	bool m_center = false;		//中央についているか

	bool m_button_push = false;	//ボタンが押されたか
	bool m_button_trigger = false;	//ボタンが押されたか(トリガー)
	
	bool m_bullet_used = false;	//弾が尽きたかどうか
	
	TYPE m_type = TYPE::TYPE1;	//自分のタイプ

	//とある座標取得用
	//現在はPlayerArm1のホーミング弾の敵の位置取得用
	D3DXVECTOR2 m_something_pos = D3DXVECTOR2(0.0f, 0.0f);	

//メンバ関数
public:
	//デフォルトコンストラクタ
	inhPlayerArm(){}

	//引数付きコンストラクタ
	inhPlayerArm(int bullet_max_num, bool right, int type, int hp_max = 0)
		:m_bullet_max_num(bullet_max_num), m_right(right), m_type((TYPE)type),
		m_bullet_hp(hp_max) {}

	//デストラクタ
	virtual ~inhPlayerArm()override{}

	//=========================
	// オーバーライド用
	
	//更新処理(オーバーライド)
	virtual void Update(const D3DXVECTOR2& arm_pos) = 0;

	//描画処理(オーバーライド)
	virtual void PlayerArmDraw(void)const = 0;

	//指定した番号の弾を消す(オーバーライド用)
	virtual void DeleteBullet(int index_num) = 0;

	//指定した番号の弾の座標を返す(オーバーライド用)
	virtual const D3DXVECTOR2& GetBulletPos(int index_num)const = 0;

	//指定した番号の弾のサイズを返す(オーバーライド用)
	virtual const D3DXVECTOR2& GetBulletSize(int index_num = 0)const = 0;

	
	//=====================
	// 弾
	
	//弾が尽きたかを返す
	// true：使い終わった　false：まだ使い終わってない
	bool IsBulletUsed(void)const;

	//弾が尽きたかどうかをセット
	void SetBulletUsed(bool used) { m_bullet_used = used; }

	//作った弾の数を増やす
	void IncreaseBulletMaked(int num = 1) { m_bullet_maked_num += num; }

	//作った弾の数を返す
	int GetBulletMaked(void) { return m_bullet_maked_num; }

	//現在の弾数を増やす
	void IncreaseBulletNum(int num = 1) { m_BulletNum += num; }

	//弾の数を取得
	int GetBulletNum(void)const { return m_BulletNum; }

	//==========================
	// どこの腕についているか
	
	//ついているのが右腕か左腕かを返す
	bool GetRightLeft(void)const { return m_right; }

	//右腕か左腕かをセットする
	void SetRightLeft(bool right) { m_right = right; }

	//中央についているか
	bool IsCenter(void)const { return m_center; }

	//中央についているかフラグをセット
	void SetCenter(bool center) { m_center = center; }

	//=====================
	// ボタン
	
	//ボタンが押されたかフラグをセット
	void SetButtonPush(bool push) { m_button_push = push; }

	//ボタンが押されたかを返す
	bool IsButtonPush(void)const { return m_button_push; }

	//ボタンが押されたかフラグをセット　トリガー
	void SetButtonTrigger(bool push) { m_button_trigger = push; }

	//ボタンが押されたかを返す　トリガー
	bool IsButtonTrigger(void)const { return m_button_trigger; }


	//タイプを返す
	TYPE GetType(void)const { return m_type; }

	//=====================
	// とある座標
	
	//とある座標セット用(詳細はメンバ変数のm_something_posのコメントへ)
	void SetSomethingPos(const D3DXVECTOR2& pos) { m_something_pos = pos; }

	//とある座標取得用(詳細はメンバ変数のm_something_posのコメントへ)
	const D3DXVECTOR2& GetSomethingPos(void)const { return m_something_pos; }

	//=====================
	// 残弾数
	
	//残弾数回復
	void HeelBullet(void) { m_bullet_maked_num = 0; }

	//残弾数を返す
	int GetRemainingBullet(void);

	//=====================
	// HP
	
	//HPを減らす、HPが0以下になったらtrueを返す
	bool ReduceHP(int num) {
		m_bullet_hp -= num;
		if (m_bullet_hp <= 0) {
			return true;
		}
		return false;
	}
};

#endif // !_INH_PLAYER_ARM_H_