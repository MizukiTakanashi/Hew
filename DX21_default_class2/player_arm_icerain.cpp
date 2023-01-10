//=======================================
// ƒvƒŒƒCƒ„[‚Ì˜r‚Ì•X‚Ì’eŠÖŒW(cppƒtƒ@ƒCƒ‹)
// ì¬“úF2022/1/1
// ì¬ÒF–î–ìãÄ‘å
//=======================================
#include "player_arm_icerain.h"
//==========================
// ’è”‚Ì‰Šú‰»
//==========================
const float PlayerArmIceRain::BULLET_SIZE_X = 20.0f;
const float PlayerArmIceRain::BULLET_SIZE_Y = 50.0f;
const float PlayerArmIceRain::BULLET_SPEED = 20.0f;

//==========================
// XVˆ—
//==========================
void PlayerArmIceRain::Update(const D3DXVECTOR2& arm_pos)
{
	//¡‚¢‚é’e‚Ìˆ—
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		//’e‚ÌXVˆ—
		m_pBullet[i].Update();

		//‰æ–ÊŠO‚©‚ço‚½‚ç...
		if (m_pBullet[i].GetScreenOut()) {
			DeleteBullet(i);
		}
	}

	//‚à‚µ‚à’e‚Ì§ŒÀ‚ª’´‚¦‚Ä‚½‚ç’e‚ğì‚ç‚È‚¢
	if (inhPlayerArm::IsBulletUsed()) {
		return;
	}

	//”­ËŠÔŠuƒJƒEƒ“ƒg
	m_bullet_interval_count++;
	m_bullet_interval_count1++;
	m_bullet_interval_count2++;
	m_bullet_interval_count3++;
	m_bullet_interval_count4++;

	//ƒ{ƒ^ƒ“‚ª‰Ÿ‚³‚ê‚½‚ç
	if ((inhPlayerArm::GetRightLeft() && inhPlayerArm::IsButtonPush()) ||
		(!inhPlayerArm::GetRightLeft() && inhPlayerArm::IsButtonPush())) {
		//”­Ë‚Å‚«‚éŠÔ‚É‚È‚Á‚½‚ç...
		if (m_bullet_interval_count > BULLET_INTERVAL) {
			m_bullet_interval_count = 0;

			//˜r‚ÌØ‚è—£‚µ‚Æ“¯‚É’e‚ğì‚ç‚È‚¢‚½‚ß‚Ìˆ—
			if (inhPlayerArm::GetBulletMaked() == BULLET_NUM_MAX - 1)
			{
				//ì‚Á‚½’e‚Ì”‚ğ‘‚â‚·
				inhPlayerArm::IncreaseBulletMaked();

				return;
			}

			//’e‚ğì‚é
			Bullet temp(m_bulletdraw, arm_pos,
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0.0f, -BULLET_SPEED), 0.0f);

			m_pBullet[inhPlayerArm::GetBulletNum()] = temp;

			//Œ»İ‚Ì’e‚Ì”‚ğ‘‚â‚·
			inhPlayerArm::IncreaseBulletNum();

			//ì‚Á‚½’e‚Ì”‚ğ‘‚â‚·
			inhPlayerArm::IncreaseBulletMaked();
		}
		//”­Ë‚Å‚«‚éŠÔ‚É‚È‚Á‚½‚ç...
		if (m_bullet_interval_count1 > BULLET_INTERVAL1) {
			m_bullet_interval_count1 = 0;

			//˜r‚ÌØ‚è—£‚µ‚Æ“¯‚É’e‚ğì‚ç‚È‚¢‚½‚ß‚Ìˆ—
			if (inhPlayerArm::GetBulletMaked() == BULLET_NUM_MAX - 1)
			{
				//ì‚Á‚½’e‚Ì”‚ğ‘‚â‚·
				inhPlayerArm::IncreaseBulletMaked();

				return;
			}

			//’e‚ğì‚é
			Bullet temp(m_bulletdraw, arm_pos + D3DXVECTOR2(30.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0.0f, -BULLET_SPEED), 0.0f);

			m_pBullet[inhPlayerArm::GetBulletNum()] = temp;

			//Œ»İ‚Ì’e‚Ì”‚ğ‘‚â‚·
			inhPlayerArm::IncreaseBulletNum();

			//ì‚Á‚½’e‚Ì”‚ğ‘‚â‚·
			inhPlayerArm::IncreaseBulletMaked();
		}
		//”­Ë‚Å‚«‚éŠÔ‚É‚È‚Á‚½‚ç...
		if (m_bullet_interval_count2 > BULLET_INTERVAL2) {
			m_bullet_interval_count2 = 0;

			//˜r‚ÌØ‚è—£‚µ‚Æ“¯‚É’e‚ğì‚ç‚È‚¢‚½‚ß‚Ìˆ—
			if (inhPlayerArm::GetBulletMaked() == BULLET_NUM_MAX - 1)
			{
				//ì‚Á‚½’e‚Ì”‚ğ‘‚â‚·
				inhPlayerArm::IncreaseBulletMaked();

				return;
			}

			//’e‚ğì‚é
			Bullet temp(m_bulletdraw, arm_pos + D3DXVECTOR2(-30.0f, 0.0f), 
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0.0f, -BULLET_SPEED), 0.0f);

			m_pBullet[inhPlayerArm::GetBulletNum()] = temp;

			//Œ»İ‚Ì’e‚Ì”‚ğ‘‚â‚·
			inhPlayerArm::IncreaseBulletNum();

			//ì‚Á‚½’e‚Ì”‚ğ‘‚â‚·
			inhPlayerArm::IncreaseBulletMaked();
		}
		//”­Ë‚Å‚«‚éŠÔ‚É‚È‚Á‚½‚ç...
		if (m_bullet_interval_count3 > BULLET_INTERVAL3) {
			m_bullet_interval_count3 = 0;

			//˜r‚ÌØ‚è—£‚µ‚Æ“¯‚É’e‚ğì‚ç‚È‚¢‚½‚ß‚Ìˆ—
			if (inhPlayerArm::GetBulletMaked() == BULLET_NUM_MAX - 1)
			{
				//ì‚Á‚½’e‚Ì”‚ğ‘‚â‚·
				inhPlayerArm::IncreaseBulletMaked();

				return;
			}

			//’e‚ğì‚é
			Bullet temp(m_bulletdraw, arm_pos + D3DXVECTOR2(50.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0.0f, -BULLET_SPEED), 0.0f);

			m_pBullet[inhPlayerArm::GetBulletNum()] = temp;

			//Œ»İ‚Ì’e‚Ì”‚ğ‘‚â‚·
			inhPlayerArm::IncreaseBulletNum();

			//ì‚Á‚½’e‚Ì”‚ğ‘‚â‚·
			inhPlayerArm::IncreaseBulletMaked();
		}
		//”­Ë‚Å‚«‚éŠÔ‚É‚È‚Á‚½‚ç...
		if (m_bullet_interval_count4 > BULLET_INTERVAL4) {
			m_bullet_interval_count4 = 0;

			//˜r‚ÌØ‚è—£‚µ‚Æ“¯‚É’e‚ğì‚ç‚È‚¢‚½‚ß‚Ìˆ—
			if (inhPlayerArm::GetBulletMaked() == BULLET_NUM_MAX - 1)
			{
				//ì‚Á‚½’e‚Ì”‚ğ‘‚â‚·
				inhPlayerArm::IncreaseBulletMaked();

				return;
			}

			//’e‚ğì‚é
			Bullet temp(m_bulletdraw, arm_pos + D3DXVECTOR2(-50.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0.0f, -BULLET_SPEED), 0.0f);

			m_pBullet[inhPlayerArm::GetBulletNum()] = temp;

			//Œ»İ‚Ì’e‚Ì”‚ğ‘‚â‚·
			inhPlayerArm::IncreaseBulletNum();

			//ì‚Á‚½’e‚Ì”‚ğ‘‚â‚·
			inhPlayerArm::IncreaseBulletMaked();
		}
	}
}

//==========================
// •`‰æˆ—
//==========================
void PlayerArmIceRain::PlayerArmDraw()const
{
	for (int i = 0; i < inhPlayerArm::GetBulletNum(); i++) {
		m_pBullet[i].Draw();
	}
}

//==========================
// w’è‚µ‚½”Ô†‚Ì’e‚ğÁ‚·
//==========================
void PlayerArmIceRain::DeleteBullet(int index_num)
{
	//’e‚ğÁ‚·
	for (int i = index_num; i < inhPlayerArm::GetBulletNum(); i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	inhPlayerArm::IncreaseBulletNum(-1);
}