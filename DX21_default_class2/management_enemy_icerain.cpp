//=======================================
// ���ʂ̓G�̊Ǘ��֌W(cpp�t�@�C��)
// �쐬���F2022/09/13
// �쐬�ҁF��������
//=======================================
#include "management_enemy_icerain.h"

//==========================
// �萔�̏�����
//==========================
const float EnemyIceRainManagement::BULLET_SIZE_X = 20.0f;
const float EnemyIceRainManagement::BULLET_SIZE_Y = 50.0f;
const float EnemyIceRainManagement::BULLET_SPEED = 2.5f;

//=========================
// �����t���R���X�g���N�^
//=========================
EnemyIceRainManagement::EnemyIceRainManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2)
	:EnemyManagement(ENEMY_NUM, ATTACK, BULLET_ATTACK), m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBullet(pDrawObject2)
{
	m_pEnemyIceRain = new EnemyIceRain[ENEMY_NUM];
	m_pBullet = new Bullet[ENEMY_NUM];
}

//======================
// �X�V����
//======================
void EnemyIceRainManagement::Update(const D3DXVECTOR2& PlayerPos)
{
	m_FlameNum++; //�t���[�����𑝉�

	if (m_FlameNum == m_SetEnemyTime[m_EnemyNum])
	{
		EnemyIceRain temp(m_pDrawObjectEnemy, m_SetEnemy[m_EnemyNum]);
		m_pEnemyIceRain[GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		m_EnemyNum++;
	}

	//������G�̏���
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemyIceRain[i].Update();

		//�e�����
		if (m_pEnemyIceRain[i].GetFlagBulletMake())
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyIceRain[i].GetPos(),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 10.0f), 0.0f); 
			// �e�̑傫��								�e��������		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyIceRain[i].BulletMake();
		}
		//�e�����
		if (m_pEnemyIceRain[i].GetFlagBulletMake1())
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyIceRain[i].GetPos() + D3DXVECTOR2(30.0f, 0.0f), 
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 10.0f), 0.0f);
			// �e�̑傫��								�e��������		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyIceRain[i].BulletMake1();
		}
		//�e�����
		if (m_pEnemyIceRain[i].GetFlagBulletMake2())
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyIceRain[i].GetPos() + D3DXVECTOR2(-30.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 10.0f), 0.0f);
			// �e�̑傫��								�e��������		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyIceRain[i].BulletMake2();
		}
		//�e�����
		if (m_pEnemyIceRain[i].GetFlagBulletMake3())
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyIceRain[i].GetPos() + D3DXVECTOR2(50.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 10.0f), 0.0f);
			// �e�̑傫��								�e��������		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyIceRain[i].BulletMake3();
		}
		//�e�����
		if (m_pEnemyIceRain[i].GetFlagBulletMake4())
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyIceRain[i].GetPos() + D3DXVECTOR2(-50.0f, 0.0f),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 10.0f), 0.0f);
			// �e�̑傫��								�e��������		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyIceRain[i].BulletMake4();
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
void EnemyIceRainManagement::Draw(void)const
{
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemyIceRain[i].Draw();
	}

	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		m_pBullet[i].Draw();
	}
}

//======================
// �G��HP�����炷
//======================
bool EnemyIceRainManagement::ReduceHP(int index_num, int reduceHP)
{
	m_pEnemyIceRain[index_num].ReduceHP(reduceHP);

	if (m_pEnemyIceRain[index_num].GetHP() <= 0)
	{//HP���O�ȉ��Ȃ�G������


		return true;
	}
	return false;
}

//==========================
// �G������
//==========================
void EnemyIceRainManagement::DeleteObj(int index_num)
{
	//�G������
	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemyIceRain[i] = m_pEnemyIceRain[i + 1];
	}

	//�p�����̓G���������Ă�
	EnemyManagement::DeleteObj(index_num);
}

//======================
// �e������
//======================
void EnemyIceRainManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < EnemyManagement::GetBulletNum() - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	EnemyManagement::IncreaseBulletNum(-1);
}