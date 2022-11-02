//=======================================
// ���ʂ̓G�̊Ǘ��֌W(cpp�t�@�C��)
// �쐬���F2022/09/13
// �쐬�ҁF��������
//=======================================
#include "EnemyGatoringManagement.h"
#define _USE_MATH_DEFINES
#include <math.h>

//==========================
// �萔�̏�����
//==========================
const float EnemyGatoringManagement::BULLET_SIZE_X = 15.0f;
const float EnemyGatoringManagement::BULLET_SIZE_Y = 30.0f;
const float EnemyGatoringManagement::BULLET_SPEED = 2.5f;

//=========================
// �����t���R���X�g���N�^
//=========================
EnemyGatoringManagement::EnemyGatoringManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, EnemySetPos& pEnemySetPos)
	:m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBullet(pDrawObject2), m_pEnemySetPos(pEnemySetPos)
{
	m_pEnemyGatoring = new EnemyGatoring[MAX_NUM];
	m_pBullet = new Bullet[MAX_NUM];
}

//======================
// �X�V����
//======================
void EnemyGatoringManagement::Update(const D3DXVECTOR2& PlayerPos)
{
	//���Ԃ�������G��z�u
	if (m_count++ > APPEARANCE_TIME && m_enemy_num != MAX_NUM) {
		//�����_���ŏo���ʒu�����߂�
		float x = rand() % (SCREEN_WIDTH - (int)EnemyGatoring::SIZE_X / 2) + EnemyGatoring::SIZE_X / 2;

		//�t���O�ɉ����ēG�����
		if (m_pEnemySetPos.SetEnemy(D3DXVECTOR2(x, EnemyGatoring::STOP_POS_Y), D3DXVECTOR2(EnemyGatoring::SIZE_X + EnemyGatoring::RANGE * 2, EnemyGatoring::SIZE_Y))) {
			EnemyGatoring temp(m_pDrawObjectEnemy, D3DXVECTOR2(x, -EnemyGatoring::SIZE_Y / 2));
			m_pEnemyGatoring[m_enemy_num] = temp;
			m_enemy_num++;
		}

		m_count = 0;
	}

	//������G�̏���
	for (int i = 0; i < m_enemy_num; i++) {
		m_pEnemyGatoring[i].Update();

		//�e�����
		if (m_pEnemyGatoring[i].GetFlagBulletMake() && m_bullet_num != MAX_NUM) 
		{

			Bullet temp(m_pDrawObjectBullet, m_pEnemyGatoring[i].GetPos(),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y),D3DXVECTOR2(0, 10.0f), 0.0f);
						   // �e�̑傫��								�e��������		
			m_pBullet[m_bullet_num] = temp;

			m_bullet_num++;

			m_pEnemyGatoring[i].BulletMake();
		}
	}

	//������e�̏���
	for (int i = 0; i < m_bullet_num; i++) {
		m_pBullet[i].Update();
		//��ʊO����o����...
		if (m_pBullet[i].GetScreenOut()) {
			//�e������
			DeleteBullet(i);
		}
	}
}

//==========================
// �`�揈��
//==========================
void EnemyGatoringManagement::Draw(void)const
{
	for (int i = 0; i < m_enemy_num; i++) {
		m_pEnemyGatoring[i].Draw();
	}

	for (int i = 0; i < m_bullet_num; i++) {
		m_pBullet[i].Draw();
	}
}

//======================
// �G������
//======================
void EnemyGatoringManagement::DeleteEnemy(int index_num)
{
	m_pEnemySetPos.DeleteEnemy(m_pEnemyGatoring[index_num].GetPos());

	for (int i = index_num; i < m_enemy_num - 1; i++) {
		m_pEnemyGatoring[i] = m_pEnemyGatoring[i + 1];
	}
	m_enemy_num--;
}

//======================
// �e������
//======================
void EnemyGatoringManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < m_bullet_num - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	m_bullet_num--;
}