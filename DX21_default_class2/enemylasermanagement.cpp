//=======================================
// ���[�U�[�̓G�̊Ǘ��֌W(cpp�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#include "enemylasermanagement.h"
#define _USE_MATH_DEFINES
#include <math.h>

//==========================
// �萔�̏�����
//==========================
const float EnemyLaserManagement::BULLET_SIZE_X = 30.0f;
const float EnemyLaserManagement::BULLET_SIZE_Y = 0.0f;
//const float EnemyLaserManagement::BULLET_SPEED = 2.5f;


//=========================
// �����t���R���X�g���N�^
//=========================
EnemyLaserManagement::EnemyLaserManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, EnemySetPos& pEnemySetPos)
	:Management(MAX_NUM), m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectLaser(pDrawObject2), m_pEnemySetPos(pEnemySetPos)
{
	m_pEnemyLaser = new EnemyLaser[MAX_NUM];
	m_pLaser = new Laser[MAX_NUM];
}

//======================
// �X�V����
//======================
void EnemyLaserManagement::Update()
{
	//���Ԃ�������G��z�u
	if (m_count++ > APPEARANCE_TIME && GetObjNum() != MAX_NUM) {
		//�����_���ŏo���ʒu�����߂�
		float x = rand() % (SCREEN_WIDTH - (int)EnemyLaser::SIZE_X / 2) + EnemyLaser::SIZE_X / 2;

		//�t���O�ɉ����ēG�����
		if (m_pEnemySetPos.SetEnemy(D3DXVECTOR2(x, EnemyLaser::STOP_POS_Y), D3DXVECTOR2(EnemyLaser::SIZE_X + EnemyLaser::RANGE * 2, EnemyLaser::SIZE_Y))) {
			EnemyLaser temp(m_pDrawObjectEnemy, D3DXVECTOR2(x, -EnemyLaser::SIZE_Y / 2));
			m_pEnemyLaser[GetObjNum()] = temp;
			IncreaseObjNum();
		}

		m_count = 0;
	}

	//������G�̏���
	for (int i = 0; i < GetObjNum(); i++)
	{
		m_pEnemyLaser[i].Update();

		//�e�����
		if (m_pEnemyLaser[i].GetFlagBulletMake() && m_laser_num != MAX_NUM) 
		{
			Laser temp(m_pDrawObjectLaser, m_pEnemyLaser[i].GetPos() + D3DXVECTOR2(0.0f, 10.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), &m_pEnemyLaser[i]);
			m_pLaser[m_laser_num] = temp;

			m_laser_num++;

			m_pEnemyLaser[i].BulletMake();
		}
	}

	//������e�̏���
	for (int i = 0; i < m_laser_num; i++) 
	{
		m_pLaser[i].Update();
		//��ʊO����o����...
		if (m_pLaser[i].GetScreenOut() || !m_pLaser[i].IsLaserUse())
		{
			//�e������
			DeleteBullet(i);
		}
	}
}

//==========================
// �`�揈��
//==========================
void EnemyLaserManagement::Draw(void)const
{
	Management::DrawObj();

	for (int i = 0; i < m_laser_num; i++) 
	{
		m_pLaser[i].Draw();
	}
}

//======================
// �G������
//======================
void EnemyLaserManagement::DeleteEnemy(int index_num)
{
	m_pEnemySetPos.DeleteEnemy(m_pEnemyLaser[index_num].GetPos());

	for (int i = index_num; i < Management::GetObjNum() - 1; i++) {
		m_pEnemyLaser[i] = m_pEnemyLaser[i + 1];
	}
	Management::IncreaseObjNum(-1);
}

//======================
// �e������
//======================
void EnemyLaserManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < m_laser_num - 1; i++) 
	{
		m_pLaser[i] = m_pLaser[i + 1];
	}
	m_laser_num--;
}