//=======================================
// �v���C���[�̘r1�֌W(cpp�t�@�C��)
// �쐬���F2022/10/30
// �쐬�ҁF��������
//=======================================
#include "PlayerArm3.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "input.h"

//==========================
// �萔�̏�����
//==========================
const float PlayerArm3::BULLET_SIZE_X = 40.0f;
const float PlayerArm3::BULLET_SIZE_Y = 40.0f;
const float PlayerArm3::BULLET_SPEED = 2.5f;

//==========================
// �X�V����
//==========================
void PlayerArm3::Update()
{
	//�{�^���������ꂽ��
	if ((m_right && GetKeyboardPress(DIK_RIGHT))|| (!m_right && GetKeyboardPress(DIK_LEFT))) {
		
		//�e�����
		Bullet temp(m_bulletdraw, GetPos(),
			D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0.0f,-BULLET_SPEED),0.0f );

		m_pBullet[m_bullet_num] = temp;

		//���݂̒e�̐��𑝂₷
		m_bullet_num++;
	}

	//������e�̏���
	for (int i = 0; i < m_bullet_num; i++) {
		

		//�e�̍X�V����
		m_pBullet[i].Update();

		//��ʊO����o����A���Ԍo�߂�����...
		if (m_pBullet[i].GetScreenOut()){
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
void PlayerArm3::PlayerArmDraw()const
{
	for (int i = 0; i < m_bullet_num; i++) {
		m_pBullet[i].Draw();
	}
}
