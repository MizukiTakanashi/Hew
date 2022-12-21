//=======================================
// プレイヤーの腕1関係(cppファイル)
// 作成日：2022/10/30
// 作成者：高梨水希
//=======================================
#include "player_arm_barrier.h"

//==========================
// 定数の初期化
//==========================
const float PlayerArmBarrier::BULLET_SIZE_X = 80.0f;
const float PlayerArmBarrier::BULLET_SIZE_Y = 10.0f;
const D3DXVECTOR2 PlayerArmBarrier::RIGHT_BARRIER_INTERVAL_POS = D3DXVECTOR2(-30.0f, -45.0f);
const D3DXVECTOR2 PlayerArmBarrier::LEFT_BARRIER_INTERVAL_POS = D3DXVECTOR2(30.0f, -45.0f);

//==========================
// 更新処理
//==========================
void PlayerArmBarrier::Update(const D3DXVECTOR2& arm_pos)
{
	//バリアの処理
	if (inhPlayerArm::GetBulletNum() == 1) {
		//ついているのが右であれば
		if (inhPlayerArm::GetRightLeft()) {
			m_pBullet->SetPos(arm_pos + RIGHT_BARRIER_INTERVAL_POS);
		}
		//左であれば
		else {
			m_pBullet->SetPos(arm_pos + LEFT_BARRIER_INTERVAL_POS);
		}
	}

	//もしも弾の制限が超えてたらバリアを作らない
	//バリアがもうすでに作られていたら
	if (inhPlayerArm::IsBulletUsed() || inhPlayerArm::GetBulletNum() == 1) {
		return;
	}

	//ボタンが押されたら
	if ((inhPlayerArm::GetRightLeft() && inhPlayerArm::IsButtonTrigger()) ||
		(!inhPlayerArm::GetRightLeft() && inhPlayerArm::IsButtonTrigger())) {
		//腕の切り離しと同時に弾を作らないための処理
		if (inhPlayerArm::GetBulletMaked() == BULLET_NUM_MAX - 1)
		{
			//作った弾の数を増やす
			inhPlayerArm::IncreaseBulletMaked();

			return;
		}

		//バリアを作る
		m_pBullet = new Bullet(m_bulletdraw, arm_pos,
			D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0.0f, 0.0f), 0.0f);

		//現在の弾の数を増やす
		inhPlayerArm::IncreaseBulletNum();

		//作った弾の数を増やす
		inhPlayerArm::IncreaseBulletMaked();
	}
}

//==========================
// 描画処理
//==========================
void PlayerArmBarrier::PlayerArmDraw()const
{
	if (inhPlayerArm::GetBulletNum() == 1) {
		m_pBullet->Draw();
	}
}

//==========================
// 指定した番号の弾を消す
//==========================
void PlayerArmBarrier::DeleteBullet(int index_num)
{
	//弾を消す
	delete m_pBullet;

	inhPlayerArm::IncreaseBulletNum(-1);
}
