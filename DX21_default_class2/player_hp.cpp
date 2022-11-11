//=======================================
// プレイヤーHP関係(cppファイル)
// 作成日：2022/09/17
// 作成者：高梨水希
//=======================================
#include "player_hp.h"

//==========================
// 定数初期化
//==========================
const float PlayerHP::HP_MAX = 1.0f;
const float PlayerHP::SIZE_X = 200.0f;
const float PlayerHP::SIZE_Y = 25.0f;
const float PlayerHP::FLAME_SIZE_X = 205.0f;
const float PlayerHP::FLAME_SIZE_Y = 30.0f;
const float PlayerHP::POS_SPACE_X = 20.0f;
const float PlayerHP::POS_SPACE_Y = 20.0f;
const float PlayerHP::POS_X = (PlayerHP::SIZE_X / 2 + PlayerHP::POS_SPACE_X);
const float PlayerHP::POS_Y = (PlayerHP::SIZE_Y / 2 + PlayerHP::POS_SPACE_Y);
const int PlayerHP::INVINCIBLE__FRAME = 30;	//無敵時間


//==========================
// HPを減らす
//==========================
void PlayerHP::ReduceHP(float reduce_num, D3DXVECTOR2 ppos)
{
	//無敵かどうか
	if (m_invincible > 0)
	{//無敵
		return;
	}
	else
	{//無敵じゃない
		m_hp -= reduce_num;
		//爆発をセット
		m_pExplosionManagement->SetExplosion(ppos);
		//コンボを途切れさせる
		m_pNumber->InitCombo();
		SetInvincibleFrame();
	}

	//もしもHPが0であれば
	if (m_hp <= 0) {
		m_hp = 0;
		m_HP0 = true;
		return;
	}

	//HPバーのサイズ、位置の変更
	float tempXsize = SIZE_X * (m_hp / HP_MAX);
	UI::SetSize(D3DXVECTOR2(tempXsize, SIZE_Y));
	UI::SetPos(D3DXVECTOR2(tempXsize / 2 + POS_SPACE_X, POS_Y));
}
//=====================================
//回復処理
//=====================================
void PlayerHP::HeelHP(float heel_num, D3DXVECTOR2 ppos)
{
	//回復処理
	m_hp += heel_num;
	//HPバーのサイズ、位置の変更
	float tempXsize = SIZE_X * (m_hp / HP_MAX);
	UI::SetSize(D3DXVECTOR2(tempXsize, SIZE_Y));
	UI::SetPos(D3DXVECTOR2(tempXsize / 2 + POS_SPACE_X, POS_Y));
}

//==========================
// 更新処理
//==========================
void PlayerHP::Update(void)
{
	//無敵時間減少
	if (m_invincible > 0)
	{
		m_invincible--;
	}

}
//==========================
// 描画処理
//==========================
void PlayerHP::DrawHP(void)const
{
	if (!m_HP0) {
		//HPバーを描画
		UI::Draw();
	}

	//フレームを描画
	m_frame_DrawObject.Draw(D3DXVECTOR2(POS_X, POS_Y), D3DXVECTOR2(FLAME_SIZE_X, FLAME_SIZE_Y));
}