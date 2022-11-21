//=======================================
// ���ʂ̓G�̊Ǘ��֌W(cpp�t�@�C��)
// �쐬���F2022/09/13
// �쐬�ҁF��������
//=======================================
#include "management_enemy_gatoring.h"
#define _USE_MATH_DEFINES
#include <math.h>

//==========================
// �萔�̏�����
//==========================
const float EnemyGatoringManagement::BULLET_SIZE_X = 20.0f;
const float EnemyGatoringManagement::BULLET_SIZE_Y = 20.0f;
const float EnemyGatoringManagement::BULLET_SPEED = 2.5f;

//=========================
// �����t���R���X�g���N�^
//=========================
EnemyGatoringManagement::EnemyGatoringManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, EnemySetPos& pEnemySetPos)
	:EnemyManagement(ENEMY_NUM, ATTACK, BULLET_ATTACK),m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBullet(pDrawObject2), m_pEnemySetPos(pEnemySetPos)
{
	m_pEnemyGatoring = new EnemyGatoring[ENEMY_NUM];
	m_pBullet = new Bullet[ENEMY_NUM];
}

//======================
// �X�V����
//======================
void EnemyGatoringManagement::Update(const D3DXVECTOR2& PlayerPos)
{
	AddFlame(); //�t���[�����𑝉�

	int i = GetFlameNum();
	if (GetFlameNum() == m_SetEnemyTime[m_EnemyNum] && GetObjNum() != ENEMY_NUM)
	{
		EnemyGatoring temp(m_pDrawObjectEnemy, m_SetEnemy[m_EnemyNum]);
		m_pEnemyGatoring[GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		m_EnemyNum++;
	}

	//������G�̏���
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemyGatoring[i].Update();

		//�e�����
		if (m_pEnemyGatoring[i].GetFlagBulletMake() && EnemyManagement::GetBulletNum() != ENEMY_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyGatoring[i].GetPos(),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y),D3DXVECTOR2(0, 10.0f), 0.0f);
						   // �e�̑傫��								�e��������		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyGatoring[i].BulletMake();
		}
	}

	//������e�̏���
	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
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
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemyGatoring[i].Draw();
	}

	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		m_pBullet[i].Draw();
	}
}

//======================
// �G������
//======================
void EnemyGatoringManagement::DeleteObj(int index_num)
{
	EnemyManagement::DeleteObj(index_num);

	m_pEnemySetPos.DeleteEnemy(m_pEnemyGatoring[index_num].GetPos());

	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemyGatoring[i] = m_pEnemyGatoring[i + 1];
	}
	EnemyManagement::IncreaseObjNum(-1);
}

//======================
// �e������
//======================
void EnemyGatoringManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < EnemyManagement::GetBulletNum() - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	EnemyManagement::IncreaseBulletNum(-1);
}