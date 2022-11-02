//=======================================
// 自機の左(ヘッダ)
// 作成日：2022/10/25
// 作成者：小西 蓮
//=======================================
#include "playerleft.h"
#include "input.h"

#include "PlayerArm1.h"
#include "PlayerArm2.h"
#include "PlayerArm3.h"

//==========================
// 定数の初期化
//==========================
const float PlayerLeft::SHOT_SPEED = 5.0f;
const D3DXVECTOR2 PlayerLeft::FROM_PLAYER_POS = D3DXVECTOR2(-30.0f, 0.0f);

//==========================
// 更新処理
//==========================
void PlayerLeft::Update(const D3DXVECTOR2& player_pos, const D3DXVECTOR2& enemy_pos)
{
	//  Rキーを押すと腕に装着している敵を発射する
	if (GetKeyboardTrigger(DIK_E))	
	{
		m_shot = true;	// 発射した
	}

	// 自分自身を発射する
	if (m_shot)
	{
		MovePos(D3DXVECTOR2(0.0f, -SHOT_SPEED));	// 動く際に必要
		
		// 画面外に出たら...
		if (GetScreenOut())
		{
			//TYPEを元に戻す
			m_type = TYPE::TYPE_NONE;
			
			//位置を元に戻す
			SetPos(player_pos);
			
			//発射のフラグをオフ
			m_shot = false;
		}
	}
	//発射以外の時はプレイヤーの横について弾を発射する
	else
	{
		// 移動
		SetPos(player_pos + FROM_PLAYER_POS);

		if (m_pEnemyItem != nullptr) {
			//更新処理の前の各々の処理
			switch (m_type) {

			case TYPE::TYPE1:
				//ホーミング用の敵の位置を取得
				m_pEnemyItem->SetSomethingPos(enemy_pos);
				break;

			default:
				break;
			}

			//腕についてるアイテムの処理
			m_pEnemyItem->Update(GameObject::GetPos());
		}
	}
}

//==========================
// 描画処理
//==========================
void PlayerLeft::LeftDraw(void)const
{
	//腕になにかついていれば描画
	if (m_type != TYPE::TYPE_NONE)
	{
		Draw();

		if (m_pEnemyItem != nullptr) {
			//腕についているアイテムの描画
			m_pEnemyItem->PlayerArmDraw();
		}
	}
}

void PlayerLeft::SetType(int type)
{
	//発射中であればセットしない
	if (m_shot) {
		return;
	}

	//前のタイプのインスタンスを削除
	delete m_pEnemyItem;
	m_pEnemyItem = nullptr;

	//タイプをセット
	m_type = (TYPE)type;

	//テクスチャをタイプに合わせてセット
	GameObject::SetAnimationNum((float)m_type - 1.0f);

	//タイプに沿って腕のアイテムをセット
	switch (m_type) {

	case TYPE::TYPE1:
		m_pEnemyItem = new PlayerArm1(m_bullet_draw, false);
		break;

	case TYPE::TYPE2:
		m_pEnemyItem = new PlayerArm2(m_laser_draw, false);
		break;

	case TYPE::TYPE3:
		m_pEnemyItem = new PlayerArm3(m_bullet_draw, false);
		break;

	default:
		break;
	}
}