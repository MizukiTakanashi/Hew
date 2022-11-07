//=======================================
// 自機の右(ヘッダ)
// 作成日：2022/10/25
// 作成者：山本亮太
//=======================================
#include "player_right.h"

//#include "input.h"
#include "inputx.h"
#include "keyboard.h"

#include "player_arm_1.h"
#include "player_arm_2.h"
#include "player_arm_3.h"

//==========================
// 定数の初期化
//==========================
const D3DXVECTOR2 PlayerRight::SIZE = D3DXVECTOR2(50.0f, 50.0f);
const float PlayerRight::SHOT_SPEED = 5.0f;
const D3DXVECTOR2 PlayerRight::FROM_PLAYER_POS = D3DXVECTOR2(30.0f, 0.0f);

//==========================
// 更新処理
//==========================
void PlayerRight::Update(const D3DXVECTOR2& player_pos, const D3DXVECTOR2& enemy_pos)
{
	//パッドRボタンを押したら...
	//キーボードRを押したら...
	if (InputGetKeyDown(KK_R) || IsButtonTriggered(0, XINPUT_GAMEPAD_RIGHT_SHOULDER))
	{
		if (m_type != TYPE::TYPE_NONE && m_type != TYPE::TYPE_OLD) {
			//自分自身を発射
			m_shot = true;

			m_type = TYPE::TYPE_SHOOT;
		}
	}

	//自分自身を発射
	if (m_shot)
	{
		MovePos(D3DXVECTOR2(0.0f, -SHOT_SPEED));

		//画面外に出たら...
		if (GetScreenOut())
		{
			m_type = TYPE::TYPE_OLD;

			//位置を元に戻す
			SetPos(player_pos + FROM_PLAYER_POS);

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
		//移動
		SetPos(player_pos + FROM_PLAYER_POS);

		//腕についているアイテムの処理
		if (m_pEnemyItem != nullptr) {
			//=======================
			// 更新処理の前の処理
			//ホーミング用の敵の位置を取得(PlayerArm1)
			m_pEnemyItem->SetSomethingPos(enemy_pos);

			//ボタン押されたか判断
			switch (m_type) {

				//Arm2はトリガーになってる
			case TYPE::TYPE2:
				m_pEnemyItem->SetButtonPush(InputGetKeyDown(KK_RIGHT) ||
					GetRightTriggerTriggered(0, TRIGGER));
				break;

			default:
				m_pEnemyItem->SetButtonPush(InputGetKey(KK_RIGHT) ||
					GetRightTrigger(0) > TRIGGER);
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
}

//==========================
// 描画処理
//==========================
void PlayerRight::RightDraw(void)const
{
	//腕になにかついていれば描画
	if (m_type != TYPE::TYPE_NONE)
	{
		if (m_type != TYPE::TYPE_OLD) {
			//腕についているアイテム自身の描画
			Draw();
		}

		if (m_pEnemyItem != nullptr) {
			//腕についているアイテムの弾等描画
			m_pEnemyItem->PlayerArmDraw();
		}
	}
}

//==========================
// タイプをセット
//==========================
void PlayerRight::SetType(int type, bool newtype)
{
	//発射中であればセットしない
	if (m_shot) {
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
	m_type = (TYPE)type;

	//テクスチャをタイプに合わせてセット
	GameObject::SetAnimationNum((float)m_type - 1.0f);

	if (newtype) {
		//前のタイプのインスタンスを削除
		delete m_pEnemyItem;
		m_pEnemyItem = nullptr;

		//タイプに沿って腕のアイテムをセット
		switch (m_type) {

		case TYPE::TYPE1:
			m_pEnemyItem = new PlayerArm1(m_bullet_draw, true, (int)m_type - 1);
			break;

		case TYPE::TYPE2:
			m_pEnemyItem = new PlayerArm2(m_laser_draw, true, (int)m_type - 1);
			break;

		case TYPE::TYPE3:
			m_pEnemyItem = new PlayerArm3(m_bullet_draw, true, (int)m_type - 1);
			break;

		default:
			break;
		}
	}
}