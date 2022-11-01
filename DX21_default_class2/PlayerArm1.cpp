//=======================================
// �v���C���[�̘r1�֌W(cpp�t�@�C��)
// �쐬���F2022/10/30
// �쐬�ҁF��������
//=======================================
#include "PlayerArm1.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "input.h"

//==========================
// �萔�̏�����
//==========================
const float PlayerArm1::BULLET_SIZE_X = 40.0f;
const float PlayerArm1::BULLET_SIZE_Y = 40.0f;
const float PlayerArm1::BULLET_SPEED = 2.5f;

//==========================
// �X�V����
//==========================
void PlayerArm1::Update()
{
	//�{�^���������ꂽ��
	if ((m_right && GetKeyboardPress(DIK_RIGHT)) || (!m_right && GetKeyboardPress(DIK_LEFT))) {
		//�v���C���[�̌��ǂ��悤�ɂ��āA�e�𐶐�
		D3DXVECTOR2 movTemp = m_enemy_pos - GetPos();
		D3DXVECTOR2 rotposTemp = GetPos() - m_enemy_pos;
		D3DXVec2Normalize(&movTemp, &movTemp);
		movTemp *= BULLET_SPEED;

		float rotTemp = atan2(rotposTemp.y, rotposTemp.x) * (180 / M_PI) + 180.0f;

		//�e�����
		Bullet temp(m_bulletdraw, GetPos(),
			D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), movTemp, rotTemp);

		m_pBullet[m_bullet_num] = temp;

		//���݂̒e�̐��𑝂₷
		m_bullet_num++;
	}

	//������e�̏���
	for (int i = 0; i < m_bullet_num; i++) {
		//�v���C���[�̌��ǂ�(�z�[�~���O�e)
		D3DXVECTOR2 movTemp = m_enemy_pos - m_pBullet[i].GetPos();
		D3DXVECTOR2 rotposTemp = m_pBullet[i].GetPos() - m_enemy_pos;
		D3DXVec2Normalize(&movTemp, &movTemp);
		movTemp *= BULLET_SPEED;

		float rotTemp = atan2(rotposTemp.y, rotposTemp.x) * (180 / M_PI) + 180.0f;

		m_pBullet[i].SetRot(rotTemp);
		m_pBullet[i].SetMove(movTemp);

		//�e�̍X�V����
		m_pBullet[i].Update();

		//��ʊO����o����A���Ԍo�߂�����...
		if (m_pBullet[i].GetScreenOut() || m_pBullet[i].GetTime() > BULLET_BREAK_TIME) {
			//�e������
			for (int j = i; j < m_bullet_num; j++) {
				m_pBullet[j] = m_pBullet[j + 1];
			}
			m_bullet_num--;
		}
	}
}

//==========================
// �`�揈��
//==========================
void PlayerArm1::PlayerArmDraw()
{
	for (int i = 0; i < m_bullet_num; i++) {
		m_pBullet[i].Draw();
	}
}
