//=======================================
// �v���C���[�֌W(cpp�t�@�C��)
// �쐬���F2022/06/27
// �쐬�ҁF��������
//=======================================
#include "player.h"
#include "input.h"
#include "ScreenOut.h"

//==========================
// �萔�̏�����
//==========================
const float Player::BOX_W = 50.0f;
const float Player::BOX_H = 50.0f;
const float Player::START_POS_X = (SCREEN_WIDTH / 2);
const float Player::START_POS_Y = (SCREEN_HEIGHT / 2);
const float Player::SPEED_X = 2.0f;
const float Player::SPEED_Y = 2.0f;
const float Player::SPEED = 2.0f;
const float Player::BULLET_SIZE_X = 40.0f;
const float Player::BULLET_SIZE_Y = 40.0f;
const float Player::BULLET_SPEED_X = 2.5f;

//======================
// �X�V����
//======================
void Player::Update()
{
	D3DXVECTOR2 temp = D3DXVECTOR2(0.0f, 0.0f);

	//���󂪉����ꂽ��
	if (GetKeyboardPress(DIK_UP)) {
		temp.y -= SPEED_Y;
	}
	//����󂪉����ꂽ��
	if (GetKeyboardPress(DIK_DOWN)) {
		temp.y += SPEED_Y;
	}
	//�E��󂪉����ꂽ��
	if (GetKeyboardPress(DIK_RIGHT)) {
		temp.x += SPEED_X;
	}
	//�E��󂪉����ꂽ��
	if (GetKeyboardPress(DIK_LEFT)) {
		temp.x -= SPEED_X;
	}

	//���K��
	D3DXVec2Normalize(&temp, &temp);
	temp *= SPEED;

	//�ړ�
	GameObject::MovePos(temp);

	//��ʊO�ɏo����
	if (GameObject::GetScreenOut()) {
		//��ʓ��ɖ߂�
		ScreenOut::GetScreenIn(GameObject::GetPos(), D3DXVECTOR2(BOX_W, BOX_H));
	}


	//======================
	// �e

	m_BulletInterval++;
	//�X�y�[�X�������ꂽ + ���ˊԊu���w��̒l�𒴂�����e�𐶐�
	if (GetKeyboardPress(DIK_SPACE) && m_BulletInterval > BULLET_INTERVAL_TIME) {
		m_BulletInterval = 0;

		if (m_BulletNum < BULLET_MAX_NUM) {
			Bullet temp(m_BulletDrawObject, GameObject::GetPos(), D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y),
				D3DXVECTOR2(BULLET_SPEED_X, 0.0f), 0.0f);
			m_pBullet[m_BulletNum] = temp;
			m_BulletNum++;
		}
	}

	for (int i = 0; i < m_BulletNum; i++) {
		m_pBullet[i].Update();

		//��ʊO�ɏo����
		if (m_pBullet[i].GetScreenOut()) {
			//�e������
			DeleteBullet(i);
		}
	}
}

//==========================
// �e�̕`�揈��
//==========================
void Player::DrawBullet(void)const
{
	for (int i = 0; i < m_BulletNum; i++) {
		m_pBullet[i].Draw();
	}
}

//==========================
// �e������
//==========================
void Player::DeleteBullet(int index_num)
{
	for (int i = index_num; i < m_BulletNum - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	m_BulletNum--;
}