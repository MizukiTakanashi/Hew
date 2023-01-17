//===================================================
// プレイヤーの腕の右左関係(継承用)(cppファイル)
// 作成日：2022/11/08
// 作成者：高梨水希
//===================================================
#include "inh_player_arm_both.h"
#include "player_arm_1.h"
#include "player_arm_2.h"
#include "player_arm_3.h"
#include "player_arm_barrier.h"
#include "player_arm_stop.h"
#include "player_arm_icerain.h"
#include "player_arm_grenade.h"

//==========================
// 定数の初期化
//==========================
const D3DXVECTOR2 inhPlayerArmBoth::SIZE = D3DXVECTOR2(50.0f, 50.0f);
const float inhPlayerArmBoth::SHOT_SPEED = 5.0f;
const D3DXVECTOR2 inhPlayerArmBoth::ICON_SIZE = D3DXVECTOR2(50.0f, 50.0f);


//==========================
// 更新処理
//==========================
void inhPlayerArmBoth::Update(const D3DXVECTOR2& player_pos, const D3DXVECTOR2& enemy_pos)
{
	int hp_reduce = 0;

	//パッドLボタンを押したら...
	//キーボードEを押したら...
	if (m_separation_button)
	{
		if (m_type != TYPE::TYPE_NONE && m_type != TYPE::TYPE_OLD) {
			//自分自身を発射
			m_shot = true;

			//弾が出しきったフラグをセット
			if (m_pEnemyItem)
			{
				m_pEnemyItem->SetBulletUsed(true);
			}
			m_type = TYPE::TYPE_SHOOT;

		}
	}

	// 自分自身を発射する
	if (m_shot)
	{
		MovePos(D3DXVECTOR2(0.0f, -SHOT_SPEED));	// 動く際に必要

		// 画面外に出たら...
		if (GetScreenOut())
		{
			m_type = TYPE::TYPE_OLD;

			//位置を元に戻す
			SetPos(player_pos + m_from_player);

			//発射のフラグをオフ
			m_shot = false;
		}

		//もしも前のタイプの弾が残っていたら
		if (m_type == TYPE::TYPE_SHOOT) {
			//腕についているアイテムの処理
			if (m_pEnemyItem != nullptr) {
				//ホーミング用の敵の位置を取得(PlayerArm1)
				m_pEnemyItem->SetSomethingPos(enemy_pos);

				//腕についてるアイテムの処理
				m_pEnemyItem->Update(GameObject::GetPos());
			}
		}
	}
	//発射以外の時はプレイヤーの横について弾を発射する
	else
	{
		// 移動
		SetPos(player_pos + m_from_player);

		//腕についているアイテムの処理
		if (m_pEnemyItem != nullptr) {
			//=======================
			// 更新処理の前の処理
			//ホーミング用の敵の位置を取得(PlayerArm1)
			m_pEnemyItem->SetSomethingPos(enemy_pos);

			//m_pEnemyItem->SetButtonTrigger(false);
			//m_pEnemyItem->SetButtonPush(false);
			//ボタン押されたか判断
			switch (m_type) {

				//Arm2はトリガーになってる
			case TYPE::TYPE_LASER:
				m_pEnemyItem->SetButtonTrigger(m_bullet_shot_trigger);
				break;

			case TYPE::TYPE_BARRIAR:
				m_pEnemyItem->SetButtonTrigger(m_bullet_shot_trigger);
				break;

			default: 
				m_pEnemyItem->SetButtonPush(m_bullet_shot);
				break;
			}


			//腕についてるアイテムの処理
			m_pEnemyItem->Update(GameObject::GetPos());

			//弾を使い切ったら切り離す
			if (m_pEnemyItem->IsBulletUsed() && m_type != TYPE::TYPE_OLD && m_type != TYPE::TYPE_SHOOT) {
				m_shot = true;
				m_type = TYPE::TYPE_SHOOT;
			}
		}
	}

	//残弾数を更新
	if (m_pRemaining_Num && m_pEnemyItem)
	{
		m_pRemaining_Num->SetNumber(m_pEnemyItem->GetRemainingBullet());
	}

}

//==========================
// 描画処理
//==========================
void inhPlayerArmBoth::ArmDraw(void) const
{
	//腕になにかついていれば描画
	if (m_type != TYPE::TYPE_NONE)
	{
		if (m_type != TYPE::TYPE_OLD) {
			//腕についているアイテム自身の描画
			Draw();
			//残弾数横の敵アイコン表示
			Draw(m_Remaining_Icon_Pos, ICON_SIZE);
		}

		if (m_pEnemyItem != nullptr) {
			//腕についているアイテムの弾等描画
			m_pEnemyItem->PlayerArmDraw();
			if (m_type != TYPE::TYPE_OLD)
			{
				m_pRemaining_Num->DrawNumber();
			}
		}

	}


	if (m_pRemaining_Num)
	{
	}
}

//==========================
// 腕のタイプを設定
//==========================
void inhPlayerArmBoth::SetType(TYPE type, bool newtype)
{
	//発射中であればセットしない
	if (m_shot/*m_type == TYPE::TYPE_SHOOT*/) {
		return;
	}

	//既にタイプがついていればセットしない
	if (m_type != TYPE::TYPE_NONE && m_type != TYPE::TYPE_OLD) {
		//newtypeがfalseなら強制的にタイプをセット（playaer_arm_change用）
		if (newtype) {
			return;
		}
	}

	//タイプをセット
	m_type = type;

	//発射中をセットされた場合はテクスチャを変えない
	if (m_type != TYPE::TYPE_SHOOT) {

	}//発射中をセットされた場合は発射中のフラグをオン
	else {
		//弾が出しきったフラグをセット
		if (m_pEnemyItem)
		{
			m_pEnemyItem->SetBulletUsed(true);
		}
		m_shot = true;
	}

	//newtypeがfalseならインスタンスは消さないで保存（playaer_arm_change用）
	if (newtype) {
		//前のタイプのインスタンスを削除
		delete m_pEnemyItem;
		m_pEnemyItem = nullptr;

		//タイプに沿って腕のアイテムをセット
		switch (m_type) {

		case TYPE::TYPE_HOMING:
			m_pEnemyItem = new PlayerArm1(*m_bullet_draw, false, (int)m_type - 1);
			GameObject::SetDrawob(*m_enemy_homing_draw);
			break;

		case TYPE::TYPE_LASER:
			m_pEnemyItem = new PlayerArm2(*m_laser_draw, false, (int)m_type - 1);
			GameObject::SetDrawob(*m_enemy_laser_draw);

			break;

		case TYPE::TYPE_GATORING:
			m_pEnemyItem = new PlayerArm3(*m_bullet_draw, false, (int)m_type - 1);
			GameObject::SetDrawob(*m_enemy_gatoring_draw);

			break;

		case TYPE::TYPE_BARRIAR:
			m_pEnemyItem = new PlayerArmBarrier(*m_barrier_draw, false, (int)m_type - 1);
			GameObject::SetDrawob(*m_enemy_barrier_draw);

			break;

		case TYPE::TYPE_STOP:
			m_pEnemyItem = new PlayerArmStop(*m_bullet_stop_draw, false, (int)m_type - 1);
			GameObject::SetDrawob(*m_enemy_stop_draw);

			break;

		case TYPE::TYPE_ICERAIN:
			m_pEnemyItem = new PlayerArmIceRain(*m_enemy_icerain_draw, false, (int)m_type - 1);
			GameObject::SetDrawob(*m_enemy_icerain_draw);

			break;

		case TYPE::TYPE7:
			m_pEnemyItem = new PlayerArmGrenade(*m_bullet_draw, m_explosion_draw, false, (int)m_type - 1);
			GameObject::SetDrawob(*m_enemy_homing_draw);


		default:
			break;
		}
	}
}

void inhPlayerArmBoth::BreakShootingArm()
{
	//タイプをセット
	m_type = TYPE::TYPE_NONE;

	delete m_pEnemyItem;
	m_pEnemyItem = nullptr;
}
