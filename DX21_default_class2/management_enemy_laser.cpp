//=======================================
// ���[�U�[�̓G�̊Ǘ��֌W(cpp�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#include "management_enemy_laser.h"
#define _USE_MATH_DEFINES
#include <math.h>

//==========================
// �萔�̏�����
//==========================
const float EnemyLaserManagement::BULLET_SIZE_X = 20.0f;
const float EnemyLaserManagement::BULLET_SIZE_Y = 0.0f;


//=========================
// �����t���R���X�g���N�^
//=========================
EnemyLaserManagement::EnemyLaserManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, EnemySetPos& pEnemySetPos)
	:EnemyManagement(ENEMY_NUM, ATTACK, LASER_ATTACK), m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectLaser(pDrawObject2), m_pEnemySetPos(pEnemySetPos)
{
	m_pEnemyLaser = new EnemyLaser[ENEMY_NUM];
	m_pLaser = new Laser[ENEMY_NUM];
}

//======================
// �X�V����
//======================
void EnemyLaserManagement::Update()
{
	AddFlame(); //�t���[�����𑝉�

	int i = GetFlameNum();
	if (GetFlameNum() == m_SetEnemyTime[m_EnemyNum] && GetObjNum() != ENEMY_NUM)
	{
		EnemyLaser temp(m_pDrawObjectEnemy, m_SetEnemy[m_EnemyNum]);
		m_pEnemyLaser[GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		m_EnemyNum++;
	}

	//������G�̏���
	for (int i = 0; i < GetObjNum(); i++)
	{
		m_pEnemyLaser[i].Update();
		//���[�U�[�̃A�b�v�f�[�g
		if (m_pEnemyLaser[i].GetLaserIndex() >= 0)
		{
			m_pLaser[m_pEnemyLaser[i].GetLaserIndex()].Update(m_pEnemyLaser[i].GetPos());
		}

		//�e�����
		if (m_pEnemyLaser[i].GetFlagBulletMake() && EnemyManagement::GetBulletNum() != ENEMY_NUM)
		{
			//���[�U�[�ԍ����Z�b�g
			m_pEnemyLaser[i].SetLaserIndex(EnemyManagement::GetBulletNum());
			Laser temp(m_pDrawObjectLaser, m_pEnemyLaser[i].GetPos() + D3DXVECTOR2(0.0f, 10.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y));
			m_pLaser[EnemyManagement::GetBulletNum()] = temp;
			m_pEnemyLaser[i].SetLaserIndex(EnemyManagement::GetBulletNum());
			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyLaser[i].BulletMake();
		}
	}

	//���񂾓G�̃��[�U�[�̃A�b�v�f�[�g
	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++)
	{
		if (m_pLaser[i].GetLaserTime() < 0)
		{
			m_pLaser[i].Update(m_pLaser->GetPos());
		}
		
		//��ʊO����o����...
		if (m_pLaser[i].GetScreenOut())
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
	EnemyManagement::DeleteObj(index_num);

	if (m_pEnemyLaser[index_num].GetLaserIndex() >= 0)
	{
		m_pLaser[m_pEnemyLaser[index_num].GetLaserIndex()].DeleteLaser();
	}

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
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++)
	{
		if (m_pEnemyLaser[i].GetLaserIndex() == index_num)
		{
			m_pEnemyLaser[i].SetLaserIndex(-1);
		}
		else if (m_pEnemyLaser[i].GetLaserIndex() > index_num)
		{
			m_pEnemyLaser[i].SetLaserIndex(m_pEnemyLaser[i].GetLaserIndex() - 1);
		}
	}
	EnemyManagement::IncreaseBulletNum(-1);
}