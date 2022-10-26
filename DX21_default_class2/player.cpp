//=======================================
// プレイヤー関係(cppファイル)
// 作成日：2022/06/27
// 作成者：高梨水希
//=======================================
#include "player.h"
#include "input.h"
#include "ScreenOut.h"

//==========================
// 定数の初期化
//==========================
const float Player::BOX_W = 75.0f;
const float Player::BOX_H = 75.0f;
const float Player::START_POS_X = (SCREEN_WIDTH / 2);
const float Player::START_POS_Y = (SCREEN_HEIGHT / 2);
const float Player::SPEED_X = 20.0f;
const float Player::SPEED_Y = 20.0f;
const float Player::SPEED = 10.0f;
const float Player::BULLET_SIZE_X = 40.0f;
const float Player::BULLET_SIZE_Y = 40.0f;
const float Player::BULLET_SPEED_X = 0.0f;
const float Player::BULLET_SPEED_Y = -10.5f;

//======================
// 更新処理
//======================
void Player::Update()
{
	D3DXVECTOR2 temp = D3DXVECTOR2(0.0f, 0.0f);

	//上矢印が押されたら
	if (GetKeyboardPress(DIK_W)) {
		temp.y -= SPEED_Y;
	}
	//下矢印が押されたら
	if (GetKeyboardPress(DIK_S)) {
		temp.y += SPEED_Y;
	}
	//左矢印が押されたら
	if (GetKeyboardPress(DIK_A)) {
		temp.x -= SPEED_X;
	}
	//右矢印が押されたら
	if (GetKeyboardPress(DIK_D)) {
		temp.x += SPEED_X;
	}

	//正規化
	D3DXVec2Normalize(&temp, &temp);
	temp *= SPEED;

	//移動
	GameObject::MovePos(temp);

	//画面外に出たら
	if (GameObject::GetScreenOut()) {
		//画面内に戻す
		ScreenOut::GetScreenIn(GameObject::GetPos(), D3DXVECTOR2(BOX_W, BOX_H));
	}


	//======================
	// 弾

	m_BulletInterval++;
	//スペースが押された + 発射間隔が指定の値を超えたら弾を生成
	if (GetKeyboardPress(DIK_SPACE) && m_BulletInterval > BULLET_INTERVAL_TIME) {
		m_BulletInterval = 0;

		if (m_BulletNum < BULLET_MAX_NUM) {
			Bullet temp(m_BulletDrawObject, GameObject::GetPos(), D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y),
				D3DXVECTOR2(BULLET_SPEED_X, BULLET_SPEED_Y), 0.0f);
			m_pBullet[m_BulletNum] = temp;
			m_BulletNum++;
		}
	}

	for (int i = 0; i < m_BulletNum; i++) {
		m_pBullet[i].Update();

		//画面外に出たら
		if (m_pBullet[i].GetScreenOut()) {
			//弾を消す
			DeleteBullet(i);
		}
	}
}

//==========================
// 弾の描画処理
//==========================
void Player::DrawBullet(void)const
{
	for (int i = 0; i < m_BulletNum; i++) {
		m_pBullet[i].Draw();
	}
}

//==========================
// 弾を消す
//==========================
void Player::DeleteBullet(int index_num)
{
	for (int i = index_num; i < m_BulletNum - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	m_BulletNum--;
}