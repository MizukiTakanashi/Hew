#include "management_enemy_attack.h"
#define _USE_MATH_DEFINES
#include <math.h>

//==========================
// �萔�̏�����
//==========================
const float EnemyAttackManagement::BULLET_SIZE_X = 100.0f;
const float EnemyAttackManagement::BULLET_SIZE_Y = 100.0f;
const float EnemyAttackManagement::BULLET_SPEED = 0.0f;

const float EnemyAttackManagement::ATTACK_SPEED = 5.0f;
//=========================
// �����t���R���X�g���N�^
//=========================
EnemyAttackManagement::EnemyAttackManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2)
	:EnemyManagement(EnemyManagement::TYPE::ATTACK, ENEMY_NUM, ATTACK, BULLET_ATTACK), m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBullet(pDrawObject2)
{
	m_pEnemyAttack = new EnemyAttack[ENEMY_NUM];

	m_pBullet = new Bullet[ENEMY_NUM];
}

//======================
// �X�V����
//======================
void EnemyAttackManagement::Update(const D3DXVECTOR2& PlayerPos)
{
	m_FlameNum++; //�t���[�����𑝉�

	if (m_FlameNum == m_SetEnemyTime[m_EnemyNum])
	{
		EnemyAttack temp(m_pDrawObjectEnemy, m_SetEnemy[m_EnemyNum]);
		m_pEnemyAttack[GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		m_EnemyNum++;
	}

	if (m_EnemyNum == ENEMY_NUM)
	{
		m_tutorial_clear = true;
	}

	//������G�̏���
	for (int i = 0; i < GetObjNum(); i++) {
		m_tutorial_clear = false;
		m_pEnemyAttack[i].Update();
		if (m_pEnemyAttack[i].GetFlagExplosion() == false) {
			//���ԂɂȂ�����˂�����
			if (m_pEnemyAttack[i].GetFlagAttack()) {
				//�v���C���[�̌��ǂ�(�z�[�~���O�e)
				D3DXVECTOR2 movTemp = PlayerPos - m_pEnemyAttack[i].GetPos();
				D3DXVECTOR2 rotposTemp = m_pEnemyAttack[i].GetPos() - PlayerPos;
				D3DXVec2Normalize(&movTemp, &movTemp);
				movTemp *= ATTACK_SPEED;
				m_pEnemyAttack[i].MovePos(movTemp);
			}
		}
		if (m_pEnemyAttack[i].GetFlagExplosion()==true)
		{
			//�e�����
			if (m_pEnemyAttack[i].GetFlagBulletMake())
			{
				Bullet temp(m_pDrawObjectBullet, m_pEnemyAttack[i].GetPos(),
					D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0, 0.0f), 0.0f);
				// �e�̑傫��								�e��������		
				m_pBullet[EnemyManagement::GetBulletNum()] = temp;

				EnemyManagement::IncreaseBulletNum(1);

				m_pEnemyAttack[i].BulletMake();
			}
			m_pEnemyAttack[i].MovePos(D3DXVECTOR2(0.0f, 0.0f));
			DeleteObj(i);
		}

		//��ʊO�ɏo�������
		if (m_pEnemyAttack[i].GetScreenOut()) {
			DeleteObj(i);
			break;
		}
	}
	//������e�̏���
	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		m_pBullet[i].Update();
		if (m_pBullet[i].GetTime() == 120)
		{
			//�e������
			DeleteBullet(i);
		}
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
void EnemyAttackManagement::Draw(void)const
{
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemyAttack[i].Draw();
	}

	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		m_pBullet[i].Draw();
	}
}

//======================
// �G��HP�����炷
//======================
bool EnemyAttackManagement::ReduceHP(int index_num, int reduceHP)
{
	m_pEnemyAttack[index_num].ReduceHP(reduceHP);
	if (m_pEnemyAttack[index_num].GetHP() <= 0)
	{//HP���O�ȉ��Ȃ�G������

		return true;
	}
	return false;
}
//==========================
// �G������
//==========================
void EnemyAttackManagement::DeleteObj(int index_num)
{
	//�G������
	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemyAttack[i] = m_pEnemyAttack[i + 1];
	}

	//�p�����̓G���������Ă�
	EnemyManagement::DeleteObj(index_num);
}

//======================
// �e������
//======================
void EnemyAttackManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < EnemyManagement::GetBulletNum() - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	EnemyManagement::IncreaseBulletNum(-1);
}