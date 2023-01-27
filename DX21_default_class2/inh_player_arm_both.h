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
#include "sound.h"

class inhPlayerArmBoth :public GameObject
{
	//定数
public:
	//腕につく敵のタイプ
	enum class TYPE :int
	{
		TYPE_HOMING,	//ホーミング
		TYPE_LASER,		//レーザー
		TYPE_GATORING,	//ガトリング
		TYPE_BARRIAR,	//バリア
		TYPE_STOP,		//動きを止める
		TYPE_ICERAIN,	//氷の敵
		TYPE_GRENADE,	//グレネード敵
		TYPE_FIRE,		//炎の敵
		TYPE_ACID,		//酸性雨
		TYPE_FIREBALL,	//炎の弾の敵
		TYPE_NONE,	//	何もついていない
		TYPE_SHOOT,	// 前のタイプの弾の処理 & 自身発射中
		TYPE_DM_SHOOT,	//ダメージをくらった時の
		TYPE_OLD,	// 前のタイプの弾の処理中
		TYPE_NUM,
	};

	//定数
private:
	//cppで初期化
	static const D3DXVECTOR2 SIZE;				//サイズ
	static const float SHOT_SPEED;				//切り離し発射スピード

	//メンバ変数
private:
	D3DXVECTOR2 m_from_player = D3DXVECTOR2(0.0f, 0.0f);	//プレイヤーからどれくらい離れているか

	bool m_shot = false;					//自分自身が発射されてるか否か

	//弾
	DrawObject* m_bullet_draw = nullptr;		//弾の描画オブジェクト
	DrawObject* m_laser_draw = nullptr;			//レーザーの描画オブジェクト
	DrawObject* m_barrier_draw = nullptr;		//バリアの描画オブジェクト
	DrawObject* m_bullet_stop_draw = nullptr;	//動きを止める敵の弾の描画オブジェクト
	DrawObject* m_bullet_icerain_draw = nullptr;//氷の敵の描画
	DrawObject* m_bullet_fire_draw = nullptr;	//氷の敵の描画
	DrawObject* m_bullet_acid_draw = nullptr;	//氷の敵の描画
	DrawObject* m_bullet_fireball_draw = nullptr;	//氷の敵の描画
	
	//敵
	DrawObject* m_enemy_homing_draw = nullptr;	//弾の描画オブジェクト
	DrawObject* m_enemy_gatoring_draw = nullptr;//弾の描画オブジェクト
	DrawObject* m_enemy_laser_draw = nullptr;	//レーザーの描画オブジェクト
	DrawObject* m_enemy_barrier_draw = nullptr;	//バリアの描画オブジェクト
	DrawObject* m_enemy_stop_draw = nullptr;	//動きを止める敵の弾の描画オブジェクト
	DrawObject* m_enemy_icerain_draw = nullptr;	//氷の敵の描画
	DrawObject* m_enemy_grenade_draw = nullptr;	//グレネードの敵の描画
	DrawObject* m_enemy_fire_draw = nullptr;	//炎の敵の描画
	DrawObject* m_enemy_fireball_draw = nullptr;	//炎の敵の描画
	DrawObject* m_enemy_acid_draw = nullptr;	//炎の敵の描画

	DrawObject m_explosion_draw;			//爆発の描画オブジェクト

	bool m_separation_button = false;		//切り離しボタンが押されたか
	bool m_bullet_shot = false;				//弾発射のボタンが押されたか(押している間)
	bool m_bullet_shot_trigger = false;		//弾発射のボタンが押されたか(押した時)

	bool m_right = false;					//腕の右か左についているか

	bool m_hit_stop = false;				//合体したときのヒットストップ
	int m_SE_25 = 0;						//合体音

protected:
	static const D3DXVECTOR2 ICON_SIZE;			//敵アイコンの表示場所

	TYPE m_type = TYPE::TYPE_NONE;			//ついた敵のタイプ
	inhPlayerArm* m_pEnemyItem = nullptr;	//腕についている敵のクラス
	Number* m_pRemaining_Num = nullptr;	//残弾数表示オブジェクト
	D3DXVECTOR2 m_Remaining_Icon_Pos = D3DXVECTOR2(0.0f, 0.0f);	//敵アイコン表示場所


//メンバ関数
public:
	//デフォルトコンストラクタ
	inhPlayerArmBoth(){}

	//引数付きコンストラクタ
	inhPlayerArmBoth(const D3DXVECTOR2& pos,
		const D3DXVECTOR2& from_player, DrawObject& pDrawobNumber, D3DXVECTOR2 num_pos, D3DXVECTOR2 icon_pos,
		bool right = false)
		:GameObject(pDrawobNumber, pos, SIZE), m_from_player(from_player), m_Remaining_Icon_Pos(icon_pos), 
		m_right(right)
	{
		m_pRemaining_Num = new Number(pDrawobNumber, num_pos, D3DXVECTOR2(30.0f, 40.0f), 2);
		m_SE_25 = LoadSound((char*)"data\\SE\\_25.wav");
		SetVolume(m_SE_25, 0.5f);
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
	virtual void ArmDraw(void)const;

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

	//合体し、ヒットストップするか返す
	bool IsHitStop(void)const { return m_hit_stop; }

	//合体し、ヒットストップするかをセット
	void SetHitStop(bool hit_stop) { m_hit_stop = hit_stop; }


	//====================
	// 弾
	//丸い弾の描画オブジェクトをセット
	void DrawSetSurcleBullet(DrawObject* pDraw) { m_bullet_draw = pDraw; }

	//レーザーの描画オブジェクトをセット
	void DrawSetLaser(DrawObject* pDraw) { m_laser_draw = pDraw; }

	//バリアの描画オブジェクトをセット
	void DrawSetBarrier(DrawObject* pDraw) { m_barrier_draw = pDraw; }

	//動きを止める敵の弾描画オブジェクトをセット
	void DrawSetBulleStop(DrawObject* pDraw) { m_bullet_stop_draw = pDraw; }

	//氷の敵の弾の描画
	void DrawSetIceRain(DrawObject* pDraw) { m_bullet_icerain_draw = pDraw; }

	//炎の敵の弾の描画
	void DrawSetFire(DrawObject* pDraw) { m_bullet_fire_draw = pDraw; }

	//酸性雨の敵の弾の描画
	void DrawSetAcid(DrawObject* pDraw) { m_bullet_acid_draw = pDraw; }

	//酸性雨の敵の弾の描画
	void DrawSetFireBall(DrawObject* pDraw) { m_bullet_fireball_draw = pDraw; }


	//========================
	// 敵
	//ホーミングの敵の腕の描画
	void DrawSetHomingE(DrawObject* pDraw) { m_enemy_homing_draw = pDraw; }

	//レーザーの敵の腕の描画
	void DrawSetLaserE(DrawObject* pDraw) { m_enemy_laser_draw = pDraw; }

	//ガトリングの敵の腕の描画
	void DrawSetGatoringE(DrawObject* pDraw) { m_enemy_gatoring_draw = pDraw; }

	//バリアの敵の腕の描画
	void DrawSetBarriarE(DrawObject* pDraw) { m_enemy_barrier_draw = pDraw; }

	//STOPの敵の腕の描画
	void DrawSetStopE(DrawObject* pDraw) { m_enemy_stop_draw = pDraw; }

	//氷の敵の腕の描画
	void DrawSetIceRainE(DrawObject* pDraw) { m_enemy_icerain_draw = pDraw; }

	//グレネードの敵の腕の描画
	void DrawSetGrenadeE(DrawObject* pDraw) { m_enemy_grenade_draw = pDraw; }

	//炎の敵の腕の描画
	void DrawSetFireE(DrawObject* pDraw) { m_enemy_fire_draw = pDraw; }

	//爆発の描画セット
	void DrawSetExplosion(DrawObject& pDraw) { m_explosion_draw = pDraw; }

	//爆発の描画セット
	void DrawSetFireballE(DrawObject* pDraw) { m_enemy_fireball_draw = pDraw; }

	//爆発の描画セット
	void DrawSetAcidE(DrawObject* pDraw) { m_enemy_acid_draw = pDraw; }
};

#endif // !_INH_PLAYER_ARM_BOTH_H_