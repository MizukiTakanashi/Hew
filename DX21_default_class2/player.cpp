//=======================================
// ƒvƒŒƒCƒ„[ŠÖŒW(cppƒtƒ@ƒCƒ‹)
// ì¬“úF2022/06/27
// ì¬ŽÒF‚—œ…Šó
//=======================================
#include "player.h"
#include "input.h"
#include "screen_out.h"
#include "player_hp.h"

//==========================
// ’è”‚Ì‰Šú‰»
//==========================
const float Player::BOX_W = 75.0f;
const float Player::BOX_H = 75.0f;
const float Player::START_POS_X = (SCREEN_WIDTH / 2);
const float Player::START_POS_Y = (SCREEN_HEIGHT / 2);
const float Player::SPEED_X = 20.0f;
const float Player::SPEED_Y = 20.0f;
const float Player::SPEED = 10.0f;
const float Player::BULLET_SIZE_X = 15.0f;
const float Player::BULLET_SIZE_Y = 30.0f;
const float Player::BULLET_SPEED_X = 0.0f;
const float Player::BULLET_SPEED_Y = -10.5f;

const D3DXCOLOR Player::INVINCIBLE__COLOR = D3DXCOLOR(1.0f, 0.3f, 0.3f, 1.0f);			//ƒvƒŒƒCƒ„[–³“GŽžŠÔ‚ÌF


//======================
// XVˆ—
//======================
void Player::Update(bool isinvincible)
{
	D3DXVECTOR2 temp = D3DXVECTOR2(0.0f, 0.0f);

	//ã–îˆó‚ª‰Ÿ‚³‚ê‚½‚ç
	if (GetKeyboardPress(DIK_W)) {
		temp.y -= SPEED_Y;
	}
	//‰º–îˆó‚ª‰Ÿ‚³‚ê‚½‚ç
	if (GetKeyboardPress(DIK_S)) {
		temp.y += SPEED_Y;
	}
	//¶–îˆó‚ª‰Ÿ‚³‚ê‚½‚ç
	if (GetKeyboardPress(DIK_A)) {
		temp.x -= SPEED_X;
	}
	//‰E–îˆó‚ª‰Ÿ‚³‚ê‚½‚ç
	if (GetKeyboardPress(DIK_D)) {
		temp.x += SPEED_X;
	}

	//³‹K‰»
	D3DXVec2Normalize(&temp, &temp);
	temp *= SPEED;

	//ˆÚ“®
	GameObject::MovePos(temp);

	//‰æ–Ê“à‚É–ß‚·
	SetPos(ScreenOut::GetScreenIn(GameObject::GetPos(), D3DXVECTOR2(BOX_W, BOX_H)));


	//======================
	// ’e

	m_BulletInterval++;
	//ƒXƒy[ƒX‚ª‰Ÿ‚³‚ê‚½ + ”­ŽËŠÔŠu‚ªŽw’è‚Ì’l‚ð’´‚¦‚½‚ç’e‚ð¶¬
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

		//‰æ–ÊŠO‚Éo‚½‚ç
		if (m_pBullet[i].GetScreenOut()) {
			//’e‚ðÁ‚·
			DeleteBullet(i);
		}
	}

	//–³“GŽžŠÔ‚ÍF•ÏX
	if (isinvincible)
	{//–³“G‚¶‚á‚È‚¢
		SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	}
	else
	{//–³“G
		SetColor(INVINCIBLE__COLOR);
	}
}

//==========================
// ’e‚Ì•`‰æˆ—
//==========================
void Player::DrawBullet(void)const
{
	for (int i = 0; i < m_BulletNum; i++) {
		m_pBullet[i].Draw();
	}
}

//==========================
// ’e‚ðÁ‚·
//==========================
void Player::DeleteBullet(int index_num)
{
	for (int i = index_num; i < m_BulletNum - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	m_BulletNum--;
}