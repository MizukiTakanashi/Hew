//=======================================
// �v���C���[�֌W(cpp�t�@�C��)
// �쐬���F2022/06/27
// �쐬�ҁF��������
//=======================================
#include "player.h"

//#include "input.h"
#include "inputx.h"
#include "keyboard.h"

#include "screen_out.h"
#include "player_hp.h"

//==========================
// �萔�̏�����
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
const D3DXCOLOR Player::INVINCIBLE__COLOR = D3DXCOLOR(1.0f, 0.3f, 0.3f, 1.0f);			//�v���C���[���G���Ԃ̐F
int a = 0;
int b = 0;
int Bom_Count = 0;
//======================
// �X�V����
//======================
void Player::Update(bool isinvincible)
{
	D3DXVECTOR2 temp = D3DXVECTOR2(0.0f, 0.0f);

	//==========================
	// �p�b�h

	//���X�e�B�b�N�ŏ�ɓ|���ꂽ��...
	if (GetThumbLeftY(0) > 0) {
		//��ɍs��
		temp.y -= SPEED_Y * GetThumbLeftY(0);
	}
	//���X�e�B�b�N�ŉ��ɓ|���ꂽ��...
	if (GetThumbLeftY(0) < 0) {
		//���ɍs��
		temp.y += SPEED_Y * -GetThumbLeftY(0);
	}
	//���X�e�B�b�N�ō��ɓ|���ꂽ��...
	if (GetThumbLeftX(0) < 0) {
		//���ɍs��
		temp.x += SPEED_X * GetThumbLeftX(0);
	}
	//���X�e�B�b�N�ŉE�ɓ|���ꂽ��...
	if (GetThumbLeftX(0) > 0) {
		//�E�ɍs��
		temp.x += SPEED_X * GetThumbLeftX(0);
	}

	//�\���L�[�オ�����ꂽ��
	if (IsButtonPressed(0, XINPUT_GAMEPAD_DPAD_UP)) {
		temp.y -= SPEED_Y;
	}
	//�\���L�[���������ꂽ��
	if (IsButtonPressed(0, XINPUT_GAMEPAD_DPAD_DOWN)) {
		temp.y += SPEED_Y;
	}
	//�\���L�[���������ꂽ��
	if (IsButtonPressed(0, XINPUT_GAMEPAD_DPAD_LEFT)) {
		temp.x -= SPEED_X;
	}
	//�\���L�[�E�������ꂽ��
	if (IsButtonPressed(0, XINPUT_GAMEPAD_DPAD_RIGHT)) {
		temp.x += SPEED_X;
	}

	//==========================
	// �L�[�{�[�h

	//���󂪉����ꂽ��
	if (InputGetKey(KK_W)) {
		temp.y -= SPEED_Y;
	}
	//����󂪉����ꂽ��
	if (InputGetKey(KK_S)) {
		temp.y += SPEED_Y;
	}
	//����󂪉����ꂽ��
	if (InputGetKey(KK_A)) {
		temp.x -= SPEED_X;
	}
	//�E��󂪉����ꂽ��
	if (InputGetKey(KK_D)) {
		temp.x += SPEED_X;
	}

	if (temp.x != 0.0f || temp.y != 0.0f)
	{//�ړ����Ă���
		//�A�j���[�V�����Z�b�g
		Player::SetAnimationNum(0);
	}
	else
	{//�ړ����ĂȂ�������
		//�A�j���[�V�����Z�b�g
		Player::SetAnimationNum(1);
	}

	//���K��
	D3DXVec2Normalize(&temp, &temp);
	temp *= SPEED;

	//�ړ�
	GameObject::MovePos(temp);

	//��ʓ��ɖ߂�
	SetPos(ScreenOut::GetScreenIn(GameObject::GetPos(), D3DXVECTOR2(BOX_W, BOX_H)));


	//======================
	// �e

	m_BulletInterval++;
	//�p�b�h��A�������ꂽ��A���̓L�[�{�[�h�̃X�y�[�X�������ꂽ��...
	//�Ȃ������ˊԊu���w��̒l�𒴂�����e�𐶐�
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

		//��ʊO�ɏo����
		if (m_pBullet[i].GetScreenOut()) {
			//�e������
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

	//���G���Ԃ͐F�ύX
	if (isinvincible)
	{//���G����Ȃ�
		SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	}
	else
	{//���G
		SetColor(INVINCIBLE__COLOR);
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
//==========================
// ���e�̕`�揈��
//==========================
void Player::DrawBom(void)const
{
	for (int i = 0; i < m_BomNum; i++) {
		m_pBom[i].Draw();
	}
}

//==========================
// ���e������
//==========================
void Player::DeleteBom(int index_num)
{
	for (int i = index_num; i < m_BomNum - 1; i++) {
		m_pBom[i] = m_pBom[i + 1];
	}
	m_BomNum--;
}