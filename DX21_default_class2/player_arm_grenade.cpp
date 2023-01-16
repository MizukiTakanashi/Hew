//=================================================
// プレイヤーの腕のグレネード関係(ヘッダファイル)
// 作成日：2023/01/13
// 作成者：高梨水希
//=================================================

#include "player_arm_grenade.h"
#define _USE_MATH_DEFINES
#include <math.h>

//==========================
// 定数の初期化
//==========================
//public
const D3DXVECTOR2 PlayerArmGrenade::BULLET_SIZE = D3DXVECTOR2(21.0f, 21.0f);
const D3DXVECTOR2 PlayerArmGrenade::FIND_BULLET_SIZE = D3DXVECTOR2(20.0f, 20.0f);
const D3DXVECTOR2 PlayerArmGrenade::FIND_RANGE = D3DXVECTOR2(100.0f, 100.0f);

//private
const float PlayerArmGrenade::BULLET_SPEED = 15.0f;
const D3DXVECTOR2 PlayerArmGrenade::EXPLOSION_RANGE = D3DXVECTOR2(200.0f, 200.0f);

//==========================
// デフォルトコンストラクタ
//==========================
PlayerArmGrenade::PlayerArmGrenade()
{
	for (int i = 0; i < BULLET_SHOOT_MAX; i++) {
		m_pBullet[i] = nullptr;
		m_pExplosionDraw[i] = nullptr;
		m_attack_count[i] = -1;
	}
}

//==========================
// 引数付きコンストラクタ
//==========================
PlayerArmGrenade::PlayerArmGrenade(DrawObject bulletdraw, DrawObject explosiondraw, 
	bool right, int type)
	:inhPlayerArm(BULLET_NUM_MAX, right, type), m_bulletdraw(bulletdraw), m_explosiondraw(explosiondraw) {
	for (int i = 0; i < BULLET_SHOOT_MAX; i++) {
		m_pBullet[i] = nullptr;
		m_pExplosionDraw[i] = nullptr;
		m_attack_count[i] = -1;
	}
}

//==========================
// デストラクタ
//==========================
PlayerArmGrenade::~PlayerArmGrenade()
{
	for (int i = 0; i < BULLET_SHOOT_MAX; i++) {
		if (m_pBullet[i] != nullptr) {
			delete m_pBullet[i];
		}

		if (m_pExplosionDraw[i] != nullptr) {
			delete m_pExplosionDraw[i];
		}
	}
}

//==========================
// 更新処理
//==========================
void PlayerArmGrenade::Update(const D3DXVECTOR2& arm_pos)
{
	bool none_enemy = false;
	//狙う敵がいなかったら...
	if (inhPlayerArm::GetSomethingPos() == D3DXVECTOR2(0.0f, 0.0f)) {
		//フラグをオンにする
		none_enemy = true;
	}

	//今いる弾の処理
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		//弾の更新処理
		m_pBullet[i]->Update();

		//画面外から出たら、時間経過したら...
		if (m_pBullet[i]->GetScreenOut() || m_pBullet[i]->GetTime() > BULLET_BREAK_TIME) {
			DeleteBullet(i);
		}

		//攻撃開始していれば...
		if (m_attack_count[i] >= 0) {
			//爆発時間になったら...
			if (m_pBullet[i]->GetTime() - m_attack_count[i] > EXPLOSION_WAIT_TIME &&
				m_pExplosionDraw[i] == nullptr) {
				m_pBullet[i]->SetSize(EXPLOSION_RANGE);
				m_pExplosionDraw[i] = new Explosion(m_explosiondraw, m_pBullet[i]->GetPos());
				m_pExplosionDraw[i]->SetSize(EXPLOSION_RANGE);
			}
		}

		//爆発があれば更新処理を行う
		if (m_pExplosionDraw[i] != nullptr) {
			m_pExplosionDraw[i]->Update();

			//爆発が終わったら...
			if (m_pExplosionDraw[i]->GetEndAnimation()) {
				DeleteBullet(i);a
			}
		}
	}

	//もしも弾の制限が超えてたら弾を作らない
	if (inhPlayerArm::IsBulletUsed()) {
		return;
	}

	//発射間隔カウント
	m_interval_count++;

	//正しいボタンが押されたら
	if ((inhPlayerArm::GetRightLeft() && inhPlayerArm::IsButtonPush()) ||
		(!inhPlayerArm::GetRightLeft() && inhPlayerArm::IsButtonPush())) {
		//発射間隔が一定以上になったら
		if (m_interval_count > BULLET_INTERVAL) {
			//カウントをリセット
			m_interval_count = 0;

			//腕の切り離しと同時に弾を作らないための処理
			if (inhPlayerArm::GetBulletMaked() == BULLET_NUM_MAX - 1)
			{
				//作った弾の数を増やす
				inhPlayerArm::IncreaseBulletMaked();

				return;
			}

			D3DXVECTOR2 movTemp = D3DXVECTOR2(0.0f, -BULLET_SPEED);
			float rotTemp = 0.0f;

			//狙う敵がいなかったら何もしない(まっすぐに飛んでいく)
			if (!none_enemy) {
				//一番近い敵の後を追うようにして、弾を生成
				movTemp = inhPlayerArm::GetSomethingPos() - arm_pos;
				D3DXVECTOR2 rotposTemp = arm_pos - inhPlayerArm::GetSomethingPos();
				D3DXVec2Normalize(&movTemp, &movTemp);
				movTemp *= BULLET_SPEED;

				rotTemp = atan2(rotposTemp.y, rotposTemp.x) * (180 / M_PI) + 180.0f;
			}

			m_pBullet[inhPlayerArm::GetBulletNum()] = new Bullet(m_bulletdraw, arm_pos, 
				FIND_BULLET_SIZE, movTemp, rotTemp);

			//現在の弾の数を増やす
			inhPlayerArm::IncreaseBulletNum();

			//作った弾の数を増やす
			inhPlayerArm::IncreaseBulletMaked();
		}
	}
}

//==========================
// 描画処理
//==========================
void PlayerArmGrenade::PlayerArmDraw()const
{
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		//爆発
		if (m_pExplosionDraw[i] != nullptr) {
			m_pExplosionDraw[i]->Draw();
		}
		else {
			//弾
			m_pBullet[i]->Draw();
		}
	}
}

//==========================
// 指定した番号の弾を消す
//==========================
void PlayerArmGrenade::DeleteBullet(int index_num)
{
	if (m_pExplosionDraw[index_num] != nullptr) {
		if (!m_pExplosionDraw[index_num]->GetEndAnimation()) {
			return;
		}
	}

	delete m_pBullet[index_num];
	m_pBullet[index_num] = nullptr;

	if (m_pExplosionDraw[index_num] != nullptr) {
		delete m_pExplosionDraw[index_num];
		m_pExplosionDraw[index_num] = nullptr;
	}

	//弾を消す
	for (int i = index_num; i < inhPlayerArm::GetBulletNum() - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
		m_pBullet[i + 1] = nullptr;

		m_pExplosionDraw[i] = m_pExplosionDraw[i + 1];
		m_pExplosionDraw[i + 1] = nullptr;

		m_attack_count[i] = m_attack_count[i + 1];
		m_attack_count[i + 1] = -1;
	}
	inhPlayerArm::IncreaseBulletNum(-1);
}

//==========================================================
// アクションを起こす(指定した番号の弾の爆発をセット)
//==========================================================s
void PlayerArmGrenade::Action(int index_num)
{
	m_pBullet[index_num]->SetSize(BULLET_SIZE);
	m_attack_count[index_num] = m_pBullet[index_num]->GetTime();
	m_pBullet[index_num]->SetMove(D3DXVECTOR2(0.0f, 0.0f));
}