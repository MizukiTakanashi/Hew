//=======================================
// プレイヤーHP関係(cppファイル)
// 作成日：2022/09/17
// 作成者：高梨水希
//=======================================
#include "player_hp.h"
#include "game.h"
#include "sound.h"

//==========================
// 定数初期化
//==========================
const float PlayerHP::HP_MAX = 3.0f;
const float PlayerHP::SIZE_X = 200.0f;
const float PlayerHP::SIZE_Y = 25.0f;
const float PlayerHP::POS_X = 30;
const float PlayerHP::POS_Y = 30;
const float PlayerHP::BET_X = 40;

//==========================
// 引数付きコンストラクタ
//==========================
PlayerHP::PlayerHP(DrawObject& DrawObject1, ExplosionManagement* pEM, Player* pPlayer)
	:UI(DrawObject1, D3DXVECTOR2(POS_X, POS_Y),D3DXVECTOR2(SIZE_X, SIZE_Y)), 
	m_pExplosionManagement(pEM), m_pPlayer(pPlayer)
{
	//プレイヤーダメージ音
	m_SE_04 = LoadSound((char*)"data\\SE\\1_04_2.wav");
	//SetVolume(g_SE, 0.1f);
}

//==========================
// HPを減らす
//==========================
void PlayerHP::ReduceHP(float reduce_num)
{
	//無敵かどうか
	if (m_invincible > 0)
	{//無敵
		return;
	}
	else
	{//無敵じゃない
		m_hp -= reduce_num;

		//ヒットストップ
		HitStop(30);
		SetInvincibleFrame();

		PlaySound(m_SE_04, 0);
	}

	//もしもHPが0であれば
	if (m_hp <= 0) {
		m_hp = 0;
		m_HP0 = true;
		return;
	}
}
//=====================================
// 回復処理
//=====================================
void PlayerHP::HeelHP(float heel_num)
{
	//回復処理
	m_hp += heel_num;
}

//==========================
// 更新処理
//==========================
void PlayerHP::Update(void)
{
	if (m_hp < 3)
	{//HPが少なくなったら
		//プレイヤーの見た目変更
		m_pPlayer->SetAnimationNum(2);
	}

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
	for (int i = 0; i < m_hp; i++)
	{
		UI::Draw(D3DXVECTOR2(POS_X  + i * BET_X, POS_Y), D3DXVECTOR2(40, 40));
	}
}