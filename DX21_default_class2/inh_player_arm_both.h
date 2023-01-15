#pragma once
//===================================================
// プレイヤーの腕の右左関係(継承用)(ヘッダファイル)
// 作成日：2022/11/08
// 作成者：高梨水希
//===================================================

#ifndef _INH_PLAYER_ARM_BOTH_H_
#define _INH_PLAYER_ARM_BOTH_H_

#include "game_object.h"
#include "inh_player_arm.h"
#include "number.h"

class inhPlayerArmBoth :public GameObject
{
//定数
public:
	//腕につく敵のタイプ
	enum class TYPE :int
	{
		TYPE_NONE,	//	何もついていない
		TYPE1,		//ホーミング
		TYPE2,		//レーザー
		TYPE3,		//ガトリング
		TYPE4,		//バリア
		TYPE5,		//動きを止める
		TYPE6,		//氷の敵
		TYPE7,
		TYPE8,
		TYPE_SHOOT,	// 前のタイプの弾の処理 & 自身発射中
		TYPE_OLD,	// 前のタイプの弾の処理中
		TYPE_NUM,
	};

//定数
private:
	//cppで初期化
	static const D3DXVECTOR2 SIZE;				//サイズ
	static const float SHOT_SPEED;				//切り離し発射スピード
	static const D3DXVECTOR2 ICON_SIZE;			//敵アイコンの表示場所

//メンバ変数
private: 
	D3DXVECTOR2 m_from_player = D3DXVECTOR2(0.0f, 0.0f);	//プレイヤーからどれくらい離れているか

	bool m_shot = false;					//自分自身が発射されてるか否か
	TYPE m_type = TYPE::TYPE_NONE;			//ついた敵のタイプ

	inhPlayerArm* m_pEnemyItem = nullptr;	//腕についている敵のクラス
	DrawObject m_bullet_draw;				//弾の描画オブジェクト
	DrawObject m_laser_draw;				//レーザーの描画オブジェクト
	DrawObject* m_barrier_draw = nullptr;	//バリアの描画オブジェクト
	DrawObject* m_bullet_stop_draw = nullptr;	//動きを止める敵の弾の描画オブジェクト
	DrawObject* m_bullet_icerain_draw = nullptr;	//氷の敵の描画

	bool m_separation_button = false;		//切り離しボタンが押されたか
	bool m_bullet_shot = false;				//弾発射のボタンが押されたか(押している間)
	bool m_bullet_shot_trigger = false;		//弾発射のボタンが押されたか(押した時)

	Number* m_pRemaining_Num = nullptr;	//残弾数表示オブジェクト
	D3DXVECTOR2 m_Remaining_Icon_Pos = D3DXVECTOR2(0.0f, 0.0f);	//敵アイコン表示場所

//メンバ関数
public:
	//デフォルトコンストラクタ
	inhPlayerArmBoth(){}

	//引数付きコンストラクタ
	inhPlayerArmBoth(DrawObject& pDrawObject, DrawObject& pBullet, DrawObject& pLaser, const D3DXVECTOR2& pos,
		const D3DXVECTOR2& from_player, DrawObject& pDrawobNumber, D3DXVECTOR2 num_pos, D3DXVECTOR2 icon_pos)
		:GameObject(pDrawObject, pos, SIZE), m_bullet_draw(pBullet), m_laser_draw(pLaser),
		m_from_player(from_player), m_Remaining_Icon_Pos(icon_pos) 
	{
		m_pRemaining_Num = new Number(pDrawobNumber, num_pos, D3DXVECTOR2(40.0f, 60.0f), 2);
	}

	//デストラクタ
	virtual ~inhPlayerArmBoth()override 
	{
		delete m_pEnemyItem; 
		delete m_pRemaining_Num;
	}

	//更新処理
	// player_pos：プレイヤーの座標　enemy_pos：一番近い敵の座標
	void Update(const D3DXVECTOR2& player_pos, const D3DXVECTOR2& enemy_pos);

	//描画処理
	void ArmDraw(void)const;

	//腕のタイプを設定
	void SetType(TYPE type, bool newtype = true);

	//タイプを返す
	TYPE GetType(void)const { return m_type; }

	// 腕のクラスのポインタを返す
	inhPlayerArm* GetArmPointer(void)const { return m_pEnemyItem; }

	//腕のクラスのポインタのセット
	void SetArmPointer(inhPlayerArm* ArmPointer) { m_pEnemyItem = ArmPointer; }


	//切り離しボタンが押されたかフラグをセット
	void SetSeparationButton(bool flag) { m_separation_button = flag; }

	//弾発射のボタンが押されたかフラグ(押している間)をセット
	void SetBulletShotButton(bool flag) { m_bullet_shot = flag; }

	//弾発射のボタンが押されたかフラグ(押した時)をセット
	void SetBulletShotButtonTrigger(bool flag) { m_bullet_shot_trigger = flag; }

	//残弾数回復
	void HeelBullet(void) { if (m_pEnemyItem)m_pEnemyItem->HeelBullet(); }

	//隕石と当たった時に腕を消す
	void BreakShootingArm();

	//バリアの描画オブジェクトをセット
	void DrawSetBarrier(DrawObject* pDraw) { m_barrier_draw = pDraw; }

	//動きを止める敵の弾描画オブジェクトをセット
	void DrawSetBulleStop(DrawObject* pDraw) { m_bullet_stop_draw = pDraw; }

	//氷の敵の腕の描画
	void DrawSetIceRain(DrawObject* pDraw) { m_bullet_icerain_draw = pDraw; }
};

#endif // !_INH_PLAYER_ARM_BOTH_H_