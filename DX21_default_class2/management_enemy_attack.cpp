//=======================================
// ���ʂ̓G�̊Ǘ��֌W(cpp�t�@�C��)
// �쐬���F2022/09/13
// �쐬�ҁF��������
//=======================================
#include "management_enemy_attack.h"
#define _USE_MATH_DEFINES
#include <math.h>


const float EnemyAttackManagement::ATTACK_SPEED = 5.0f;
//=========================
// �����t���R���X�g���N�^
//=========================
EnemyAttackManagement::EnemyAttackManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, EnemySetPos& pEnemySetPos)
	:EnemyManagement(ENEMY_NUM, ATTACK, BULLET_ATTACK), m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBullet(pDrawObject2), m_pEnemySetPos(pEnemySetPos)
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

	int i = m_FlameNum;
	if (m_FlameNum == m_SetEnemyTime[m_EnemyNum])
	{
		EnemyAttack temp(m_pDrawObjectEnemy, m_SetEnemy[m_EnemyNum]);
		m_pEnemyAttack[GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		m_EnemyNum++;
	}

	//������G�̏���
	for (int i = 0; i < GetObjNum(); i++) {
		m_pEnemyAttack[i].Update();

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
		EnemyManagement::DeleteObj(index_num, reduceHP);

		m_pEnemySetPos.DeleteEnemy(m_pEnemyAttack[index_num].GetPos());

		for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
			m_pEnemyAttack[i] = m_pEnemyAttack[i + 1];
		}
		EnemyManagement::IncreaseObjNum(-1);

		return true;
	}
	return false;
}

void EnemyAttackManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < EnemyManagement::GetBulletNum() - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	EnemyManagement::IncreaseBulletNum(-1);
}


