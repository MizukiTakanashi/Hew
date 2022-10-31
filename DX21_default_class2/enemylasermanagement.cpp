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


//=========================
// �����t���R���X�g���N�^
//=========================
EnemyLaserManagement::EnemyLaserManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, EnemySetPos& pEnemySetPos)
	:EnemyManagement(MAX_NUM, MAX_NUM, ATTACK, LASER_ATTACK), m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectLaser(pDrawObject2), m_pEnemySetPos(pEnemySetPos)
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
			EnemyManagement::IncreaseObjNum(1);
		}

		m_count = 0;
	}

	//������G�̏���
	for (int i = 0; i < GetObjNum(); i++)
	{
		m_pEnemyLaser[i].Update();

		//�e�����
		if (m_pEnemyLaser[i].GetFlagBulletMake() && EnemyManagement::GetBulletNum() != MAX_NUM)
		{
			Laser temp(m_pDrawObjectLaser, m_pEnemyLaser[i].GetPos() + D3DXVECTOR2(0.0f, 10.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), &m_pEnemyLaser[i]);
			m_pLaser[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyLaser[i].BulletMake();
		}
	}

	//������e�̏���
	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++)
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
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemyLaser[i].Draw();
	}

	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++)
	{
		m_pLaser[i].Draw();
	}
}

//======================
// �G������
//======================
void EnemyLaserManagement::DeleteObj(int index_num)
{
	m_pEnemySetPos.DeleteEnemy(m_pEnemyLaser[index_num].GetPos());

	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemyLaser[i] = m_pEnemyLaser[i + 1];
	}
	EnemyManagement::IncreaseObjNum(-1);
}

//======================
// �e������
//======================
void EnemyLaserManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < EnemyManagement::GetBulletNum() - 1; i++)
	{
		m_pLaser[i] = m_pLaser[i + 1];
	}
	EnemyManagement::IncreaseBulletNum(-1);
}