//=======================================
// プレイヤー関係(cppファイル)
// 作成日：2022/06/27
// 作成者：高梨水希
//=======================================
#include "player.h"

//#include "input.h"
#include "inputx.h"
#include "keyboard.h"

#include "screen_out.h"
#include "player_hp.h"

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
const float Player::BULLET_SIZE_X = 15.0f;
const float Player::BULLET_SIZE_Y = 40.0f;
const float Player::BULLET_SPEED_X = 0.0f;
const float Player::BULLET_SPEED_Y = -10.5f;
const float Player::BOM_SIZE_X = 1260.0f;
const float Player::BOM_SIZE_Y = 720.0f;
const D3DXCOLOR Player::INVINCIBLE__COLOR = D3DXCOLOR(1.0f, 0.3f, 0.3f, 1.0f);			//プレイヤー無敵時間の色
int a = 0;
int b = 0;
int Bom_Count = 0;
//======================
// 更新処理
//======================
void Player::Update(bool isinvincible)
{
	D3DXVECTOR2 temp = D3DXVECTOR2(0.0f, 0.0f);

	//==========================
	// パッド

	//左スティックで上に倒されたら...
	if (GetThumbLeftY(0) > 0) {
		//上に行く
		temp.y -= SPEED_Y * GetThumbLeftY(0);
	}
	//左スティックで下に倒されたら...
	if (GetThumbLeftY(0) < 0) {
		//下に行く
		temp.y += SPEED_Y * -GetThumbLeftY(0);
	}
	//左スティックで左に倒されたら...
	if (GetThumbLeftX(0) < 0) {
		//左に行く
		temp.x += SPEED_X * GetThumbLeftX(0);
	}
	//左スティックで右に倒されたら...
	if (GetThumbLeftX(0) > 0) {
		//右に行く
		temp.x += SPEED_X * GetThumbLeftX(0);
	}

	//十字キー上が押されたら
	if (IsButtonPressed(0, XINPUT_GAMEPAD_DPAD_UP)) {
		temp.y -= SPEED_Y;
	}
	//十字キー下が押されたら
	if (IsButtonPressed(0, XINPUT_GAMEPAD_DPAD_DOWN)) {
		temp.y += SPEED_Y;
	}
	//十字キー左が押されたら
	if (IsButtonPressed(0, XINPUT_GAMEPAD_DPAD_LEFT)) {
		temp.x -= SPEED_X;
	}
	//十字キー右が押されたら
	if (IsButtonPressed(0, XINPUT_GAMEPAD_DPAD_RIGHT)) {
		temp.x += SPEED_X;
	}

	//==========================
	// キーボード

	//上矢印が押されたら
	if (InputGetKey(KK_W)) {
		temp.y -= SPEED_Y;
	}
	//下矢印が押されたら
	if (InputGetKey(KK_S)) {
		temp.y += SPEED_Y;
	}
	//左矢印が押されたら
	if (InputGetKey(KK_A)) {
		temp.x -= SPEED_X;
	}
	//右矢印が押されたら
	if (InputGetKey(KK_D)) {
		temp.x += SPEED_X;
	}

	if (temp.x != 0.0f || temp.y != 0.0f)
	{//移動してたら
		//アニメーションセット
		Player::SetAnimationNum(0);
	}
	else
	{//移動してなかったら
		//アニメーションセット
		Player::SetAnimationNum(1);
	}

	//正規化
	D3DXVec2Normalize(&temp, &temp);
	temp *= SPEED;

	//移動
	GameObject::MovePos(temp);

	//画面内に戻す
	SetPos(ScreenOut::GetScreenIn(GameObject::GetPos(), D3DXVECTOR2(BOX_W, BOX_H)));


	//======================
	// 弾

	m_BulletInterval++;
	//パッドのAが押されたら、又はキーボードのスペースが押されたら...
	//なおかつ発射間隔が指定の値を超えたら弾を生成
	if ((InputGetKey(KK_SPACE) || IsButtonPressed(0, XINPUT_GAMEPAD_A)) &&
		m_BulletInterval > BULLET_INTERVAL_TIME) {
		m_BulletInterval = 0;
		
		if (m_BulletNum < BULLET_MAX_NUM) {
			Bullet temp(m_BulletDrawObject, GameObject::GetPos(), D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y),
				D3DXVECTOR2(BULLET_SPEED_X, BULLET_SPEED_Y), 0.0f);
			m_pBullet[m_BulletNum] = temp;
			m_BulletNum++;
		}

	}
	if ((InputGetKeyDown(KK_ENTER)))
	{
		Bom_Count++;
		if (Bom_Count < 4) {
			if (m_BomNum < BOM_MAX_NUM) {
				Bom temp1(m_BomDrawObject, D3DXVECTOR2(BOM_SIZE_X / 2, BOM_SIZE_Y / 2), D3DXVECTOR2(BOM_SIZE_X, BOM_SIZE_Y),
					0.0f);
				m_pBom[m_BomNum] = temp1;
				m_BomNum++;
			}
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

	a++;
	for (int i = 0; i < m_BomNum; i++)
	{
		m_pBom[i].Update();
		if (b == 0)
		{
			DeleteBom(i);
		}
	}
	b = a % 60;

	//無敵時間は色変更
	if (isinvincible)
	{//無敵じゃない
		SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	}
	else
	{//無敵
		SetColor(INVINCIBLE__COLOR);
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
//==========================
// 爆弾の描画処理
//==========================
void Player::DrawBom(void)const
{
	for (int i = 0; i < m_BomNum; i++) {
		m_pBom[i].Draw();
	}
}

//==========================
// 爆弾を消す
//==========================
void Player::DeleteBom(int index_num)
{
	for (int i = index_num; i < m_BomNum - 1; i++) {
		m_pBom[i] = m_pBom[i + 1];
	}
	m_BomNum--;
}